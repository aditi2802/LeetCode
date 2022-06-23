class Solution {
public:
    static bool compare(vector<int> &v1, vector<int> &v2){
        return (v1[1]<v2[1]);
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
       sort(courses.begin(),courses.end(), compare); 
        int totalDuration = 0;
        priority_queue<int> q;
        
        for(int i=0;i<courses.size();i++){
            int currentDuration = courses[i][0];
            int finishTime = courses[i][1];
            
            totalDuration += currentDuration;
            q.push(currentDuration);
            
            if(totalDuration>finishTime){
                totalDuration -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};