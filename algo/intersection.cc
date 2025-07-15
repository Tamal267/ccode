int ori(const pair<int, int> &o, const pair<int, int> &a, const pair<int, int> &b) {
	int ret = (a.first - o.first) * (b.second - o.second) -
		(a.second - o.second) * (b.first - o.first);
	return (ret > 0) - (ret < 0); // returns 1 for counter-clockwise, -1 for clockwise, 0 for collinear
}

bool isIntersect(const pair<int, int> &p1, const pair<int, int> &p2,
		const pair<int, int> &q1, const pair<int, int> &q2) {
	// Check if all points are collinear
	if (ori(p1, p2, q1) == 0 && ori(p1, p2, q2) == 0 &&
			ori(q1, q2, p1) == 0 && ori(q1, q2, p2) == 0) {

		// If not overlapping projections, then no intersection
		return (min(p1, p2) <= max(q1, q2) && max(p1, p2) >= min(q1, q2));
	}

	return (ori(p1, p2, q1) * ori(p1, p2, q2) <= 0) &&
		(ori(q1, q2, p1) * ori(q1, q2, p2) <= 0);
}

