# UART_Library_BBB
Library to use the UART peripheral of the Beagle Bone Black REVC

**Note, you have to enable the UART you want to work on by loading the device tree overlay  
To load the device tree overlay for Beagle Bone Black running Debian 10 (4.19.94-ti-r42 kernel)  
Step1: sudo nano /boot/uEnv.txt  
Step2: Add "uboot_overlay_addr4=/lib/firmware/BB-UART4-00A0.dtbo"   
Step3: Save and Reboot. 

