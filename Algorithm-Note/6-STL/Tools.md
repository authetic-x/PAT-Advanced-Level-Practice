#	Foundamental data-structure tools and functions
<br>

##	vector<typename> vi

*	vi.push_back()
*	vi.pop_back()
*	vi.size()
*	vi.clear()
*	vi.insert()
	vi.insert(vi.begin()+2, -1)
*	vi.erase()
	vi.erase(vi.begin()+1, vi.begin()+4)


##	set<typename> s

*	s.insert()
*	s.find()
*	s.erase()
*	s.size()
*	s.clear()

##	map<typename, typename> mp

*	map.find()
*	map.erase()
*	map.size()

##	queue<typename> q

*	q.push()
*	q.front()
*	q.back()
*	q.pop()
*	q.empty()
*	q.size()

##	stack<typename> s

*	s.push()
*	s.top()
*	s.pop()
*	s.empty()
*	s.size()

##	iterator

	vector<int>::iterator it = vi.begin();    //返回首地址
	for (; it!=vi.end(); it++) {
		printf("%d\n", *it);
	}
	map<int, char>::iterator it;
	for (it=mp.begin(); it!=map.end(); it++) {
		printf("%d %c\n", it->first, it->second);
	}
