class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		if (nums1.size() > nums2.size()) {
			swap(nums1, nums2);
		}
		if (nums1.empty()) {
			int n = (int)nums2.size();
			return (nums2[n / 2] + nums2[(n - 1) / 2]) / 2.0;
		}
		int n1 = (int)nums1.size(), n2 = (int)nums2.size();
		int l = 0, r = n1 + 1, pos = (n1 + n2) / 2;
		while (l < r - 1) {
			int m = (l + r - 1) / 2, m2 = pos - m;
			if (nums1[m] < nums2[m2 - 1]) {
				l = m + 1;
			} else {
				r = m + 1;
			}
		}
		int res1 = l, res2 = pos - res1, left = 0, right = 0;
		if (res1 == 0) {
			left = nums2[res2 - 1];
		} else if (res2 == 0) {
			left = nums1[res1 - 1];
		} else {
			left = max(nums1[res1 - 1], nums2[res2 - 1]);
		}
		if (res1 == n1) {
			right = nums2[res2];
		} else if (res2 == n2) {
			right = nums1[res1];
		} else {
			right = min(nums1[res1], nums2[res2]);
		}
		return (n1 + n2) % 2 == 1 ? right : (left + right) / 2.0;
	}
};
