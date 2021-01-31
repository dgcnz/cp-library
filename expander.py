#!/usr/bin/env python3

import re
import sys
import argparse
from logging import Logger, basicConfig, getLogger
from os import getenv, environ, pathsep
from pathlib import Path
from typing import List, Set, Optional


logger = getLogger(__name__)  # type: Logger


class Expander:
    cplib_include = re.compile(r'#include\s*["<](cplib/.*(|.hpp))[">]\s*')
    include_guard = re.compile(r'#.*CPLIB_.*_HPP')

    def is_ignored_line(self, line) -> bool:
        if self.include_guard.match(line):
            return True
        if line.strip() == "#pragma once":
            return True
        if line.strip().startswith('//'):
            return True
        return False

    def __init__(self, lib_paths: List[Path]):
        self.lib_paths = lib_paths

    included = set()  # type: Set[Path]

    def find_cpl(self, cpl_name: str) -> Path:
        for lib_path in self.lib_paths:
            path = lib_path / cpl_name
            if path.exists():
                return path
        logger.error('cannot find: {}'.format(cpl_name))
        raise FileNotFoundError()

    def expand_cpl(self, cpl_file_path: Path) -> List[str]:
        if cpl_file_path in self.included:
            logger.info('already included: {}'.format(cpl_file_path.name))
            return []
        self.included.add(cpl_file_path)
        logger.info('include: {}'.format(cpl_file_path.name))

        cpl_source = open(str(cpl_file_path)).read()

        result = []  # type: List[str]
        for line in cpl_source.splitlines():
            if self.is_ignored_line(line):
                continue

            m = self.cplib_include.match(line)
            if m:
                name = m.group(1)
                result.extend(self.expand_cpl(self.find_cpl(name)))
                continue

            result.append(line)
        return result

    def expand(self, source: str) -> str:
        self.included = set()
        result = []  # type: List[str]
        for line in source.splitlines():
            m = self.cplib_include.match(line)
            if m:
                cpl_path = self.find_cpl(m.group(1))
                result.extend(self.expand_cpl(cpl_path))
                continue

            result.append(line)
        return '\n'.join(result)


if __name__ == "__main__":
    basicConfig(
        format="%(asctime)s [%(levelname)s] %(message)s",
        datefmt="%H:%M:%S",
        level=getenv('LOG_LEVEL', 'INFO'),
    )
    parser = argparse.ArgumentParser(description='Expander')
    parser.add_argument('source', help='Source File')
    parser.add_argument('-c', '--console',
                        action='store_true', help='Print to Console')
    parser.add_argument('--lib', help='Path to CP Library')
    opts = parser.parse_args()

    lib_paths = []
    if opts.lib:
        lib_paths.append(Path(opts.lib))
    if 'CPLUS_INCLUDE_PATH' in environ:
        lib_paths.extend(
            map(Path, filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))
    lib_paths.append(Path.cwd())
    expander = Expander(lib_paths)
    source = open(opts.source).read()
    output = expander.expand(source)

    if opts.console:
        print(output)
    else:
        with open('combined.cpp', 'w') as f:
            f.write(output)
