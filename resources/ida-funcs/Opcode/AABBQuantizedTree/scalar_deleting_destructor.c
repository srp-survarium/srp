Opcode::AABBQuantizedTree *__thiscall Opcode::AABBQuantizedTree::`scalar deleting destructor'(
        Opcode::AABBQuantizedTree *this,
        char a2)
{
  Opcode::AABBQuantizedTree::~AABBQuantizedTree(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
