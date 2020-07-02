set program=DeleteComment.exe

echo.01 - Base test with good input data > expected.txt
%program% < test1.txt >> expected.txt

echo 02 - Test with incorrect path >> expected.txt
%program% < test2.txt >> expected.txt


