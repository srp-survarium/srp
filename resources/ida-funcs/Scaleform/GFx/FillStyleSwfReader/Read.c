void __thiscall Scaleform::GFx::FillStyleSwfReader::Read(
        Scaleform::GFx::FillStyleSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v5; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pBuffer; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v8; // ecx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *p_pFill; // esi
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // eax
  double v12; // st7
  Scaleform::GFx::SWFProcessInfo *v13; // esi
  int v14; // ecx
  unsigned int v15; // eax
  unsigned __int16 v16; // bx
  Scaleform::Render::ComplexFill *v17; // eax
  Scaleform::Render::ComplexFill *v18; // eax
  Scaleform::Render::ComplexFill *v19; // edi
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v21; // esi
  bool v22; // zf
  int v23; // eax
  int v24; // eax
  Scaleform::Render::GradientType v25; // esi
  Scaleform::Render::GradientData *v26; // eax
  Scaleform::Render::GradientData *v27; // eax
  Scaleform::Render::GradientData *v28; // ebx
  Scaleform::Render::ComplexFill *v29; // esi
  Scaleform::RefCountVImpl *v30; // ecx
  Scaleform::Ptr<Scaleform::Render::GradientData> *p_pGradient; // esi
  signed int v32; // edi
  bool v33; // cc
  Scaleform::GFx::SWFProcessInfo *v34; // esi
  int v35; // ecx
  unsigned int v36; // eax
  unsigned __int8 v37; // bl
  Scaleform::Render::GradientData *v38; // esi
  float *v39; // eax
  Scaleform::GFx::SWFProcessInfo *v40; // eax
  Scaleform::Render::ComplexFill *v41; // edi
  Scaleform::Render::ComplexFill *v42; // eax
  Scaleform::Render::ComplexFill *v43; // eax
  Scaleform::RefCountVImpl *v44; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v45; // esi
  unsigned int Id; // edi
  Scaleform::Render::Image *v47; // edi
  Scaleform::Ptr<Scaleform::Render::Image> *p_pImage; // esi
  Scaleform::GFx::TempBindData *pTempBindData; // ecx
  Scaleform::RefCountVImpl *v50; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v51; // esi
  char v52; // [esp+3A1h] [ebp-75h]
  Scaleform::GFx::ResourceHandle phandle; // [esp+3A6h] [ebp-70h] BYREF
  Scaleform::GFx::ResourceId v55; // [esp+3AEh] [ebp-68h]
  Scaleform::Render::Color pc; // [esp+3B2h] [ebp-64h] BYREF
  Scaleform::Render::Matrix2x4<float> v57; // [esp+3B6h] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> pm; // [esp+3D6h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+3F6h] [ebp-20h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v5 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v5 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  pBuffer = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pAltStream->Stream.pBuffer;
  LOBYTE(pBuffer) = *((_BYTE *)&pBuffer->__vftable + Pos);
  pAltStream->Stream.Pos = Pos + 1;
  v52 = (char)pBuffer;
  phandle.HType = RH_Pointer;
  pc = (Scaleform::Render::Color)(unsigned __int8)pBuffer;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(pBuffer);
  if ( !v52 )
  {
    Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &pc, tagType);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v8);
    this->FillStyle->Color = pc.Raw;
    pObject = (Scaleform::RefCountVImpl *)this->FillStyle->pFill.pObject;
    p_pFill = &this->FillStyle->pFill;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    p_pFill->pObject = 0;
    return;
  }
  if ( (v52 & 0x10) != 0 )
  {
    p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    pm.M[0][0] = 1.0;
    pm.M[0][1] = 0.0;
    pm.M[0][2] = 0.0;
    pm.M[0][3] = 0.0;
    pm.M[1][0] = 0.0;
    pm.M[1][2] = 0.0;
    pm.M[1][3] = 0.0;
    pm.M[1][1] = 1.0;
    if ( !p_ProcessInfo )
      p_ProcessInfo = &p->ProcessInfo;
    Scaleform::GFx::Stream::ReadMatrix(&p_ProcessInfo->Stream, &pm);
    v57.M[0][0] = 1.0;
    v57.M[0][1] = 0.0;
    v57.M[0][2] = 0.0;
    v57.M[0][3] = 0.0;
    v57.M[1][0] = 0.0;
    v57.M[1][2] = 0.0;
    v57.M[1][3] = 0.0;
    v57.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::AppendScaling(&v57, 0.000030517578);
    v57.M[0][3] = v57.M[0][3] + 0.5;
    if ( v52 == 16 )
      v12 = v57.M[1][3] + 0.0;
    else
      v12 = v57.M[1][3] + 0.5;
    v57.M[1][3] = v12;
    m.M[0][0] = 1.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    m.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&m, &pm);
    Scaleform::Render::Matrix2x4<float>::Prepend(&v57, &m);
    if ( p->pAltStream )
      v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    else
      v13 = &p->ProcessInfo;
    v14 = v13->Stream.DataSize - v13->Stream.Pos;
    v13->Stream.UnusedBits = 0;
    if ( v14 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&v13->Stream);
    v15 = v13->Stream.Pos;
    LOBYTE(v14) = v13->Stream.pBuffer[v15];
    v13->Stream.Pos = v15 + 1;
    if ( (v14 & 0x10) != 0 )
      phandle.HType = RH_Index;
    v16 = v14 & 0xF;
    v55.Id = v14 & 0xF;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v14);
    v17 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v17 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v17);
      v19 = v18;
    }
    else
    {
      v19 = 0;
    }
    v20 = (Scaleform::RefCountVImpl *)this->FillStyle->pFill.pObject;
    v21 = &this->FillStyle->pFill;
    if ( v20 )
      Scaleform::RefCountImpl::Release(v20);
    v23 = *(_DWORD *)&pc - 16;
    v22 = pc == 16;
    v21->pObject = v19;
    if ( !v22 )
    {
      v24 = v23 - 2;
      if ( !v24 )
      {
        v25 = GradientRadial;
        goto LABEL_33;
      }
      if ( v24 == 1 )
      {
        v25 = GradientFocalPoint;
LABEL_33:
        v26 = (Scaleform::Render::GradientData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   24,
                                                   0);
        if ( v26 )
        {
          Scaleform::Render::GradientData::GradientData(v26, v25, v16, phandle.HType & 1);
          v28 = v27;
        }
        else
        {
          v28 = 0;
        }
        v29 = this->FillStyle->pFill.pObject;
        v30 = (Scaleform::RefCountVImpl *)v29->pGradient.pObject;
        p_pGradient = &v29->pGradient;
        if ( v30 )
          Scaleform::RefCountImpl::Release(v30);
        v32 = 0;
        v33 = (int)v55.Id <= 0;
        p_pGradient->pObject = v28;
        if ( !v33 )
        {
          do
          {
            v34 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
            if ( !v34 )
              v34 = &p->ProcessInfo;
            v35 = v34->Stream.DataSize - v34->Stream.Pos;
            v34->Stream.UnusedBits = 0;
            if ( v35 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&v34->Stream);
            v36 = v34->Stream.Pos;
            v37 = v34->Stream.pBuffer[v36];
            v34->Stream.Pos = v36 + 1;
            Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &pc, tagType);
            this->FillStyle->pFill.pObject->pGradient.pObject->pRecords[v32].ColorV = pc;
            this->FillStyle->pFill.pObject->pGradient.pObject->pRecords[v32++].Ratio = v37;
          }
          while ( v32 < (int)v55.Id );
        }
        if ( v52 == 19 )
        {
          v38 = this->FillStyle->pFill.pObject->pGradient.pObject;
          pc = (Scaleform::Render::Color)(__int16)Scaleform::GFx::LoadProcess::ReadU16(p);
          v38->FocalRatio = (double)(int)pc.Raw * 0.00390625;
        }
        v39 = (float *)this->FillStyle->pFill.pObject;
        v39[4] = v57.M[0][0];
        v39 += 4;
        v39[1] = v57.M[0][1];
        v39[2] = v57.M[0][2];
        v39[3] = v57.M[0][3];
        v39[4] = v57.M[1][0];
        v39[5] = v57.M[1][1];
        v39[6] = v57.M[1][2];
        v39[7] = v57.M[1][3];
        return;
      }
    }
    v25 = GradientLinear;
    goto LABEL_33;
  }
  if ( (v52 & 0x40) != 0 )
  {
    v55.Id = (unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v55.Id);
    v40 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    v41 = 0;
    m.M[0][0] = 1.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    m.M[1][1] = 1.0;
    if ( !v40 )
      v40 = &p->ProcessInfo;
    Scaleform::GFx::Stream::ReadMatrix(&v40->Stream, &m);
    phandle.HType = RH_Pointer;
    phandle.BindIndex = 0;
    Scaleform::Render::Matrix2x4<float>::GetInverse(&m, &pm);
    v42 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v42 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v42);
      v41 = v43;
    }
    v44 = (Scaleform::RefCountVImpl *)this->FillStyle->pFill.pObject;
    v45 = &this->FillStyle->pFill;
    if ( v44 )
      Scaleform::RefCountImpl::Release(v44);
    v45->pObject = v41;
    Scaleform::Render::Matrix2x4<float>::operator=(&this->FillStyle->pFill.pObject->ImageMatrix, &pm);
    switch ( pc.Raw )
    {
      case '@':
        this->FillStyle->pFill.pObject->FillMode.Fill = 2;
        break;
      case 'A':
        this->FillStyle->pFill.pObject->FillMode.Fill = 3;
        break;
      case 'B':
        this->FillStyle->pFill.pObject->FillMode.Fill = 0;
        break;
      case 'C':
        this->FillStyle->pFill.pObject->FillMode.Fill = 1;
        break;
      default:
        break;
    }
    Id = v55.Id;
    if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
           p->pLoadData.pObject,
           (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType *)&phandle,
           v55)
      && phandle.HType == RH_Pointer
      && phandle.BindIndex )
    {
      if ( ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)phandle.BindIndex + 8))(phandle.BindIndex) & 0xFF00) == 0x100 )
      {
        v47 = *(Scaleform::Render::Image **)(phandle.HType == RH_Pointer ? phandle.BindIndex + 0xC : 12);
        p_pImage = &this->FillStyle->pFill.pObject->pImage;
        if ( v47 )
          v47->AddRef(v47);
        if ( p_pImage->pObject )
          p_pImage->pObject->Release(p_pImage->pObject);
        p_pImage->pObject = v47;
      }
    }
    else
    {
      this->FillStyle->Color = -5776071;
      if ( phandle.HType == RH_Index )
      {
        this->FillStyle->pFill.pObject->BindIndex = phandle.BindIndex;
        pTempBindData = p->pTempBindData;
        if ( pTempBindData && (v52 == 66 || v52 == 64) )
          Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::Add<unsigned int>(
            &pTempBindData->FillStyleImageWrap,
            &this->FillStyle->pFill.pObject->BindIndex);
      }
      else
      {
        v50 = (Scaleform::RefCountVImpl *)this->FillStyle->pFill.pObject;
        v51 = &this->FillStyle->pFill;
        if ( v50 )
          Scaleform::RefCountImpl::Release(v50);
        v51->pObject = 0;
        if ( Id != 0xFFFF )
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)135168,
            "An image with resource id %d is not found in resource table.",
            Id);
      }
    }
    if ( phandle.HType == RH_Pointer && phandle.BindIndex )
      Scaleform::GFx::Resource::Release(phandle.pResource);
  }
}
