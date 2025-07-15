void __thiscall Scaleform::GFx::FillStyleSwfReader::Read(
        Scaleform::GFx::FillStyleSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        int tagType)
{
  Scaleform::GFx::LoadProcess *v3; // ebx
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v5; // eax
  unsigned int Pos; // eax
  unsigned __int8 v7; // cl
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *p_pFill; // esi
  Scaleform::GFx::SWFProcessInfo *v11; // eax
  double v12; // st7
  Scaleform::GFx::SWFProcessInfo *v13; // esi
  int v14; // edx
  unsigned int v15; // eax
  unsigned __int8 v16; // cl
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
  Scaleform::Render::GradientData *v28; // edi
  Scaleform::Render::ComplexFill *v29; // esi
  Scaleform::RefCountVImpl *v30; // ecx
  Scaleform::Ptr<Scaleform::Render::GradientData> *p_pGradient; // esi
  signed int i; // edi
  Scaleform::GFx::Stream *p_Stream; // esi
  int v34; // edx
  unsigned int v35; // eax
  unsigned __int8 v36; // bl
  Scaleform::Render::GradientData *v37; // esi
  float *v38; // eax
  Scaleform::GFx::SWFProcessInfo *v39; // eax
  Scaleform::GFx::SWFProcessInfo *v40; // eax
  Scaleform::Render::ComplexFill *v41; // eax
  signed int v42; // eax
  Scaleform::RefCountVImpl *v43; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v44; // esi
  Scaleform::Render::Image *v45; // ebx
  Scaleform::Ptr<Scaleform::Render::Image> *p_pImage; // esi
  Scaleform::GFx::TempBindData *pTempBindData; // ebx
  Scaleform::RefCountVImpl *v48; // ecx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v49; // esi
  unsigned int Raw; // eax
  unsigned __int8 v51; // [esp+1Bh] [ebp-79h]
  Scaleform::Render::Color U16; // [esp+20h] [ebp-74h] BYREF
  signed int EntryCount; // [esp+24h] [ebp-70h]
  int v55; // [esp+28h] [ebp-6Ch]
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType recordCount; // [esp+2Ch] [ebp-68h] BYREF
  Scaleform::Render::Matrix2x4<float> matrix; // [esp+34h] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> pm; // [esp+54h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+74h] [ebp-20h] BYREF

  v3 = p;
  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v5 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v5 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  v7 = pAltStream->Stream.pBuffer[Pos];
  pAltStream->Stream.Pos = Pos + 1;
  v51 = v7;
  U16 = 0;
  v55 = v7;
  Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
    &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
    "  FillStyle read type = 0x%X\n",
    v7);
  if ( !v51 )
  {
    Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &U16, tagType);
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  color: ");
    if ( p->pAltStream )
      p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    else
      p_ProcessInfo = &p->ProcessInfo;
    Scaleform::GFx::Stream::LogParseClass(&p_ProcessInfo->Stream, U16);
    this->FillStyle->Color = U16.Raw;
    pObject = (Scaleform::RefCountVImpl *)this->FillStyle->pFill.pObject;
    p_pFill = &this->FillStyle->pFill;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    p_pFill->pObject = 0;
    return;
  }
  if ( (v51 & 0x10) != 0 )
  {
    v11 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    pm.M[0][0] = 1.0;
    pm.M[0][1] = 0.0;
    pm.M[0][2] = 0.0;
    pm.M[0][3] = 0.0;
    pm.M[1][0] = 0.0;
    pm.M[1][2] = 0.0;
    pm.M[1][3] = 0.0;
    pm.M[1][1] = 1.0;
    if ( !v11 )
      v11 = &p->ProcessInfo;
    Scaleform::GFx::Stream::ReadMatrix(&v11->Stream, &pm);
    matrix.M[0][0] = 1.0;
    matrix.M[0][1] = 0.0;
    matrix.M[0][2] = 0.0;
    matrix.M[0][3] = 0.0;
    matrix.M[1][0] = 0.0;
    matrix.M[1][2] = 0.0;
    matrix.M[1][3] = 0.0;
    matrix.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::AppendScaling(&matrix, 0.000030517578);
    matrix.M[0][3] = matrix.M[0][3] + 0.5;
    if ( v51 == 16 )
      v12 = matrix.M[1][3] + 0.0;
    else
      v12 = matrix.M[1][3] + 0.5;
    matrix.M[1][3] = v12;
    m.M[0][0] = 1.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    m.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&m, &pm);
    Scaleform::Render::Matrix2x4<float>::Prepend(&matrix, &m);
    v13 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v13 )
      v13 = &p->ProcessInfo;
    v14 = v13->Stream.DataSize - v13->Stream.Pos;
    v13->Stream.UnusedBits = 0;
    if ( v14 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&v13->Stream);
    v15 = v13->Stream.Pos;
    v16 = v13->Stream.pBuffer[v15];
    v13->Stream.Pos = v15 + 1;
    if ( (v16 & 0x10) != 0 )
      U16 = (Scaleform::Render::Color)1;
    recordCount.EntryCount = v16 & 0xF;
    EntryCount = recordCount.EntryCount;
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  gradients: numGradients = %d\n",
      recordCount.EntryCount);
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
    v23 = v55 - 16;
    v22 = v55 == 16;
    v21->pObject = v19;
    if ( !v22 )
    {
      v24 = v23 - 2;
      if ( !v24 )
      {
        v25 = GradientRadial;
        goto LABEL_35;
      }
      if ( v24 == 1 )
      {
        v25 = GradientFocalPoint;
LABEL_35:
        v26 = (Scaleform::Render::GradientData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   24,
                                                   0);
        if ( v26 )
        {
          Scaleform::Render::GradientData::GradientData(v26, v25, recordCount.EntryCount, U16.Channels.Blue & 1);
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
        p_pGradient->pObject = v28;
        for ( i = 0; i < EntryCount; ++i )
        {
          p_Stream = v3->pAltStream;
          if ( !p_Stream )
            p_Stream = &v3->ProcessInfo.Stream;
          v34 = p_Stream->DataSize - p_Stream->Pos;
          p_Stream->UnusedBits = 0;
          if ( v34 < 1 )
            Scaleform::GFx::Stream::PopulateBuffer1(p_Stream);
          v35 = p_Stream->Pos;
          v36 = p_Stream->pBuffer[v35];
          p_Stream->Pos = v35 + 1;
          Scaleform::GFx::LoadProcess::ReadRgbaTag(p, (Scaleform::Render::Color *)&recordCount, tagType);
          this->FillStyle->pFill.pObject->pGradient.pObject->pRecords[i].ColorV.Raw = recordCount.EntryCount;
          this->FillStyle->pFill.pObject->pGradient.pObject->pRecords[i].Ratio = v36;
          v3 = p;
        }
        if ( v51 == 19 )
        {
          v37 = this->FillStyle->pFill.pObject->pGradient.pObject;
          recordCount.EntryCount = (__int16)Scaleform::GFx::LoadProcess::ReadU16(v3);
          v37->FocalRatio = (double)(int)recordCount.EntryCount * 0.00390625;
        }
        v38 = (float *)this->FillStyle->pFill.pObject;
        v38[4] = matrix.M[0][0];
        v38 += 4;
        v38[1] = matrix.M[0][1];
        v38[2] = matrix.M[0][2];
        v38[3] = matrix.M[0][3];
        v38[4] = matrix.M[1][0];
        v38[5] = matrix.M[1][1];
        v38[6] = matrix.M[1][2];
        v38[7] = matrix.M[1][3];
        return;
      }
    }
    v25 = GradientLinear;
    goto LABEL_35;
  }
  if ( (v51 & 0x40) != 0 )
  {
    U16 = (Scaleform::Render::Color)(unsigned __int16)Scaleform::GFx::LoadProcess::ReadU16(p);
    Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>::LogParse(
      &p->Scaleform::GFx::LogBase<Scaleform::GFx::LoadProcess>,
      "  BitmapChar = %d\n",
      U16);
    v39 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    matrix.M[0][0] = 1.0;
    matrix.M[0][1] = 0.0;
    matrix.M[0][2] = 0.0;
    matrix.M[0][3] = 0.0;
    matrix.M[1][0] = 0.0;
    matrix.M[1][2] = 0.0;
    matrix.M[1][3] = 0.0;
    matrix.M[1][1] = 1.0;
    if ( !v39 )
      v39 = &p->ProcessInfo;
    Scaleform::GFx::Stream::ReadMatrix(&v39->Stream, &matrix);
    v40 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    if ( !v40 )
      v40 = &p->ProcessInfo;
    Scaleform::GFx::Stream::LogParseClass(&v40->Stream, &matrix);
    recordCount.EntryCount = 0;
    recordCount.SizeMask = 0;
    Scaleform::Render::Matrix2x4<float>::GetInverse(&matrix, &m);
    v41 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v41 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v41);
      EntryCount = v42;
    }
    else
    {
      EntryCount = 0;
    }
    v43 = (Scaleform::RefCountVImpl *)this->FillStyle->pFill.pObject;
    v44 = &this->FillStyle->pFill;
    if ( v43 )
      Scaleform::RefCountImpl::Release(v43);
    v44->pObject = (Scaleform::Render::ComplexFill *)EntryCount;
    Scaleform::Render::Matrix2x4<float>::operator=(&this->FillStyle->pFill.pObject->ImageMatrix, &m);
    switch ( v55 )
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
    if ( Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
           p->pLoadData.pObject,
           &recordCount,
           (Scaleform::GFx::ResourceId)U16)
      && !recordCount.EntryCount
      && recordCount.SizeMask )
    {
      if ( ((*(int (__thiscall **)(unsigned int))(*(_DWORD *)recordCount.SizeMask + 8))(recordCount.SizeMask) & 0xFF00) == 0x100 )
      {
        v45 = *(Scaleform::Render::Image **)(recordCount.EntryCount == 0 ? recordCount.SizeMask + 0xC : 12);
        p_pImage = &this->FillStyle->pFill.pObject->pImage;
        if ( v45 )
          v45->AddRef(*(struct Scaleform::Render::Image **)(recordCount.EntryCount == 0 ? recordCount.SizeMask + 0xC : 12));
        if ( p_pImage->pObject )
          p_pImage->pObject->Release(p_pImage->pObject);
        p_pImage->pObject = v45;
      }
    }
    else
    {
      this->FillStyle->Color = -5776071;
      if ( recordCount.EntryCount == 1 )
      {
        this->FillStyle->pFill.pObject->BindIndex = recordCount.SizeMask;
        pTempBindData = p->pTempBindData;
        if ( pTempBindData && (v51 == 66 || v51 == 64) )
          Scaleform::HashSet<unsigned int,Scaleform::FixedSizeHash<unsigned int>,Scaleform::FixedSizeHash<unsigned int>,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedEntry<unsigned int,Scaleform::FixedSizeHash<unsigned int>>>::Add<unsigned int>(
            &pTempBindData->FillStyleImageWrap,
            &this->FillStyle->pFill.pObject->BindIndex);
      }
      else
      {
        v48 = (Scaleform::RefCountVImpl *)this->FillStyle->pFill.pObject;
        v49 = &this->FillStyle->pFill;
        if ( v48 )
          Scaleform::RefCountImpl::Release(v48);
        Raw = U16.Raw;
        v49->pObject = 0;
        if ( Raw != 0xFFFF )
          Scaleform::LogDebugMessage(
            (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
            "An image with resource id %d is not found in resource table.",
            Raw);
      }
    }
    if ( !recordCount.EntryCount && recordCount.SizeMask )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)recordCount.SizeMask);
  }
}
