#ifndef _RBT_
#define _RBT_

template<typename TKey, typename TData, typename TLessComp>
class RedBlackTree {
	private:
		enum class Color : bool {
			BLACK = true,
			RED = false	
		};

		struct TreeNode {
			Color color;
			TKey key;
			TData data;
			TreeNode * right;
			TreeNode * left;
			TreeNode * parent;
		};	

		/* As every leaf node is a black node, with all
		 * other attributes undefined, a unique sentinel can be
		 * used to represent that.
		 * */
		TreeNode nil {Color::BLACK};

		TreeNode * root;

		void left_rotate(TreeNode * node);
		void right_rotate(TreeNode * node);
};

#include "../src/rbt.cpp"
#endif
