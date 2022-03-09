// Approach 1: Generating all Permuations
class Solution {
public:
    void permute(int index,string sequence, vector<string> &result,int n){
        if(index==n-1){
            result.push_back(sequence);
            return;
        };
        for(int i=index;i<n;i++){
            swap(sequence[i],sequence[index]);
            permute(index+1,sequence,result,n);
            swap(sequence[i],sequence[index]);
        }
    }
    string getPermutation(int n, int k) {
        vector<string> result;
        string sequence;
        for(int i=1;i<=n;i++)
            sequence+=to_string(i);
        
        permute(0,sequence,result,n);
        sort(result.begin(),result.end());
        return result[k-1];
    }
};

// Approach 2: Generating all Permuations
class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        string sequence;
        int fact=1;
        for(int i=1;i<=n;i++){
            sequence+=to_string(i);
            fact*=i;
        }
        k=k-1;
        fact=fact/n;
        while(true){
            result+=sequence[k/fact];
            sequence.erase(sequence.begin()+(k/fact));
            if(sequence.length()==0) break;
            k=k%fact;
            fact=fact/sequence.length();
        }
        return result;
    }
};