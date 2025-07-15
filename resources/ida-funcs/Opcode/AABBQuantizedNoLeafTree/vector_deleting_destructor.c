Opcode::AABBQuantizedNoLeafTree *__thiscall Opcode::AABBQuantizedNoLeafTree::`vector deleting destructor'(
        Opcode::AABBQuantizedNoLeafTree *this,
        char a2)
{
  Opcode::AABBQuantizedNoLeafTree::~AABBQuantizedNoLeafTree(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
