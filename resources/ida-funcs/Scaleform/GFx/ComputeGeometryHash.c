int __usercall Scaleform::GFx::ComputeGeometryHash@<eax>(
        _BYTE *a1@<ebx>,
        _BYTE *a2@<esi>,
        const Scaleform::Render::ShapeDataInterface *sh)
{
  int v5; // esi
  unsigned int v6; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  int i; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  Scaleform::Render::PathEdgeType j; // eax
  bool v15; // zf
  int v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // edx
  char v24; // [esp+Fh] [ebp-5Dh]
  _DWORD v25[2]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v26[4]; // [esp+18h] [ebp-54h] BYREF
  _BYTE v27[8]; // [esp+1Ch] [ebp-50h] BYREF
  _BYTE v28[16]; // [esp+24h] [ebp-48h] BYREF
  _DWORD v29[2]; // [esp+34h] [ebp-38h] BYREF
  _DWORD v30[11]; // [esp+3Ch] [ebp-30h] BYREF
  char v31; // [esp+68h] [ebp-4h]
  char v32; // [esp+70h] [ebp+4h]

  if ( sh->IsEmpty(sh) )
    return 0;
  v5 = 5381;
  v6 = sh->GetStartingPos(sh);
  *(float *)&v30[10] = 1.0;
  v29[0] = v6;
  ReadPathInfo = sh->ReadPathInfo;
  v29[1] = 0;
  memset(v30, 0, 40);
  v31 = 0;
  v32 = 1;
  for ( i = ReadPathInfo(sh, (Scaleform::Render::ShapePosInfo *)v29, (float *)v27, v25);
        i;
        i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *))sh->ReadPathInfo)(sh, v30) )
  {
    if ( !v32 && i == 2 )
      break;
    v32 = 0;
    v9 = 12;
    v10 = v5;
    do
    {
      v11 = (unsigned __int8)*(&v24 + v9--);
      v10 = (33 * v10) ^ v11;
    }
    while ( v9 );
    v5 = v10;
    if ( v25[0] == v25[1] )
    {
      ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *, _BYTE *, _BYTE *))sh->SkipPathData)(
        sh,
        v29,
        a2,
        a1);
    }
    else
    {
      v12 = 8;
      do
      {
        v13 = (unsigned __int8)v26[v12-- + 3];
        v10 = (33 * v10) ^ v13;
      }
      while ( v12 );
      v5 = v10;
      for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *, _BYTE *, _BYTE *, _BYTE *))sh->ReadEdge)(
                  sh,
                  v29,
                  v27,
                  a2,
                  a1); j; j = sh->ReadEdge(sh, (Scaleform::Render::ShapePosInfo *)v30, (float *)v28) )
      {
        v15 = j == Edge_LineTo;
        v16 = v5;
        if ( v15 )
        {
          v17 = 8;
          do
          {
            v18 = (unsigned __int8)v27[v17-- + 7];
            v16 = (33 * v16) ^ v18;
          }
          while ( v17 );
          v5 = v16;
        }
        else
        {
          v19 = 16;
          do
          {
            v20 = (unsigned __int8)v27[v19-- + 7];
            v21 = (33 * v16) ^ v20;
            v16 = v21;
          }
          while ( v19 );
          v5 = v21;
        }
      }
    }
    a1 = v26;
    a2 = v28;
  }
  return v5;
}
