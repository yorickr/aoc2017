const readline = require('readline');

const stdin = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false,
});

const lines = [];
var amount_lines = 0;

const day4p1 = () => {
    const total_valid_lines = lines.map((line) => {
        const phrases = line.split(' ');
        const filtered_phrases = phrases.reduce((acc, val) => {
            if (!acc.includes(val)) {
                acc.push(val);
            }
            return acc;
        }, []);
        return filtered_phrases.length == phrases.length;
    }).reduce((acc, val) => {
        return acc + val;
    }, 0);
    console.log('Total valid lines is ' + total_valid_lines);
};

const is_anagram = (word1, word2) => {
    if (word1.length === word2.length) {
        const word1s = word1.split('').sort().join('');
        const word2s = word2.split('').sort().join('');
        console.log('Comparing word1 and word2 ', word1, word2);
        console.log('Result ', word1s, word2s, word1s === word2s);
        return word1s === word2s;
    } else {
        return false;
    }
};

const day4p2 = () => {
    const total_valid_lines = lines.map((line) => {
        const phrases = line.split(' ');
        const filtered_phrases = phrases.reduce((acc, val) => {
            if (!acc.includes(val)) {
                acc.push(val);
            }
            return acc;
        }, []);
        if (filtered_phrases.length !== phrases.length) {
            return 0;
        } else {
            // check for anagrams.
            // check 1 word against ALL words in phrases.
            for (w1 of phrases) {
                for (w2 of phrases) {
                    if (w1 === w2) {
                        continue;
                    }
                    if (is_anagram(w1, w2)) {
                        return 0;
                    }
                }
            }
            return 1;
        }
    }).reduce((acc, val) => {
        return acc + val;
    }, 0);
    console.log('Total valid lines is ' + total_valid_lines);
};

stdin.question('How many lines should we read? ', (answer) => {
    console.log('Amount of lines to be read set to ' + answer);
    amount_lines = parseInt(answer);
});

stdin.on('line', (line) => {
    lines.push(line);
    amount_lines--;
    if (amount_lines === 0) {
        // we done bois.
        // day4p1();
        day4p2();
        stdin.close();
    }
});
