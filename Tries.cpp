// Tries.cpp : Defines the entry point for the application.
//

#include "Tries.h"

Trie::Trie() {
	root = new TrieNode();
}

void Trie::insert(string word) {
	TrieNode* current = root;
	for (char ch : word) {
		if (!current->hasChild(ch)) {
			current->addChild(ch);
		}
		current = current->getChild(ch);
	}
	current->isEndOfWord = true;
}

bool Trie::contains(string word) {
	if (word.empty()) return false;
	TrieNode* current = root;
	for (char ch : word) {
		if (!current->hasChild(ch)) {
			return false;
		}
		current = current->getChild(ch);
	}
	return current->isEndOfWord;
}

vector<string> Trie::findWords(const string& prefix) {
	vector<string> result;
	TrieNode* current = root;

	// Navigate to the node corresponding to the prefix
	for (char ch : prefix) {
		if (!current->hasChild(ch)) {
			return result; // Prefix not found
		}
		current = current->getChild(ch);
	}

	// Collect words starting from the current node
	collectWords(current, prefix, result);
	return result;
}

void Trie::remove(string word)
{
	if (word.empty()) return;
	remove(root, word, 0);
}

void Trie::collectWords(TrieNode* node, const string& prefix, vector<string>& result) {
	if (node->isEndOfWord) {
		result.push_back(prefix);
	}
	for (auto& child : node->getChildren()) {
		collectWords(child.second, prefix + child.first, result);
	}
}

void Trie::remove(TrieNode* root, string word, int index)
{
	if (index == word.length()) {
		root->isEndOfWord = false;
		return;
	}

	char ch = word[index];
	TrieNode *child = root->getChild(ch);
	if (child == nullptr)
		return;

	remove(child, word, index + 1);

	if (!child->hasChildren() && !child->isEndOfWord)
		root->removeChild(ch);
}

void Trie::demoTrie() {
	Trie trie;
	trie.insert("cat");
	trie.insert("canine");

	string prefix = "c";
	vector<string> words = trie.findWords(prefix);
	if (words.empty()) {
		std::cout << "No words found with the prefix \"" << prefix << "\".\n";
	}
	else {
		std::cout << "Words with the prefix \"" << prefix << "\":\n";
		for (const string& word : words) {
			std::cout << word << std::endl;
		}
	}
}
