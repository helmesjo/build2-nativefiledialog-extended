# nativefiledialog-extended - Cross-platform native file open/save/folder dialogs

This is a `build2` package repository for
[`nativefiledialog-extended`](https://github.com/btzy/nativefiledialog-extended),
a small library that portably invokes native file open, folder select, and
file save dialogs.

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`nativefiledialog-extended` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libnativefiledialog-extended/PACKAGE-README.md) file.

The development setup for `nativefiledialog-extended` uses the standard `bdep`-based workflow.
For example:

```
git clone .../nativefiledialog-extended.git
cd nativefiledialog-extended

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```
