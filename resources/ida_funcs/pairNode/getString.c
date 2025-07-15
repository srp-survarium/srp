char *__thiscall pairNode::getString(pairNode *this, char *buf, char *end)
{
  char *result; // eax

  result = this->left->getString(this->left, buf, end);
  if ( result < end )
    return this->right->getString(this->right, result, end);
  return result;
}
