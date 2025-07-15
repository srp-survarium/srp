void __cdecl btSoftBodyHelpers::DrawFaceTree(btSoftBody *psb, btIDebugDraw *idraw)
{
  btDbvtNode *m_root; // [esp-18h] [ebp-38h]
  btVector3 lcolor; // [esp+0h] [ebp-20h] BYREF
  btVector3 ncolor; // [esp+10h] [ebp-10h] BYREF

  m_root = psb->m_fdbvt.m_root;
  lcolor.mVec128.m128_u64[0] = LODWORD(s_bm_current_air_resistance);
  lcolor.mVec128.m128_u64[1] = 0;
  ncolor.mVec128.m128_i32[0] = 0;
  *(unsigned __int64 *)((char *)ncolor.mVec128.m128_u64 + 4) = LODWORD(s_bm_current_air_resistance);
  ncolor.mVec128.m128_i32[3] = 0;
  drawTree(idraw, m_root, 0, &ncolor, &lcolor, 0, -1);
}
