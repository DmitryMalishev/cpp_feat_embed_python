@echo off
setlocal

echo. & echo THIS SCRIPT downloads embedded version of Python 3.10 to 'python_embedded' dir,
echo then copyies numpy package from the Python default system installation. & echo.
echo Make sure you have Python 3.10 installed + numpy and PYTHONPATH env var is set & echo.

PAUSE

if "%PYTHONPATH%" == "" (
	echo ERROR: PYTHONPATH is not set
	exit 1
)

if not exist "%PYTHONPATH%\Lib\site-packages\numpy" (
	echo ERROR: NUMPY is not found
	exit 1
)

set "remotePythonEmbeddedPackage=https://www.python.org/ftp/python/3.10.10/python-3.10.10-embed-amd64.zip"
set "localPythonEmbeddedFolder=python_embedded\"

for %%X in ("%remotePythonEmbeddedPackage%") do set pythonFileName=%%~nxX
echo The name of the file is %pythonFileName%

echo ## Downloading %pythonFileName%...
curl -o "%pythonFileName%" %remotePythonEmbeddedPackage%

echo ## Extracting %pythonFileName%...
tar xzf %pythonFileName% -C %localPythonEmbeddedFolder%

echo ## Copying NUMPY from system to embedded dir...
xcopy  /E /Y /V /q "%PYTHONPATH%\Lib\site-packages\numpy" "%localPythonEmbeddedFolder%\numpy\"

echo. & echo FINISH: ALL OPERATIONS DONE