btDbvtNode *__usercall createnode_1@<eax>(btDbvt *pdbvt@<ecx>, const btDbvtAabbMm *volume@<esi>, btDbvtNode *parent)
{
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
  result->parent = 0;
  result->dataAsInt = (int)parent;
  result->childs[1] = 0;
  result->volume = *volume;
  return result;
}
