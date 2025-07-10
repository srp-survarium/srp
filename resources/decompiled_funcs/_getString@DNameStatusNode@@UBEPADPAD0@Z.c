char *__thiscall DNameStatusNode::getString(DNameStatusNode *this, char *buf, char *end)
{
  if ( this->me == DN_truncated )
    return getStringHelper(buf, end, " ?? ", 4);
  else
    return buf;
}
