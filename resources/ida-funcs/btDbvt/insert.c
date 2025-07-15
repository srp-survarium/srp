btDbvtNode *__thiscall btDbvt::insert(btDbvt *this, btDbvt *volume, void *data, int a4)
{
  btDbvtNode *m_free; // eax
  btDbvtNode *v7; // [esp+14h] [ebp+8h]

  m_free = volume->m_free;
  if ( m_free )
    volume->m_free = 0;
  else
    m_free = (btDbvtNode *)btAlignedAllocInternal(0x30u);
  m_free->dataAsInt = a4;
  m_free->parent = 0;
  m_free->childs[1] = 0;
  v7 = m_free;
  qmemcpy(m_free, data, 0x20u);
  insertleaf(volume->m_root, volume, m_free);
  ++volume->m_leaves;
  return v7;
}
