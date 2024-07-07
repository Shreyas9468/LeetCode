public class WordFilter {
    private class TrieNode {
        private char character;
        private final TrieNode[] children = new TrieNode[26];
        private final List<Integer> wordIndices = new ArrayList<>();
    }

    private final TrieNode prefixRoot = new TrieNode();
    private final TrieNode suffixRoot = new TrieNode();
    
    private void insert(final String word, final int start, final int end, final int step, TrieNode root, final int index) {
        for(int i = start; i != end; i += step) {
            int charIndex = word.charAt(i) - 'a';

            if(root.children[charIndex] == null)
                root.children[charIndex] = new TrieNode();

            root = root.children[charIndex];
            root.wordIndices.add(index);
        }
    }
    
    public WordFilter(final String[] words) {
        final Set<String> set = new HashSet<>();

        for(int i = words.length - 1; i > -1; i--) {
            if(set.contains(words[i])) 
                continue;

            set.add(words[i]);

            insert(words[i], 0, words[i].length(), 1, this.prefixRoot, i);
            insert(words[i], words[i].length() - 1, -1, -1, this.suffixRoot, i);
        }
    }

    public List<Integer> getIndices(final String word, final int start, final int end, final int step, TrieNode root) {
        for(int i = start; i != end; i += step) {
            root = root.children[word.charAt(i) - 'a'];

            if(root == null) 
                return new ArrayList<>();
        }
        return root.wordIndices;
    }
    
    public int f(final String prefix, final String suffix) {
        final List<Integer> prefixIndices = getIndices(prefix, 0, prefix.length(), 1, this.prefixRoot);
        final List<Integer> suffixIndices = getIndices(suffix, suffix.length() - 1, -1, -1, this.suffixRoot);

        int prefixIndex = 0, suffixIndex = 0;

        while(prefixIndex < prefixIndices.size() && suffixIndex < suffixIndices.size()) {
            int prefixValue = prefixIndices.get(prefixIndex), suffixValue = suffixIndices.get(suffixIndex);

            if(prefixValue == suffixValue) 
                return suffixValue;

            if(suffixValue > prefixValue) 
                suffixIndex++;
            else 
                prefixIndex++;
        }

        return -1;
    }
}

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */