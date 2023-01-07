class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int total_cost=0;
        int curr_gas=0;
        int start_point=0;
        for(int i=0;i<gas.size();i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0){
                start_point=(i+1)%gas.size();
                curr_gas=0;
            }
            
        }
        if(total_gas>=total_cost){
            return start_point;
        }
        else{
            return -1;
        }
    }
};