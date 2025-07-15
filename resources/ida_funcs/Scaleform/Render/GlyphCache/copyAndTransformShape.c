void __thiscall Scaleform::Render::GlyphCache::copyAndTransformShape(
        Scaleform::Render::GlyphCache *this,
        Scaleform::Render::VectorGlyphShape *glyphShape,
        const Scaleform::Render::ShapeDataInterface *srcShape,
        bool fauxBold,
        bool fauxItalic,
        unsigned int outline,
        float italicOffset,
        float nominalSize)
{
  bool (__thiscall *IsEmpty)(Scaleform::Render::ShapeDataInterface *); // edx
  Scaleform::Render::GlyphCache *v9; // esi
  unsigned int v10; // eax
  Scaleform::Render::ShapePathType k; // esi
  unsigned int v12; // ebx
  Scaleform::Render::PathEdgeType m; // eax
  double v14; // st7
  Scaleform::Render::GlyphShape *v15; // eax
  double v16; // st7
  Scaleform::Render::GlyphShape *v17; // eax
  double v18; // st7
  Scaleform::Render::GlyphShape *v19; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v20; // ecx
  char isOuterContourCW; // al
  Scaleform::Render::Stroker_vtbl *v22; // edx
  double v23; // st7
  Scaleform::Render::ShapePathType (__thiscall *ReadPathInfo)(Scaleform::Render::ShapeDataInterface *, Scaleform::Render::ShapePosInfo *, float *, unsigned int *); // edx
  Scaleform::Render::ShapePathType i; // eax
  Scaleform::Render::PathEdgeType j; // eax
  _DWORD *v27; // ecx
  double OutlineRatio; // st7
  bool v29; // zf
  float v30; // eax
  Scaleform::Render::PathBasic *v31; // ebx
  unsigned int v32; // edi
  Scaleform::Render::VertexBasic *v33; // edx
  float v34; // eax
  _DWORD *v35; // edi
  int v36; // edx
  Scaleform::Render::GlyphShape *pObject; // ecx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // esi
  int v39; // eax
  unsigned int Size; // eax
  unsigned int v41; // ebx
  unsigned __int8 *Data; // edx
  unsigned int v43; // eax
  unsigned int v44; // ebx
  unsigned __int8 *v45; // edx
  unsigned int v46; // eax
  unsigned int v47; // ebx
  unsigned __int8 *v48; // edx
  double v49; // st7
  int v50; // ebx
  float *p_x; // edi
  Scaleform::Render::GlyphShape *v52; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v53; // ecx
  int v54; // esi
  int v55; // eax
  int v56; // edi
  Scaleform::Render::GlyphShape *v57; // eax
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v58; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v59; // edi
  unsigned int v60; // esi
  bool *v61; // ecx
  Scaleform::Render::GlyphShape *v62; // eax
  double Multiplier; // st7
  float param_60b; // [esp+E8Ch] [ebp-164h]
  float param_60c; // [esp+E8Ch] [ebp-164h]
  float param_60d; // [esp+E8Ch] [ebp-164h]
  int param_60; // [esp+E8Ch] [ebp-164h]
  int param_60a; // [esp+E8Ch] [ebp-164h]
  int v69; // [esp+E90h] [ebp-160h]
  int v70; // [esp+E94h] [ebp-15Ch]
  Scaleform::Render::TessBase *v71; // [esp+E98h] [ebp-158h]
  float v72; // [esp+EA4h] [ebp-14Ch]
  float v73; // [esp+EA4h] [ebp-14Ch]
  float v74; // [esp+EA4h] [ebp-14Ch]
  float v75; // [esp+EA4h] [ebp-14Ch]
  float v76; // [esp+EA4h] [ebp-14Ch]
  float v77; // [esp+EA4h] [ebp-14Ch]
  float v78; // [esp+EA4h] [ebp-14Ch]
  float v79; // [esp+EA4h] [ebp-14Ch]
  float v80; // [esp+EA4h] [ebp-14Ch]
  float v81; // [esp+EA4h] [ebp-14Ch]
  float v82; // [esp+EA4h] [ebp-14Ch]
  float v83; // [esp+EA4h] [ebp-14Ch]
  _DWORD *v84; // [esp+EA4h] [ebp-14Ch]
  char v85; // [esp+EABh] [ebp-145h]
  float x; // [esp+EACh] [ebp-144h] BYREF
  float y; // [esp+EB0h] [ebp-140h] BYREF
  float v88; // [esp+EB4h] [ebp-13Ch]
  float v89; // [esp+EB8h] [ebp-138h]
  float v90; // [esp+EC4h] [ebp-12Ch]
  float v91; // [esp+EC8h] [ebp-128h]
  int v92; // [esp+ECCh] [ebp-124h]
  Scaleform::Render::Matrix2x4<float> v93; // [esp+ED0h] [ebp-120h] BYREF
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v94; // [esp+EF4h] [ebp-FCh] BYREF
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v95; // [esp+EFCh] [ebp-F4h] BYREF
  Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v96; // [esp+F04h] [ebp-ECh] BYREF
  int v97; // [esp+F0Ch] [ebp-E4h]
  Scaleform::Render::VertexPath *p_TmpPath1; // [esp+F10h] [ebp-E0h]
  unsigned int leftStyle; // [esp+F14h] [ebp-DCh] BYREF
  unsigned int rightStyle; // [esp+F18h] [ebp-D8h]
  unsigned int strokeStyle; // [esp+F1Ch] [ebp-D4h]
  unsigned int v102; // [esp+F20h] [ebp-D0h]
  Scaleform::Render::TessBase con; // [esp+F24h] [ebp-CCh] BYREF
  Scaleform::Render::Stroker *p_mStroker; // [esp+F28h] [ebp-C8h]
  float v105; // [esp+F2Ch] [ebp-C4h]
  float v106; // [esp+F30h] [ebp-C0h]
  float v107; // [esp+F34h] [ebp-BCh]
  float v108; // [esp+F38h] [ebp-B8h]
  Scaleform::Render::ShapePosInfo pos; // [esp+F3Ch] [ebp-B4h] BYREF
  Scaleform::Render::GlyphCache *v110; // [esp+F74h] [ebp-7Ch]
  _DWORD v111[13]; // [esp+F78h] [ebp-78h] BYREF
  char v112; // [esp+FACh] [ebp-44h]
  Scaleform::Render::ToleranceParams param; // [esp+FB0h] [ebp-40h] BYREF
  int savedregs; // [esp+FF0h] [ebp+0h] BYREF

  IsEmpty = srcShape->IsEmpty;
  v9 = this;
  v110 = this;
  if ( !IsEmpty(srcShape) )
  {
    v72 = nominalSize * 0.015625;
    Scaleform::Render::ToleranceParams::ToleranceParams(&param);
    param.CurveTolerance = param.CurveTolerance * v72;
    param.CollinearityTolerance = v72 * param.CollinearityTolerance;
    v93.M[0][0] = 1.0;
    v93.M[0][1] = 0.0;
    v93.M[0][2] = 0.0;
    v93.M[0][3] = 0.0;
    v93.M[1][0] = 0.0;
    v93.M[1][2] = 0.0;
    v93.M[1][3] = 0.0;
    v93.M[1][1] = 1.0;
    if ( fauxItalic )
    {
      v93.M[0][3] = 0.0 + 0.0;
      v93.M[1][3] = italicOffset + 0.0;
      param_60b = -v9->Param.FauxItalicAngle;
      Scaleform::Render::Matrix2x4<float>::AppendShearing(&v93, 0.0, param_60b);
      v93.M[0][3] = v93.M[0][3] + 0.0;
      v93.M[1][3] = v93.M[1][3] - italicOffset;
    }
    v10 = srcShape->GetStartingPos(srcShape);
    *(float *)&v111[12] = 1.0;
    pos.Sfactor = 1.0;
    v111[0] = v10;
    memset(&v111[1], 0, 44);
    v112 = 0;
    memset(&pos, 0, 48);
    pos.Initialized = 0;
    v85 = 1;
    if ( fauxBold || *(float *)&outline != 0.0 )
    {
      isOuterContourCW = Scaleform::Render::GlyphCache::isOuterContourCW(v9, (unsigned int *)v9, srcShape);
      v22 = v9->mStroker.__vftable;
      HIBYTE(v90) = isOuterContourCW;
      v22->Clear(&v9->mStroker);
      v9->TmpPath1.Clear(&v9->TmpPath1);
      if ( fauxBold )
        v23 = v9->Param.FauxBoldRatio * nominalSize;
      else
        v23 = 0.0;
      v75 = v23;
      v9->mStroker.Width = v75 * 0.5;
      ReadPathInfo = srcShape->ReadPathInfo;
      v105 = 1.0;
      v106 = 1000.0;
      con.__vftable = (Scaleform::Render::TessBase_vtbl *)&Scaleform::Render::StrokeScaler::`vftable';
      p_mStroker = &v9->mStroker;
      v107 = 0.0;
      v108 = 0.0;
      for ( i = ReadPathInfo(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x, &leftStyle);
            i;
            i = srcShape->ReadPathInfo(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x, &leftStyle) )
      {
        if ( !v85 && i == Shape_NewLayer )
          break;
        v85 = 0;
        if ( leftStyle == rightStyle )
        {
          srcShape->SkipPathData(srcShape, (Scaleform::Render::ShapePosInfo *)v111);
        }
        else
        {
          v76 = x;
          x = x * v93.M[0][0] + v93.M[0][1] * y + v93.M[0][3];
          y = y * v93.M[1][1] + v93.M[1][0] * v76 + v93.M[1][3];
          v107 = x;
          v108 = y;
          v77 = y * v106;
          param_60c = v77;
          v78 = x * v105;
          ((void (__thiscall *)(Scaleform::Render::Stroker *, _DWORD, _DWORD))p_mStroker->AddVertex)(
            p_mStroker,
            LODWORD(v78),
            LODWORD(param_60c));
          for ( j = srcShape->ReadEdge(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x);
                j;
                j = srcShape->ReadEdge(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x) )
          {
            v79 = x;
            x = x * v93.M[0][0] + v93.M[0][1] * y + v93.M[0][3];
            y = y * v93.M[1][1] + v93.M[1][0] * v79 + v93.M[1][3];
            if ( j == Edge_LineTo )
            {
              v107 = x;
              v108 = y;
              v80 = y * v106;
              param_60d = v80;
              v81 = x * v105;
              ((void (__thiscall *)(Scaleform::Render::Stroker *, _DWORD, _DWORD))p_mStroker->AddVertex)(
                p_mStroker,
                LODWORD(v81),
                LODWORD(param_60d));
            }
            else
            {
              v82 = v88;
              v88 = v93.M[0][3] + v93.M[0][0] * v88 + v93.M[0][1] * v89;
              v89 = v93.M[1][3] + v93.M[1][1] * v89 + v93.M[1][0] * v82;
              Scaleform::Render::TessellateQuadCurve(&con, &param, x, y, v88, v89);
            }
          }
          v9->mStroker.ClosePath(&v9->mStroker);
          Scaleform::Render::Stroker::CalcEquidistant(&v9->mStroker, &v9->TmpPath1, HIBYTE(v90) == 0);
        }
      }
      Scaleform::Render::VertexPath::Scale(&v9->TmpPath1, 1.0, 0.001);
      v27 = &v9->TmpPath1.__vftable;
      p_TmpPath1 = &v9->TmpPath1;
      if ( *(float *)&outline != 0.0 )
      {
        v9->TmpPath2.Clear(&v9->TmpPath2);
        v9->mStroker.Clear(&v9->mStroker);
        OutlineRatio = v9->Param.OutlineRatio;
        v102 = outline;
        v29 = v9->TmpPath1.Paths.Size == 0;
        v9->mStroker.LineJoin = MiterJoin;
        v91 = 0.0;
        v83 = OutlineRatio * (double)outline * nominalSize;
        v9->mStroker.Width = v83 * 0.5;
        if ( !v29 )
        {
          v30 = v91;
          do
          {
            v31 = &v9->TmpPath1.Paths.Pages[LODWORD(v30) >> 2][LOBYTE(v30) & 3];
            if ( v31->Count > 2 )
            {
              v32 = 0;
              do
              {
                v33 = v9->TmpPath1.Vertices.Pages[(v32 + v31->Start) >> 4];
                ((void (__thiscall *)(int, _DWORD, _DWORD))v9->mStroker.AddVertex)(
                  &v9->mStroker,
                  v33[(v32 + v31->Start) & 0xF].x,
                  v33[(v32 + v31->Start) & 0xF].y);
                ++v32;
              }
              while ( v32 < v31->Count );
              v9->mStroker.ClosePath(&v9->mStroker);
              Scaleform::Render::Stroker::GenerateStroke(
                &v9->mStroker,
                (int)v31,
                (int)&savedregs,
                COERCE_FLOAT((Scaleform::Render::GlyphCache *)&v9->mStroker),
                &v9->TmpPath2,
                v69,
                v70,
                v71);
              v30 = v91;
            }
            ++LODWORD(v30);
            v91 = v30;
          }
          while ( LODWORD(v30) < v9->TmpPath1.Paths.Size );
        }
        v27 = &v9->TmpPath2.__vftable;
        p_TmpPath1 = &v9->TmpPath2;
      }
      v34 = 0.0;
      v97 = 0;
      v91 = 0.0;
      if ( v27[7] )
      {
        do
        {
          v35 = (_DWORD *)(*(_DWORD *)(v27[10] + 4 * (LODWORD(v34) >> 2)) + 8 * (LOBYTE(v34) & 3));
          v84 = v35;
          if ( v35[1] > 2u )
          {
            v36 = *(_DWORD *)(v27[5] + 4 * (*v35 >> 4));
            pObject = glyphShape->pShape.pObject;
            pContainer = pObject->pContainer;
            v39 = *v35 & 0xF;
            v92 = *(int *)(v36 + 8 * v39);
            v102 = *(unsigned int *)(v36 + 8 * v39 + 4);
            v95.Multiplier = pObject->Multiplier;
            v95.Encoder.Data = pContainer;
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
              &v95.Encoder,
              2 - (v97 != 0));
            Size = pContainer->Data.Size;
            v41 = Size + 1;
            if ( Size + 1 >= Size )
            {
              if ( v41 >= pContainer->Data.Policy.Capacity )
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
                  pContainer,
                  v41 + (v41 >> 2));
            }
            else if ( v41 < pContainer->Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
                pContainer,
                v41);
            }
            Data = pContainer->Data.Data;
            pContainer->Data.Size = v41;
            Data[v41 - 1] = 4;
            v43 = pContainer->Data.Size;
            v44 = v43 + 1;
            if ( v43 + 1 >= v43 )
            {
              if ( v44 >= pContainer->Data.Policy.Capacity )
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
                  pContainer,
                  v44 + (v44 >> 2));
            }
            else if ( v44 < pContainer->Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
                pContainer,
                v44);
            }
            v45 = pContainer->Data.Data;
            pContainer->Data.Size = v44;
            v45[v44 - 1] = 0;
            v46 = pContainer->Data.Size;
            v47 = v46 + 1;
            if ( v46 + 1 >= v46 )
            {
              if ( v47 >= pContainer->Data.Policy.Capacity )
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
                  pContainer,
                  v47 + (v47 >> 2));
            }
            else if ( v47 < pContainer->Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
                pContainer,
                v47);
            }
            v48 = pContainer->Data.Data;
            v49 = v95.Multiplier * *(float *)&v92;
            pContainer->Data.Size = v47;
            v48[v47 - 1] = 0;
            v50 = (int)v49;
            pos.StartX = (int)v49;
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
              &v95.Encoder,
              (int)v49);
            pos.LastY = (int)(v95.Multiplier * *(float *)&v102);
            pos.StartY = pos.LastY;
            Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
              &v95.Encoder,
              pos.LastY);
            v92 = 1;
            if ( v35[1] > 1u )
            {
              do
              {
                p_x = &p_TmpPath1->Vertices.Pages[(unsigned int)(v92 + *v84) >> 4][(v92 + *v84) & 0xF].x;
                v52 = glyphShape->pShape.pObject;
                v53 = v52->pContainer;
                v96.Multiplier = v52->Multiplier;
                v96.Encoder.Data = v53;
                v54 = (int)(v96.Multiplier * *p_x) - v50;
                v55 = (int)(v96.Multiplier * p_x[1]);
                v56 = v55 - pos.LastY;
                if ( v55 == pos.LastY )
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v96.Encoder,
                    v54);
                }
                else
                {
                  param_60 = v55 - pos.LastY;
                  if ( v54 )
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                      &v96.Encoder,
                      v54,
                      param_60);
                  else
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                      &v96.Encoder,
                      param_60);
                }
                pos.LastY += v56;
                v50 += v54;
                ++v92;
              }
              while ( (unsigned int)v92 < v84[1] );
            }
            v57 = glyphShape->pShape.pObject;
            v58 = v57->pContainer;
            v94.Multiplier = v57->Multiplier;
            v94.Encoder.Data = v58;
            if ( v50 != pos.StartX || pos.LastY != pos.StartY )
            {
              if ( pos.StartY == pos.LastY )
              {
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                  &v94.Encoder,
                  pos.StartX - v50);
              }
              else
              {
                param_60a = pos.StartY - pos.LastY;
                if ( pos.StartX == v50 )
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                    &v94.Encoder,
                    param_60a);
                else
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                    &v94.Encoder,
                    pos.StartX - v50,
                    param_60a);
              }
            }
            v59 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)glyphShape->pShape.pObject->pContainer;
            v60 = v59->Size + 1;
            if ( v60 >= v59->Size )
            {
              if ( v60 >= v59->Policy.Capacity )
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  v59,
                  v59,
                  v60 + (v60 >> 2));
            }
            else if ( v60 < v59->Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v59,
                v59,
                v59->Size + 1);
            }
            v61 = v59->Data;
            ++v97;
            v34 = v91;
            v59->Size = v60;
            v61[v60 - 1] = 15;
            v27 = &p_TmpPath1->__vftable;
            v9 = v110;
          }
          ++LODWORD(v34);
          v91 = v34;
        }
        while ( LODWORD(v34) < v27[7] );
      }
      v62 = glyphShape->pShape.pObject;
      Multiplier = v62->Multiplier;
      v94.Encoder.Data = v62->pContainer;
      v94.Multiplier = Multiplier;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        &v94.Encoder,
        0);
      v9->mStroker.Clear(&v9->mStroker);
      v9->TmpPath1.Clear(&v9->TmpPath1);
      v9->TmpPath2.Clear(&v9->TmpPath2);
      Scaleform::Render::LinearHeap::ClearAndRelease(&v9->LHeap1);
      Scaleform::Render::LinearHeap::ClearAndRelease(&v9->LHeap2);
    }
    else
    {
      for ( k = srcShape->ReadPathInfo(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x, &leftStyle);
            k;
            k = srcShape->ReadPathInfo(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x, &leftStyle) )
      {
        if ( !v85 && k == Shape_NewLayer )
          break;
        v12 = leftStyle;
        v85 = 0;
        if ( leftStyle == rightStyle )
        {
          srcShape->SkipPathData(srcShape, (Scaleform::Render::ShapePosInfo *)v111);
        }
        else
        {
          Scaleform::Render::Matrix2x4<float>::Transform(&v93, &x, &y);
          Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
            glyphShape->pShape.pObject,
            &pos,
            k,
            v12,
            rightStyle,
            strokeStyle,
            x,
            y);
          for ( m = srcShape->ReadEdge(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x);
                m;
                m = srcShape->ReadEdge(srcShape, (Scaleform::Render::ShapePosInfo *)v111, &x) )
          {
            v14 = x;
            v73 = x;
            if ( m == Edge_LineTo )
            {
              v15 = glyphShape->pShape.pObject;
              x = v14 * v93.M[0][0] + v93.M[0][1] * y + v93.M[0][3];
              y = y * v93.M[1][1] + v93.M[1][0] * v73 + v93.M[1][3];
              v16 = v15->Multiplier;
              v94.Encoder.Data = v15->pContainer;
              v94.Multiplier = v16;
              Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                &v94,
                &pos,
                x,
                y);
            }
            else
            {
              v17 = glyphShape->pShape.pObject;
              x = v14 * v93.M[0][0] + v93.M[0][1] * y + v93.M[0][3];
              y = y * v93.M[1][1] + v93.M[1][0] * v73 + v93.M[1][3];
              v74 = v88;
              v88 = v93.M[0][3] + v93.M[0][0] * v88 + v93.M[0][1] * v89;
              v89 = v93.M[1][3] + v93.M[1][0] * v74 + v93.M[1][1] * v89;
              v18 = v17->Multiplier;
              v96.Encoder.Data = v17->pContainer;
              v96.Multiplier = v18;
              Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
                &v96,
                &pos,
                x,
                y,
                v88,
                v89);
            }
          }
          v19 = glyphShape->pShape.pObject;
          v20 = v19->pContainer;
          v95.Multiplier = v19->Multiplier;
          v95.Encoder.Data = v20;
          Scaleform::Render::ShapeDataPackedEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::ClosePath(
            &v95,
            &pos);
          Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(glyphShape->pShape.pObject);
        }
      }
      Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(glyphShape->pShape.pObject);
    }
  }
}
