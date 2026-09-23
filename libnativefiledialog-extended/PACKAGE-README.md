# libnativefiledialog-extended - Native File Dialog Extended

This is a `build2` package for the
[`nativefiledialog-extended`](https://github.com/btzy/nativefiledialog-extended)
C library. It provides a small, portable API for invoking native file open,
folder select, and file save dialogs on Windows, macOS, and Linux (GTK3 or
xdg-desktop-portal), without linking large dependencies like wxWidgets or Qt.
An optional C++ wrapper (`nfd.hpp`) is provided for C++ projects.


## Usage

To start using `libnativefiledialog-extended` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libnativefiledialog-extended ^1.4.0
```

Then import the library in your `buildfile`:

```
import libs = libnativefiledialog-extended%lib{nfd}
```

On Linux, this library also requires the GTK3 development files
(`gtk+-3.0`, discovered via `pkg-config`) or, if
`config.libnativefiledialog_extended.portal` is enabled, `dbus-1`.


## Importable targets

This package provides the following importable targets:

```
lib{nfd}
```

`lib{nfd}` is the native file dialog library itself.


## Configuration variables

This package provides the following configuration variables:

```
[bool] config.libnativefiledialog_extended.portal                        ?= false
[bool] config.libnativefiledialog_extended.case_sensitive_filter         ?= false
[bool] config.libnativefiledialog_extended.append_extension              ?= false
[bool] config.libnativefiledialog_extended.override_recent_with_default  ?= false
[bool] config.libnativefiledialog_extended.macos_allowed_content_types   ?= true
```

`portal` selects the xdg-desktop-portal/D-Bus backend instead of the
default GTK3 backend on Linux.

`case_sensitive_filter` makes file filters case-sensitive on Linux.

`append_extension` automatically appends the file extension to an
extensionless selection in the save dialog on Linux (mainly relevant to the
portal backend).

`override_recent_with_default` uses the default path instead of the recent
folder on Windows.

`macos_allowed_content_types` uses `allowedContentTypes`
(`UniformTypeIdentifiers`, macOS >= 11) instead of the deprecated
`allowedFileTypes` for filter lists on macOS.
