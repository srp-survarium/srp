pDNameNode *__thiscall pDNameNode::pDNameNode(pDNameNode *this, DName *pName)
{
  pDNameNode *result; // eax
  DName *v3; // ecx
  char v4; // dl

  result = this;
  v3 = pName;
  result->__vftable = (pDNameNode_vtbl *)&pDNameNode::`vftable';
  if ( pName )
  {
    v4 = *((_BYTE *)pName + 4);
    if ( v4 == 2 || v4 == 3 )
      v3 = 0;
  }
  result->me = v3;
  return result;
}
