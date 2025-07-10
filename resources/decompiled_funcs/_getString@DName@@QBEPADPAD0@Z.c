char *__thiscall DName::getString(DName *this, char *buf, char *end)
{
  DNameNode *node; // ecx

  node = this->node;
  if ( node )
    return node->getString(node, buf, end);
  else
    return buf;
}
