char __userpurge Scaleform::Render::GlyphCache::isOuterContourCW@<al>(
        Scaleform::Render::GlyphCache *this@<ecx>,
        int *a2@<esi>,
        const Scaleform::Render::ShapeDataInterface *shape)
{
  unsigned int v3; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  int i; // eax
  Scaleform::Render::ShapeDataInterface_vtbl *v6; // edx
  Scaleform::Render::PathEdgeType j; // ecx
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st6
  double v13; // st5
  char v16; // [esp+29h] [ebp-91h]
  float v17; // [esp+2Eh] [ebp-8Ch]
  float v18; // [esp+32h] [ebp-88h]
  float v19; // [esp+36h] [ebp-84h]
  float v20; // [esp+3Ah] [ebp-80h]
  float v21; // [esp+3Eh] [ebp-7Ch]
  float v22; // [esp+42h] [ebp-78h]
  float v23; // [esp+46h] [ebp-74h]
  float v24; // [esp+4Ah] [ebp-70h]
  float v25; // [esp+4Eh] [ebp-6Ch]
  float v26; // [esp+52h] [ebp-68h]
  float v27; // [esp+56h] [ebp-64h]
  float v28; // [esp+5Ah] [ebp-60h]
  float v29; // [esp+5Eh] [ebp-5Ch] BYREF
  float v30; // [esp+62h] [ebp-58h] BYREF
  float v31; // [esp+66h] [ebp-54h]
  float v32; // [esp+6Ah] [ebp-50h]
  float v33; // [esp+6Eh] [ebp-4Ch]
  unsigned int v34; // [esp+76h] [ebp-44h] BYREF
  _DWORD v35[12]; // [esp+7Ah] [ebp-40h] BYREF
  char v36; // [esp+AAh] [ebp-10h]
  int v37; // [esp+AEh] [ebp-Ch] BYREF
  int v38; // [esp+B2h] [ebp-8h] BYREF

  v19 = 1.0e10;
  v18 = 1.0e10;
  v17 = -1.0e10;
  v24 = -1.0e10;
  v23 = -1.0e10;
  v26 = 1.0e10;
  v25 = 1.0e10;
  v3 = shape->GetStartingPos(shape);
  *(float *)&v35[11] = 1.0;
  v34 = v3;
  ReadPathInfo = shape->ReadPathInfo;
  memset(v35, 0, 44);
  v36 = 0;
  v16 = 1;
  for ( i = ReadPathInfo(shape, (Scaleform::Render::ShapePosInfo *)&v34, &v29, (unsigned int *)&v37);
        i;
        i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *, float *))shape->ReadPathInfo)(
              shape,
              v35,
              &v30) )
  {
    if ( !v16 && i == 2 )
      break;
    v6 = shape->__vftable;
    v16 = 0;
    if ( v37 == v38 )
    {
      ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, unsigned int *, int *))v6->SkipPathData)(
        shape,
        &v34,
        a2);
    }
    else
    {
      v20 = 0.0;
      v27 = v29;
      v28 = v30;
      v21 = v30;
      v22 = v29;
      for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, unsigned int *, float *, int *))v6->ReadEdge)(
                  shape,
                  &v34,
                  &v29,
                  a2); j; j = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)v35, &v30) )
      {
        v8 = v30;
        if ( v20 > (double)v30 )
          v20 = v30;
        v9 = v31;
        if ( v19 > (double)v31 )
          v19 = v31;
        if ( v17 < v8 )
          v17 = v30;
        if ( v18 < v9 )
          v18 = v31;
        v21 = v23 * v9 - v22 * v8 + v21;
        v23 = v30;
        v22 = v31;
        if ( j == Edge_QuadTo )
        {
          v10 = v32;
          if ( v20 > (double)v32 )
            v20 = v32;
          v11 = v33;
          if ( v19 > (double)v33 )
            v19 = v33;
          if ( v17 < v10 )
            v17 = v32;
          if ( v18 < v11 )
            v18 = v33;
          v21 = v8 * v11 - v9 * v10 + v21;
          v23 = v32;
          v22 = v33;
        }
      }
      v12 = v28;
      v13 = v29;
      if ( v28 != v23 || v13 != v22 )
      {
        if ( v20 > v12 )
          v20 = v28;
        if ( v19 > v13 )
          v19 = v29;
        if ( v17 < v12 )
          v17 = v28;
        if ( v18 < v13 )
          v18 = v29;
      }
      if ( v27 > (double)v20 || v26 > (double)v19 || v25 < (double)v17 || v24 < (double)v18 )
      {
        v26 = v19;
        v25 = v17;
        v24 = v18;
      }
    }
    a2 = &v38;
  }
  return 1;
}
