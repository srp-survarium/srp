char *__thiscall pcharNode::getString(pcharNode *this, char *buf, char *end)
{
  return getStringHelper(buf, end, this->me, this->myLen);
}
