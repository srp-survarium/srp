btDbvtNode *__cdecl createnode(btDbvtNode *parent, void *data)
{
  btDbvt *pdbvt; // ecx
  btDbvtNode *result; // eax

  result = pdbvt->m_free;
  if ( result )
  {
    pdbvt->m_free = 0;
  }
  else
  {
    ++gNumAlignedAllocs;
    result = (btDbvtNode *)sAlignedAllocFunc(0x30u, 16);
  }
  result->parent = parent;
  result->dataAsInt = (int)data;
  result->childs[1] = 0;
  return result;
}
