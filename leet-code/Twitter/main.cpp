#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;
class Twitter {
private:
	struct Node{
		set<int> followee;
		list<int> tweets;
	};
	static const int maximum = 10;
	int time;
	map<int, Node> users;
	map<int, int> tweet_time;
public:
    /** Initialize your data structure here. */
    Twitter() {
		time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		users[userId].tweets.push_front(tweetId);
		tweet_time[tweetId] = time;
		if(users[userId].tweets.size() > maximum)
			users[userId].tweets.pop_back();
		time++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		list<int> ans = users[userId].tweets;
		for (const auto &item : users[userId].followee) {
			auto tweet1 = ans.begin();
			auto tweet2 = users[item].tweets.begin();
			if(item == userId)
				continue;
			for (int i = 0; i < maximum && (tweet1!=ans.end() || tweet2!= users[item].tweets.end()); ++i) {
				if(tweet1==ans.end()) {
					ans.push_back(*tweet2);
					tweet2++;
				} else if (tweet2 == users[item].tweets.end());
				else if(tweet_time[*tweet1] < tweet_time[*tweet2]) {
					ans.insert(tweet1, *tweet2);
					if(ans.size() > maximum)
						ans.pop_back();
					tweet2++;
				} else
					tweet1++;
			}
		}
		vector<int> feed;
		for (const auto &an : ans) {
			feed.push_back(an);
		}
		return feed;
	}

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		users[followerId].followee.insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		users[followerId].followee.erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
void print(const vector<int> f){
	for (const auto &item : f) {
		cout << item << ' ';
	}
	cout << endl;
}
int main() {
	Twitter* twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
	twitter->postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
	print(twitter->getNewsFeed(1));

// 用户1关注了用户2.
	twitter->follow(2, 1);

// 用户2发送了一个新推文 (推文id = 6).
//	twitter->postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
	print(twitter->getNewsFeed(2));

// 用户1取消关注了用户2.
	twitter->unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
	print(twitter->getNewsFeed(1));
	return 0;
}
