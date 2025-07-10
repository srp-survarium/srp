void __userpurge Scaleform::Render::GlyphCache::addShapeToRasterizer(
        Scaleform::Render::GlyphCache *this@<ecx>,
        unsigned int *a2@<ebx>,
        float *a3@<edi>,
        const Scaleform::Render::ShapeDataInterface *shape,
        float scaleX,
        float scaleY,
        float a7,
        float a8)
{
  unsigned int v9; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  int i; // eax
  Scaleform::Render::PathEdgeType j; // eax
  bool first; // [esp+37h] [ebp-9Dh]
  float coord[6]; // [esp+38h] [ebp-9Ch] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+50h] [ebp-84h] BYREF
  unsigned int styles[3]; // [esp+88h] [ebp-4Ch] BYREF
  Scaleform::Render::ToleranceParams param; // [esp+94h] [ebp-40h] BYREF

  if ( !shape->IsEmpty(shape) )
  {
    Scaleform::Render::ToleranceParams::ToleranceParams(&param);
    v9 = shape->GetStartingPos(shape);
    pos.Sfactor = 1.0;
    pos.Pos = v9;
    ReadPathInfo = shape->ReadPathInfo;
    memset(&pos.StartX, 0, 44);
    pos.Initialized = 0;
    first = 1;
    for ( i = ReadPathInfo(shape, &pos, coord, styles);
          i;
          i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *))shape->ReadPathInfo)(
                shape,
                &pos.StartY) )
    {
      if ( !first && i == 2 )
        break;
      first = 0;
      if ( styles[0] == styles[1] )
      {
        ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))shape->SkipPathData)(
          shape,
          &pos,
          a3,
          a2);
      }
      else
      {
        coord[0] = coord[0] * scaleX;
        coord[1] = coord[1] * scaleY;
        Scaleform::Render::Rasterizer::MoveTo(&this->Ras, coord[0], coord[1]);
        for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, float *, unsigned int *))shape->ReadEdge)(
                    shape,
                    &pos,
                    coord,
                    a3,
                    a2); j; j = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)&pos.StartY, &coord[2]) )
        {
          coord[2] = coord[2] * a7;
          coord[3] = coord[3] * a8;
          if ( j == Edge_LineTo )
          {
            Scaleform::Render::Rasterizer::LineTo(&this->Ras, coord[2], coord[3]);
          }
          else
          {
            coord[4] = a7 * coord[4];
            coord[5] = a8 * coord[5];
            Scaleform::Render::TessellateQuadCurve(
              &this->Ras,
              (Scaleform::Render::ToleranceParams *)&param.CollinearityTolerance,
              coord[2],
              coord[3],
              coord[4],
              coord[5]);
          }
        }
        this->Ras.ClosePath(&this->Ras);
      }
      a2 = &styles[2];
      a3 = &coord[2];
    }
  }
}
