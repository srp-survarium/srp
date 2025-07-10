char __userpurge Scaleform::Render::GlyphCache::isOuterContourCW@<al>(
        Scaleform::Render::GlyphCache *this@<ecx>,
        unsigned int *a2@<esi>,
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
  bool first; // [esp+29h] [ebp-91h]
  float maxY1; // [esp+2Eh] [ebp-8Ch]
  float minY1; // [esp+32h] [ebp-88h]
  float minX1; // [esp+36h] [ebp-84h]
  float sum; // [esp+3Ah] [ebp-80h]
  float prevY; // [esp+3Eh] [ebp-7Ch]
  float prevX; // [esp+42h] [ebp-78h]
  float maxY2; // [esp+46h] [ebp-74h]
  float maxX2; // [esp+4Ah] [ebp-70h]
  float minY2; // [esp+4Eh] [ebp-6Ch]
  float minX2; // [esp+52h] [ebp-68h]
  float firstX; // [esp+56h] [ebp-64h]
  float firstY; // [esp+5Ah] [ebp-60h]
  float coord[6]; // [esp+5Eh] [ebp-5Ch] BYREF
  Scaleform::Render::ShapePosInfo srcPos; // [esp+76h] [ebp-44h] BYREF
  unsigned int styles[3]; // [esp+AEh] [ebp-Ch] BYREF

  minX1 = 1.0e10;
  minY1 = 1.0e10;
  maxY1 = -1.0e10;
  maxX2 = -1.0e10;
  maxY2 = -1.0e10;
  minX2 = 1.0e10;
  minY2 = 1.0e10;
  v3 = shape->GetStartingPos(shape);
  srcPos.Sfactor = 1.0;
  srcPos.Pos = v3;
  ReadPathInfo = shape->ReadPathInfo;
  memset(&srcPos.StartX, 0, 44);
  srcPos.Initialized = 0;
  first = 1;
  for ( i = ReadPathInfo(shape, &srcPos, coord, styles);
        i;
        i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *, float *))shape->ReadPathInfo)(
              shape,
              &srcPos.StartX,
              &coord[1]) )
  {
    if ( !first && i == 2 )
      break;
    v6 = shape->__vftable;
    first = 0;
    if ( styles[0] == styles[1] )
    {
      ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, unsigned int *))v6->SkipPathData)(
        shape,
        &srcPos,
        a2);
    }
    else
    {
      sum = 0.0;
      firstX = coord[0];
      firstY = coord[1];
      prevY = coord[1];
      prevX = coord[0];
      for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))v6->ReadEdge)(
                  shape,
                  &srcPos,
                  coord,
                  a2); j; j = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)&srcPos.StartX, &coord[1]) )
      {
        v8 = coord[1];
        if ( sum > (double)coord[1] )
          sum = coord[1];
        v9 = coord[2];
        if ( minX1 > (double)coord[2] )
          minX1 = coord[2];
        if ( maxY1 < v8 )
          maxY1 = coord[1];
        if ( minY1 < v9 )
          minY1 = coord[2];
        prevY = maxY2 * v9 - prevX * v8 + prevY;
        maxY2 = coord[1];
        prevX = coord[2];
        if ( j == Edge_QuadTo )
        {
          v10 = coord[3];
          if ( sum > (double)coord[3] )
            sum = coord[3];
          v11 = coord[4];
          if ( minX1 > (double)coord[4] )
            minX1 = coord[4];
          if ( maxY1 < v10 )
            maxY1 = coord[3];
          if ( minY1 < v11 )
            minY1 = coord[4];
          prevY = v8 * v11 - v9 * v10 + prevY;
          maxY2 = coord[3];
          prevX = coord[4];
        }
      }
      v12 = firstY;
      v13 = coord[0];
      if ( firstY != maxY2 || v13 != prevX )
      {
        if ( sum > v12 )
          sum = firstY;
        if ( minX1 > v13 )
          minX1 = coord[0];
        if ( maxY1 < v12 )
          maxY1 = firstY;
        if ( minY1 < v13 )
          minY1 = coord[0];
      }
      if ( firstX > (double)sum || minX2 > (double)minX1 || minY2 < (double)maxY1 || maxX2 < (double)minY1 )
      {
        minX2 = minX1;
        minY2 = maxY1;
        maxX2 = minY1;
      }
    }
    a2 = &styles[1];
  }
  return 1;
}
