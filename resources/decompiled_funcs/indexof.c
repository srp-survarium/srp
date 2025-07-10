BOOL __usercall indexof@<eax>(const btDbvtNode *node@<eax>)
{
  return node->parent->childs[1] == node;
}
