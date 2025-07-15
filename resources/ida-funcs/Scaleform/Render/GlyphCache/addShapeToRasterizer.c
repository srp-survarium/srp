void __userpurge Scaleform::Render::GlyphCache::addShapeToRasterizer(
        Scaleform::Render::GlyphCache *this@<ecx>,
        char *a2@<ebx>,
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
  char v15; // [esp+37h] [ebp-9Dh]
  float x; // [esp+38h] [ebp-9Ch] BYREF
  float y; // [esp+3Ch] [ebp-98h]
  float v18; // [esp+40h] [ebp-94h] BYREF
  float v19; // [esp+44h] [ebp-90h]
  float v20; // [esp+48h] [ebp-8Ch]
  float v21; // [esp+4Ch] [ebp-88h]
  _DWORD v22[2]; // [esp+50h] [ebp-84h] BYREF
  _DWORD v23[11]; // [esp+58h] [ebp-7Ch] BYREF
  char v24; // [esp+84h] [ebp-50h]
  _DWORD v25[2]; // [esp+88h] [ebp-4Ch] BYREF
  char v26; // [esp+90h] [ebp-44h] BYREF
  Scaleform::Render::ToleranceParams param; // [esp+94h] [ebp-40h] BYREF

  if ( !shape->IsEmpty(shape) )
  {
    Scaleform::Render::ToleranceParams::ToleranceParams(&param);
    v9 = shape->GetStartingPos(shape);
    *(float *)&v23[10] = 1.0;
    v22[0] = v9;
    ReadPathInfo = shape->ReadPathInfo;
    v22[1] = 0;
    memset(v23, 0, 40);
    v24 = 0;
    v15 = 1;
    for ( i = ReadPathInfo(shape, (Scaleform::Render::ShapePosInfo *)v22, &x, v25);
          i;
          i = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *))shape->ReadPathInfo)(
                shape,
                v23) )
    {
      if ( !v15 && i == 2 )
        break;
      v15 = 0;
      if ( v25[0] == v25[1] )
      {
        ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *, float *, char *))shape->SkipPathData)(
          shape,
          v22,
          a3,
          a2);
      }
      else
      {
        x = x * scaleX;
        y = y * scaleY;
        Scaleform::Render::Rasterizer::MoveTo(&this->Ras, x, y);
        for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *, float *, float *, char *))shape->ReadEdge)(
                    shape,
                    v22,
                    &x,
                    a3,
                    a2); j; j = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)v23, &v18) )
        {
          v18 = v18 * a7;
          v19 = v19 * a8;
          if ( j == Edge_LineTo )
          {
            Scaleform::Render::Rasterizer::LineTo(&this->Ras, v18, v19);
          }
          else
          {
            v20 = a7 * v20;
            v21 = a8 * v21;
            Scaleform::Render::TessellateQuadCurve(
              &this->Ras,
              (Scaleform::Render::ToleranceParams *)&param.CollinearityTolerance,
              v18,
              v19,
              v20,
              v21);
          }
        }
        this->Ras.ClosePath(&this->Ras);
      }
      a2 = &v26;
      a3 = &v18;
    }
  }
}
