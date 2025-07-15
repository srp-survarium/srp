void __userpurge Scaleform::Render::GlyphCache::addShapeAutoFit(
        Scaleform::Render::GlyphCache *this@<ecx>,
        unsigned int *a2@<ebx>,
        const Scaleform::Render::ShapeDataInterface *shape,
        unsigned int nomHeight,
        int lowerCaseTop,
        int upperCaseTop,
        float screenSize,
        float stretch)
{
  Scaleform::Render::GlyphCache *v8; // ebp
  Scaleform::Render::GlyphFitter *p_Fitter; // esi
  int v10; // eax
  unsigned int (__thiscall *GetStartingPos)(Scaleform::Render::ShapeDataInterface *); // eax
  unsigned int v12; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  unsigned int v14; // ebx
  int v15; // eax
  double j; // st7
  Scaleform::Render::PathEdgeType k; // eax
  double v18; // st7
  Scaleform::Render::GlyphFitter::ContourType *v19; // ebp
  __int16 MinY; // cx
  int v21; // eax
  __int16 v22; // ax
  __int16 MinX; // di
  __int16 v24; // cx
  int v25; // edx
  Scaleform::Render::Rasterizer *p_Ras; // ebx
  unsigned int m; // edi
  __int16 v28; // cx
  int v29; // eax
  __int16 v30; // ax
  __int16 v31; // cx
  int v32; // edx
  float y; // [esp+20h] [ebp-C4h]
  float ya; // [esp+20h] [ebp-C4h]
  Scaleform::Render::GlyphFitter::VertexType v; // [esp+34h] [ebp-B0h]
  float vc; // [esp+34h] [ebp-B0h]
  Scaleform::Render::GlyphFitter::VertexType va; // [esp+34h] [ebp-B0h]
  float vd; // [esp+34h] [ebp-B0h]
  float ve; // [esp+34h] [ebp-B0h]
  Scaleform::Render::GlyphFitter::VertexType vb; // [esp+34h] [ebp-B0h]
  float vf; // [esp+34h] [ebp-B0h]
  float vg; // [esp+34h] [ebp-B0h]
  float v44; // [esp+38h] [ebp-ACh]
  float scale; // [esp+3Ch] [ebp-A8h]
  float scalea; // [esp+3Ch] [ebp-A8h]
  float ib; // [esp+40h] [ebp-A4h]
  float i; // [esp+40h] [ebp-A4h]
  unsigned int ia; // [esp+40h] [ebp-A4h]
  float coord[6]; // [esp+48h] [ebp-9Ch] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+60h] [ebp-84h] BYREF
  unsigned int styles[3]; // [esp+98h] [ebp-4Ch] BYREF
  Scaleform::Render::ToleranceParams param; // [esp+A4h] [ebp-40h] BYREF

  v8 = this;
  p_Fitter = &this->Fitter;
  this->Fitter.Clear(&this->Fitter);
  if ( !shape->IsEmpty(shape) )
  {
    v10 = (int)(64.0 * screenSize);
    v = (Scaleform::Render::GlyphFitter::VertexType)v10;
    if ( v10 > 2048 )
    {
      v10 = 2048;
      v = (Scaleform::Render::GlyphFitter::VertexType)2048;
    }
    v8->Fitter.NominalFontHeight = v10;
    ib = (float)(int)v;
    scale = ib / (double)nomHeight;
    i = ib * 0.5 / screenSize;
    Scaleform::Render::ToleranceParams::ToleranceParams(&param);
    GetStartingPos = shape->GetStartingPos;
    param.CurveTolerance = param.CurveTolerance * i;
    param.CollinearityTolerance = i * param.CollinearityTolerance;
    v12 = GetStartingPos(shape);
    ReadPathInfo = shape->ReadPathInfo;
    pos.Sfactor = 1.0;
    v14 = 0;
    pos.Pos = v12;
    memset(&pos.StartX, 0, 44);
    pos.Initialized = 0;
    HIBYTE(v44) = 1;
    v15 = ReadPathInfo(shape, &pos, coord, styles);
    for ( j = scale; v15; j = scale )
    {
      if ( !HIBYTE(v44) && v15 == 2 )
        break;
      HIBYTE(v44) = 0;
      if ( styles[0] == styles[1] )
      {
        ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, unsigned int *))shape->SkipPathData)(
          shape,
          &pos,
          a2);
      }
      else
      {
        coord[0] = coord[0] * j;
        vc = -j;
        coord[1] = vc * coord[1];
        Scaleform::Render::GlyphFitter::MoveTo(p_Fitter, coord[0], coord[1]);
        for ( k = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *))shape->ReadEdge)(
                    shape,
                    &pos,
                    coord,
                    a2); k; k = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)&pos.StartX, &coord[1]) )
        {
          coord[1] = coord[1] * i;
          coord[2] = v44 * coord[2];
          if ( k == Edge_LineTo )
          {
            Scaleform::Render::GlyphFitter::LineTo(p_Fitter, coord[1], coord[2]);
          }
          else
          {
            coord[3] = i * coord[3];
            coord[4] = v44 * coord[4];
            Scaleform::Render::TessellateQuadCurve(
              p_Fitter,
              (Scaleform::Render::ToleranceParams *)&param.CurveTolerance,
              coord[1],
              coord[2],
              coord[3],
              coord[4]);
          }
        }
        p_Fitter->ClosePath(p_Fitter);
      }
      a2 = &styles[1];
      v15 = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *, float *))shape->ReadPathInfo)(
              shape,
              &pos.StartX,
              &coord[1]);
    }
    Scaleform::Render::GlyphFitter::FitGlyph(
      p_Fitter,
      (int)screenSize,
      0,
      (int)(j * (double)lowerCaseTop),
      (int)((double)upperCaseTop * j));
    ia = 0;
    scalea = 1.0 / (double)v8->Fitter.UnitsPerPixelY;
    if ( v8->Fitter.Contours.Size )
    {
      v18 = scalea;
      while ( 1 )
      {
        v19 = &v8->Fitter.Contours.Pages[v14 >> 2][v14 & 3];
        if ( v19->NumVertices > 2 )
        {
          MinY = p_Fitter->MinY;
          va = this->Fitter.Vertices.Pages[v19->StartVertex >> 4][v19->StartVertex & 0xF];
          v21 = va.y - MinY;
          if ( v21 < 0 || v21 >= (signed int)p_Fitter->LerpRampY.Size )
            v22 = HIWORD(*(_DWORD *)&this->Fitter.Vertices.Pages[v19->StartVertex >> 4][v19->StartVertex & 0xF]);
          else
            v22 = MinY + p_Fitter->LerpRampY.Array[v21];
          MinX = p_Fitter->MinX;
          v24 = (__int16)this->Fitter.Vertices.Pages[v19->StartVertex >> 4][v19->StartVertex & 0xF];
          v25 = va.x - MinX;
          if ( v25 >= 0 && v25 < (signed int)p_Fitter->LerpRampX.Size )
            v24 = MinX + p_Fitter->LerpRampX.Array[v25];
          p_Ras = &this->Ras;
          vd = (double)-v22 * v18;
          y = vd;
          ve = v18 * (double)v24 * stretch;
          Scaleform::Render::Rasterizer::MoveTo(&this->Ras, ve, y);
          for ( m = 1; m < v19->NumVertices; ++m )
          {
            v28 = p_Fitter->MinY;
            vb = this->Fitter.Vertices.Pages[(m + v19->StartVertex) >> 4][(m + v19->StartVertex) & 0xF];
            v29 = vb.y - v28;
            if ( v29 < 0 || v29 >= (signed int)p_Fitter->LerpRampY.Size )
              v30 = HIWORD(*(_DWORD *)&this->Fitter.Vertices.Pages[(m + v19->StartVertex) >> 4][(m + v19->StartVertex)
                                                                                              & 0xF]);
            else
              v30 = v28 + p_Fitter->LerpRampY.Array[v29];
            v31 = (__int16)this->Fitter.Vertices.Pages[(m + v19->StartVertex) >> 4][(m + v19->StartVertex) & 0xF];
            v32 = vb.x - p_Fitter->MinX;
            if ( v32 >= 0 && v32 < (signed int)p_Fitter->LerpRampX.Size )
              v31 = p_Fitter->MinX + p_Fitter->LerpRampX.Array[v32];
            p_Ras = &this->Ras;
            vf = (double)-v30 * scalea;
            ya = vf;
            vg = scalea * (double)v31 * stretch;
            Scaleform::Render::Rasterizer::LineTo(&this->Ras, vg, ya);
          }
          p_Ras->ClosePath(p_Ras);
          v18 = scalea;
          v14 = ia;
        }
        ia = ++v14;
        if ( v14 >= this->Fitter.Contours.Size )
          break;
        v8 = this;
      }
    }
    p_Fitter->Clear(p_Fitter);
  }
}
