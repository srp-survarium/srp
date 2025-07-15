void __thiscall Scaleform::Render::ShapeMeshProvider::createMorphData(Scaleform::Render::ShapeMeshProvider *this)
{
  Scaleform::Render::ShapeDataInterface *pObject; // esi
  unsigned int (__thiscall *GetFillStyleCount)(Scaleform::Render::ShapeDataInterface *); // eax
  int v4; // edi
  void (__thiscall *GetFillStyle)(Scaleform::Render::ShapeDataInterface *, unsigned int, Scaleform::Render::FillStyleType *); // edx
  Scaleform::RefCountVImpl *v6; // ecx
  void (__thiscall *v7)(Scaleform::Render::ShapeDataInterface *, unsigned int, Scaleform::Render::FillStyleType *); // eax
  int v8; // edi
  void (__thiscall *GetStrokeStyle)(Scaleform::Render::ShapeDataInterface *, unsigned int, Scaleform::Render::StrokeStyleType *); // edx
  void (__thiscall *v10)(Scaleform::Render::ShapeDataInterface *, unsigned int, Scaleform::Render::StrokeStyleType *); // eax
  unsigned int v11; // esi
  unsigned int v12; // eax
  Scaleform::Render::MorphShapeData *v13; // esi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData1; // esi
  unsigned int Size; // eax
  void **p_Data; // edi
  unsigned int v17; // ecx
  Scaleform::RefCountVImpl *v18; // ecx
  bool v19; // zf
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData2; // esi
  unsigned int v22; // eax
  void **v23; // edi
  unsigned int v24; // ecx
  Scaleform::RefCountVImpl *v25; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v26; // edi
  Scaleform::Render::ShapePathType v27; // esi
  Scaleform::Render::ShapePathType v28; // eax
  Scaleform::Render::MorphShapeData *v29; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v30; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v31; // ebp
  unsigned int v32; // esi
  bool *v33; // eax
  Scaleform::Render::MorphShapeData *v34; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v35; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v36; // ebp
  unsigned int v37; // esi
  bool *v38; // eax
  double v39; // st7
  Scaleform::Render::PathEdgeType v40; // esi
  Scaleform::Render::PathEdgeType v41; // eax
  Scaleform::Render::MorphShapeData *v42; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v43; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v44; // ebp
  unsigned int v45; // esi
  bool *v46; // eax
  Scaleform::Render::MorphShapeData *v47; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v48; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v49; // ebp
  unsigned int v50; // esi
  bool *v51; // eax
  Scaleform::Render::ShapeDataInterface *v52; // ecx
  Scaleform::Render::MorphShapeData *v53; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v54; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v55; // ebp
  unsigned int v56; // esi
  bool *v57; // edx
  Scaleform::Render::MorphShapeData *v58; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v59; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v60; // ebp
  unsigned int v61; // esi
  bool *v62; // edx
  Scaleform::Render::ShapeDataInterface *v63; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v64; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v65; // ebp
  unsigned int v66; // esi
  bool *v67; // eax
  Scaleform::Render::MorphShapeData *v68; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v69; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v70; // ebp
  unsigned int v71; // esi
  bool *v72; // eax
  Scaleform::Render::MorphShapeData *v73; // ebp
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus v74; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v75; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v76; // edi
  unsigned int v77; // esi
  bool *v78; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v79; // edi
  unsigned int v80; // esi
  bool *v81; // eax
  Scaleform::Render::MorphShapeData *v82; // ebx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus v83; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v84; // ebx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v85; // edi
  unsigned int v86; // esi
  bool *v87; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v88; // edi
  unsigned int v89; // esi
  Scaleform::Render::MorphShapeData *v90; // ebp
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus Status; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v92; // ebp
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v93; // edi
  unsigned int v94; // esi
  bool *v95; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v96; // edi
  unsigned int v97; // esi
  bool *v98; // eax
  Scaleform::Render::MorphShapeData *v99; // ebx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus v100; // eax
  Scaleform::Render::MorphShapeData *v101; // eax
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus v102; // ecx
  Scaleform::Render::ShapeDataInterface *v103; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v104; // edi
  unsigned int v105; // esi
  bool *v106; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *RefCount; // edi
  unsigned int v108; // esi
  bool *v109; // edx
  Scaleform::Render::ShapeDataInterface *v110; // eax
  Scaleform::Render::MorphShapeData *v111; // ebx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus v112; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v113; // edi
  unsigned int v114; // esi
  bool *v115; // eax
  Scaleform::ArrayLH<Scaleform::Render::FillStyleType,2,Scaleform::ArrayDefaultPolicy> *x; // [esp+58h] [ebp-160h]
  Scaleform::Render::FillStyleType fs2; // [esp+74h] [ebp-144h] BYREF
  Scaleform::Render::FillStyleType fs1; // [esp+7Ch] [ebp-13Ch] BYREF
  int v119; // [esp+84h] [ebp-134h]
  Scaleform::Render::ShapeDataInterface *morph1; // [esp+88h] [ebp-130h]
  Scaleform::Render::ShapeDataInterface *morph2; // [esp+8Ch] [ebp-12Ch]
  unsigned int styles1[3]; // [esp+90h] [ebp-128h] BYREF
  float coord2[6]; // [esp+9Ch] [ebp-11Ch] BYREF
  float coord1[6]; // [esp+B4h] [ebp-104h] BYREF
  Scaleform::Render::ShapePosInfo posInfo2; // [esp+CCh] [ebp-ECh] BYREF
  Scaleform::Render::ShapePosInfo posInfo1; // [esp+104h] [ebp-B4h] BYREF
  Scaleform::Render::ShapePosInfo prevPos1; // [esp+13Ch] [ebp-7Ch] BYREF
  unsigned int styles2[3]; // [esp+174h] [ebp-44h] BYREF
  Scaleform::Render::ShapePosInfo prevPos2; // [esp+180h] [ebp-38h] BYREF

  pObject = this->pShapeData.pObject;
  GetFillStyleCount = pObject->GetFillStyleCount;
  morph2 = this->pMorphData.pObject->pMorphTo.pObject;
  morph1 = pObject;
  if ( GetFillStyleCount(pObject) )
  {
    v4 = 1;
    do
    {
      GetFillStyle = pObject->GetFillStyle;
      fs1.pFill.pObject = 0;
      GetFillStyle(pObject, v4, &fs1);
      v6 = (Scaleform::RefCountVImpl *)fs1.pFill.pObject;
      if ( fs1.pFill.pObject )
      {
        if ( fs1.pFill.pObject->pGradient.pObject )
        {
          v7 = morph2->GetFillStyle;
          fs2.pFill.pObject = 0;
          v7(morph2, v4, &fs2);
          if ( !Scaleform::Render::GradientData::operator==(
                  fs1.pFill.pObject->pGradient.pObject,
                  fs2.pFill.pObject->pGradient.pObject) )
          {
            fs1.pFill.pObject->pGradient.pObject->pMorphTo = fs2.pFill.pObject->pGradient.pObject;
            this->GradientMorph = 1;
          }
          if ( fs2.pFill.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)fs2.pFill.pObject);
          v6 = (Scaleform::RefCountVImpl *)fs1.pFill.pObject;
        }
        if ( v6 )
          Scaleform::RefCountImpl::Release(v6);
      }
      ++v4;
    }
    while ( v4 - 1 < pObject->GetFillStyleCount(pObject) );
  }
  if ( pObject->GetStrokeStyleCount(pObject) )
  {
    v8 = 1;
    do
    {
      GetStrokeStyle = pObject->GetStrokeStyle;
      prevPos1.FillBase = 0;
      prevPos1.StrokeBase = 0;
      GetStrokeStyle(pObject, v8, (Scaleform::Render::StrokeStyleType *)&prevPos1);
      if ( prevPos1.FillBase && *(_DWORD *)(prevPos1.FillBase + 12) )
      {
        v10 = morph2->GetStrokeStyle;
        prevPos2.FillBase = 0;
        prevPos2.StrokeBase = 0;
        v10(morph2, v8, (Scaleform::Render::StrokeStyleType *)&prevPos2);
        if ( !Scaleform::Render::GradientData::operator==(
                *(Scaleform::Render::GradientData **)(prevPos1.FillBase + 12),
                *(const Scaleform::Render::GradientData **)(prevPos2.FillBase + 12)) )
        {
          *(_DWORD *)(*(_DWORD *)(prevPos1.FillBase + 12) + 20) = *(_DWORD *)(prevPos2.FillBase + 12);
          this->GradientMorph = 1;
        }
        if ( prevPos2.StrokeBase )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)prevPos2.StrokeBase);
        if ( prevPos2.FillBase )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)prevPos2.FillBase);
      }
      if ( prevPos1.StrokeBase )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)prevPos1.StrokeBase);
      if ( prevPos1.FillBase )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)prevPos1.FillBase);
      ++v8;
    }
    while ( v8 - 1 < pObject->GetStrokeStyleCount(pObject) );
  }
  v11 = pObject->GetStartingPos(pObject);
  v12 = morph2->GetStartingPos(morph2);
  posInfo1.Pos = v11;
  posInfo1.Sfactor = 1.0;
  v13 = this->pMorphData.pObject;
  posInfo2.Sfactor = 1.0;
  p_ShapeData1 = &v13->ShapeData1;
  memset(&posInfo1.StartX, 0, 44);
  posInfo1.Initialized = 0;
  posInfo2.Pos = v12;
  memset(&posInfo2.StartX, 0, 44);
  posInfo2.Initialized = 0;
  p_ShapeData1->Status = Status_Clean;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_ShapeData1->Fills.Data,
    &p_ShapeData1->Fills,
    0);
  Size = p_ShapeData1->Strokes.Data.Size;
  p_Data = (void **)&p_ShapeData1->Strokes.Data.Data;
  if ( Size )
  {
    v17 = (unsigned int)*p_Data + 28 * Size - 8;
    fs2.Color = v17;
    fs1.Color = Size;
    do
    {
      v18 = *(Scaleform::RefCountVImpl **)(v17 + 4);
      if ( v18 )
        Scaleform::RefCountImpl::Release(v18);
      if ( *(_DWORD *)fs2.Color )
        Scaleform::RefCountImpl::Release(*(Scaleform::RefCountVImpl **)fs2.Color);
      v17 = fs2.Color - 28;
      v19 = fs1.Color-- == 1;
      fs2.Color -= 28;
    }
    while ( !v19 );
    if ( (p_ShapeData1->Strokes.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( *p_Data )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *p_Data);
        *p_Data = 0;
      }
      p_ShapeData1->Strokes.Data.Policy.Capacity = 0;
    }
  }
  else if ( !p_ShapeData1->Strokes.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_ShapeData1->Strokes.Data,
      &p_ShapeData1->Strokes,
      0);
  }
  p_ShapeData1->Strokes.Data.Size = 0;
  Data = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_ShapeData1->Data;
  if ( Data->Size )
  {
    if ( (Data->Policy.Capacity & 0xFFFFFFFE) == 0 )
      goto LABEL_46;
  }
  else if ( Data->Policy.Capacity )
  {
    goto LABEL_46;
  }
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(Data, Data, 0);
LABEL_46:
  Data->Size = 0;
  p_ShapeData1->StartX = 0.0;
  p_ShapeData1->StartY = 0.0;
  p_ShapeData1->LastX = 0.0;
  p_ShapeData1->LastY = 0.0;
  p_ShapeData2 = &this->pMorphData.pObject->ShapeData2;
  x = &this->pMorphData.pObject->ShapeData2.Fills;
  p_ShapeData2->Status = Status_Clean;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_ShapeData2->Fills.Data,
    x,
    0);
  v22 = p_ShapeData2->Strokes.Data.Size;
  v23 = (void **)&p_ShapeData2->Strokes.Data.Data;
  if ( v22 )
  {
    v24 = (unsigned int)*v23 + 28 * v22 - 8;
    fs2.Color = v24;
    fs1.Color = v22;
    do
    {
      v25 = *(Scaleform::RefCountVImpl **)(v24 + 4);
      if ( v25 )
        Scaleform::RefCountImpl::Release(v25);
      if ( *(_DWORD *)fs2.Color )
        Scaleform::RefCountImpl::Release(*(Scaleform::RefCountVImpl **)fs2.Color);
      v24 = fs2.Color - 28;
      v19 = fs1.Color-- == 1;
      fs2.Color -= 28;
    }
    while ( !v19 );
    if ( (p_ShapeData2->Strokes.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
    {
      if ( *v23 )
      {
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v23);
        *v23 = 0;
      }
      p_ShapeData2->Strokes.Data.Policy.Capacity = 0;
    }
  }
  else if ( !p_ShapeData2->Strokes.Data.Policy.Capacity )
  {
    Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &p_ShapeData2->Strokes.Data,
      &p_ShapeData2->Strokes,
      0);
  }
  p_ShapeData2->Strokes.Data.Size = 0;
  v26 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)p_ShapeData2->Data;
  if ( v26->Size )
  {
    if ( (v26->Policy.Capacity & 0xFFFFFFFE) != 0 )
      goto LABEL_63;
  }
  else if ( !v26->Policy.Capacity )
  {
LABEL_63:
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(v26, v26, 0);
  }
  v26->Size = 0;
  p_ShapeData2->StartX = 0.0;
  HIBYTE(v119) = 1;
  p_ShapeData2->StartY = 0.0;
  p_ShapeData2->LastX = 0.0;
  p_ShapeData2->LastY = 0.0;
  while ( 1 )
  {
    v27 = morph1->ReadPathInfo(morph1, &posInfo1, coord1, styles1);
    v28 = morph2->ReadPathInfo(morph2, &posInfo2, coord2, styles2);
    if ( v27 == Shape_EndShape || v28 == Shape_EndShape )
      break;
    if ( v27 == Shape_NewLayer || HIBYTE(v119) )
    {
      v29 = this->pMorphData.pObject;
      v30 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v29->ShapeData1.Data;
      v31 = &v29->ShapeData1;
      v32 = v30->Size + 1;
      if ( v32 >= v30->Size )
      {
        if ( v32 >= v30->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v30,
            v30,
            v32 + (v32 >> 2));
      }
      else if ( v32 < v30->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v30,
          v30,
          v30->Size + 1);
      }
      v33 = v30->Data;
      v30->Size = v32;
      v33[v32 - 1] = 0;
      v31->Status = Status_StartLayer;
      v34 = this->pMorphData.pObject;
      v35 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v34->ShapeData2.Data;
      v36 = &v34->ShapeData2;
      v37 = v35->Size + 1;
      if ( v37 >= v35->Size )
      {
        if ( v37 >= v35->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v35,
            v35,
            v37 + (v37 >> 2));
      }
      else if ( v37 < v35->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v35,
          v35,
          v35->Size + 1);
      }
      v38 = v35->Data;
      v35->Size = v37;
      v38[v37 - 1] = 0;
      v36->Status = Status_StartLayer;
      HIBYTE(v119) = 0;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &this->pMorphData.pObject->ShapeData1,
      styles1[0],
      styles1[1],
      styles1[2]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &this->pMorphData.pObject->ShapeData2,
      styles1[0],
      styles1[1],
      styles1[2]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData1,
      coord1[0],
      coord1[1]);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData2,
      coord2[0],
      coord2[1]);
