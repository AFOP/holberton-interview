#!/usr/bin/node
// Write a script that prints all characters of a Star Wars movie:
// The first positional argument passed is the Movie ID - example: 3 = “Return of the Jedi”
// Display one character name per line in the same order as the “characters” list in the /films/ endpoint
// You must use the Star wars API
// You must use the request module
const request = require('request');
request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, (err, res, body) => {
  if (!err) {
    const characters = JSON.parse(body).characters;
    recursionRequestPrint(characters, 0);
  }
});

function recursionRequestPrint (url, index) {
  request(url[index], (err, res, body) => {
    if (!err) {
      console.log(JSON.parse(body).name);
      if (index + 1 < url.length) recursionRequestPrint(url, ++index);
    }
  });
}
