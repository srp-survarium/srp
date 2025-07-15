char __cdecl FrustumCullsSphere(const struct SpeedTree::Vec4 *const a1, const struct SpeedTree::Vec3 *a2, float a3)
{
  float v4; // [esp+0h] [ebp-8h]
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    v4 = a1[i].x * a2->x + a1[i].y * a2->y + a1[i].z * a2->z + a1[i].w;
    if ( v4 < -a3 )
      return 1;
  }
  return 0;
}
