void __userpurge btDbvt::update(btDbvtNode *leaf@<edi>, btDbvt *this, btDbvtAabbMm *volume)
{
  btDbvtNode *m_root; // eax
  int m_lkhd; // esi
  int i; // edx

  m_root = removeleaf(leaf, this);
  if ( m_root )
  {
    m_lkhd = this->m_lkhd;
    if ( m_lkhd < 0 )
    {
      m_root = this->m_root;
    }
    else
    {
      for ( i = 0; i < m_lkhd; m_root = m_root->parent )
      {
        if ( !m_root->parent )
          break;
        ++i;
      }
    }
  }
  leaf->volume = *volume;
  insertleaf(m_root, this, leaf);
}
