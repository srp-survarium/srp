void __cdecl ComputeFrustumAABB(const struct SpeedTree::Vec3 *const a1, SpeedTree::CExtents *a2)
{
  int i; // [esp+4h] [ebp-4h]

  a2->m_cMin.x = 3.4028235e38;
  a2->m_cMin.y = 3.4028235e38;
  a2->m_cMin.z = 3.4028235e38;
  a2->m_cMax.x = -3.4028235e38;
  a2->m_cMax.y = -3.4028235e38;
  a2->m_cMax.z = -3.4028235e38;
  for ( i = 0; i < 8; ++i )
    SpeedTree::CExtents::ExpandAround(a2, &a1[i]);
}
