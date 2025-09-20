using int3=array<int,3>; //(timestamp, source, destination)
const int N=100000;
int3 q[N];
int front=0, back=0; 
class Router {
public:
    // destination -> (front index, timestamps) as queue           
    unordered_map<int, pair<int,vector<int>>> byDest; 
    unordered_set<long long> seen; // pack(source,dest)
    size_t memoryLimit;

    Router(size_t memoryLimit): memoryLimit(memoryLimit) {
        front=back=0;
    }

    // pack source & destination into long long
    long long pack(int x, int y) { return ((long long)x<<32)|y; }

    bool addPacket(int source, int destination, int timestamp) {
        if (front<back && timestamp==q[back-1][0]) {
            long long key=pack(source, destination);
            if (seen.count(key)) return 0; // duplicate 
        } 
        else 
            seen.clear(); // new timestamp batch, reset seen

        // If memory limit reached, remove oldest packet
        if (back-front==memoryLimit) {
            auto old=q[front++]; 

            auto& [head, qq]=byDest[old[2]];
            if (head+1<=qq.size()) head++;

            if (old[0]==timestamp)//same timestamp with oldest packet
                seen.erase(pack(old[1], old[2]));
        }

        // Add new packet
        q[back++]={timestamp, source, destination};
        if (!byDest.count(destination))
            byDest[destination].first=0;
        byDest[destination].second.push_back(timestamp);
        seen.insert(pack(source, destination));
        return 1;
    }

    vector<int> forwardPacket() {
        if (front==back) return {};
        auto x=q[front++]; 

        auto& [head, qq]=byDest[x[2]];
        if (head+1<=qq.size()) head++;

        if (q[back-1][0]==x[0])// front & back have the same timestamp
            seen.erase(pack(x[1], x[2]));

        return {x[1], x[2], x[0]};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& [head, qq]=byDest[destination];
        // timestamps are sorted, use binary search
        auto itL=lower_bound(qq.begin()+head, qq.end(), startTime);
        auto itR=upper_bound(qq.begin()+head, qq.end(), endTime);
        return itR-itL;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */