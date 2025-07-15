void __cdecl Opcode::AABBQuantizedTree::Walk_::_4_::Local::_Walk(
        const Opcode::AABBQuantizedNode *current_node,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  const Opcode::AABBQuantizedNode *i; // esi
  const Opcode::AABBQuantizedNode *mData; // eax

  for ( i = current_node; i; i = (const Opcode::AABBQuantizedNode *)(i->mData + 16) )
  {
    if ( !callback(i, user_data) )
      break;
    mData = (const Opcode::AABBQuantizedNode *)i->mData;
    if ( ((unsigned __int8)mData & 1) != 0 )
      break;
    Opcode::AABBQuantizedTree::Walk_::_4_::Local::_Walk(mData, callback, user_data);
  }
}
