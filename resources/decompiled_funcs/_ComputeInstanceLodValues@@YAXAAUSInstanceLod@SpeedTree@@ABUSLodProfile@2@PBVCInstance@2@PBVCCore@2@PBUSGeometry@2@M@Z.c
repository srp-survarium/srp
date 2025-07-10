void __cdecl ComputeInstanceLodValues(
        struct SpeedTree::SInstanceLod *a1,
        const struct SpeedTree::SLodProfile *a2,
        const struct SpeedTree::CInstance *a3,
        SpeedTree::CCore *a4,
        const struct SpeedTree::SGeometry *a5,
        float a6)
{
  float v6; // [esp+8h] [ebp-48h]

  a1->m_pInstance = a3;
  a1->m_fDistanceFromCameraSquared = a6;
  if ( a2->m_bLodIsPresent )
    v6 = SpeedTree::CCore::ComputeLodByDistanceSquared(a4, a1->m_fDistanceFromCameraSquared);
  else
    v6 = 1.0;
  a1->m_fLod = v6;
  SpeedTree::CCore::ComputeLodSnapshot(a4, a1->m_fLod, &a1->m_sLodSnapshot);
  a1->m_afShaderLerps[0] = SpeedTree::CCore::ComputeShaderLerp(a1->m_fLod, a5->m_nNumBranchLods);
  a1->m_afShaderLerps[1] = SpeedTree::CCore::ComputeShaderLerp(a1->m_fLod, a5->m_nNumFrondLods);
  a1->m_afShaderLerps[2] = SpeedTree::CCore::ComputeShaderLerp(a1->m_fLod, a5->m_nNumLeafCardLods);
  a1->m_afShaderLerps[3] = SpeedTree::CCore::ComputeShaderLerp(a1->m_fLod, a5->m_nNumLeafMeshLods);
}