LABEL_81:
    *(float *)&fs1.Color = coord1[0];
    *(float *)&fs1.pFill.pObject = coord1[1];
LABEL_82:
    *(float *)&fs2.Color = coord2[0];
    v39 = coord2[1];
LABEL_83:
    *(float *)&fs2.pFill.pObject = v39;
    while ( 1 )
    {
      while ( 1 )
      {
        qmemcpy(&prevPos1, &posInfo1, sizeof(prevPos1));
        qmemcpy(&prevPos2, &posInfo2, sizeof(prevPos2));
        v40 = morph1->ReadEdge(morph1, &posInfo1, coord1);
        v41 = morph2->ReadEdge(morph2, &posInfo2, coord2);
        if ( v40 == Edge_EndPath )
          break;
        if ( v41 == Edge_EndPath )
        {
          v53 = this->pMorphData.pObject;
          qmemcpy(&posInfo1, &prevPos1, sizeof(posInfo1));
          v54 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v53->ShapeData1.Data;
          v55 = &v53->ShapeData1;
          v56 = v54->Size + 1;
          if ( v56 >= v54->Size )
          {
            if ( v56 >= v54->Policy.Capacity )
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v54,
                v54,
                v56 + (v56 >> 2));
          }
          else if ( v56 < v54->Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v54,
              v54,
              v54->Size + 1);
          }
          v57 = v54->Data;
          v54->Size = v56;
          v57[v56 - 1] = 6;
          v55->Status = Status_EndPath;
          v58 = this->pMorphData.pObject;
          v59 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v58->ShapeData2.Data;
          v60 = &v58->ShapeData2;
          v61 = v59->Size + 1;
          if ( v61 >= v59->Size )
          {
            if ( v61 >= v59->Policy.Capacity )
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v59,
                v59,
                v61 + (v61 >> 2));
          }
          else if ( v61 < v59->Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v59,
              v59,
              v59->Size + 1);
          }
          v62 = v59->Data;
          v63 = morph2;
          v59->Size = v61;
          v62[v61 - 1] = 6;
          v60->Status = Status_EndPath;
          if ( v63->ReadPathInfo(v63, &posInfo2, coord2, styles2) )
          {
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
              &this->pMorphData.pObject->ShapeData1,
              styles1[0],
              styles1[1],
              styles1[2]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
              &this->pMorphData.pObject->ShapeData2,
              styles1[0],
              styles1[1],
              styles1[2]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
              &this->pMorphData.pObject->ShapeData1,
              *(float *)&fs1.Color,
              *(float *)&fs1.pFill.pObject);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
              &this->pMorphData.pObject->ShapeData2,
              coord2[0],
              coord2[1]);
            goto LABEL_82;
          }
          v90 = this->pMorphData.pObject;
          Status = v90->ShapeData1.Status;
          v92 = &v90->ShapeData1;
          if ( Status != Status_EndShape && Status )
          {
            if ( Status != Status_EndPath )
            {
              v93 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v92->Data;
              v94 = v93->Size + 1;
              if ( v94 >= v93->Size )
              {
                if ( v94 >= v93->Policy.Capacity )
                  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                    v93,
                    v93,
                    v94 + (v94 >> 2));
              }
              else if ( v94 < v93->Policy.Capacity >> 1 )
              {
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  v93,
                  v93,
                  v93->Size + 1);
              }
              v95 = v93->Data;
              v93->Size = v94;
              v95[v94 - 1] = 6;
              v92->Status = Status_EndPath;
            }
            v96 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v92->Data;
            v97 = v96->Size + 1;
            if ( v97 >= v96->Size )
            {
              if ( v97 >= v96->Policy.Capacity )
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  v96,
                  v96,
                  v97 + (v97 >> 2));
            }
            else if ( v97 < v96->Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v96,
                v96,
                v96->Size + 1);
            }
            v98 = v96->Data;
            v96->Size = v97;
            v98[v97 - 1] = 7;
            v92->Status = Status_EndShape;
          }
          v99 = this->pMorphData.pObject;
          v100 = v99->ShapeData2.Status;
          v84 = &v99->ShapeData2;
          if ( v100 != Status_EndShape && v100 )
          {
            if ( v100 != Status_EndPath )
              Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v84);
            goto LABEL_160;
          }
          return;
        }
        if ( v40 != v41 )
        {
          if ( v40 == Edge_LineTo )
          {
            if ( v41 != Edge_QuadTo )
            {
LABEL_119:
              Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                &this->pMorphData.pObject->ShapeData1,
                coord1[0],
                coord1[1]);
              Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                &this->pMorphData.pObject->ShapeData2,
                coord2[0],
                coord2[1]);
              goto LABEL_81;
            }
            coord1[2] = coord1[0];
            coord1[3] = coord1[1];
            coord1[0] = (coord1[0] + *(float *)&fs1.Color) * 0.5;
            coord1[1] = 0.5 * (coord1[1] + *(float *)&fs1.pFill.pObject);
            goto LABEL_121;
          }
          if ( v40 == Edge_QuadTo )
          {
            if ( v41 == Edge_LineTo )
            {
              coord2[2] = coord2[0];
              coord2[3] = coord2[1];
              coord2[0] = (coord2[0] + *(float *)&fs2.Color) * 0.5;
              coord2[1] = 0.5 * (coord2[1] + *(float *)&fs2.pFill.pObject);
            }
LABEL_121:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &this->pMorphData.pObject->ShapeData1,
              coord1[0],
              coord1[1],
              coord1[2],
              coord1[3]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &this->pMorphData.pObject->ShapeData2,
              coord2[0],
              coord2[1],
              coord2[2],
              coord2[3]);
            *(float *)&fs1.Color = coord1[2];
            *(float *)&fs1.pFill.pObject = coord1[3];
            *(float *)&fs2.Color = coord2[2];
            v39 = coord2[3];
            goto LABEL_83;
          }
        }
        switch ( v40 )
        {
          case Edge_LineTo:
            goto LABEL_119;
          case Edge_QuadTo:
            goto LABEL_121;
          case Edge_CubicTo:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &this->pMorphData.pObject->ShapeData1,
              coord1[0],
              coord1[1],
              coord1[2],
              coord1[3],
              coord1[4],
              coord1[5]);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &this->pMorphData.pObject->ShapeData2,
              coord2[0],
              coord2[1],
              coord2[2],
              coord2[3],
              coord2[4],
              coord2[5]);
            *(float *)&fs1.Color = coord1[4];
            *(float *)&fs1.pFill.pObject = coord1[5];
            *(float *)&fs2.Color = coord2[4];
            v39 = coord2[5];
            goto LABEL_83;
        }
      }
      v42 = this->pMorphData.pObject;
      if ( v41 == Edge_EndPath )
        break;
      qmemcpy(&posInfo2, &prevPos2, sizeof(posInfo2));
      v43 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v42->ShapeData1.Data;
      v44 = &v42->ShapeData1;
      v45 = v43->Size + 1;
      if ( v45 >= v43->Size )
      {
        if ( v45 >= v43->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v43,
            v43,
            v45 + (v45 >> 2));
      }
      else if ( v45 < v43->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v43,
          v43,
          v43->Size + 1);
      }
      v46 = v43->Data;
      v43->Size = v45;
      v46[v45 - 1] = 6;
      v44->Status = Status_EndPath;
      v47 = this->pMorphData.pObject;
      v48 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v47->ShapeData2.Data;
      v49 = &v47->ShapeData2;
      v50 = v48->Size + 1;
      if ( v50 >= v48->Size )
      {
        if ( v50 >= v48->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v48,
            v48,
            v50 + (v50 >> 2));
      }
      else if ( v50 < v48->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v48,
          v48,
          v48->Size + 1);
      }
      v51 = v48->Data;
      v52 = morph1;
      v48->Size = v50;
      v51[v50 - 1] = 6;
      v49->Status = Status_EndPath;
      if ( v52->ReadPathInfo(v52, &posInfo1, coord1, styles1) == Shape_EndShape )
      {
        v73 = this->pMorphData.pObject;
        v74 = v73->ShapeData1.Status;
        v75 = &v73->ShapeData1;
        if ( v74 != Status_EndShape && v74 )
        {
          if ( v74 != Status_EndPath )
          {
            v76 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v75->Data;
            v77 = v76->Size + 1;
            if ( v77 >= v76->Size )
            {
              if ( v77 >= v76->Policy.Capacity )
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  v76,
                  v76,
                  v77 + (v77 >> 2));
            }
            else if ( v77 < v76->Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v76,
                v76,
                v76->Size + 1);
            }
            v78 = v76->Data;
            v76->Size = v77;
            v78[v77 - 1] = 6;
            v75->Status = Status_EndPath;
          }
          v79 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v75->Data;
          v80 = v79->Size + 1;
          if ( v80 >= v79->Size )
          {
            if ( v80 >= v79->Policy.Capacity )
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v79,
                v79,
                v80 + (v80 >> 2));
          }
          else if ( v80 < v79->Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v79,
              v79,
              v79->Size + 1);
          }
          v81 = v79->Data;
          v79->Size = v80;
          v81[v80 - 1] = 7;
          v75->Status = Status_EndShape;
        }
        v82 = this->pMorphData.pObject;
        v83 = v82->ShapeData2.Status;
        v84 = &v82->ShapeData2;
        if ( v83 != Status_EndShape && v83 )
        {
          if ( v83 != Status_EndPath )
          {
            v85 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v84->Data;
            v86 = v85->Size + 1;
            if ( v86 >= v85->Size )
            {
              if ( v86 >= v85->Policy.Capacity )
                Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  v85,
                  v85,
                  v86 + (v86 >> 2));
            }
            else if ( v86 < v85->Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                v85,
                v85,
                v85->Size + 1);
            }
            v87 = v85->Data;
            v85->Size = v86;
            v87[v86 - 1] = 6;
            goto LABEL_159;
          }
          goto LABEL_160;
        }
        return;
      }
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        &this->pMorphData.pObject->ShapeData1,
        styles1[0],
        styles1[1],
        styles1[2]);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        &this->pMorphData.pObject->ShapeData2,
        styles1[0],
        styles1[1],
        styles1[2]);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
        &this->pMorphData.pObject->ShapeData1,
        coord1[0],
        coord1[1]);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
        &this->pMorphData.pObject->ShapeData2,
        *(float *)&fs2.Color,
        *(float *)&fs2.pFill.pObject);
      *(float *)&fs1.Color = coord1[0];
      *(float *)&fs1.pFill.pObject = coord1[1];
    }
    v64 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v42->ShapeData1.Data;
    v65 = &v42->ShapeData1;
    v66 = v64->Size + 1;
    if ( v66 >= v64->Size )
    {
      if ( v66 >= v64->Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v64,
          v64,
          v66 + (v66 >> 2));
    }
    else if ( v66 < v64->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v64,
        v64,
        v64->Size + 1);
    }
    v67 = v64->Data;
    v64->Size = v66;
    v67[v66 - 1] = 6;
    v65->Status = Status_EndPath;
    v68 = this->pMorphData.pObject;
    v69 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v68->ShapeData2.Data;
    v70 = &v68->ShapeData2;
    v71 = v69->Size + 1;
    if ( v71 >= v69->Size )
    {
      if ( v71 >= v69->Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v69,
          v69,
          v71 + (v71 >> 2));
    }
    else if ( v71 < v69->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v69,
        v69,
        v69->Size + 1);
    }
    v72 = v69->Data;
    v69->Size = v71;
    v72[v71 - 1] = 6;
    v70->Status = Status_EndPath;
  }
  v101 = this->pMorphData.pObject;
  v102 = v101->ShapeData1.Status;
  v103 = &v101->ShapeData1;
  morph1 = v103;
  if ( v102 != Status_EndShape && v102 )
  {
    if ( v102 == Status_EndPath )
    {
LABEL_192:
      RefCount = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)morph1[4].RefCount;
      v108 = RefCount->Size + 1;
      if ( v108 >= RefCount->Size )
      {
        if ( v108 >= RefCount->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            RefCount,
            RefCount,
            v108 + (v108 >> 2));
      }
      else if ( v108 < RefCount->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          RefCount,
          RefCount,
          RefCount->Size + 1);
      }
      v109 = RefCount->Data;
      v110 = morph1;
      RefCount->Size = v108;
      v109[v108 - 1] = 7;
      v110[1].__vftable = (Scaleform::Render::ShapeDataInterface_vtbl *)6;
      goto LABEL_198;
    }
    v104 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v103[4].RefCount;
    v105 = v104->Size + 1;
    if ( v105 >= v104->Size )
    {
      if ( v105 >= v104->Policy.Capacity )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v104,
          v104,
          v105 + (v105 >> 2));
        goto LABEL_190;
      }
    }
    else if ( v105 < v104->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v104,
        v104,
        v104->Size + 1);
