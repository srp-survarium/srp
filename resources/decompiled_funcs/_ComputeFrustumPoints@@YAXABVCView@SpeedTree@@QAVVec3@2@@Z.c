void __cdecl ComputeFrustumPoints(const struct SpeedTree::CView *a1, struct SpeedTree::Vec3 *const a2)
{
  int v2; // [esp+18Ch] [ebp-68h]
  struct SpeedTree::Vec4 *i; // [esp+190h] [ebp-64h]
  struct SpeedTree::Vec4 v4; // [esp+194h] [ebp-60h] BYREF
  struct SpeedTree::Vec4 v5; // [esp+1A4h] [ebp-50h] BYREF
  struct SpeedTree::Vec4 v6; // [esp+1B4h] [ebp-40h] BYREF
  struct SpeedTree::Vec4 v7; // [esp+1C4h] [ebp-30h] BYREF
  struct SpeedTree::Vec4 v8; // [esp+1D4h] [ebp-20h] BYREF
  struct SpeedTree::Vec4 v9; // [esp+1E4h] [ebp-10h] BYREF

  v2 = 6;
  for ( i = &v4; --v2 >= 0; ++i )
  {
    i->x = 0.0;
    i->y = 0.0;
    i->z = 0.0;
    i->w = 1.0;
  }
  ExtractPlanes(&a1->m_mComposite, &v4);
  Compute3PlaneIntersection(&v4, &v6, &v9, a2);
  Compute3PlaneIntersection(&v4, &v7, &v9, a2 + 1);
  Compute3PlaneIntersection(&v4, &v7, &v8, a2 + 2);
  Compute3PlaneIntersection(&v4, &v6, &v8, a2 + 3);
  Compute3PlaneIntersection(&v5, &v6, &v9, a2 + 4);
  Compute3PlaneIntersection(&v5, &v7, &v9, a2 + 5);
  Compute3PlaneIntersection(&v5, &v7, &v8, a2 + 6);
  Compute3PlaneIntersection(&v5, &v6, &v8, a2 + 7);
}
