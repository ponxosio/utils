COPY %1\utils.dll X:\utils\dll_%2\bin\utils.dll
COPY %1\utils.lib X:\utils\dll_%2\bin\utils.lib

DEL /S X:\utils\dll_%2\include\*.h
XCOPY /S /Y X:\utils\utils\*.h X:\utils\dll_%2\include