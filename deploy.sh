#!/bin/bash

rm -rf _build
jupyter-book build . --toc ./_toc.yml --config _jupBook/_config.yml
ghp-import -n -p -f _build/html
