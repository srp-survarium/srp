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
  _DWORD *v13; // ecx
  _DWORD *v14; // esi
  unsigned int v15; // eax
  char v17; // [esp+1Fh] [ebp-B9h]
  _DWORD v18[13]; // [esp+20h] [ebp-B8h] BYREF
  char v19; // [esp+54h] [ebp-84h]
  _DWORD v20[13]; // [esp+58h] [ebp-80h] BYREF
  char v21; // [esp+8Ch] [ebp-4Ch]
  _DWORD v22[6]; // [esp+90h] [ebp-48h] BYREF
  _DWORD v23[3]; // [esp+A8h] [ebp-30h] BYREF
  _DWORD v24[6]; // [esp+B4h] [ebp-24h] BYREF
  _BYTE v25[12]; // [esp+CCh] [ebp-Ch] BYREF

  v2 = a->IsEmpty(a);
  v3 = b->IsEmpty(b);
  if ( v2 || v3 )
    return v2 == v3;
  v4 = a->GetStartingPos(a);
  v5 = b->GetStartingPos(b);
  *(float *)&v20[12] = 1.0;
  *(float *)&v18[12] = 1.0;
  v20[0] = v4;
  memset(&v20[1], 0, 44);
  v21 = 0;
  v18[0] = v5;
  memset(&v18[1], 0, 44);
  v19 = 0;
  v17 = 1;
LABEL_4:
  v6 = a->ReadPathInfo(a, (Scaleform::Render::ShapePosInfo *)v20, (float *)v24, (unsigned int *)v25);
  if ( v6 != b->ReadPathInfo(b, (Scaleform::Render::ShapePosInfo *)v18, (float *)v22, v23) )
    return 0;
  if ( v6 )
  {
    if ( v6 == Shape_NewLayer || v17 )
      v17 = 0;
    v7 = 12;
    v8 = 0;
    while ( *(_DWORD *)&v25[v8 * 4] == v23[v8] )
    {
      v7 -= 4;
      ++v8;
      if ( v7 < 4 )
      {
        v9 = 8;
        v10 = 0;
        while ( v24[v10] == v22[v10] )
        {
          v9 -= 4;
          ++v10;
          if ( v9 < 4 )
          {
            while ( 1 )
            {
              v11 = a->ReadEdge(a, (Scaleform::Render::ShapePosInfo *)v20, (float *)v24);
              if ( v11 != b->ReadEdge(b, (Scaleform::Render::ShapePosInfo *)v18, (float *)v22) )
                return 0;
              if ( v11 == Edge_EndPath )
                goto LABEL_4;
              v12 = v11 == Edge_QuadTo;
              v13 = v22;
              v14 = v24;
              v15 = 4 * (2 * v12 + 2);
              if ( v15 >= 4 )
              {
                while ( *v14 == *v13 )
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
