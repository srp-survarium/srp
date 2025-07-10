void __usercall deletenode(btDbvt *pdbvt@<esi>, btDbvtNode *node@<edi>)
{
  btDbvtNode *m_free; // eax

  m_free = pdbvt->m_free;
  if ( m_free )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_free);
  }
  pdbvt->m_free = node;
}
