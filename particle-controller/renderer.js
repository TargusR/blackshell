// This file is required by the index.html file and will
// be executed in the renderer process for that window.
// All of the Node.js APIs are available in this process.

/*
var recept = document.getElementById("last-command");
console.log(recept)
recept.innerHTML = "Hola";
console.log(recept)
console.log($);
*/

$("#last-command").html("hola");


var net = require('net');
var HOST = '127.0.0.1';
var PORT = 1337;


// crear servidor
var server = net.createServer(function(socket) {
  console.log('SERVER ONLINE: ' + socket.remoteAddress +':'+ socket.remotePort + '\r\n');
  socket.pipe(socket);

  socket.on('data', function(data) {  
    //console.log('DATA ' + sock.remoteAddress + ': ' + data);
    // Write the data back to the socket, the client will receive it as data from the server
    socket.write('You said: "' + data + '"'); 
  });

}).listen(PORT, HOST);

// crear cliente
var client = net.Socket();
client.connect(PORT, HOST, function() {
    //console.log('CONNECTED TO: ' + HOST + ':' + PORT);
    // Write a message to the socket as soon as the client is connected, the server will receive it as message from the client 
    client.write('Hello, im a client');
});

$(document).click(function(e) {
  client.write('Coordinates are: ' + e.pageX + ", " + e.pageY);
  $("#cx").html(e.pageX);
  $("#cy").html(e.pageY);
})