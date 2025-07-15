void __usercall btDbvt::clear(btDbvt *this@<ecx>, btDbvt *a2@<esi>)
{
  if ( a2->m_root )
    recursedeletenode(a2, a2->m_root);
  btAlignedFreeInternal(a2->m_free);
  a2->m_lkhd = -1;
  a2->m_free = 0;
  if ( a2->m_stkStack.m_data )
  {
    if ( a2->m_stkStack.m_ownsMemory )
      btAlignedFreeInternal(a2->m_stkStack.m_data);
    a2->m_stkStack.m_data = 0;
  }
  a2->m_stkStack.m_data = 0;
  a2->m_stkStack.m_size = 0;
  a2->m_stkStack.m_capacity = 0;
  a2->m_stkStack.m_ownsMemory = 1;
  a2->m_opath = 0;
}
