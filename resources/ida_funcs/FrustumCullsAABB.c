char __cdecl FrustumCullsAABB(
        const struct SpeedTree::Vec4 *const a1,
        const struct SpeedTree::Vec3 *a2,
        const struct SpeedTree::CExtents *a3)
{
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    if ( (a2->x + a3->m_cMin.x) * a1[i].x
       + (a2->y + a3->m_cMin.y) * a1[i].y
       + (a2->z + a3->m_cMin.z) * a1[i].z
       + a1[i].w <= 0.0
      && (a2->x + a3->m_cMax.x) * a1[i].x
       + (a2->y + a3->m_cMin.y) * a1[i].y
       + (a2->z + a3->m_cMin.z) * a1[i].z
       + a1[i].w <= 0.0
      && (a2->x + a3->m_cMin.x) * a1[i].x
       + (a2->y + a3->m_cMax.y) * a1[i].y
       + (a2->z + a3->m_cMin.z) * a1[i].z
       + a1[i].w <= 0.0
      && (a2->x + a3->m_cMax.x) * a1[i].x
       + (a2->y + a3->m_cMax.y) * a1[i].y
       + (a2->z + a3->m_cMin.z) * a1[i].z
       + a1[i].w <= 0.0
      && (a2->x + a3->m_cMin.x) * a1[i].x
       + (a2->y + a3->m_cMin.y) * a1[i].y
       + (a2->z + a3->m_cMax.z) * a1[i].z
       + a1[i].w <= 0.0
      && (a2->x + a3->m_cMax.x) * a1[i].x
       + (a2->y + a3->m_cMin.y) * a1[i].y
       + (a2->z + a3->m_cMax.z) * a1[i].z
       + a1[i].w <= 0.0
      && (a2->x + a3->m_cMin.x) * a1[i].x
       + (a2->y + a3->m_cMax.y) * a1[i].y
       + (a2->z + a3->m_cMax.z) * a1[i].z
       + a1[i].w <= 0.0
      && (a2->x + a3->m_cMax.x) * a1[i].x
       + (a2->y + a3->m_cMax.y) * a1[i].y
       + (a2->z + a3->m_cMax.z) * a1[i].z
       + a1[i].w <= 0.0 )
    {
      return 1;
    }
  }
  return 0;
}
