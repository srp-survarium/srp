void __usercall btDbvt::remove(btDbvt *this@<esi>, btDbvtNode *leaf@<edi>)
{
  btDbvtNode *m_free; // eax
  btDbvt *v3; // [esp+0h] [ebp-4h]

  removeleaf(leaf, v3);
  m_free = this->m_free;
  if ( m_free )
  {
    ++gNumAlignedFree;
    sAlignedFreeFunc(m_free);
  }
  --this->m_leaves;
  this->m_free = leaf;
}
