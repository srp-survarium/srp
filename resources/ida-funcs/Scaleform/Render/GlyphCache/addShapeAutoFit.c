void __userpurge Scaleform::Render::GlyphCache::addShapeAutoFit(
        Scaleform::Render::GlyphCache *this@<ecx>,
        int *a2@<ebx>,
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
  int v12; // eax
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  unsigned int v14; // ebx
  int v15; // eax
  double i; // st7
  Scaleform::Render::PathEdgeType j; // eax
  double v18; // st7
  Scaleform::Render::GlyphFitter::ContourType *v19; // ebp
  __int16 MinY; // cx
  int v21; // eax
  __int16 v22; // ax
  __int16 MinX; // di
  __int16 v24; // cx
  int v25; // edx
  Scaleform::Render::Rasterizer *p_Ras; // ebx
  unsigned int k; // edi
  __int16 v28; // cx
  int v29; // eax
  __int16 v30; // ax
  __int16 v31; // cx
  int v32; // edx
  float y; // [esp+20h] [ebp-C4h]
  float ya; // [esp+20h] [ebp-C4h]
  int v36; // [esp+34h] [ebp-B0h]
  float v37; // [esp+34h] [ebp-B0h]
  Scaleform::Render::GlyphFitter::VertexType v38; // [esp+34h] [ebp-B0h]
  float v39; // [esp+34h] [ebp-B0h]
  float v40; // [esp+34h] [ebp-B0h]
  Scaleform::Render::GlyphFitter::VertexType v41; // [esp+34h] [ebp-B0h]
  float v42; // [esp+34h] [ebp-B0h]
  float v43; // [esp+34h] [ebp-B0h]
  float v44; // [esp+38h] [ebp-ACh]
  float v45; // [esp+3Ch] [ebp-A8h]
  float v46; // [esp+3Ch] [ebp-A8h]
  float v47; // [esp+40h] [ebp-A4h]
  float v48; // [esp+40h] [ebp-A4h]
  unsigned int v49; // [esp+40h] [ebp-A4h]
  float x; // [esp+48h] [ebp-9Ch] BYREF
  float x2; // [esp+4Ch] [ebp-98h] BYREF
  float v53; // [esp+50h] [ebp-94h]
  float v54; // [esp+54h] [ebp-90h]
  float v55; // [esp+58h] [ebp-8Ch]
  int v56; // [esp+60h] [ebp-84h] BYREF
  _DWORD v57[12]; // [esp+64h] [ebp-80h] BYREF
  char v58; // [esp+94h] [ebp-50h]
  int v59; // [esp+98h] [ebp-4Ch] BYREF
  int v60; // [esp+9Ch] [ebp-48h] BYREF
  Scaleform::Render::ToleranceParams param; // [esp+A4h] [ebp-40h] BYREF

  v8 = this;
  p_Fitter = &this->Fitter;
  this->Fitter.Clear(&this->Fitter);
  if ( !shape->IsEmpty(shape) )
  {
    v10 = (int)(64.0 * screenSize);
    v36 = v10;
    if ( v10 > 2048 )
    {
      v10 = 2048;
      v36 = 2048;
    }
    v8->Fitter.NominalFontHeight = v10;
    v47 = (float)v36;
    v45 = v47 / (double)nomHeight;
    v48 = v47 * 0.5 / screenSize;
    Scaleform::Render::ToleranceParams::ToleranceParams(&param);
    GetStartingPos = shape->GetStartingPos;
    param.CurveTolerance = param.CurveTolerance * v48;
    param.CollinearityTolerance = v48 * param.CollinearityTolerance;
    v12 = GetStartingPos(shape);
    ReadPathInfo = shape->ReadPathInfo;
    *(float *)&v57[11] = 1.0;
    v14 = 0;
    v56 = v12;
    memset(v57, 0, 44);
    v58 = 0;
    HIBYTE(v44) = 1;
    v15 = ReadPathInfo(shape, (Scaleform::Render::ShapePosInfo *)&v56, &x, (unsigned int *)&v59);
    for ( i = v45; v15; i = v45 )
    {
      if ( !HIBYTE(v44) && v15 == 2 )
        break;
      HIBYTE(v44) = 0;
      if ( v59 == v60 )
      {
        ((void (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *, int *))shape->SkipPathData)(
          shape,
          &v56,
          a2);
      }
      else
      {
        x = x * i;
        v37 = -i;
        x2 = v37 * x2;
        Scaleform::Render::GlyphFitter::MoveTo(p_Fitter, x, x2);
        for ( j = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, int *, float *, int *))shape->ReadEdge)(
                    shape,
                    &v56,
                    &x,
                    a2); j; j = shape->ReadEdge(shape, (Scaleform::Render::ShapePosInfo *)v57, &x2) )
        {
          x2 = x2 * v48;
          v53 = v44 * v53;
          if ( j == Edge_LineTo )
          {
            Scaleform::Render::GlyphFitter::LineTo(p_Fitter, x2, v53);
          }
          else
          {
            v54 = v48 * v54;
            v55 = v44 * v55;
            Scaleform::Render::TessellateQuadCurve(
              p_Fitter,
              (Scaleform::Render::ToleranceParams *)&param.CurveTolerance,
              x2,
              v53,
              v54,
              v55);
          }
        }
        p_Fitter->ClosePath(p_Fitter);
      }
      a2 = &v60;
      v15 = ((int (__thiscall *)(const Scaleform::Render::ShapeDataInterface *, _DWORD *, float *))shape->ReadPathInfo)(
              shape,
              v57,
              &x2);
    }
    Scaleform::Render::GlyphFitter::FitGlyph(
      p_Fitter,
      (int)screenSize,
      0,
      (int)(i * (double)lowerCaseTop),
      (int)((double)upperCaseTop * i));
    v49 = 0;
    v46 = 1.0 / (double)v8->Fitter.UnitsPerPixelY;
    if ( v8->Fitter.Contours.Size )
    {
      v18 = v46;
      while ( 1 )
      {
        v19 = &v8->Fitter.Contours.Pages[v14 >> 2][v14 & 3];
        if ( v19->NumVertices > 2 )
        {
          MinY = p_Fitter->MinY;
          v38 = this->Fitter.Vertices.Pages[v19->StartVertex >> 4][v19->StartVertex & 0xF];
          v21 = v38.y - MinY;
          if ( v21 < 0 || v21 >= (signed int)p_Fitter->LerpRampY.Size )
            v22 = HIWORD(*(_DWORD *)&this->Fitter.Vertices.Pages[v19->StartVertex >> 4][v19->StartVertex & 0xF]);
          else
            v22 = MinY + p_Fitter->LerpRampY.Array[v21];
          MinX = p_Fitter->MinX;
          v24 = (__int16)this->Fitter.Vertices.Pages[v19->StartVertex >> 4][v19->StartVertex & 0xF];
          v25 = v38.x - MinX;
          if ( v25 >= 0 && v25 < (signed int)p_Fitter->LerpRampX.Size )
            v24 = MinX + p_Fitter->LerpRampX.Array[v25];
          p_Ras = &this->Ras;
          v39 = (double)-v22 * v18;
          y = v39;
          v40 = v18 * (double)v24 * stretch;
          Scaleform::Render::Rasterizer::MoveTo(&this->Ras, v40, y);
          for ( k = 1; k < v19->NumVertices; ++k )
          {
            v28 = p_Fitter->MinY;
            v41 = this->Fitter.Vertices.Pages[(k + v19->StartVertex) >> 4][(k + v19->StartVertex) & 0xF];
            v29 = v41.y - v28;
            if ( v29 < 0 || v29 >= (signed int)p_Fitter->LerpRampY.Size )
              v30 = HIWORD(*(_DWORD *)&this->Fitter.Vertices.Pages[(k + v19->StartVertex) >> 4][(k + v19->StartVertex)
                                                                                              & 0xF]);
            else
              v30 = v28 + p_Fitter->LerpRampY.Array[v29];
            v31 = (__int16)this->Fitter.Vertices.Pages[(k + v19->StartVertex) >> 4][(k + v19->StartVertex) & 0xF];
            v32 = v41.x - p_Fitter->MinX;
            if ( v32 >= 0 && v32 < (signed int)p_Fitter->LerpRampX.Size )
              v31 = p_Fitter->MinX + p_Fitter->LerpRampX.Array[v32];
            p_Ras = &this->Ras;
            v42 = (double)-v30 * v46;
            ya = v42;
            v43 = v46 * (double)v31 * stretch;
            Scaleform::Render::Rasterizer::LineTo(&this->Ras, v43, ya);
          }
          p_Ras->ClosePath(p_Ras);
          v18 = v46;
          v14 = v49;
        }
        v49 = ++v14;
        if ( v14 >= this->Fitter.Contours.Size )
          break;
        v8 = this;
      }
    }
    p_Fitter->Clear(p_Fitter);
  }
}
