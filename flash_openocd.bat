pause
cd scripts
..\openocd.exe -f board/bluepill.cfg -c "reset_config trst_only combined" -c "program ../Release/USID.elf verify reset exit" 
pause
