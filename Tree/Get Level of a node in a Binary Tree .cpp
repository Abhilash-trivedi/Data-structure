int getLevel(struct Node *node, int target)
{
	queue<Node*>q;
	q.push(node);
	int count=0;
	while(!q.empty())
	{
	    int sz=q.size();
	    count++;
	    while(sz--)
	    {
	        if(q.front()->data==target)
	        {
	            return count;
	        }
	        if(q.front()->left)
	        {
	            q.push(q.front()->left);
	        }
	        if(q.front()->right)
	        {
	            q.push(q.front()->right);
	        }
	        q.pop();
	    }
	}
	return 0;
}
