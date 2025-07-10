unsigned int __thiscall Opcode::AABBNoLeafTree::GetUsedBytes(Opcode::AABBNoLeafTree *this)
{
  return 32 * this->mNbNodes;
}
