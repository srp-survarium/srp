void __cdecl recursedeletenode(btDbvt *pdbvt, btDbvtNode *node)
{
  btDbvtNode *m_free; // eax

  if ( node->childs[1] )
  {
    recursedeletenode(pdbvt, node->childs[0]);
    recursedeletenode(pdbvt, node->childs[1]);
  }
  if ( node == pdbvt->m_root )
    pdbvt->m_root = 0;
  m_free = pdbvt->m_free;
  if ( m_free )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_free);
  }
  pdbvt->m_free = node;
}
