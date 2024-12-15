// Tries.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector;
using std::string;
using std::unordered_map;

class TrieNode {
private:
	unordered_map<char, TrieNode*> children;
public:
	unordered_map<char, TrieNode*> getChildren() {
		return children;
	}
	bool isEndOfWord;
	TrieNode() : isEndOfWord{false} {}
	bool hasChildren() {
		return !children.empty();
	}
	bool hasChild(char ch) {
		return children.find(ch) != children.end();
	}
	void addChild(char ch) {
		children[ch] = new TrieNode();
	}
	TrieNode* getChild(char ch) {
		return children[ch];
	}
	void removeChild(char ch) {
		children.erase(ch);
	}
};

class Trie {
	TrieNode *root;
public:
	Trie();
private:
	void remove(TrieNode* root, string word, int index);
	void collectWords(TrieNode* node, const string& prefix, vector<string>& result);
public:
	void insert(string word);
	bool contains(string word);
	void remove(string word);
	vector<string> findWords(const string& prefix);
	static void demoTrie();
};




// TODO: Reference additional headers your program requires here.
