Calling cmake
-------------

`cmake .. -DANTLR_EXECUTABLE=/opt/homebrew/Cellar/antlr/4.10.1/antlr-4.10.1-complete.jar`

`java -jar third-party/antlr-v4.10.1/antlr-4.10.1-complete.jar -visitor -no-listener -Dlanguage=Cpp grammar/MerrillTecplot.g4 -o src`
