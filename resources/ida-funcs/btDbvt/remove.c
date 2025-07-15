void __usercall btDbvt::remove(btDbvt *this@<esi>, btDbvtNode *leaf@<edi>)
{
  btDbvt *v2; // [esp+0h] [ebp-4h]

  removeleaf(leaf, v2);
  btAlignedFreeInternal(this->m_free);
  --this->m_leaves;
  this->m_free = leaf;
}
