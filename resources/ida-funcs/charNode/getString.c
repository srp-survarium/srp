char *__thiscall charNode::getString(charNode *this, char *buf, char *end)
{
  char *result; // eax

  result = buf;
  if ( buf < end )
  {
    *buf = this->me;
    return buf + 1;
  }
  return result;
}
