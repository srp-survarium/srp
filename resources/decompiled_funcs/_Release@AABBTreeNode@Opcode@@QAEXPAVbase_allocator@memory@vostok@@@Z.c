void __usercall Opcode::AABBTreeNode::Release(Opcode::AABBTreeNode *this@<ecx>, _DWORD *a2@<esi>)
{
  unsigned int v2; // eax

  v2 = a2[6] & 0xFFFFFFFE;
  if ( (a2[6] & 1) == 0 && v2 )
    (*(void (__thiscall **)(Opcode::AABBTreeNode *, unsigned int))(LODWORD(this->mBV.mCenter.x) + 24))(this, v2 - 8);
  a2[7] = 0;
  a2[8] = 0;
}
