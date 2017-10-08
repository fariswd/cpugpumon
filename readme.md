# cpugpumon
Identifikasi Temperature & %Usage untuk CPU+GPU  


![alt text](https://github.com/fariswd/cpugpumon/raw/master/cpugpumon.jpg "Header")

Adalah sebuah hardware monitoring yang memonitor suhu dan %usage pada komputer. Dalam hal ini HWInfo Plugin telah menyediakan RESTful `API` yang dapat diakses dalam bentuk `JSON`. Dengan bantuan `NodeJs` untuk mengirimkan value yang diinginkan (dalam hal ini Temperatur & Usage) ke `Arduino` yang dilengkapi dengan Lcd16x2.  


### HWInfo Plugin
download here https://www.hwinfo.com/forum/Thread-Introducing-Remote-Sensor-Monitor-A-RESTful-Web-Server


### Arduino/esp8266 pada "COM6"
Menggunakan library LiquidCrystalI2C  
Wire Map:  
ESP => LCDI2C  
D1 => SCL  
D2 => SDA  
Vin => 5V  
Gnd => Gnd  


### NodeJs
Metode Foreverloop sampai ctrl+c  
Menggunakan library:  
request = mengambil body dari sebuah halaman website(dalam hal ini ambil json yang digenerate oleh HWInfo Plugin di localhost:55555)  
serialport = write serial ke arduino  
system-sleep = membuat delay sekian milli second


### Catatan
send serial pada COM6 baud rate 9600  
send "cl" untuk clear screen  
send dengan awalan "1" untuk menulis pada baris 1  
send dengan awalan "2" untuk menulis pada baris 2  
jalankan "Remote Sensor Monitor.exe" dahulu kemudian server.js  
pengetesan dengan Dota2 https://twitter.com/radenfaris/status/916874818556903424


Faris Widyantho  
2017