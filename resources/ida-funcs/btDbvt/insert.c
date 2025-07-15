btDbvtNode *__userpurge btDbvt::insert@<eax>(
        btDbvt *this@<ecx>,
        btDbvt *a2@<edi>,
        const btDbvtAabbMm *volume,
        void *data)
{
  btDbvtNode *m_free; // esi

  m_free = a2->m_free;
  if ( m_free )
  {
    a2->m_free = 0;
  }
  else
  {
    ++gNumAlignedAllocs;
    m_free = (btDbvtNode *)sAlignedAllocFunc(0x30u, 16);
  }
  m_free->parent = 0;
  m_free->dataAsInt = (int)data;
  m_free->childs[1] = 0;
  m_free->volume = *volume;
  insertleaf(a2->m_root, a2, m_free);
  ++a2->m_leaves;
  return m_free;
}
