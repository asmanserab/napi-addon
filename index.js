//index.js
const testNapiAddon = require('./build/Release/test-napi.node');

//Funktionen
console.log('addon',testNapiAddon.hello());
console.log('addon',testNapiAddon.add(3, 8));

// Klassen-Methoden
const classInstance = new testNapiAddon.ClassExample(4.3);
console.log('Testing class initial value : ', classInstance.getValue());
console.log('After adding 3.3 : ', classInstance.add(3.3));

module.exports = testNapiAddon;