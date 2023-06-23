const net = require('net');

const HOST = '127.0.0.1';
const PORT = 55001;

// Create a new TCP socket
const client = new net.Socket();

// Connect to the server
client.connect(PORT, HOST, () => { 
  
    // Send a message to the server
    client.write('Hello, from JS!');
});