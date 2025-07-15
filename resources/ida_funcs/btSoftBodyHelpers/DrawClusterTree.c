void __usercall btSoftBodyHelpers::DrawClusterTree(btSoftBody *psb@<edx>, btIDebugDraw *idraw)
{
  btDbvtNode *m_root; // [esp-18h] [ebp-38h]
  btVector3 lcolor; // [esp+0h] [ebp-20h] BYREF
  btVector3 ncolor; // [esp+10h] [ebp-10h] BYREF

  m_root = psb->m_cdbvt.m_root;
  lcolor.mVec128.m128_u64[0] = (unsigned int)clear_value;
  lcolor.mVec128.m128_u64[1] = 0;
  ncolor.mVec128.m128_i32[0] = 0;
  ncolor.mVec128.m128_i32[1] = (int)clear_value;
  ncolor.mVec128.m128_u64[1] = (unsigned int)clear_value;
  drawTree(idraw, m_root, 0, &ncolor, &lcolor, 0, -1);
}
