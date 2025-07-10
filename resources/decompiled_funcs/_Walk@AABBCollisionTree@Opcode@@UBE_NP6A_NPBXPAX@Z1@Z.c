char __thiscall Opcode::AABBCollisionTree::Walk(
        Opcode::AABBCollisionTree *this,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  if ( !callback )
    return 0;
  Opcode::AABBCollisionTree::Walk_::_4_::Local::_Walk(this->mNodes, callback, user_data);
  return 1;
}
