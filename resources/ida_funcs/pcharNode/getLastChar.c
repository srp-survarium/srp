char __thiscall pcharNode::getLastChar(pcharNode *this)
{
  int myLen; // eax

  myLen = this->myLen;
  if ( myLen )
    return this->me[myLen - 1];
  else
    return 0;
}
