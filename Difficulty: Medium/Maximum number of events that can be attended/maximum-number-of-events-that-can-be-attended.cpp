class Solution {
  public:
    int maxEvents(int start[], int end[], int N) {
        vector<pair<int, int>> events;
        for (int i = 0; i < N; ++i) {
            events.push_back({start[i], end[i]});
        }

        // Sort by start time
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap by end time

        int day = 1, i = 0, res = 0;
        while (i < N || !minHeap.empty()) {
            // Add all events starting today
            while (i < N && events[i].first == day) {
                minHeap.push(events[i].second);
                i++;
            }

            // Remove all events that already ended
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                res++;
            }

            day++;
        }

        return res;
    }
};
