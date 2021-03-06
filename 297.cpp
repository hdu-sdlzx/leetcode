class Codec
{
	TreeNode* _deserialize(const char* data, int& p)
	{
		if (data[p] == '.') {
			p += 2;
			return nullptr;
		}
		TreeNode* res = new TreeNode(0);
		int n = 0;
		sscanf(data + p, "%d%n", &res->val, &n);
		p += n + 1;
		res->left = _deserialize(data, p);
		res->right = _deserialize(data, p);
		return res;
	}
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		if (root == nullptr) {
			return ". ";
		}
		return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		int pos = 0;
		return _deserialize(data.c_str(), pos);
	}
};
