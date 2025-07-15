int __usercall Scaleform::GFx::ComputeGeometryHash@<eax>(
        unsigned int *a1@<ebx>,
        float *a2@<esi>,
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
  unsigned int styles[3]; // [esp+10h] [ebp-5Ch] BYREF
  float coord[6]; // [esp+1Ch] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+34h] [ebp-38h] BYREF
  char first; // [esp+70h] [ebp+4h]

  if ( sh->IsEmpty(sh) )
    return 0;
  v5 = 5381;
  v6 = sh->GetStartingPos(sh);
  pos.Sfactor = 1.0;
  pos.Pos = v6;
  ReadPathInfo = sh->ReadPathInfo;
  memset(&pos.StartX, 0, 44);
  pos.Initialized = 0;
  first = 1;
  for ( i = ReadPathInfo(sh, &pos, coord, styles);
        i;
        i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *))sh->ReadPathInfo)(
              sh,
              &pos.StartY) )
  {
    if ( !first && i == 2 )
      break;
    first = 0;
    v9 = 12;
    v10 = v5;
    do
    {
      v11 = (unsigned __int8)*(&v24 + v9--);
      v10 = (33 * v10) ^ v11;
    }
    while ( v9 );
    v5 = v10;
    if ( styles[0] == styles[1] )
    {
      ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))sh->SkipPathData)(
        sh,
        &pos,
        a2,
        a1);
    }
    else
    {
      v12 = 8;
      do
      {
        v13 = *((unsigned __int8 *)&styles[2] + v12-- + 3);
        v10 = (33 * v10) ^ v13;
      }
      while ( v12 );
      v5 = v10;
      for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, float *, unsigned int *))sh->ReadEdge)(
                  sh,
                  &pos,
                  coord,
                  a2,
                  a1); j; j = sh->ReadEdge(sh, (Scaleform::Render::ShapePosInfo *)&pos.StartY, &coord[2]) )
      {
        v15 = j == Edge_LineTo;
        v16 = v5;
        if ( v15 )
        {
          v17 = 8;
          do
          {
            v18 = *((unsigned __int8 *)&coord[1] + v17-- + 3);
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
            v20 = *((unsigned __int8 *)&coord[1] + v19-- + 3);
            v21 = (33 * v16) ^ v20;
            v16 = v21;
          }
          while ( v19 );
          v5 = v21;
        }
      }
    }
    a1 = &styles[2];
    a2 = &coord[2];
  }
  return v5;
}
