---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n\nimport re\nimport sys\nimport argparse\nfrom logging\
    \ import Logger, basicConfig, getLogger\nfrom os import getenv, environ, pathsep\n\
    from pathlib import Path\nfrom typing import List, Set, Optional\n\n\nlogger =\
    \ getLogger(__name__)  # type: Logger\n\n\nclass Expander:\n    cplib_include\
    \ = re.compile(r'#include\\s*[\"<](cplib/.*(|.hpp))[\">]\\s*')\n    include_guard\
    \ = re.compile(r'#.*CPLIB_.*_HPP')\n\n    def is_ignored_line(self, line) -> bool:\n\
    \        if self.include_guard.match(line):\n            return True\n       \
    \ if line.strip() == \"#pragma once\":\n            return True\n        if line.strip().startswith('//'):\n\
    \            return True\n        return False\n\n    def __init__(self, lib_paths:\
    \ List[Path]):\n        self.lib_paths = lib_paths\n\n    included = set()  #\
    \ type: Set[Path]\n\n    def find_cpl(self, cpl_name: str) -> Path:\n        for\
    \ lib_path in self.lib_paths:\n            path = lib_path / cpl_name\n      \
    \      if path.exists():\n                return path\n        logger.error('cannot\
    \ find: {}'.format(cpl_name))\n        raise FileNotFoundError()\n\n    def expand_cpl(self,\
    \ cpl_file_path: Path) -> List[str]:\n        if cpl_file_path in self.included:\n\
    \            logger.info('already included: {}'.format(cpl_file_path.name))\n\
    \            return []\n        self.included.add(cpl_file_path)\n        logger.info('include:\
    \ {}'.format(cpl_file_path.name))\n\n        cpl_source = open(str(cpl_file_path)).read()\n\
    \n        result = []  # type: List[str]\n        for line in cpl_source.splitlines():\n\
    \            if self.is_ignored_line(line):\n                continue\n\n    \
    \        m = self.cplib_include.match(line)\n            if m:\n             \
    \   name = m.group(1)\n                result.extend(self.expand_cpl(self.find_cpl(name)))\n\
    \                continue\n\n            result.append(line)\n        return result\n\
    \n    def expand(self, source: str) -> str:\n        self.included = set()\n \
    \       result = []  # type: List[str]\n        for line in source.splitlines():\n\
    \            m = self.cplib_include.match(line)\n            if m:\n         \
    \       cpl_path = self.find_cpl(m.group(1))\n                result.extend(self.expand_cpl(cpl_path))\n\
    \                continue\n\n            result.append(line)\n        return '\\\
    n'.join(result)\n\n\nif __name__ == \"__main__\":\n    basicConfig(\n        format=\"\
    %(asctime)s [%(levelname)s] %(message)s\",\n        datefmt=\"%H:%M:%S\",\n  \
    \      level=getenv('LOG_LEVEL', 'INFO'),\n    )\n    parser = argparse.ArgumentParser(description='Expander')\n\
    \    parser.add_argument('source', help='Source File')\n    parser.add_argument('-c',\
    \ '--console',\n                        action='store_true', help='Print to Console')\n\
    \    parser.add_argument('--lib', help='Path to CP Library')\n    opts = parser.parse_args()\n\
    \n    lib_paths = []\n    if opts.lib:\n        lib_paths.append(Path(opts.lib))\n\
    \    if 'CPLUS_INCLUDE_PATH' in environ:\n        lib_paths.extend(\n        \
    \    map(Path, filter(None, environ['CPLUS_INCLUDE_PATH'].split(pathsep))))\n\
    \    lib_paths.append(Path.cwd())\n    expander = Expander(lib_paths)\n    source\
    \ = open(opts.source).read()\n    output = expander.expand(source)\n\n    if opts.console:\n\
    \        print(output)\n    else:\n        with open('combined.cpp', 'w') as f:\n\
    \            f.write(output)\n"
  dependsOn: []
  isVerificationFile: false
  path: expander.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: expander.py
layout: document
redirect_from:
- /library/expander.py
- /library/expander.py.html
title: expander.py
---
