void __cdecl recursedeletenode(btDbvt *pdbvt, btDbvtNode *node)
{
  if ( node->childs[1] )
  {
    recursedeletenode(pdbvt, node->childs[0]);
    recursedeletenode(pdbvt, node->childs[1]);
  }
  if ( node == pdbvt->m_root )
    pdbvt->m_root = 0;
  btAlignedFreeInternal(pdbvt->m_free);
  pdbvt->m_free = node;
}
