

how to do the isempty thing

bool ElephantList::ISEmpty() const
{
	if (head->next == 0)
		return true;
	else
		return false;

}



how to do a destructor:

elephantList:~ElephantList()
{
	elepant *back, *current;
	back = head;
	current = head->next;
	

}