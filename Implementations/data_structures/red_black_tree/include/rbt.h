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

			TreeNode (Color _color) : color {_color} {}
			TreeNode (TKey _key, TData _data, Color _color)
				: key {_key}, data {_data}, key {_key},
		       		  right {nil}, left {nil}, parent {nil} {};
		};	

		/* As every leaf node is a black node, with all
		 * other attributes undefined, a unique sentinel can be
		 * used to represent that.
		 * */
		TreeNode * nil = new TreeNode {Color::BLACK};

		TreeNode * root;
		
		/**
		 * \brief Takes a node and substitutes it by its right child.
		 * \param node The node.
		 * */
		void left_rotate(TreeNode * node);
		
		/**
		 * \brief Takes a node and substitutes it by its left child.
		 * \param node The node.
		 * */
		void right_rotate(TreeNode * node);


		/**
		 * \brief Fix up the tree after one insertion.
		 * \param A node recently inserted.
		 * */
		void fix_up(TreeNode * node);

	public:
		/**
		 * \brief Constructor.
		 * */
		RedBlackTree() : root {nullptr} {};
		
		/**
		 * \brief Performs an insertion of a new node in the tree.
		 * \param newKey Key of the new node.
		 * \param newData Represents the data inside the node.
		 * */
		TData * insert(const TKey & newKey, TData newData);

};

#include "../src/rbt.cpp"
#endif
