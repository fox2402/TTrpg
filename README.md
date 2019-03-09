TTrpg install steps
=

Use the CMake, duh

CMake calls git submodules to pull the external libs, if you're using and IDE
and haven't (or cannot) make it use your SSH key (hi windows), just use this:
	..* git submodule update

and then rebuild.

External libs pulled are:
	..* [asio](https://github.com/chriskohlhoff/asio/)

(btw there's nothing right now)
