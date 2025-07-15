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
  int v11; // esi
  int v12; // eax
  Scaleform::Render::MorphShapeData *v13; // esi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData1; // esi
  float v15; // eax
  void **p_Data; // edi
  int v17; // ecx
  Scaleform::RefCountVImpl *v18; // ecx
  bool v19; // zf
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *Data; // edi
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *p_ShapeData2; // esi
  float v22; // eax
  void **v23; // edi
  int v24; // ecx
  Scaleform::RefCountVImpl *v25; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v26; // edi
  int v27; // esi
  int v28; // eax
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
  int v40; // esi
  int v41; // eax
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
  _DWORD *v52; // ecx
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
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v103; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v104; // edi
  unsigned int v105; // esi
  bool *v106; // ecx
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v107; // edi
  unsigned int v108; // esi
  bool *v109; // edx
  _DWORD *v110; // eax
  Scaleform::Render::MorphShapeData *v111; // ebx
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::DataStatus v112; // eax
  Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *v113; // edi
  unsigned int v114; // esi
  bool *v115; // eax
  Scaleform::ArrayLH<Scaleform::Render::FillStyleType,2,Scaleform::ArrayDefaultPolicy> *x; // [esp+58h] [ebp-160h]
  float v117; // [esp+74h] [ebp-144h] BYREF
  Scaleform::RefCountVImpl *v118; // [esp+78h] [ebp-140h]
  float v119; // [esp+7Ch] [ebp-13Ch] BYREF
  Scaleform::RefCountVImpl *v120; // [esp+80h] [ebp-138h]
  int v121; // [esp+84h] [ebp-134h]
  Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v122; // [esp+88h] [ebp-130h]
  Scaleform::Render::ShapeDataInterface *v123; // [esp+8Ch] [ebp-12Ch]
  unsigned int leftStyle; // [esp+90h] [ebp-128h] BYREF
  unsigned int rightStyle; // [esp+94h] [ebp-124h]
  unsigned int strokeStyle; // [esp+98h] [ebp-120h]
  float v127; // [esp+9Ch] [ebp-11Ch] BYREF
  float cy; // [esp+A0h] [ebp-118h]
  float v129; // [esp+A4h] [ebp-114h]
  float v130; // [esp+A8h] [ebp-110h]
  float v131; // [esp+ACh] [ebp-10Ch]
  float v132; // [esp+B0h] [ebp-108h]
  float cx1; // [esp+B4h] [ebp-104h] BYREF
  float y; // [esp+B8h] [ebp-100h]
  float cx2; // [esp+BCh] [ebp-FCh]
  Scaleform::RefCountVImpl *v136; // [esp+C0h] [ebp-F8h]
  float v137; // [esp+C4h] [ebp-F4h]
  Scaleform::RefCountVImpl *v138; // [esp+C8h] [ebp-F0h]
  _DWORD v139[14]; // [esp+CCh] [ebp-ECh] BYREF
  _DWORD v140[14]; // [esp+104h] [ebp-B4h] BYREF
  Scaleform::RefCountVImpl *v141[14]; // [esp+13Ch] [ebp-7Ch] BYREF
  _DWORD v142[3]; // [esp+174h] [ebp-44h] BYREF
  Scaleform::RefCountVImpl *v143[14]; // [esp+180h] [ebp-38h] BYREF

  pObject = this->pShapeData.pObject;
  GetFillStyleCount = pObject->GetFillStyleCount;
  v123 = this->pMorphData.pObject->pMorphTo.pObject;
  v122 = (Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)pObject;
  if ( GetFillStyleCount(pObject) )
  {
    v4 = 1;
    do
    {
      GetFillStyle = pObject->GetFillStyle;
      *(float *)&v120 = 0.0;
      GetFillStyle(pObject, v4, (Scaleform::Render::FillStyleType *)&v119);
      v6 = v120;
      if ( *(float *)&v120 != 0.0 )
      {
        if ( v120[1].RefCount )
        {
          v7 = v123->GetFillStyle;
          *(float *)&v118 = 0.0;
          v7(v123, v4, (Scaleform::Render::FillStyleType *)&v117);
          if ( !Scaleform::Render::GradientData::operator==(
                  (Scaleform::Render::GradientData *)v120[1].RefCount,
                  (const Scaleform::Render::GradientData *)v118[1].RefCount) )
          {
            *(_DWORD *)(v120[1].RefCount + 20) = v118[1].RefCount;
            this->GradientMorph = 1;
          }
          if ( *(float *)&v118 != 0.0 )
            Scaleform::RefCountImpl::Release(v118);
          v6 = v120;
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
      v141[5] = 0;
      v141[6] = 0;
      GetStrokeStyle(pObject, v8, (Scaleform::Render::StrokeStyleType *)v141);
      if ( v141[5] && v141[5][1].RefCount )
      {
        v10 = v123->GetStrokeStyle;
        v143[5] = 0;
        v143[6] = 0;
        v10(v123, v8, (Scaleform::Render::StrokeStyleType *)v143);
        if ( !Scaleform::Render::GradientData::operator==(
                (Scaleform::Render::GradientData *)v141[5][1].RefCount,
                (const Scaleform::Render::GradientData *)v143[5][1].RefCount) )
        {
          *(_DWORD *)(v141[5][1].RefCount + 20) = v143[5][1].RefCount;
          this->GradientMorph = 1;
        }
        if ( v143[6] )
          Scaleform::RefCountImpl::Release(v143[6]);
        if ( v143[5] )
          Scaleform::RefCountImpl::Release(v143[5]);
      }
      if ( v141[6] )
        Scaleform::RefCountImpl::Release(v141[6]);
      if ( v141[5] )
        Scaleform::RefCountImpl::Release(v141[5]);
      ++v8;
    }
    while ( v8 - 1 < pObject->GetStrokeStyleCount(pObject) );
  }
  v11 = pObject->GetStartingPos(pObject);
  v12 = v123->GetStartingPos(v123);
  v140[0] = v11;
  *(float *)&v140[12] = 1.0;
  v13 = this->pMorphData.pObject;
  *(float *)&v139[12] = 1.0;
  p_ShapeData1 = &v13->ShapeData1;
  memset(&v140[1], 0, 44);
  LOBYTE(v140[13]) = 0;
  v139[0] = v12;
  memset(&v139[1], 0, 44);
  LOBYTE(v139[13]) = 0;
  p_ShapeData1->Status = Status_Clean;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_ShapeData1->Fills.Data,
    &p_ShapeData1->Fills,
    0);
  v15 = *(float *)&p_ShapeData1->Strokes.Data.Size;
  p_Data = (void **)&p_ShapeData1->Strokes.Data.Data;
  if ( v15 == 0.0 )
  {
    if ( !p_ShapeData1->Strokes.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_ShapeData1->Strokes.Data,
        &p_ShapeData1->Strokes,
        0);
  }
  else
  {
    v17 = (int)*p_Data + 28 * LODWORD(v15) - 8;
    v117 = *(float *)&v17;
    v119 = v15;
    do
    {
      v18 = *(Scaleform::RefCountVImpl **)(v17 + 4);
      if ( v18 )
        Scaleform::RefCountImpl::Release(v18);
      if ( *(_DWORD *)LODWORD(v117) )
        Scaleform::RefCountImpl::Release(*(Scaleform::RefCountVImpl **)LODWORD(v117));
      v17 = LODWORD(v117) - 28;
      v19 = LODWORD(v119)-- == 1;
      LODWORD(v117) -= 28;
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
  v22 = *(float *)&p_ShapeData2->Strokes.Data.Size;
  v23 = (void **)&p_ShapeData2->Strokes.Data.Data;
  if ( v22 == 0.0 )
  {
    if ( !p_ShapeData2->Strokes.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_ShapeData2->Strokes.Data,
        &p_ShapeData2->Strokes,
        0);
  }
  else
  {
    v24 = (int)*v23 + 28 * LODWORD(v22) - 8;
    v117 = *(float *)&v24;
    v119 = v22;
    do
    {
      v25 = *(Scaleform::RefCountVImpl **)(v24 + 4);
      if ( v25 )
        Scaleform::RefCountImpl::Release(v25);
      if ( *(_DWORD *)LODWORD(v117) )
        Scaleform::RefCountImpl::Release(*(Scaleform::RefCountVImpl **)LODWORD(v117));
      v24 = LODWORD(v117) - 28;
      v19 = LODWORD(v119)-- == 1;
      LODWORD(v117) -= 28;
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
  HIBYTE(v121) = 1;
  p_ShapeData2->StartY = 0.0;
  p_ShapeData2->LastX = 0.0;
  p_ShapeData2->LastY = 0.0;
  while ( 1 )
  {
    v27 = v122->ReadPathInfo(v122, (Scaleform::Render::ShapePosInfo *)v140, &cx1, &leftStyle);
    v28 = v123->ReadPathInfo(v123, (Scaleform::Render::ShapePosInfo *)v139, &v127, v142);
    if ( !v27 || !v28 )
      break;
    if ( v27 == 2 || HIBYTE(v121) )
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
      HIBYTE(v121) = 0;
    }
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &this->pMorphData.pObject->ShapeData1,
      leftStyle,
      rightStyle,
      strokeStyle);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
      &this->pMorphData.pObject->ShapeData2,
      leftStyle,
      rightStyle,
      strokeStyle);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData1,
      cx1,
      y);
    Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
      &this->pMorphData.pObject->ShapeData2,
      v127,
      cy);
LABEL_81:
    v119 = cx1;
    *(float *)&v120 = y;
LABEL_82:
    v117 = v127;
    v39 = cy;
LABEL_83:
    *(float *)&v118 = v39;
    while ( 1 )
    {
      while ( 1 )
      {
        qmemcpy(v141, v140, sizeof(v141));
        qmemcpy(v143, v139, sizeof(v143));
        v40 = v122->ReadEdge(v122, (Scaleform::Render::ShapePosInfo *)v140, &cx1);
        v41 = v123->ReadEdge(v123, (Scaleform::Render::ShapePosInfo *)v139, &v127);
        if ( !v40 )
          break;
        if ( !v41 )
        {
          v53 = this->pMorphData.pObject;
          qmemcpy(v140, v141, sizeof(v140));
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
          v63 = v123;
          v59->Size = v61;
          v62[v61 - 1] = 6;
          v60->Status = Status_EndPath;
          if ( v63->ReadPathInfo(v63, (Scaleform::Render::ShapePosInfo *)v139, &v127, v142) )
          {
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
              &this->pMorphData.pObject->ShapeData1,
              leftStyle,
              rightStyle,
              strokeStyle);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
              &this->pMorphData.pObject->ShapeData2,
              leftStyle,
              rightStyle,
              strokeStyle);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
              &this->pMorphData.pObject->ShapeData1,
              v119,
              *(float *)&v120);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
              &this->pMorphData.pObject->ShapeData2,
              v127,
              cy);
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
          if ( v40 == 1 )
          {
            if ( v41 != 2 )
            {
LABEL_119:
              Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                &this->pMorphData.pObject->ShapeData1,
                cx1,
                y);
              Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::LineTo(
                &this->pMorphData.pObject->ShapeData2,
                v127,
                cy);
              goto LABEL_81;
            }
            cx2 = cx1;
            *(float *)&v136 = y;
            cx1 = (cx1 + v119) * 0.5;
            y = 0.5 * (y + *(float *)&v120);
            goto LABEL_121;
          }
          if ( v40 == 2 )
          {
            if ( v41 == 1 )
            {
              v129 = v127;
              v130 = cy;
              v127 = (v127 + v117) * 0.5;
              cy = 0.5 * (cy + *(float *)&v118);
            }
LABEL_121:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &this->pMorphData.pObject->ShapeData1,
              cx1,
              y,
              cx2,
              *(float *)&v136);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::QuadTo(
              &this->pMorphData.pObject->ShapeData2,
              v127,
              cy,
              v129,
              v130);
            v119 = cx2;
            v120 = v136;
            v117 = v129;
            v39 = v130;
            goto LABEL_83;
          }
        }
        switch ( v40 )
        {
          case 1:
            goto LABEL_119;
          case 2:
            goto LABEL_121;
          case 3:
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &this->pMorphData.pObject->ShapeData1,
              cx1,
              y,
              cx2,
              *(float *)&v136,
              v137,
              *(float *)&v138);
            Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::CubicTo(
              &this->pMorphData.pObject->ShapeData2,
              v127,
              cy,
              v129,
              v130,
              v131,
              v132);
            v119 = v137;
            v120 = v138;
            v117 = v131;
            v39 = v132;
            goto LABEL_83;
        }
      }
      v42 = this->pMorphData.pObject;
      if ( !v41 )
        break;
      qmemcpy(v139, v143, sizeof(v139));
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
      v52 = &v122->__vftable;
      v48->Size = v50;
      v51[v50 - 1] = 6;
      v49->Status = Status_EndPath;
      if ( !(*(int (__thiscall **)(_DWORD *, _DWORD *, float *, unsigned int *))(*v52 + 32))(
              v52,
              v140,
              &cx1,
              &leftStyle) )
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
        leftStyle,
        rightStyle,
        strokeStyle);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::StartPath(
        &this->pMorphData.pObject->ShapeData2,
        leftStyle,
        rightStyle,
        strokeStyle);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
        &this->pMorphData.pObject->ShapeData1,
        cx1,
        y);
      Scaleform::Render::ShapeDataFloatTempl<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::MoveTo(
        &this->pMorphData.pObject->ShapeData2,
        v117,
        *(float *)&v118);
      v119 = cx1;
      *(float *)&v120 = y;
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
  v122 = v103;
  if ( v102 != Status_EndShape && v102 )
  {
    if ( v102 == Status_EndPath )
    {
LABEL_192:
      v107 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v122->Data;
      v108 = v107->Size + 1;
      if ( v108 >= v107->Size )
      {
        if ( v108 >= v107->Policy.Capacity )
          Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v107,
            v107,
            v108 + (v108 >> 2));
      }
      else if ( v108 < v107->Policy.Capacity >> 1 )
      {
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v107,
          v107,
          v107->Size + 1);
      }
      v109 = v107->Data;
      v110 = &v122->__vftable;
      v107->Size = v108;
      v109[v108 - 1] = 7;
      v110[2] = 6;
      goto LABEL_198;
    }
    v104 = (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v103->Data;
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
      v103 = v122;
    }
    v106 = v104->Data;
    v104->Size = v105;
    v106[v105 - 1] = 6;
    v103->Status = Status_EndPath;
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
