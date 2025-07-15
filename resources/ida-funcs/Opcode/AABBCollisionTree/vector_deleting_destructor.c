Opcode::AABBCollisionTree *__thiscall Opcode::AABBCollisionTree::`vector deleting destructor'(
        Opcode::AABBCollisionTree *this,
        char a2)
{
  Opcode::AABBCollisionTree::~AABBCollisionTree(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
