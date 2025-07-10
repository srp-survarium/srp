char __usercall TestSepAxis@<al>(
        btConvexPolyhedron *hullA@<edx>,
        const btVector3 *sep_axis@<esi>,
        btConvexPolyhedron *hullB,
        const btTransform *transA,
        const btTransform *transB,
        float *depth)
{
  float v6; // xmm0_4
  float Min1; // [esp+4h] [ebp-10h] BYREF
  float Max0; // [esp+8h] [ebp-Ch] BYREF
  float Min0; // [esp+Ch] [ebp-8h] BYREF
  float Max1; // [esp+10h] [ebp-4h] BYREF

  btConvexPolyhedron::project(hullA, transA, sep_axis, &Min0, &Max0);
  btConvexPolyhedron::project(hullB, transB, sep_axis, &Min1, &Max1);
  if ( Min1 > Max0 || Min0 > Max1 )
    return 0;
  v6 = Max1 - Min0;
  if ( (float)(Max1 - Min0) > (float)(Max0 - Min1) )
    v6 = Max0 - Min1;
  *depth = v6;
  return 1;
}
