char __thiscall Opcode::AABBQuantizedNoLeafTree::Walk(
        Opcode::AABBQuantizedNoLeafTree *this,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  if ( !callback )
    return 0;
  Opcode::AABBQuantizedNoLeafTree::Walk_::_4_::Local::_Walk(this->mNodes, callback, user_data);
  return 1;
}
