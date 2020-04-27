# endl_bench

## What is this?
A simple comparison between using std::endl and manually adding a newline character.

## Why?
It is well known in the C++ community that std::endl has a problem. That problem is that it is unnecessarily slow.
It does two things every time you call std::endl.
```
std::cout << "hello" << std::endl;
```
You do the equivalent of this which is fairly apparent, but you also flush the buffer.
```
std::cout << "hello" << "\n";
```

## What kind of performance hit can I expect?
It will wildly vary based on your use case, how expensive this operation is for your application, and whether you should have used it in the first place. Here are my results of this trivial benchmark.

```
It took say_hello 206 ms
It took say_hello_with_flush 353 ms
It took say_hello in Node.js: 265.922 ms
```

## References
My favorite article on the subject:
https://accu.org/index.php/journals/2619