LABEL_190:
      v103 = morph1;
    }
    v106 = v104->Data;
    v104->Size = v105;
    v106[v105 - 1] = 6;
    v103[1].__vftable = (Scaleform::Render::ShapeDataInterface_vtbl *)5;
    goto LABEL_192;
  }
LABEL_198:
  v111 = this->pMorphData.pObject;
  v112 = v111->ShapeData2.Status;
  v84 = &v111->ShapeData2;
  if ( v112 != Status_EndShape && v112 )
  {
    if ( v112 != Status_EndPath )
    {
      v113 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v84->Data;
      v114 = v113->Size + 1;
      if ( v114 >= v113->Size )
      {
        if ( v114 >= v113->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v113,
            v113,
            v114 + (v114 >> 2));
      }
      else if ( v114 < v113->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v113,
          v113,
          v113->Size + 1);
      }
      v115 = v113->Data;
      v113->Size = v114;
      v115[v114 - 1] = 6;
LABEL_159:
      v84->Status = Status_EndPath;
    }
LABEL_160:
    v88 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v84->Data;
    v89 = v88->Size + 1;
    if ( v89 >= v88->Size )
    {
      if ( v89 >= v88->Policy.Capacity )
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v88,
          v88,
          v89 + (v89 >> 2));
    }
    else if ( v89 < v88->Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v88,
        v88,
        v88->Size + 1);
    }
    v88->Size = v89;
    v88->Data[v89 - 1] = 7;
    v84->Status = Status_EndShape;
  }
}
