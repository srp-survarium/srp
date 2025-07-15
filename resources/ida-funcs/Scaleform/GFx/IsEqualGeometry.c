bool __cdecl Scaleform::GFx::IsEqualGeometry(
        const Scaleform::Render::ShapeDataInterface *a,
        const Scaleform::Render::ShapeDataInterface *b)
{
  char v2; // bl
  char v3; // al
  unsigned int v4; // esi
  unsigned int v5; // eax
  Scaleform::Render::ShapePathType v6; // esi
  unsigned int v7; // eax
  int v8; // ecx
  unsigned int v9; // eax
  int v10; // ecx
  Scaleform::Render::PathEdgeType v11; // esi
  BOOL v12; // eax
  float *v13; // ecx
  float *v14; // esi
  unsigned int v15; // eax
  bool first; // [esp+1Fh] [ebp-B9h]
  Scaleform::Render::ShapePosInfo posInfo2; // [esp+20h] [ebp-B8h] BYREF
  Scaleform::Render::ShapePosInfo posInfo1; // [esp+58h] [ebp-80h] BYREF
  float coord2[6]; // [esp+90h] [ebp-48h] BYREF
  unsigned int styles2[3]; // [esp+A8h] [ebp-30h] BYREF
  float coord1[6]; // [esp+B4h] [ebp-24h] BYREF
  unsigned int styles1[3]; // [esp+CCh] [ebp-Ch] BYREF

  v2 = a->IsEmpty(a);
  v3 = b->IsEmpty(b);
  if ( v2 || v3 )
    return v2 == v3;
  v4 = a->GetStartingPos(a);
  v5 = b->GetStartingPos(b);
  posInfo1.Sfactor = 1.0;
  posInfo2.Sfactor = 1.0;
  posInfo1.Pos = v4;
  memset(&posInfo1.StartX, 0, 44);
  posInfo1.Initialized = 0;
  posInfo2.Pos = v5;
  memset(&posInfo2.StartX, 0, 44);
  posInfo2.Initialized = 0;
  first = 1;
LABEL_4:
  v6 = a->ReadPathInfo(a, &posInfo1, coord1, styles1);
  if ( v6 != b->ReadPathInfo(b, &posInfo2, coord2, styles2) )
    return 0;
  if ( v6 )
  {
    if ( v6 == Shape_NewLayer || first )
      first = 0;
    v7 = 12;
    v8 = 0;
    while ( styles1[v8] == styles2[v8] )
    {
      v7 -= 4;
      ++v8;
      if ( v7 < 4 )
      {
        v9 = 8;
        v10 = 0;
        while ( LODWORD(coord1[v10]) == LODWORD(coord2[v10]) )
        {
          v9 -= 4;
          ++v10;
          if ( v9 < 4 )
          {
            while ( 1 )
            {
              v11 = a->ReadEdge(a, &posInfo1, coord1);
              if ( v11 != b->ReadEdge(b, &posInfo2, coord2) )
                return 0;
              if ( v11 == Edge_EndPath )
                goto LABEL_4;
              v12 = v11 == Edge_QuadTo;
              v13 = coord2;
              v14 = coord1;
              v15 = 4 * (2 * v12 + 2);
              if ( v15 >= 4 )
              {
                while ( *(_DWORD *)v14 == *(_DWORD *)v13 )
                {
                  v15 -= 4;
                  ++v13;
                  ++v14;
                  if ( v15 < 4 )
                    goto LABEL_20;
                }
                return 0;
              }
LABEL_20:
              if ( v15
                && (*(_BYTE *)v13 != *(_BYTE *)v14
                 || v15 > 1
                 && (*((_BYTE *)v13 + 1) != *((_BYTE *)v14 + 1) || v15 > 2 && *((_BYTE *)v13 + 2) != *((_BYTE *)v14 + 2))) )
              {
                return 0;
              }
            }
          }
        }
        return 0;
      }
    }
    return 0;
  }
  return 1;
}
