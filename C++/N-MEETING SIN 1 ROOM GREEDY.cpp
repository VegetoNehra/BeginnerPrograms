#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Meeting {
public:
    int start;
    int end;
    int pos;  // 0-based position index

    Meeting(int s, int e, int p) : start(s), end(e), pos(p) {}
};

// Comparator to sort meetings based on end times
bool meetingComparator(Meeting m1, Meeting m2) {
    if (m1.end == m2.end) {
        return m1.pos < m2.pos;  // If end times are the same, sort by position
    }
    return m1.end < m2.end;  // Sort by end time
}

vector<int> maxMeetings(vector<int>& start, vector<int>& end, int N) {
    // Create a list of meetings
    vector<Meeting> meetings;
    for (int i = 0; i < N; i++) {
        meetings.push_back(Meeting(start[i], end[i], i));  // 0-based index
    }

    // Sort the meetings based on end times
    sort(meetings.begin(), meetings.end(), meetingComparator);

    // Select meetings using the greedy approach
    vector<int> selectedMeetings;
    selectedMeetings.push_back(meetings[0].pos);
    int lastEndTime = meetings[0].end;

    for (int i = 1; i < N; i++) {
        if (meetings[i].start > lastEndTime) {
            selectedMeetings.push_back(meetings[i].pos);
            lastEndTime = meetings[i].end;
        }
    }

    // Return the order of meetings executed
    return selectedMeetings;
}

int main() {
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    vector<int> result = maxMeetings(start, end, N);

    cout << "Max number of meetings: " << result.size() << endl;
    cout << "Meetings order (0-based): ";
    for (int pos : result) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}
