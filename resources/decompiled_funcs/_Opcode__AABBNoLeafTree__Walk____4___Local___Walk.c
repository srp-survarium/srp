void __cdecl Opcode::AABBNoLeafTree::Walk_::_4_::Local::_Walk(
        const Opcode::AABBNoLeafNode *current_node,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  const Opcode::AABBNoLeafNode *v3; // esi
  const Opcode::AABBNoLeafNode *mPosData; // eax
  unsigned int mNegData; // eax

  v3 = current_node;
  if ( current_node )
  {
    do
    {
      if ( !callback(v3, user_data) )
        break;
      mPosData = (const Opcode::AABBNoLeafNode *)v3->mPosData;
      if ( ((unsigned __int8)mPosData & 1) == 0 )
        Opcode::AABBNoLeafTree::Walk_::_4_::Local::_Walk(mPosData, callback, user_data);
      mNegData = v3->mNegData;
      if ( (mNegData & 1) != 0 )
        break;
      v3 = (const Opcode::AABBNoLeafNode *)v3->mNegData;
    }
    while ( mNegData );
  }
}
