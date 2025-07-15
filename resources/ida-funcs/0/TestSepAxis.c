char __cdecl TestSepAxis(
        btConvexPolyhedron *hullA,
        btConvexPolyhedron *hullB,
        const btTransform *transA,
        const btTransform *transB,
        float *depth)
{
  const btVector3 *v5; // ecx
  const btVector3 *v6; // ecx
  float v7; // xmm0_4
  float v9; // [esp+4h] [ebp-10h] BYREF
  float v10; // [esp+8h] [ebp-Ch] BYREF
  float v11; // [esp+Ch] [ebp-8h] BYREF
  float v12; // [esp+10h] [ebp-4h] BYREF

  btConvexPolyhedron::project(transA, v5, &v11, hullA, &v10);
  btConvexPolyhedron::project(transB, v6, &v9, hullB, &v12);
  if ( v12 > v11 || v10 > v9 )
    return 0;
  v7 = v9 - v10;
  if ( (float)(v9 - v10) > (float)(v11 - v12) )
    v7 = v11 - v12;
  *depth = v7;
  return 1;
}
