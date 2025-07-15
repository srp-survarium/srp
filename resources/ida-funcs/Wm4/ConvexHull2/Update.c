char __userpurge Wm4::ConvexHull2<float>::Update@<al>(
        Wm4::ConvexHull2<float> *this@<ecx>,
        int a2@<ebx>,
        Wm4::HullEdge2<float> **rpkHull,
        Wm4::HullEdge2<float> **i,
        Wm4::HullEdge2<float> *ia)
{
  Wm4::HullEdge2<float> *v5; // esi
  Wm4::HullEdge2<float> *v7; // ebx
  Wm4::HullEdge2<float> *v8; // edi
  Wm4::HullEdge2<float> *j; // ecx
  Wm4::HullEdge2<float> **v10; // eax
  Wm4::HullEdge2<float> *v11; // eax
  Wm4::HullEdge2<float> *v12; // esi
  Wm4::HullEdge2<float> **v13; // eax
  Wm4::HullEdge2<float> *v14; // eax
  int v15; // [esp-4h] [ebp-Ch]

  v5 = *i;
  while ( Wm4::HullEdge2<float>::GetSign(v5, (int)ia, (Wm4::Query2<float> *)rpkHull[10]) <= 0 )
  {
    v5 = v5->A[1];
    if ( v5 == *i )
      return 1;
  }
  if ( !v5 )
    return 1;
  v15 = a2;
  v7 = v5->A[0];
  if ( !v7 )
    return 0;
  v8 = v5->A[1];
  if ( !v8 )
    return 0;
  for ( j = v5; ; j = v7->A[1] )
  {
    Wm4::HullEdge2<float>::DeleteSelf(j);
    if ( Wm4::HullEdge2<float>::GetSign(v7, (int)ia, (Wm4::Query2<float> *)rpkHull[10]) <= 0 )
      break;
    *i = v7;
    v7 = v7->A[0];
    if ( !v7 )
      return 0;
  }
  while ( Wm4::HullEdge2<float>::GetSign(v8, (int)ia, (Wm4::Query2<float> *)rpkHull[10]) > 0 )
  {
    *i = v8;
    v8 = v8->A[1];
    if ( !v8 )
      return 0;
    Wm4::HullEdge2<float>::DeleteSelf(v8->A[0]);
  }
  v10 = (Wm4::HullEdge2<float> **)operator new(0x18u);
  if ( v10 )
  {
    Wm4::HullEdge2<float>::HullEdge2<float>((Wm4::HullEdge2<float> *)v7->V[1], v10, ia, v15);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = (Wm4::HullEdge2<float> **)operator new(0x18u);
  if ( v13 )
    Wm4::HullEdge2<float>::HullEdge2<float>(ia, v13, (Wm4::HullEdge2<float> *)v8->V[0], v15);
  else
    v14 = 0;
  v7->A[1] = v12;
  v12->A[1] = v14;
  v12->A[0] = v7;
  v8->A[0] = v14;
  v14->A[0] = v12;
  v14->A[1] = v8;
  *i = v12;
  return 1;
}
