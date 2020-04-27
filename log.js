function say_hello() {
    console.log("hello");
}

(function main() {
    const jsLogTime = "It took say_hello in Node.js"
    console.time(jsLogTime);
    for (i = 0; i < 1_000; i++) {
        say_hello();
    }

    console.timeEnd(jsLogTime);
}());