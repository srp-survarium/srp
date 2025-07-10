char *__thiscall pDNameNode::getString(pDNameNode *this, char *buf, char *end)
{
  DName *me; // ecx

  me = this->me;
  if ( me )
    return DName::getString(me, buf, end);
  else
    return buf;
}
