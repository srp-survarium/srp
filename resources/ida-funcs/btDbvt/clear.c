void __usercall btDbvt::clear(btDbvt *this@<ecx>, btDbvt *a2@<esi>)
{
  btDbvtNode *m_free; // eax
  btDbvt::sStkNN *m_data; // eax

  if ( a2->m_root )
    recursedeletenode(a2, a2->m_root);
  m_free = a2->m_free;
  if ( m_free )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_free);
  }
  a2->m_free = 0;
  a2->m_lkhd = -1;
  m_data = a2->m_stkStack.m_data;
  if ( m_data )
  {
    if ( a2->m_stkStack.m_ownsMemory )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(m_data);
    }
    a2->m_stkStack.m_data = 0;
  }
  a2->m_stkStack.m_data = 0;
  a2->m_stkStack.m_size = 0;
  a2->m_stkStack.m_capacity = 0;
  a2->m_stkStack.m_ownsMemory = 1;
  a2->m_opath = 0;
}
