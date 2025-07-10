char __thiscall Wm4::ConvexHull2<float>::Update(
        Wm4::ConvexHull2<float> *this,
        Wm4::HullEdge2<float> **rpkHull,
        Wm4::HullEdge2<float> **i,
        int ia)
{
  Wm4::HullEdge2<float> *v4; // esi
  Wm4::HullEdge2<float> *v5; // ecx
  int v6; // eax
  Wm4::HullEdge2<float> *v8; // edi
  Wm4::HullEdge2<float> *v9; // ebx
  Wm4::HullEdge2<float> *v10; // eax
  Wm4::HullEdge2<float> *v11; // ecx
  int v12; // eax
  Wm4::HullEdge2<float> *v13; // esi
  Wm4::HullEdge2<float> *v14; // eax
  Wm4::HullEdge2<float> *v15; // ecx
  Wm4::HullEdge2<float> *v16; // ecx
  Wm4::HullEdge2<float> *v17; // ecx
  int v18; // eax
  Wm4::HullEdge2<float> *v19; // eax
  Wm4::HullEdge2<float> *v20; // ecx
  Wm4::HullEdge2<float> *v21; // ecx
  Wm4::HullEdge2<float> *v22; // eax
  int v23; // ecx
  int *v24; // eax
  int v25; // ecx
  int v26; // [esp+8h] [ebp-14h]
  int v27; // [esp+8h] [ebp-14h]
  int v28; // [esp+Ch] [ebp-10h]

  v4 = *i;
  while ( 1 )
  {
    v5 = rpkHull[10];
    if ( ia != v4->Time )
    {
      v28 = v4->V[1];
      v6 = v4->V[0];
      v4->Time = ia;
      v4->Sign = (*(int (__thiscall **)(Wm4::HullEdge2<float> *, int, int, int))(v5->V[0] + 12))(v5, ia, v6, v28);
    }
    if ( v4->Sign > 0 )
      break;
    v4 = v4->A[1];
    if ( v4 == *i )
      return 1;
  }
  v8 = v4->A[0];
  if ( !v8 )
    return 0;
  v9 = v4->A[1];
  if ( !v9 )
    return 0;
  v8->A[1] = 0;
  v10 = v4->A[1];
  if ( v10 )
    v10->A[0] = 0;
  operator delete(v4);
  while ( 1 )
  {
    v11 = rpkHull[10];
    if ( ia != v8->Time )
    {
      v26 = v8->V[1];
      v12 = v8->V[0];
      v8->Time = ia;
      v8->Sign = (*(int (__thiscall **)(Wm4::HullEdge2<float> *, int, int, int))(v11->V[0] + 12))(v11, ia, v12, v26);
    }
    v13 = 0;
    if ( v8->Sign <= 0 )
      break;
    *i = v8;
    v8 = v8->A[0];
    if ( !v8 )
      return 0;
    v14 = v8->A[1];
    v15 = v14->A[0];
    if ( v15 )
      v15->A[1] = 0;
    v16 = v14->A[1];
    if ( v16 )
      v16->A[0] = 0;
    operator delete(v14);
  }
  while ( 1 )
  {
    v17 = rpkHull[10];
    if ( ia != v9->Time )
    {
      v27 = v9->V[1];
      v18 = v9->V[0];
      v9->Time = ia;
      v9->Sign = (*(int (__thiscall **)(Wm4::HullEdge2<float> *, int, int, int))(v17->V[0] + 12))(v17, ia, v18, v27);
    }
    if ( v9->Sign <= 0 )
      break;
    *i = v9;
    v9 = v9->A[1];
    if ( !v9 )
      return 0;
    v19 = v9->A[0];
    v20 = v19->A[0];
    if ( v20 )
      v20->A[1] = 0;
    v21 = v19->A[1];
    if ( v21 )
      v21->A[0] = 0;
    operator delete(v19);
  }
  v22 = (Wm4::HullEdge2<float> *)operator new(0x18u);
  if ( v22 )
  {
    v23 = v8->V[1];
    v22->A[0] = 0;
    v22->A[1] = 0;
    v22->Sign = 0;
    v22->V[0] = v23;
    v22->V[1] = ia;
    v22->Time = -1;
    v13 = v22;
  }
  v24 = (int *)operator new(0x18u);
  if ( v24 )
  {
    v25 = v9->V[0];
    *v24 = ia;
    v24[1] = v25;
    v24[2] = 0;
    v24[3] = 0;
    v24[4] = 0;
    v24[5] = -1;
  }
  else
  {
    v24 = 0;
  }
  v8->A[1] = v13;
  v13->A[0] = v8;
  v13->A[1] = (Wm4::HullEdge2<float> *)v24;
  v9->A[0] = (Wm4::HullEdge2<float> *)v24;
  v24[3] = (int)v9;
  v24[2] = (int)v13;
  *i = v13;
  return 1;
}
