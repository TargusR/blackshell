// Create a server instance, and chain the listen function to it
// The function passed to net.createServer() becomes the event handler for the 'connection' event
// The sock object the callback function receives UNIQUE for each connection
var net = require('net');
var HOST = '127.0.0.1';
var PORT = 1337;

net.createServer(function(sock) {
    
    // We have a connection - a socket object is assigned to the connection automatically
    sock.write('Server Online: ' + sock.remoteAddress +':'+ sock.remotePort);
    
    // Add a 'data' event handler to this instance of socket
    sock.on('data', function(data) {
        
        console.log('DATA ' + sock.remoteAddress + ': ' + data);
        // Write the data back to the socket, the client will receive it as data from the server
        sock.write('Client said "' + data + '"');
        
    });
    
    // Add a 'close' event handler to this instance of socket
    sock.on('close', function(data) {
        //console.log('CLOSED: ' + sock.remoteAddress +' '+ sock.remotePort);
    });

    setInterval(function() {
      sock.write("Soy necio.\r\n");
    }, 5000);
    
}).listen(PORT, HOST);

//console.log('Server listening on ' + HOST +':'+ PORT);


var client = new net.Socket();
client.connect(PORT, HOST, function() {

    //console.log('CONNECTED TO: ' + HOST + ':' + PORT);
    // Write a message to the socket as soon as the client is connected, the server will receive it as message from the client 
    client.write('I am Chuck Norris!');

});

// Add a 'data' event handler for the client socket
// data is what the server sent to this socket
client.on('data', function(data) {
    
    console.log('CLIENT RECEIVED:: ' + data);
    // Close the client socket completely
    //client.destroy();
    
});

// Add a 'close' event handler for the client socket
client.on('close', function() {
    console.log('Connection closed');
});

$(document).click(function(e) {
  client.write('Coordinates are: ' + e.pageX + ", " + e.pageY);
  $("#cx").html(e.pageX);
  $("#cy").html(e.pageY);
})