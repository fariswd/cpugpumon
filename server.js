var request = require("request")
var SerialPort = require('serialport');
var port = new SerialPort('COM6', {
  baudRate: 9600
});
var sleep = require('system-sleep');

var url = "http://localhost:55555"
var data;


//function search
var search = (nameKey, myArray) => {
    for (var i=0; i < myArray.length; i++) {
        if (myArray[i].SensorName === nameKey) {
            return myArray[i];
        }
    }
}

//function send serial
var writeSerial = (mess) => {
    port.write(mess, function(err) {
        if (err) {
        return console.log('Error on write: ', err.message);
        }
        console.log('message written ' + mess);
    });

    // Open errors will be emitted as an error event 
    port.on('error', function(err) {
        console.log('Error: ', err.message);
    });

}

//forever loop
while(true){

//funtion read data from url
request({
    url: url,
    json: true
}, function (error, response, body) {
    if (!error && response.statusCode === 200) {
        data = body; 
        
        var cpu = search("CPU Package", data);
        var gpu = search("GPU Temperature", data);
        var cpuUsg = search("Total CPU Usage",data);
        var cpuUsgVal = Math.round(Number(cpuUsg.SensorValue));
        var gpuUsg = search("GPU Core Load", data);
        var gpuUsgVal = Math.round(Number(gpuUsg.SensorValue));

        writeSerial("cl");
        sleep(200);
        writeSerial(1+"CPU "+cpu.SensorValue+"C "+cpuUsgVal+ "%");
        sleep(200);
        writeSerial(2+"GPU "+gpu.SensorValue+"C "+gpuUsgVal+ "%");

    }
})

sleep(5000);
}