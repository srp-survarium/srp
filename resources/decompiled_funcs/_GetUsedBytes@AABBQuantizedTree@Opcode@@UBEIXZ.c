unsigned int __thiscall Opcode::AABBQuantizedTree::GetUsedBytes(Opcode::AABBQuantizedTree *this)
{
  return 16 * this->mNbNodes;
}
