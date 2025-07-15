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
  Scaleform::Render::ComplexFill *pObject; // ebx
  Scaleform::Render::ComplexFill *v19; // ebx
  Scaleform::Render::FillStyleType *v20; // edi
  unsigned int v21; // eax
  unsigned int v22; // ebx
  unsigned int v23; // eax
  int v24; // edx
  unsigned int v25; // eax
  const Scaleform::Log **p_LogPtr; // eax
  unsigned int v27; // ecx
  Scaleform::GFx::AS2::ArraySortFunctor *Data; // edx
  const Scaleform::Log **v29; // eax
  unsigned int v30; // ecx
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // edi
  int v32; // ebx
  int v33; // edx
  unsigned int v34; // eax
  int v35; // eax
  unsigned int v36; // eax
  int v37; // edx
  int v38; // edx
  unsigned int v39; // eax
  __int16 v40; // cx
  unsigned int v41; // eax
  int v42; // eax
  unsigned int v43; // eax
  int v44; // edx
  double v45; // st7
  Scaleform::Render::ComplexFill *v46; // ecx
  Scaleform::RefCountVImpl *v47; // ecx
  Scaleform::GFx::Resource *v48; // ebx
  unsigned int Color; // eax
  unsigned int *v50; // edx
  Scaleform::RefCountVImpl *v51; // ecx
  Scaleform::Render::ComplexFill *v52; // ecx
  Scaleform::Render::GradientData *v53; // eax
  Scaleform::GFx::Resource_vtbl *v54; // eax
  unsigned int Raw; // eax
  unsigned int *v56; // ecx
  unsigned int v57; // edi
  int v58; // ebx
  Scaleform::GFx::ConstShapeWithStyles *v59; // eax
  Scaleform::RefCountVImpl *v60; // ecx
  Scaleform::GFx::ConstShapeWithStyles *v61; // ecx
  Scaleform::GFx::MorphCharacterDef *v62; // edi
  _DWORD *v63; // eax
  Scaleform::GFx::ConstShapeWithStyles *v64; // esi
  Scaleform::RefCountVImpl *v65; // ecx
  unsigned int v66; // ebx
  Scaleform::GFx::ShapeDataBase *v67; // eax
  Scaleform::GFx::ConstShapeWithStyles *v68; // esi
  Scaleform::RefCountVImpl *v69; // ecx
  Scaleform::GFx::ShapeDataBase *v70; // eax
  Scaleform::GFx::ConstShapeWithStyles *v71; // esi
  Scaleform::RefCountVImpl *v72; // ecx
  Scaleform::Render::ShapeMeshProvider *v73; // eax
  Scaleform::Render::ShapeMeshProvider *v74; // eax
  Scaleform::Render::ShapeMeshProvider *v75; // esi
  Scaleform::Render::ShapeMeshProvider *v76; // eax
  unsigned int v77; // edi
  Scaleform::GFx::AS2::Environment **p_Env; // esi
  Scaleform::RefCountVImpl *v79; // ecx
  Scaleform::GFx::AS2::Environment **v80; // esi
  Scaleform::RefCountVImpl *v81; // ecx
  Scaleform::RefCountVImpl **p_pFill; // esi
  unsigned int Size; // edi
  Scaleform::Render::FillStyleType *v84; // ebx
  Scaleform::RefCountVImpl **v85; // esi
  unsigned int v86; // edi
  Scaleform::GFx::TagType TagType; // [esp+Eh] [ebp-F0h]
  Scaleform::GFx::TagType v88; // [esp+Eh] [ebp-F0h]
  bool v89; // [esp+39h] [ebp-C5h] BYREF
  Scaleform::GFx::MorphCharacterDef *v90; // [esp+3Ah] [ebp-C4h]
  int p_Flags; // [esp+3Eh] [ebp-C0h] BYREF
  int v92; // [esp+42h] [ebp-BCh] BYREF
  Scaleform::GFx::ConstShapeWithStyles *v93; // [esp+46h] [ebp-B8h]
  unsigned int strokeStyleCount; // [esp+4Ah] [ebp-B4h]
  int v95; // [esp+4Eh] [ebp-B0h] BYREF
  int v96; // [esp+52h] [ebp-ACh] BYREF
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> v97; // [esp+56h] [ebp-A8h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy> fillStyles; // [esp+62h] [ebp-9Ch] BYREF
  int v99; // [esp+6Eh] [ebp-90h] BYREF
  unsigned int fillStyleCount; // [esp+72h] [ebp-8Ch]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+76h] [ebp-88h] BYREF
  Scaleform::Render::FillStyleType v102; // [esp+82h] [ebp-7Ch] BYREF
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::ArraySortFunctor,Scaleform::AllocatorGH<Scaleform::GFx::AS2::ArraySortFunctor,2>,Scaleform::ArrayDefaultPolicy> v103; // [esp+8Ah] [ebp-74h] BYREF
  Scaleform::Render::FillStyleType v104; // [esp+96h] [ebp-68h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+9Eh] [ebp-60h] BYREF
  Scaleform::Render::Rect<float> v106; // [esp+AEh] [ebp-50h] BYREF
  Scaleform::Render::Rect<float> v107; // [esp+BEh] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> v108; // [esp+CEh] [ebp-30h] BYREF
  Scaleform::Render::FillStyleType v109; // [esp+E6h] [ebp-18h] BYREF
  Scaleform::Render::Color v110; // [esp+EEh] [ebp-10h] BYREF
  Scaleform::Render::Color v111; // [esp+F2h] [ebp-Ch] BYREF
  Scaleform::Render::FillStyleType v112; // [esp+F6h] [ebp-8h] BYREF

  pAltStream = p->pAltStream;
  v90 = this;
  if ( pAltStream )
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)pAltStream;
  else
    p_ProcessInfo = &p->ProcessInfo;
  pr.x1 = 0.0;
  pr.y1 = 0.0;
  pr.x2 = 0.0;
  pr.y2 = 0.0;
  v108.x1 = 0.0;
  v108.y1 = 0.0;
  v108.x2 = 0.0;
  v108.y2 = 0.0;
  v106.x1 = 0.0;
  v106.y1 = 0.0;
  v106.x2 = 0.0;
  v106.y2 = 0.0;
  v107.x1 = 0.0;
  v107.y1 = 0.0;
  v107.x2 = 0.0;
  v107.y2 = 0.0;
  Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &pr);
  Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &v108);
  if ( tagInfo->TagType == Tag_DefineShapeMorph2 )
  {
    Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &v106);
    Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &v107);
    v6 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
    p_ProcessInfo->Stream.UnusedBits = 0;
    if ( v6 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
    ++p_ProcessInfo->Stream.Pos;
  }
  else
  {
    v106.x1 = pr.x1;
    v106.y1 = pr.y1;
    v106.x2 = pr.x2;
    v106.y2 = pr.y2;
    v107.x1 = v108.x1;
    v107.y1 = v108.y1;
    v107.x2 = v108.x2;
    v107.y2 = v108.y2;
  }
  v7 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
  memset(&fillStyles, 0, sizeof(fillStyles));
  memset(&v97, 0, sizeof(v97));
  p_ProcessInfo->Stream.UnusedBits = 0;
  if ( v7 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 4);
  Pos = p_ProcessInfo->Stream.Pos;
  DataSize = p_ProcessInfo->Stream.DataSize;
  v99 = p_ProcessInfo->Stream.pBuffer[Pos]
      | ((p_ProcessInfo->Stream.pBuffer[Pos + 1] | (*(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[Pos + 2] << 8)) << 8);
  Pos += 4;
  v10 = Pos + p_ProcessInfo->Stream.FilePos - DataSize;
  p_ProcessInfo->Stream.Pos = Pos;
  v96 = v10;
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
  v89 = 0;
  if ( v13 )
  {
    strokeStyleCount = v13;
    do
    {
      TagType = tagInfo->TagType;
      v104.pFill.pObject = 0;
      v112.pFill.pObject = 0;
      Scaleform::GFx::MorphCharacterDef::ReadMorphFillStyle(v90, p, TagType, &v104, &v112, &v89);
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &fillStyles,
        &fillStyles,
        fillStyles.Size + 1);
      v17 = &fillStyles.Data[fillStyles.Size - 1];
      pObject = v104.pFill.pObject;
      if ( &fillStyles.Data[fillStyles.Size] != (Scaleform::Render::FillStyleType *)8 )
      {
        v17->Color = v104.Color;
        if ( pObject )
          Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
        v17->pFill.pObject = pObject;
      }
      Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
        &v97,
        &v97,
        v97.Size + 1);
      v19 = v112.pFill.pObject;
      v20 = &v97.Data[v97.Size - 1];
      if ( &v97.Data[v97.Size] != (Scaleform::Render::FillStyleType *)8 )
      {
        v20->Color = v112.Color;
        if ( v19 )
          Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v19);
        v20->pFill.pObject = v19;
      }
      if ( v19 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19);
      if ( v104.pFill.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v104.pFill.pObject);
      --strokeStyleCount;
    }
    while ( strokeStyleCount );
  }
  memset(&pheapAddr, 0, sizeof(pheapAddr));
  memset(&v103, 0, sizeof(v103));
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
    &pheapAddr,
    &pheapAddr,
    (v22 >> 2) + v22);
  pheapAddr.Size = v22;
  if ( v22 )
  {
    p_LogPtr = &pheapAddr.Data->LogPtr;
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
    &v103,
    &v103,
    (v22 >> 2) + v22);
  Data = v103.Data;
  v103.Size = v22;
  if ( v22 )
  {
    v29 = &v103.Data->LogPtr;
    v30 = v22;
    do
    {
      if ( v29 != (const Scaleform::Log **)24 )
      {
        *(v29 - 1) = 0;
        *v29 = 0;
      }
      v29 += 7;
      --v30;
    }
    while ( v30 );
    p_Flags = (int)&Data->Func.Flags;
    v93 = (Scaleform::GFx::ConstShapeWithStyles *)v22;
    p_pLocalFrame = &pheapAddr.Data->Func.pLocalFrame;
    v95 = (char *)Data - (char *)pheapAddr.Data;
    v32 = (char *)Data - (char *)pheapAddr.Data;
    do
    {
      v33 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( v33 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
      v34 = p_ProcessInfo->Stream.Pos;
      v92 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v34];
      p_ProcessInfo->Stream.Pos = v34 + 2;
      *((float *)p_pLocalFrame - 3) = (float)v92;
      v35 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( v35 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
      v36 = p_ProcessInfo->Stream.Pos;
      v37 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v36];
      p_ProcessInfo->Stream.Pos = v36 + 2;
      v92 = v37;
      *(float *)(p_Flags - 16) = (float)v37;
      *(Scaleform::GFx::AS2::LocalFrame **)((char *)p_pLocalFrame + v32 - 4) = 0;
      *(p_pLocalFrame - 1) = 0;
      *(float *)((char *)p_pLocalFrame + v32 - 8) = 0.050000001;
      *((float *)p_pLocalFrame - 2) = 0.050000001;
      *(float *)((char *)p_pLocalFrame + v32) = 3.0;
      *(float *)p_pLocalFrame = 3.0;
      if ( tagInfo->TagType == Tag_DefineShapeMorph2 )
      {
        v38 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
        p_ProcessInfo->Stream.UnusedBits = 0;
        if ( v38 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
        v39 = p_ProcessInfo->Stream.Pos;
        v40 = *(_WORD *)&p_ProcessInfo->Stream.pBuffer[v39];
        p_ProcessInfo->Stream.Pos = v39 + 2;
        v41 = Scaleform::GFx::ConvertSwfLineStyles(v40);
        *(Scaleform::GFx::AS2::LocalFrame **)((char *)p_pLocalFrame + v32 - 4) = (Scaleform::GFx::AS2::LocalFrame *)v41;
        *(p_pLocalFrame - 1) = (Scaleform::GFx::AS2::LocalFrame *)v41;
        if ( (v41 & 0x20) != 0 )
        {
          v42 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
          p_ProcessInfo->Stream.UnusedBits = 0;
          if ( v42 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&p_ProcessInfo->Stream, 2);
          v43 = p_ProcessInfo->Stream.Pos;
          v44 = *(unsigned __int16 *)&p_ProcessInfo->Stream.pBuffer[v43];
          p_ProcessInfo->Stream.Pos = v43 + 2;
          *(float *)&v92 = (double)v44 * 0.00390625;
          v45 = *(float *)&v92;
          *(int *)((char *)p_pLocalFrame + v32) = v92;
          *(float *)p_pLocalFrame = v45;
        }
      }
      if ( (*(_BYTE *)(p_pLocalFrame - 1) & 8) != 0 )
      {
        v88 = tagInfo->TagType;
        v102.pFill.pObject = 0;
        v109.pFill.pObject = 0;
        Scaleform::GFx::MorphCharacterDef::ReadMorphFillStyle(v90, p, v88, &v102, &v109, &v89);
        v46 = v102.pFill.pObject;
        p_pLocalFrame[1] = (Scaleform::GFx::AS2::LocalFrame *)v102.Color;
        if ( v46 )
          Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v46);
        v47 = (Scaleform::RefCountVImpl *)p_pLocalFrame[2];
        if ( v47 )
          Scaleform::RefCountImpl::Release(v47);
        v48 = (Scaleform::GFx::Resource *)v109.pFill.pObject;
        Color = v109.Color;
        v50 = (unsigned int *)p_Flags;
        p_pLocalFrame[2] = (Scaleform::GFx::AS2::LocalFrame *)v102.pFill.pObject;
        *v50 = Color;
        if ( v48 )
        {
          Scaleform::RefCountImpl::AddRef(v48);
          v50 = (unsigned int *)p_Flags;
        }
        v51 = (Scaleform::RefCountVImpl *)v50[1];
        if ( v51 )
        {
          Scaleform::RefCountImpl::Release(v51);
          v50 = (unsigned int *)p_Flags;
        }
        v52 = v102.pFill.pObject;
        v50[1] = (unsigned int)v48;
        v53 = v52->pGradient.pObject;
        if ( v53 && v53->RecordCount )
          p_pLocalFrame[1] = (Scaleform::GFx::AS2::LocalFrame *)v53->pRecords->ColorV.Raw;
        v54 = v48[1].__vftable;
        if ( v54 && HIWORD(v54->GetResourceTypeCode) )
          *v50 = *((_DWORD *)v54->GetResourceReport + 1);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v48);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v102.pFill.pObject);
        v32 = v95;
      }
      else
      {
        Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &v111, tagInfo->TagType);
        Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &v110, tagInfo->TagType);
        Raw = v110.Raw;
        v56 = (unsigned int *)p_Flags;
        p_pLocalFrame[1] = (Scaleform::GFx::AS2::LocalFrame *)v111.Raw;
        *v56 = Raw;
      }
      p_Flags += 28;
      p_pLocalFrame += 7;
      v93 = (Scaleform::GFx::ConstShapeWithStyles *)((char *)v93 - 1);
    }
    while ( v93 );
  }
  v57 = p_ProcessInfo->Stream.FilePos + p_ProcessInfo->Stream.Pos - p_ProcessInfo->Stream.DataSize;
  v58 = v99 + v96;
  if ( v99 + v96 < v57 )
  {
    v62 = v90;
    v92 = 2;
    v67 = (Scaleform::GFx::ShapeDataBase *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             v90,
                                             64,
                                             &v92);
    v68 = (Scaleform::GFx::ConstShapeWithStyles *)v67;
    if ( v67 )
    {
      Scaleform::GFx::ShapeDataBase::ShapeDataBase(v67, Empty_Shape);
      v68->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
      v68->Styles = 0;
      v68->FillStylesNum = 0;
      v68->StrokeStylesNum = 0;
      v68->Bound.x1 = 0.0;
      v68->Bound.y1 = 0.0;
      v68->Bound.x2 = 0.0;
      v68->Bound.y2 = 0.0;
      v68->RectBound.x1 = 0.0;
      v68->RectBound.y1 = 0.0;
      v68->RectBound.x2 = 0.0;
      v68->RectBound.y2 = 0.0;
    }
    else
    {
      v68 = 0;
    }
    v69 = (Scaleform::RefCountVImpl *)v62->pShape1.pObject;
    if ( v69 )
      Scaleform::RefCountImpl::Release(v69);
    v62->pShape1.pObject = v68;
    v95 = 2;
    v70 = (Scaleform::GFx::ShapeDataBase *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             v62,
                                             64,
                                             &v95);
    v71 = (Scaleform::GFx::ConstShapeWithStyles *)v70;
    if ( v70 )
    {
      Scaleform::GFx::ShapeDataBase::ShapeDataBase(v70, Empty_Shape);
      v71->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
      v71->Styles = 0;
      v71->FillStylesNum = 0;
      v71->StrokeStylesNum = 0;
      v71->Bound.x1 = 0.0;
      v71->Bound.y1 = 0.0;
      v71->Bound.x2 = 0.0;
      v71->Bound.y2 = 0.0;
      v71->RectBound.x1 = 0.0;
      v71->RectBound.y1 = 0.0;
      v71->RectBound.x2 = 0.0;
      v71->RectBound.y2 = 0.0;
    }
    else
    {
      v71 = 0;
    }
    v72 = (Scaleform::RefCountVImpl *)v62->pShape2.pObject;
    if ( v72 )
      Scaleform::RefCountImpl::Release(v72);
    v66 = strokeStyleCount;
    v62->pShape2.pObject = v71;
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &p_ProcessInfo->Stream,
      "MorphCharacterDef, first shape:\n");
    v96 = 2;
    v59 = (Scaleform::GFx::ConstShapeWithStyles *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    v90,
                                                    64,
                                                    &v96);
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
      v93 = v59;
      v59->Bound.x2 = 0.0;
      v59->Bound.y2 = 0.0;
      v59->RectBound.x1 = 0.0;
      v59->RectBound.y1 = 0.0;
      v59->RectBound.x2 = 0.0;
      v59->RectBound.y2 = 0.0;
    }
    else
    {
      v93 = 0;
    }
    v60 = (Scaleform::RefCountVImpl *)v90->pShape1.pObject;
    if ( v60 )
      Scaleform::RefCountImpl::Release(v60);
    v61 = v93;
    v90->pShape1.pObject = v93;
    v61->Read(v61, p, tagInfo->TagType, v58 - v57, 0);
    Scaleform::GFx::ConstShapeWithStyles::SetStyles(
      v90->pShape1.pObject,
      fillStyleCount,
      fillStyles.Data,
      strokeStyleCount,
      (const Scaleform::Render::StrokeStyleType *)pheapAddr.Data);
    v62 = v90;
    if ( v89 )
      v90->pShape1.pObject->Flags |= 4u;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
      &p_ProcessInfo->Stream,
      "MorphCharacterDef, second shape:\n");
    Scaleform::GFx::Stream::SetPosition(&p_ProcessInfo->Stream, v58);
    v99 = 2;
    v63 = Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, v62, 64, &v99);
    if ( v63 )
    {
      *v63 = &Scaleform::RefCountImplCore::`vftable';
      v63[1] = 1;
      v63[2] = 0;
      *((_BYTE *)v63 + 12) = 0;
      *v63 = &Scaleform::GFx::ConstShapeWithStyles::`vftable';
      v63[4] = 0;
      v63[5] = 0;
      v63[6] = 0;
      *((float *)v63 + 8) = 0.0;
      *((float *)v63 + 9) = 0.0;
      v64 = (Scaleform::GFx::ConstShapeWithStyles *)v63;
      *((float *)v63 + 10) = 0.0;
      *((float *)v63 + 11) = 0.0;
      *((float *)v63 + 12) = 0.0;
      *((float *)v63 + 13) = 0.0;
      *((float *)v63 + 14) = 0.0;
      *((float *)v63 + 15) = 0.0;
    }
    else
    {
      v64 = 0;
    }
    v65 = (Scaleform::RefCountVImpl *)v62->pShape2.pObject;
    if ( v65 )
      Scaleform::RefCountImpl::Release(v65);
    v62->pShape2.pObject = v64;
    v64->Read(v64, p, tagInfo->TagType, tagInfo->TagLength + tagInfo->TagDataOffset - v58, 0);
    v66 = strokeStyleCount;
    Scaleform::GFx::ConstShapeWithStyles::SetStyles(
      v62->pShape2.pObject,
      fillStyleCount,
      v97.Data,
      strokeStyleCount,
      (const Scaleform::Render::StrokeStyleType *)v103.Data);
    if ( v89 )
      v62->pShape2.pObject->Flags |= 4u;
  }
  p_Flags = 2;
  v73 = (Scaleform::Render::ShapeMeshProvider *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v62,
                                                  96,
                                                  &p_Flags);
  if ( v73 )
  {
    Scaleform::Render::ShapeMeshProvider::ShapeMeshProvider(
      v73,
      (Scaleform::GFx::Resource *)v62->pShape1.pObject,
      (Scaleform::GFx::Resource *)v62->pShape2.pObject);
    v75 = v74;
  }
  else
  {
    v75 = 0;
  }
  v76 = v62->pShapeMeshProvider.pObject;
  if ( v76 )
    v76->Release(&v76->Scaleform::Render::MeshProvider);
  v62->pShapeMeshProvider.pObject = v75;
  v77 = v66;
  if ( v66 )
  {
    p_Env = &v103.Data[v77 - 1].Env;
    v93 = (Scaleform::GFx::ConstShapeWithStyles *)v66;
    do
    {
      v79 = (Scaleform::RefCountVImpl *)p_Env[1];
      if ( v79 )
        Scaleform::RefCountImpl::Release(v79);
      if ( *p_Env )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)*p_Env);
      p_Env -= 7;
      v93 = (Scaleform::GFx::ConstShapeWithStyles *)((char *)v93 - 1);
    }
    while ( v93 );
  }
  if ( v103.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v103.Data);
  if ( v66 )
  {
    v80 = &pheapAddr.Data[v77 - 1].Env;
    do
    {
      v81 = (Scaleform::RefCountVImpl *)v80[1];
      if ( v81 )
        Scaleform::RefCountImpl::Release(v81);
      if ( *v80 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)*v80);
      v80 -= 7;
      --v66;
    }
    while ( v66 );
  }
  if ( pheapAddr.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
  if ( v97.Size )
  {
    p_pFill = (Scaleform::RefCountVImpl **)&v97.Data[v97.Size - 1].pFill;
    Size = v97.Size;
    do
    {
      if ( *p_pFill )
        Scaleform::RefCountImpl::Release(*p_pFill);
      p_pFill -= 2;
      --Size;
    }
    while ( Size );
  }
  if ( v97.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v97.Data);
  v84 = fillStyles.Data;
  if ( fillStyles.Size )
  {
    v85 = (Scaleform::RefCountVImpl **)&fillStyles.Data[fillStyles.Size - 1].pFill;
    v86 = fillStyles.Size;
    do
    {
      if ( *v85 )
        Scaleform::RefCountImpl::Release(*v85);
      v85 -= 2;
      --v86;
    }
    while ( v86 );
  }
  if ( v84 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v84);
}
