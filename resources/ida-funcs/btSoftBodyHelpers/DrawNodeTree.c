void __cdecl btSoftBodyHelpers::DrawNodeTree(btSoftBody *psb, btIDebugDraw *idraw)
{
  btDbvtNode *m_root; // [esp-18h] [ebp-38h]
  btVector3 lcolor; // [esp+0h] [ebp-20h] BYREF
  btVector3 ncolor; // [esp+10h] [ebp-10h] BYREF

  m_root = psb->m_ndbvt.m_root;
  lcolor.mVec128.m128_f32[0] = s_bm_current_air_resistance;
  lcolor.mVec128.m128_f32[1] = s_bm_current_air_resistance;
  lcolor.mVec128.m128_u64[1] = LODWORD(s_bm_current_air_resistance);
  ncolor.mVec128.m128_u64[0] = LODWORD(s_bm_current_air_resistance);
  ncolor.mVec128.m128_u64[1] = LODWORD(s_bm_current_air_resistance);
  drawTree(idraw, m_root, 0, &ncolor, &lcolor, 0, -1);
}
