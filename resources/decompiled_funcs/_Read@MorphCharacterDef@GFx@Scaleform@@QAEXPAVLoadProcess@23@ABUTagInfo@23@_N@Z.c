void __thiscall Scaleform::GFx::MorphCharacterDef::Read(
        Scaleform::GFx::MorphCharacterDef *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo,
        bool withStyle)
{
  Scaleform::GFx::Stream *pAltStream; // eax
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // esi
  int v6; // edx
  int v7; // eax
  unsigned int Pos; // ecx
  unsigned int DataSize; // eax
  int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // edx
  unsigned int v15; // eax
  unsigned int v16; // ecx
  Scaleform::Render::FillStyleType *v17; // edi
  Scaleform::GFx::Resource *pObject; // ebx
  Scaleform::GFx::Resource *v19; // ebx
  Scaleform::Render::FillStyleType *v20; // edi
  unsigned int v21; // eax
  unsigned int v22; // ebx
  unsigned int v23; // eax
  int v24; // edx
  unsigned int v25; // eax
  const Scaleform::Log **p_LogPtr; // eax
  unsigned int v27; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v28; // ecx
  Scaleform::GFx::AS2::ArraySortFunctor *Data; // edx
  const Scaleform::Log **v30; // eax
  unsigned int v31; // ecx
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // edi
  int v33; // ebx
  int v34; // edx
  unsigned int v35; // eax
  int v36; // eax
  unsigned int v37; // eax
  int v38; // edx
  int v39; // edx
  unsigned int v40; // eax
  unsigned __int16 v41; // cx
  unsigned int v42; // eax
  int v43; // eax
  unsigned int v44; // eax
  int v45; // edx
  double v46; // st7
  Scaleform::GFx::Resource *v47; // ecx
  Scaleform::RefCountVImpl *v48; // ecx
  Scaleform::GFx::Resource *v49; // ebx
  unsigned int Color; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v51; // edx
  Scaleform::RefCountVImpl *pRCC; // ecx
  Scaleform::Render::ComplexFill *v53; // ecx
  Scaleform::Render::GradientData *v54; // eax
  Scaleform::GFx::Resource_vtbl *v55; // eax
  unsigned int Raw; // eax
  unsigned int v57; // edi
  int v58; // ebx
  Scaleform::GFx::ConstShapeWithStyles *v59; // eax
  Scaleform::RefCountVImpl *v60; // ecx
  Scaleform::GFx::ConstShapeWithStyles *v61; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v62; // ecx
  Scaleform::GFx::MorphCharacterDef *v63; // edi
  _DWORD *v64; // eax
  Scaleform::GFx::ConstShapeWithStyles *v65; // esi
  Scaleform::RefCountVImpl *v66; // ecx
  unsigned int v67; // ebx
  Scaleform::GFx::ShapeDataBase *v68; // eax
  Scaleform::GFx::ConstShapeWithStyles *v69; // esi
  Scaleform::RefCountVImpl *v70; // ecx
  Scaleform::GFx::ShapeDataBase *v71; // eax
  Scaleform::GFx::ConstShapeWithStyles *v72; // esi
  Scaleform::RefCountVImpl *v73; // ecx
  Scaleform::Render::ShapeMeshProvider *v74; // eax
  Scaleform::Render::ShapeMeshProvider *v75; // eax
  Scaleform::Render::ShapeMeshProvider *v76; // esi
  Scaleform::Render::ShapeMeshProvider *v77; // eax
  unsigned int v78; // edi
  Scaleform::GFx::AS2::Environment **p_Env; // esi
  Scaleform::RefCountVImpl *v80; // ecx
  Scaleform::GFx::AS2::Environment **v81; // esi
  Scaleform::RefCountVImpl *v82; // ecx
  Scaleform::RefCountVImpl **p_pFill; // esi
  unsigned int Size; // edi
  Scaleform::Render::FillStyleType *v85; // ebx
  Scaleform::RefCountVImpl **v86; // esi
  unsigned int v87; // edi
  Scaleform::GFx::TagType TagType; // [esp+5E2h] [ebp-F0h]
  Scaleform::GFx::TagType v89; // [esp+5E2h] [ebp-F0h]
  bool v90; // [esp+60Dh] [ebp-C5h] BYREF
  Scaleform::GFx::MorphCharacterDef *v91; // [esp+60Eh] [ebp-C4h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *p_Flags; // [esp+612h] [ebp-C0h] BYREF
  int v93; // [esp+616h] [ebp-BCh] BYREF
  Scaleform::GFx::ConstShapeWithStyles *v94; // [esp+61Ah] [ebp-B8h]
  unsigned int strokeStyleCount; // [esp+61Eh] [ebp-B4h]
  int v96; // [esp+622h] [ebp-B0h] BYREF
  int v97; // [esp+626h] [ebp-ACh] BYREF
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> v98; // [esp+62Ah] [ebp-A8h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+636h] [ebp-9Ch] BYREF
  int v100; // [esp+642h] [ebp-90h] BYREF
  unsigned int fillStyleCount; // [esp+646h] [ebp-8Ch]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> v102; // [esp+64Ah] [ebp-88h] BYREF
  Scaleform::Render::FillStyleType v103; // [esp+656h] [ebp-7Ch] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> v104; // [esp+65Eh] [ebp-74h] BYREF
  Scaleform::Render::FillStyleType v105; // [esp+66Ah] [ebp-68h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+672h] [ebp-60h] BYREF
  Scaleform::Render::Rect<float> v107; // [esp+682h] [ebp-50h] BYREF
  Scaleform::Render::Rect<float> v108; // [esp+692h] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> v109; // [esp+6A2h] [ebp-30h] BYREF
  Scaleform::Render::FillStyleType v110; // [esp+6BAh] [ebp-18h] BYREF
  Scaleform::Render::Color v111; // [esp+6C2h] [ebp-10h] BYREF
  Scaleform::Render::Color pc; // [esp+6C6h] [ebp-Ch] BYREF
  Scaleform::Render::FillStyleType v113; // [esp+6CAh] [ebp-8h] BYREF

  pAltStream = p->pAltStream;
  v91 = this;
  if ( pAltStream )
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)pAltStream;
  else
    p_ProcessInfo = &p->ProcessInfo;
  pr.x1 = 0.0;
  pr.y1 = 0.0;
  pr.x2 = 0.0;
  pr.y2 = 0.0;
  v109.x1 = 0.0;
  v109.y1 = 0.0;
  v109.x2 = 0.0;
  v109.y2 = 0.0;
  v107.x1 = 0.0;
  v107.y1 = 0.0;
  v107.x2 = 0.0;
  v107.y2 = 0.0;
  v108.x1 = 0.0;
  v108.y1 = 0.0;
  v108.x2 = 0.0;
  v108.y2 = 0.0;
  Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &pr);
  Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &v109);
  if ( tagInfo->TagType == Tag_DefineShapeMorph2 )
  {
    Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &v107);
    Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &v108);
    v6 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( v6 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
    ++p_ProcessInfo->Stream.Pos;
  }
  else
  {
    v107.x1 = pr.x1;
    v107.y1 = pr.y1;
    v107.x2 = pr.x2;
    v107.y2 = pr.y2;
    v108.x1 = v109.x1;
    v108.y1 = v109.y1;
    v108.x2 = v109.x2;
    v108.y2 = v109.y2;
  }
  v7 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  memset(&v98, 0, sizeof(v98));
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v7 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  Pos = p_ProcessInfo->Stream.Pos;
  DataSize = p_ProcessInfo->Stream.DataSize;
  v100 = p_ProcessInfo->Stream.pBuffer[Pos]
       | ((p_ProcessInfo->Stream.pBuffer[Pos + 1] | (*(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[Pos + 2] << 8)) << 8);
  Pos += 4;
  v10 = Pos + p_ProcessInfo->Stream.FilePos - DataSize;
  p_ProcessInfo->Stream.Pos = Pos;
  v97 = v10;
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (int)(DataSize - Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
  v11 = p_ProcessInfo->Stream.Pos;
  v12 = v11 + 1;
  v13 = p_ProcessInfo->Stream.pBuffer[v11];
  p_ProcessInfo->Stream.Pos = v12;
  fillStyleCount = v13;
  if ( v13 == 255 )
  {
    v14 = p_ProcessInfo->Stream.DataSize - v12;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( v14 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
    v15 = p_ProcessInfo->Stream.Pos;
    v16 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v15];
    p_ProcessInfo->Stream.Pos = v15 + 2;
    v13 = v16;
    fillStyleCount = v16;
  }
  v90 = 0;
  if ( v13 )
  {
    strokeStyleCount = v13;
    do
    {
      TagType = tagInfo->TagType;
      v105.pFill.pObject = 0;
      v113.pFill.pObject = 0;
      Scaleform::GFx::MorphCharacterDef::ReadMorphFillStyle(v91, p, TagType, &v105, &v113, &v90);
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &pheapAddr,
        &pheapAddr,
        pheapAddr.Size + 1);
      v17 = &pheapAddr.Data[pheapAddr.Size - 1];
      pObject = (Scaleform::GFx::Resource *)v105.pFill.pObject;
      if ( &pheapAddr.Data[pheapAddr.Size] != (Scaleform::Render::FillStyleType *)8 )
      {
        v17->Color = v105.Color;
        if ( pObject )
          Scaleform::RefCountImpl::AddRef(pObject);
        v17->pFill.pObject = (Scaleform::Render::ComplexFill *)pObject;
      }
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &v98,
        &v98,
        v98.Size + 1);
      v19 = (Scaleform::GFx::Resource *)v113.pFill.pObject;
      v20 = &v98.Data[v98.Size - 1];
      if ( &v98.Data[v98.Size] != (Scaleform::Render::FillStyleType *)8 )
      {
        v20->Color = v113.Color;
        if ( v19 )
          Scaleform::RefCountImpl::AddRef(v19);
        v20->pFill.pObject = (Scaleform::Render::ComplexFill *)v19;
      }
      if ( v19 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19);
      if ( v105.pFill.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v105.pFill.pObject);
      --strokeStyleCount;
    }
    while ( strokeStyleCount );
  }
  memset(&v102, 0, sizeof(v102));
  memset(&v104, 0, sizeof(v104));
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( (signed int)(p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos) < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
  v21 = p_ProcessInfo->Stream.Pos;
  v22 = p_ProcessInfo->Stream.pBuffer[v21];
  v23 = v21 + 1;
  p_ProcessInfo->Stream.Pos = v23;
  strokeStyleCount = v22;
  if ( v22 == 255 )
  {
    v24 = p_ProcessInfo->Stream.DataSize - v23;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( v24 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
    v25 = p_ProcessInfo->Stream.Pos;
    v22 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v25];
    p_ProcessInfo->Stream.Pos = v25 + 2;
    strokeStyleCount = v22;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &v102,
    &v102,
    (v22 >> 2) + v22);
  v102.Size = v22;
  if ( v22 )
  {
    p_LogPtr = &v102.Data->LogPtr;
    v27 = v22;
    do
    {
      if ( p_LogPtr != (const Scaleform::Log **)24 )
      {
        *(p_LogPtr - 1) = 0;
        *p_LogPtr = 0;
      }
      p_LogPtr += 7;
      --v27;
    }
    while ( v27 );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &v104,
    &v104,
    (v22 >> 2) + v22);
  Data = v104.Data;
  v104.Size = v22;
  if ( v22 )
  {
    v30 = &v104.Data->LogPtr;
    v31 = v22;
    do
    {
      if ( v30 != (const Scaleform::Log **)24 )
      {
        *(v30 - 1) = 0;
        *v30 = 0;
      }
      v30 += 7;
      --v31;
    }
    while ( v31 );
    p_Flags = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)&Data->Func.Flags;
    v94 = (Scaleform::GFx::ConstShapeWithStyles *)v22;
    p_pLocalFrame = &v102.Data->Func.pLocalFrame;
    v96 = (char *)Data - (char *)v102.Data;
    v33 = (char *)Data - (char *)v102.Data;
    do
    {
      v34 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( v34 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
      v35 = p_ProcessInfo->Stream.Pos;
      v93 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v35];
      p_ProcessInfo->Stream.Pos = v35 + 2;
      *((float *)p_pLocalFrame - 3) = (float)v93;
      v36 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( v36 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
      v37 = p_ProcessInfo->Stream.Pos;
      v38 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v37];
      p_ProcessInfo->Stream.Pos = v37 + 2;
      v93 = v38;
      *(float *)&p_Flags[-1]._pRCC = (float)v38;
      *(Scaleform::GFx::AS2::LocalFrame **)((char *)p_pLocalFrame + v33 - 4) = 0;
      *(p_pLocalFrame - 1) = 0;
      *(float *)((char *)p_pLocalFrame + v33 - 8) = 0.050000001;
      *((float *)p_pLocalFrame - 2) = 0.050000001;
      *(float *)((char *)p_pLocalFrame + v33) = 3.0;
      *(float *)p_pLocalFrame = 3.0;
      if ( tagInfo->TagType == Tag_DefineShapeMorph2 )
      {
        v39 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
        p_ProcessInfo->Stream.UnusedBits = 0;
        if ( v39 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
        v40 = p_ProcessInfo->Stream.Pos;
        v41 = *(_WORD *)&p_ProcessInfo->Stream.pBuffer[v40];
        p_ProcessInfo->Stream.Pos = v40 + 2;
        v42 = Scaleform::GFx::ConvertSwfLineStyles(v41);
        *(Scaleform::GFx::AS2::LocalFrame **)((char *)p_pLocalFrame + v33 - 4) = (Scaleform::GFx::AS2::LocalFrame *)v42;
        *(p_pLocalFrame - 1) = (Scaleform::GFx::AS2::LocalFrame *)v42;
        if ( (v42 & 0x20) != 0 )
        {
          v43 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
          p_ProcessInfo->Stream.UnusedBits = 0;
          if ( v43 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
          v44 = p_ProcessInfo->Stream.Pos;
          v45 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v44];
          p_ProcessInfo->Stream.Pos = v44 + 2;
          *(float *)&v93 = (double)v45 * 0.00390625;
          v46 = *(float *)&v93;
          *(int *)((char *)p_pLocalFrame + v33) = v93;
          *(float *)p_pLocalFrame = v46;
        }
      }
      if ( (*(_BYTE *)(p_pLocalFrame - 1) & 8) != 0 )
      {
        v89 = tagInfo->TagType;
        v103.pFill.pObject = 0;
        v110.pFill.pObject = 0;
        Scaleform::GFx::MorphCharacterDef::ReadMorphFillStyle(v91, p, v89, &v103, &v110, &v90);
        v47 = (Scaleform::GFx::Resource *)v103.pFill.pObject;
        p_pLocalFrame[1] = (Scaleform::GFx::AS2::LocalFrame *)v103.Color;
        if ( v47 )
          Scaleform::RefCountImpl::AddRef(v47);
        v48 = (Scaleform::RefCountVImpl *)p_pLocalFrame[2];
        if ( v48 )
          Scaleform::RefCountImpl::Release(v48);
        v49 = (Scaleform::GFx::Resource *)v110.pFill.pObject;
        Color = v110.Color;
        v51 = p_Flags;
        p_pLocalFrame[2] = (Scaleform::GFx::AS2::LocalFrame *)v103.pFill.pObject;
        v51->__vftable = (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)Color;
        if ( v49 )
        {
          Scaleform::RefCountImpl::AddRef(v49);
          v51 = p_Flags;
        }
        pRCC = (Scaleform::RefCountVImpl *)v51->_pRCC;
        if ( pRCC )
        {
          Scaleform::RefCountImpl::Release(pRCC);
          v51 = p_Flags;
        }
        v53 = v103.pFill.pObject;
        v51->pRCCRaw = (unsigned int)v49;
        v54 = v53->pGradient.pObject;
        if ( v54 && v54->RecordCount )
          p_pLocalFrame[1] = (Scaleform::GFx::AS2::LocalFrame *)v54->pRecords->ColorV.Raw;
        v55 = v49[1].__vftable;
        if ( v55 && HIWORD(v55->GetResourceTypeCode) )
          v51->__vftable = (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)*((_DWORD *)v55->GetResourceReport + 1);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v49);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v103.pFill.pObject);
        v33 = v96;
      }
      else
      {
        Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &pc, tagInfo->TagType);
        Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &v111, tagInfo->TagType);
        Raw = v111.Raw;
        v28 = p_Flags;
        p_pLocalFrame[1] = (Scaleform::GFx::AS2::LocalFrame *)pc.Raw;
        v28->__vftable = (Scaleform::GFx::AS3::RefCountBaseGC<328>_vtbl *)Raw;
      }
      p_Flags = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)p_Flags + 28);
      p_pLocalFrame += 7;
      v94 = (Scaleform::GFx::ConstShapeWithStyles *)((char *)v94 - 1);
    }
    while ( v94 );
  }
  v57 = p_ProcessInfo->Stream.FilePos + p_ProcessInfo->Stream.Pos - p_ProcessInfo->Stream.DataSize;
  v58 = v100 + v97;
  if ( v100 + v97 < v57 )
  {
    v63 = v91;
    v93 = 2;
    v68 = (Scaleform::GFx::ShapeDataBase *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             v91,
                                             64,
                                             &v93);
    v69 = (Scaleform::GFx::ConstShapeWithStyles *)v68;
    if ( v68 )
    {
      Scaleform::GFx::ShapeDataBase::ShapeDataBase(v68, Empty_Shape);
      v69->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
      v69->Styles = 0;
      v69->FillStylesNum = 0;
      v69->StrokeStylesNum = 0;
      v69->Bound.x1 = 0.0;
      v69->Bound.y1 = 0.0;
      v69->Bound.x2 = 0.0;
      v69->Bound.y2 = 0.0;
      v69->RectBound.x1 = 0.0;
      v69->RectBound.y1 = 0.0;
      v69->RectBound.x2 = 0.0;
      v69->RectBound.y2 = 0.0;
    }
    else
    {
      v69 = 0;
    }
    v70 = (Scaleform::RefCountVImpl *)v63->pShape1.pObject;
    if ( v70 )
      Scaleform::RefCountImpl::Release(v70);
    v63->pShape1.pObject = v69;
    v96 = 2;
    v71 = (Scaleform::GFx::ShapeDataBase *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             v63,
                                             64,
                                             &v96);
    v72 = (Scaleform::GFx::ConstShapeWithStyles *)v71;
    if ( v71 )
    {
      Scaleform::GFx::ShapeDataBase::ShapeDataBase(v71, Empty_Shape);
      v72->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
      v72->Styles = 0;
      v72->FillStylesNum = 0;
      v72->StrokeStylesNum = 0;
      v72->Bound.x1 = 0.0;
      v72->Bound.y1 = 0.0;
      v72->Bound.x2 = 0.0;
      v72->Bound.y2 = 0.0;
      v72->RectBound.x1 = 0.0;
      v72->RectBound.y1 = 0.0;
      v72->RectBound.x2 = 0.0;
      v72->RectBound.y2 = 0.0;
    }
    else
    {
      v72 = 0;
    }
    v73 = (Scaleform::RefCountVImpl *)v63->pShape2.pObject;
    if ( v73 )
      Scaleform::RefCountImpl::Release(v73);
    v67 = strokeStyleCount;
    v63->pShape2.pObject = v72;
  }
  else
  {
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v28);
    v97 = 2;
    v59 = (Scaleform::GFx::ConstShapeWithStyles *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    v91,
                                                    64,
                                                    &v97);
    if ( v59 )
    {
      v59->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v59->RefCount = 1;
      v59->Paths = 0;
      v59->Flags = 0;
      v59->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
      v59->Styles = 0;
      v59->FillStylesNum = 0;
      v59->StrokeStylesNum = 0;
      v59->Bound.x1 = 0.0;
      v59->Bound.y1 = 0.0;
      v94 = v59;
      v59->Bound.x2 = 0.0;
      v59->Bound.y2 = 0.0;
      v59->RectBound.x1 = 0.0;
      v59->RectBound.y1 = 0.0;
      v59->RectBound.x2 = 0.0;
      v59->RectBound.y2 = 0.0;
    }
    else
    {
      v94 = 0;
    }
    v60 = (Scaleform::RefCountVImpl *)v91->pShape1.pObject;
    if ( v60 )
      Scaleform::RefCountImpl::Release(v60);
    v61 = v94;
    v91->pShape1.pObject = v94;
    v61->Read(v61, p, tagInfo->TagType, v58 - v57, 0);
    Scaleform::GFx::ConstShapeWithStyles::SetStyles(
      v91->pShape1.pObject,
      fillStyleCount,
      pheapAddr.Data,
      strokeStyleCount,
      (const Scaleform::Render::StrokeStyleType *)v102.Data);
    v63 = v91;
    if ( v90 )
      v91->pShape1.pObject->Flags |= 4u;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v62);
    Scaleform::GFx::Stream::SetPosition(&p_ProcessInfo->Stream, v58);
    v100 = 2;
    v64 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, v63, 64, &v100);
    if ( v64 )
    {
      *v64 = &Scaleform::RefCountImplCore::`vftable';
      v64[1] = 1;
      v64[2] = 0;
      *((_BYTE *)v64 + 12) = 0;
      *v64 = &Scaleform::GFx::ConstShapeWithStyles::`vftable';
      v64[4] = 0;
      v64[5] = 0;
      v64[6] = 0;
      *((float *)v64 + 8) = 0.0;
      *((float *)v64 + 9) = 0.0;
      v65 = (Scaleform::GFx::ConstShapeWithStyles *)v64;
      *((float *)v64 + 10) = 0.0;
      *((float *)v64 + 11) = 0.0;
      *((float *)v64 + 12) = 0.0;
      *((float *)v64 + 13) = 0.0;
      *((float *)v64 + 14) = 0.0;
      *((float *)v64 + 15) = 0.0;
    }
    else
    {
      v65 = 0;
    }
    v66 = (Scaleform::RefCountVImpl *)v63->pShape2.pObject;
    if ( v66 )
      Scaleform::RefCountImpl::Release(v66);
    v63->pShape2.pObject = v65;
    v65->Read(v65, p, tagInfo->TagType, tagInfo->TagLength + tagInfo->TagDataOffset - v58, 0);
    v67 = strokeStyleCount;
    Scaleform::GFx::ConstShapeWithStyles::SetStyles(
      v63->pShape2.pObject,
      fillStyleCount,
      v98.Data,
      strokeStyleCount,
      (const Scaleform::Render::StrokeStyleType *)v104.Data);
    if ( v90 )
      v63->pShape2.pObject->Flags |= 4u;
  }
  p_Flags = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)2;
  v74 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v63,
                                                  96,
                                                  &p_Flags);
  if ( v74 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
      v74,
      (Scaleform::GFx::Resource *)v63->pShape1.pObject,
      (Scaleform::GFx::Resource *)v63->pShape2.pObject);
    v76 = v75;
  }
  else
  {
    v76 = 0;
  }
  v77 = v63->pShapeMeshProvider.pObject;
  if ( v77 )
    v77->Release(&v77->Scaleform::Render::MeshProvider);
  v63->pShapeMeshProvider.pObject = v76;
  v78 = v67;
  if ( v67 )
  {
    p_Env = &v104.Data[v78 - 1].Env;
    v94 = (Scaleform::GFx::ConstShapeWithStyles *)v67;
    do
    {
      v80 = (Scaleform::RefCountVImpl *)p_Env[1];
      if ( v80 )
        Scaleform::RefCountImpl::Release(v80);
      if ( *p_Env )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)*p_Env);
      p_Env -= 7;
      v94 = (Scaleform::GFx::ConstShapeWithStyles *)((char *)v94 - 1);
    }
    while ( v94 );
  }
  if ( v104.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v104.Data);
  if ( v67 )
  {
    v81 = &v102.Data[v78 - 1].Env;
    do
    {
      v82 = (Scaleform::RefCountVImpl *)v81[1];
      if ( v82 )
        Scaleform::RefCountImpl::Release(v82);
      if ( *v81 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)*v81);
      v81 -= 7;
      --v67;
    }
    while ( v67 );
  }
  if ( v102.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v102.Data);
  if ( v98.Size )
  {
    p_pFill = (Scaleform::RefCountVImpl **)&v98.Data[v98.Size - 1].pFill;
    Size = v98.Size;
    do
    {
      if ( *p_pFill )
        Scaleform::RefCountImpl::Release(*p_pFill);
      p_pFill -= 2;
      --Size;
    }
    while ( Size );
  }
  if ( v98.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v98.Data);
  v85 = pheapAddr.Data;
  if ( pheapAddr.Size )
  {
    v86 = (Scaleform::RefCountVImpl **)&pheapAddr.Data[pheapAddr.Size - 1].pFill;
    v87 = pheapAddr.Size;
    do
    {
      if ( *v86 )
        Scaleform::RefCountImpl::Release(*v86);
      v86 -= 2;
      --v87;
    }
    while ( v87 );
  }
  if ( v85 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v85);
}
