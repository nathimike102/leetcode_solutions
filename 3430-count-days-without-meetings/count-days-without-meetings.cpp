class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;
        sort(meetings.begin(),meetings.end());
        vector<pair<int, int>> mergedMeetings;
        int start = meetings[0][0];
        int end = meetings[0][1];
        for (int i = 1; i < meetings.size(); ++i) {
            if (meetings[i][0] <= end + 1) {
                end = max(end, meetings[i][1]);
            } else {
                mergedMeetings.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        mergedMeetings.push_back({start, end});
        int count=0;
        if (mergedMeetings[0].first > 1) {
            count += mergedMeetings[0].first - 1;
        }
        for (int i = 1; i < mergedMeetings.size(); ++i) {
            count += mergedMeetings[i].first - mergedMeetings[i - 1].second - 1;
        }
        if (mergedMeetings.back().second < days) {
            count += days - mergedMeetings.back().second;
        }
        return count;
    }
};