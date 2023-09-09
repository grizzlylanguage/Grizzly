This is how the tokens should be lexed. It might not be exactly like this if it's not fix it.

```jsonc
// This is all the lines.
[
    // This is one line.
    [
        // These are the tokens of the line.
        { Type: "Function", Value: "print" },
        { Type: "Punctuation", Value: "(" },
        { Type: "String", Value: "\"Hello World!\"" },
        { Type: "Punctuation", Value: ")" }
    ],

    // This is another line.
    [
        // These are the tokens of the line.
        { Type: "Command", Value: "exit" }
    ]
]
```