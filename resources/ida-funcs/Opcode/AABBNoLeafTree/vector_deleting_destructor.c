Opcode::AABBNoLeafTree *__thiscall Opcode::AABBNoLeafTree::`vector deleting destructor'(
        Opcode::AABBNoLeafTree *this,
        char a2)
{
  Opcode::AABBNoLeafTree::~AABBNoLeafTree(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
