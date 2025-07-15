char __thiscall DNameStatusNode::getLastChar(DNameStatusNode *this)
{
  return this->me != DN_truncated ? 0 : 0x20;
}
