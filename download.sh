#!/usr/bin/expect -f 
#the program file in the host PC 
set host_file        thermal    
#the password of the user in lophilo board
set lophilo_user     simit      
#the ip or hostname of lophilo board    
set lophilo_password simit123     
#the user name in lophilo board
set lophilo_address  10.10.10.106    
#the directory to store the program on lophilo board
set lophilo_path     ~/test/          
#download program
spawn scp $host_file $lophilo_user@$lophilo_address:$lophilo_path
set timeout 50
expect "password:"
set timeout 50
send "$lophilo_password\r"
set timeout 50
send "exit\r"
expect eof
