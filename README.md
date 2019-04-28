TTrpg install steps
=

Use the CMake, duh

CMake calls git submodules to pull the external libs, if you're using and IDE
and haven't (or cannot) make it use your SSH key (hi windows), just update the submodule yourself (with something like
'git submodule update')

and then rebuild.

External libs pulled are:
* [asio] (https://github.com/chriskohlhoff/asio/)
* [catch] (https://github.com/catchorg/Catch2)
* [rapidjson] (https://github.com/Tencent/rapidjson)

Things you need to get on your machine to build:
* [OpenSSL] (https://github.com/openssl/openssl) you need the **static libs** for crypto and ssl (asio needs it)

(btw there's nothing right now)
