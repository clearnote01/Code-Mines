# TRIE WITH CHEATING( CHEAT CAUSE ITS PYTHON (makes life easier)
class Node(object):
    def __init__(self):
        self.letter = 0
        self.word = 0
        self.word_no = []
        self.alphalist=['a','b','c','d','e','f','g','j','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        self.children = {alphabet:None for alphabet in self.alphalist}
    def increment_letter(self):
        self.letter += 1
    def increment_word(self):
        self.word += 1
    def append_wordNo(self, word_num):
        self.word_no.append(word_num)
    def print_children(self):
        print self.children

class Trie(object):
    def __init__(self, root):
        self.root = root
    def insert(self,myword, i, obj, word_no):
        '''We don't give you a reversed word either'''
        if (i == -1):
            return
        letter = myword[i]
        if(obj.children[letter]==None):
            obj.children[letter] = Node()
        obj.children[letter].increment_letter()
        obj.children[letter].append_wordNo(word_no)
        if (i == 0):
            obj.children[letter].increment_word()
        self. insert(myword, i-1, obj.children[letter],word_no)
        return
    
    def find_rhyme(self, myword, i, wordList, obj):
        '''We don't give you a reversed word for sure'''
        if(i==-1):
            # IT WILL RETURN THAT THE RHYMING WORD CONTAINS THE SUBJECT WORD WITHIN ITSELF. ALSO, NOW THE
            # LEXIOGRAPHICALLY NEAREST WORD IS TO BE GIVEN.
            # IN OTHER PROGRAMMING LANGUAGES, ONE WOULD HAVE TO MAKE ANOTHER TRIE TO CHECK THE LEXIOGRAPHIC ORDER
            a = [wordList[i] for i in obj.word_no]
            a.sort()
            if (a[0] == myword):
                return a[1]
            return a[0]
        letter = myword[i]
        if((obj.children[letter] == None)and(i==(len(myword)-1))):
            return "-1"

        if(((obj.children[letter]==None)or(obj.children[letter].letter==1))and(i!=len(myword)-1)):
            # This implies that there is only one word, in that direction and that must be our own query word
            # or it must be a word not present in the trie
            # So, it has to be something different
            a = [wordList[i] for i in obj.word_no]
            a.sort()
            if(len(a)<1):
				return "-1"
			if(a[0] == myword):
				return a[1]
			return a[0]
        elif((obj.children[letter].letter == 1)and(i==len(myword)-1)):
            a = wordList[obj.children[letter].word_no[0]]
			if(a==myword):
				return "-1"
			else:
            	return a
        else:
            #This means we have a longer common suffix, hopefully
            answer = self.find_rhyme(myword, i - 1, wordList, obj.children[letter])
            return answer

def main():
    '''this is the main function'''
    listword = [] 
    root = Node()
    myTrie = Trie(root)
    word = 'suyash'
    i=0
    while(word!=''):
        word = raw_input()
        listword.append(word)
        myTrie.insert(word, len(word)-1, root, i)
        i += 1
    #Second Part of input
    queryAnswer = []
    word ="suas"
    while(word!=''):
        word = raw_input()
        answer = myTrie.find_rhyme(word, len(word)-1, listword, root)
        if (answer == "-1"):
            print ("NO RHYME FOUND");
        else:
            print(answer)

if __name__ == '__main__':
    main()


