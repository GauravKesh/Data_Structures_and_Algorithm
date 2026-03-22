//
// Created by Gaurav Kesh Roushan on 22/03/26.
//
class Solution {
public:
	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		if (mat == target)
			return true;
		int max = 3;
		for (int i = 0; i < 4; i++) {
			if (mat == target)
				return true;
			rotate90(mat);
		}
		return false;
	}
private:
	void rotate90(vector<vector<int>>& mat) {
		int n = mat.size();

		// Transpose
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				swap(mat[i][j], mat[j][i]);
			}
		}

		// Reverse each row
		for (int i = 0; i < n; i++) {
			reverse(mat[i].begin(), mat[i].end());
		}
	}
};