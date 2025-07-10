char __thiscall Opcode::AABBQuantizedTree::Walk(
        Opcode::AABBQuantizedTree *this,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  if ( !callback )
    return 0;
  Opcode::AABBQuantizedTree::Walk_::_4_::Local::_Walk(this->mNodes, callback, user_data);
  return 1;
}
