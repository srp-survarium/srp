void __cdecl Opcode::AABBQuantizedNoLeafTree::Walk_::_4_::Local::_Walk(
        const Opcode::AABBQuantizedNoLeafNode *current_node,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  const Opcode::AABBQuantizedNoLeafNode *v3; // esi
  const Opcode::AABBQuantizedNoLeafNode *mPosData; // eax
  unsigned int mNegData; // eax

  v3 = current_node;
  if ( current_node )
  {
    do
    {
      if ( !callback(v3, user_data) )
        break;
      mPosData = (const Opcode::AABBQuantizedNoLeafNode *)v3->mPosData;
      if ( ((unsigned __int8)mPosData & 1) == 0 )
        Opcode::AABBQuantizedNoLeafTree::Walk_::_4_::Local::_Walk(mPosData, callback, user_data);
      mNegData = v3->mNegData;
      if ( (mNegData & 1) != 0 )
        break;
      v3 = (const Opcode::AABBQuantizedNoLeafNode *)v3->mNegData;
    }
    while ( mNegData );
  }
}
