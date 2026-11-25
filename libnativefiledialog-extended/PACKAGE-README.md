# libnativefiledialog-extended - Cross-platform native file open/save/folder dialogs

This is a `build2` package for the
[`nativefiledialog-extended`](https://github.com/btzy/nativefiledialog-extended)
C library. It provides a small, portable API for invoking native file open,
folder select, and file save dialogs on Windows, macOS, Linux, and BSD (GTK3
or xdg-desktop-portal), without linking large dependencies like wxWidgets or Qt.
An optional C++ wrapper (`nfd.hpp`) is provided for C++ projects.


## Usage

To start using `libnativefiledialog-extended` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnativefiledialog-extended ^1.4.1
```

Then import the library in your `buildfile`:

```
import libs = libnativefiledialog-extended%lib{nfd}
```

On Linux and BSD, the dialogs are shown with GTK3 (`gtk+-3.0`) or, with the
`portal` configuration variable (see below), with xdg-desktop-portal over D-Bus
(`dbus-1`). Wayland parent window handles additionally require
`wayland-client` and the `wayland-scanner` tool. There are no `build2`
packages for these, so they must be installed with the system package
manager, for example `libgtk-3-dev` (or `libdbus-1-dev`) and `libwayland-dev`
on Debian and Ubuntu, or `gtk3-devel` (or `dbus-devel`) and `wayland-devel` on
Fedora.


## Importable targets

This package provides the following importable targets:

```
lib{nfd}
```

`lib{nfd}` is the native file dialog library itself.


## Configuration variables

This package provides the following configuration variables, which mirror the
upstream CMake options of the same name (`NFD_PORTAL`, `NFD_X11`, etc.):

```
[bool] config.libnativefiledialog_extended.portal                                ?= false
[bool] config.libnativefiledialog_extended.x11                                   ?= <linux or bsd target>
[bool] config.libnativefiledialog_extended.wayland                               ?= <linux or bsd target>
[bool] config.libnativefiledialog_extended.case_sensitive_filter                 ?= false
[bool] config.libnativefiledialog_extended.append_extension                      ?= false
[bool] config.libnativefiledialog_extended.override_recent_with_default          ?= false
[bool] config.libnativefiledialog_extended.use_allowedcontenttypes_if_available  ?= <macos target>
```

`portal` selects the xdg-desktop-portal backend (D-Bus) instead of the GTK3
backend on Linux and BSD. Note that it changes the layout of a public
structure and is therefore also exported to the library consumers.

`x11` and `wayland` enable support for X11 and Wayland parent window handles,
respectively, on Linux and BSD, with either backend.

`case_sensitive_filter` makes file filters case-sensitive on Linux and BSD.

`append_extension` automatically appends the file extension to an
extensionless selection in the save dialog on Linux and BSD (only used by the
portal backend).

`override_recent_with_default` uses the default path instead of the recent
folder on Windows.

`use_allowedcontenttypes_if_available` uses `allowedContentTypes`
(`UniformTypeIdentifiers`) instead of the deprecated `allowedFileTypes` for
filter lists on macOS if the deployment target is macOS 11 or later.
