void __cdecl Opcode::AABBNoLeafTree::Walk_::_4_::Local::_Walk(
        const Opcode::AABBNoLeafNode *current_node,
        bool (__cdecl *callback)(const void *, void *),
        void *user_data)
{
  unsigned int mPosData; // eax

  while ( current_node && callback(current_node, user_data) )
  {
    mPosData = current_node->mPosData;
    if ( (mPosData & 1) == 0 )
      Opcode::AABBNoLeafTree::Walk_::_4_::Local::_Walk((const Opcode::AABBNoLeafNode *)mPosData, callback, user_data);
    if ( (current_node->mNegData & 1) != 0 )
      break;
    current_node = (const Opcode::AABBNoLeafNode *)current_node->mNegData;
  }
}
