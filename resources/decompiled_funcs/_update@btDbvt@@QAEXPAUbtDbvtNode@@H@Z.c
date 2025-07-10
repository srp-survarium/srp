void __usercall btDbvt::update(btDbvt *this@<esi>, btDbvtNode *leaf@<edi>)
{
  btDbvtNode *m_root; // eax
  btDbvt *v3; // [esp+0h] [ebp-8h]

  m_root = removeleaf(leaf, v3);
  if ( m_root )
    m_root = this->m_root;
  insertleaf(m_root, this, leaf);
}
