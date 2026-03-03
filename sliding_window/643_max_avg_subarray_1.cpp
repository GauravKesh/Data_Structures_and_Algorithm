//
// Created by Gaurav Kesh Roushan on 03/03/26.
//
class Solution {
public:
	double findMaxAverage(vector<int>& a, int k) {
		long long wsm = 0;
		int n = a.size();
		for (int i = 0; i < k; i++) {
			wsm += a[i];
		}
		long long wms = wsm;

		for (int i = k; i < n  ; i++) {
			wsm += a[i] - a[i - k];
			wms = max(wms, wsm);
		}
		return (double)wms / k;
	}
};