class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        //sorting in ascending order of deck
        sort(deck.begin(),deck.end());
        queue<int> q;
        for(int i=0;i<n;++i){
            q.push(i);
        }
        vector<int> result(n);
        for(int i=0;i<n;++i){
            int card=deck[i];
             //assign the current smallest card to front index
             result[q.front()]=card;
             q.pop();
             //move the next index to bottom if queue not empty
             if(!q.empty()){
                q.push(q.front());
                q.pop();
             }

        }
        return result;


    }
};