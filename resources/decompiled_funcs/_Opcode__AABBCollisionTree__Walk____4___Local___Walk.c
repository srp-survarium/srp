void __cdecl Opcode::AABBCollisionTree::Walk_::_4_::Local::_Walk(
        const Opcode::AABBCollisionNode *current_node,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  const Opcode::AABBCollisionNode *i; // esi
  const Opcode::AABBCollisionNode *mData; // eax

  for ( i = current_node; i; i = (const Opcode::AABBCollisionNode *)(i->mData + 28) )
  {
    if ( !callback(i, user_data) )
      break;
    mData = (const Opcode::AABBCollisionNode *)i->mData;
    if ( ((unsigned __int8)mData & 1) != 0 )
      break;
    Opcode::AABBCollisionTree::Walk_::_4_::Local::_Walk(mData, callback, user_data);
  }
}
