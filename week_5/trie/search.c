// Function to search a word in the Trie
int search(TrieNode *root, const char *key) {
    // 'level' will keep track of the level in the Trie (depth of the word being searched)
    int level;

    // 'length' stores the length of the word to be searched
    int length = strlen(key);

    // 'index' will be used to index the character in the node's children array
    int index;

    // 'pNode' is a pointer used to traverse the Trie, initialized to point to the root of the Trie
    TrieNode *pNode = root;

    // Loop over each character in the word
    for (level = 0; level < length; level++) {
        // Calculate the index of the current character in the node's children array
        // Subtract 'a' to get a value in the range [0, ALPHABET_SIZE - 1]
        index = key[level] - 'a';

        // If the current character is not in the Trie, return 0 (word not found)
        if (!pNode->children[index])
            return 0;

        // Move to the next node in the Trie
        pNode = pNode->children[index];
    }

    // After all characters in the word have been processed, if the current node is marked as
    // the end of a word and is not NULL, then the word is in the Trie. Return 1 (word found).
    // Otherwise, return 0 (word not found).
    return (pNode != NULL && pNode->isEndOfWord);
}
