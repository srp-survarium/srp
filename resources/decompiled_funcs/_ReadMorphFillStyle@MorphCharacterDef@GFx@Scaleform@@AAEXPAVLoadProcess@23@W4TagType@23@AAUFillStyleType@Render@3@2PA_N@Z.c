void __thiscall Scaleform::GFx::MorphCharacterDef::ReadMorphFillStyle(
        Scaleform::GFx::MorphCharacterDef *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::GFx::TagType tagType,
        Scaleform::Render::FillStyleType *fs1,
        Scaleform::Render::FillStyleType *fs2,
        bool *needResolve)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v7; // eax
  unsigned int Pos; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *pBuffer; // ecx
  unsigned __int8 v10; // bl
  Scaleform::GFx::AS3::RefCountBaseGC<328> *EntryCount; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v12; // ecx
  double v13; // st7
  int v14; // edx
  unsigned int v15; // eax
  unsigned __int8 v16; // cl
  Scaleform::Render::ComplexFill *v17; // eax
  Scaleform::Render::ComplexFill *v18; // eax
  Scaleform::Render::ComplexFill *v19; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::ComplexFill *v21; // eax
  Scaleform::Render::ComplexFill *v22; // eax
  Scaleform::Render::ComplexFill *v23; // ebx
  Scaleform::RefCountVImpl *v24; // ecx
  bool v25; // zf
  unsigned int v26; // eax
  unsigned int v27; // eax
  Scaleform::Render::GradientData *v28; // eax
  Scaleform::Render::GradientData *v29; // eax
  Scaleform::Render::GradientData *v30; // ebx
  Scaleform::Render::ComplexFill *v31; // edi
  Scaleform::RefCountVImpl *v32; // ecx
  Scaleform::Ptr<Scaleform::Render::GradientData> *p_pGradient; // edi
  Scaleform::Render::GradientData *v34; // eax
  Scaleform::Render::GradientData *v35; // eax
  Scaleform::Render::GradientData *v36; // ebx
  Scaleform::Render::ComplexFill *v37; // edi
  Scaleform::RefCountVImpl *pRecords; // ecx
  Scaleform::Ptr<Scaleform::Render::GradientData> *v39; // edi
  unsigned int v40; // edi
  Scaleform::GFx::LoadProcess *v41; // ecx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ebx
  int v43; // edx
  unsigned int v44; // eax
  unsigned __int8 v45; // dl
  Scaleform::GFx::SWFProcessInfo *v46; // ebx
  int v47; // edx
  unsigned int v48; // eax
  unsigned __int8 v49; // dl
  int v50; // ecx
  unsigned int v51; // eax
  double Raw; // st7
  Scaleform::Render::GradientData *v53; // edx
  int v54; // eax
  unsigned int v55; // eax
  double v56; // st7
  Scaleform::Render::GradientData *v57; // edx
  float *v58; // eax
  int v59; // edx
  unsigned int v60; // eax
  Scaleform::Render::Color v61; // ecx
  Scaleform::Render::ComplexFill *v62; // esi
  Scaleform::Render::ComplexFill *v63; // eax
  Scaleform::Render::ComplexFill *v64; // eax
  Scaleform::RefCountVImpl *v65; // ecx
  Scaleform::Render::ComplexFill *v66; // eax
  Scaleform::Render::ComplexFill *v67; // eax
  Scaleform::Render::ComplexFill *v68; // edi
  Scaleform::RefCountVImpl *v69; // ecx
  char ResourceHandle; // al
  unsigned int SizeMask; // ecx
  unsigned int v72; // eax
  Scaleform::Ptr<Scaleform::Render::Image> *p_pImage; // ebx
  Scaleform::Render::Image *v74; // edi
  Scaleform::Ptr<Scaleform::Render::Image> *v75; // esi
  Scaleform::RefCountVImpl *v76; // ecx
  Scaleform::RefCountVImpl *v77; // ecx
  unsigned __int8 v78; // [esp+999h] [ebp-B1h]
  unsigned __int8 v79; // [esp+999h] [ebp-B1h]
  unsigned __int8 v80; // [esp+999h] [ebp-B1h]
  Scaleform::Render::Color pc; // [esp+99Ah] [ebp-B0h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v82; // [esp+99Eh] [ebp-ACh] BYREF
  unsigned __int8 v83; // [esp+9A9h] [ebp-A1h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+9AAh] [ebp-A0h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+9CAh] [ebp-80h] BYREF
  Scaleform::Render::Matrix2x4<float> v86; // [esp+9EAh] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> v87; // [esp+A0Ah] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> pm; // [esp+A2Ah] [ebp-20h] BYREF

  if ( p->pAltStream )
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  else
    pAltStream = &p->ProcessInfo;
  v7 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v7 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  pBuffer = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)pAltStream->Stream.pBuffer;
  v83 = *((_BYTE *)&pBuffer->__vftable + Pos);
  v10 = v83;
  pAltStream->Stream.Pos = Pos + 1;
  v82.EntryCount = v10;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(pBuffer);
  if ( !v10 )
  {
    Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, &pc);
    Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, (Scaleform::Render::Color *)&v82);
    fs1->Color = pc.Raw;
    EntryCount = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)v82.EntryCount;
    fs2->Color = v82.EntryCount;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(EntryCount);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v12);
    return;
  }
  if ( (v10 & 0x10) != 0 )
  {
    pm.M[0][0] = 1.0;
    pm.M[0][1] = 0.0;
    pm.M[0][2] = 0.0;
    pm.M[0][3] = 0.0;
    pm.M[1][0] = 0.0;
    pm.M[1][2] = 0.0;
    pm.M[1][3] = 0.0;
    v87.M[0][1] = 0.0;
    v87.M[0][2] = 0.0;
    v87.M[0][3] = 0.0;
    v87.M[1][0] = 0.0;
    v87.M[1][2] = 0.0;
    v87.M[1][3] = 0.0;
    pm.M[1][1] = 1.0;
    v87.M[0][0] = 1.0;
    v87.M[1][1] = 1.0;
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &pm);
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &v87);
    v86.M[0][0] = 1.0;
    v86.M[0][1] = 0.0;
    v86.M[0][2] = 0.0;
    v86.M[0][3] = 0.0;
    v86.M[1][0] = 0.0;
    v86.M[1][2] = 0.0;
    v86.M[1][3] = 0.0;
    result.M[0][1] = 0.0;
    result.M[0][2] = 0.0;
    result.M[0][3] = 0.0;
    result.M[1][0] = 0.0;
    result.M[1][2] = 0.0;
    result.M[1][3] = 0.0;
    v86.M[1][1] = 1.0;
    result.M[0][0] = 1.0;
    result.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::AppendScaling(&v86, 0.000030517578);
    v86.M[0][3] = v86.M[0][3] + 0.5;
    if ( v10 == 16 )
    {
      v86.M[1][3] = v86.M[1][3] + 0.0;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(&result, 0.000030517578);
      result.M[0][3] = result.M[0][3] + 0.5;
      v13 = result.M[1][3] + 0.0;
    }
    else
    {
      v86.M[1][3] = v86.M[1][3] + 0.5;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(&result, 0.000030517578);
      result.M[0][3] = result.M[0][3] + 0.5;
      v13 = result.M[1][3] + 0.5;
    }
    result.M[1][3] = v13;
    m.M[0][0] = 1.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    m.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&m, &pm);
    Scaleform::Render::Matrix2x4<float>::Prepend(&v86, &m);
    m.M[0][0] = 1.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    m.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&m, &v87);
    Scaleform::Render::Matrix2x4<float>::Prepend(&result, &m);
    v14 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v14 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    v15 = pAltStream->Stream.Pos;
    v16 = pAltStream->Stream.pBuffer[v15];
    v78 = v16;
    pAltStream->Stream.Pos = v15 + 1;
    pc.Channels.Blue = 0;
    if ( tagType == Tag_DefineShapeMorph2 || v10 == 19 )
    {
      if ( (v16 & 0x10) != 0 )
        pc.Channels.Blue = 1;
      v78 = v16 & 0xF;
    }
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
    pObject = (Scaleform::RefCountVImpl *)fs1->pFill.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    fs1->pFill.pObject = v19;
    v21 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v21 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v21);
      v23 = v22;
    }
    else
    {
      v23 = 0;
    }
    v24 = (Scaleform::RefCountVImpl *)fs2->pFill.pObject;
    if ( v24 )
      Scaleform::RefCountImpl::Release(v24);
    v26 = v82.EntryCount - 16;
    v25 = v82.EntryCount == 16;
    fs2->pFill.pObject = v23;
    if ( !v25 )
    {
      v27 = v26 - 2;
      if ( !v27 )
      {
        v82.EntryCount = 1;
        goto LABEL_35;
      }
      if ( v27 == 1 )
      {
        v82.EntryCount = 2;
LABEL_35:
        v28 = (Scaleform::Render::GradientData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   24,
                                                   0);
        if ( v28 )
        {
          Scaleform::Render::GradientData::GradientData(
            v28,
            (Scaleform::Render::GradientType)v82.EntryCount,
            v78,
            pc.Channels.Blue);
          v30 = v29;
        }
        else
        {
          v30 = 0;
        }
        v31 = fs1->pFill.pObject;
        v32 = (Scaleform::RefCountVImpl *)v31->pGradient.pObject;
        p_pGradient = &v31->pGradient;
        if ( v32 )
          Scaleform::RefCountImpl::Release(v32);
        p_pGradient->pObject = v30;
        v34 = (Scaleform::Render::GradientData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   24,
                                                   0);
        if ( v34 )
        {
          Scaleform::Render::GradientData::GradientData(
            v34,
            (Scaleform::Render::GradientType)v82.EntryCount,
            v78,
            pc.Channels.Blue);
          v36 = v35;
        }
        else
        {
          v36 = 0;
        }
        v37 = fs2->pFill.pObject;
        pRecords = (Scaleform::RefCountVImpl *)v37->pGradient.pObject;
        v39 = &v37->pGradient;
        if ( pRecords )
          Scaleform::RefCountImpl::Release(pRecords);
        v39->pObject = v36;
        v40 = 0;
        for ( v82.EntryCount = v78; v40 < v82.EntryCount; LOBYTE(pRecords[v40++].__vftable) = v80 )
        {
          v41 = p;
          p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
          if ( !p_ProcessInfo )
            p_ProcessInfo = &p->ProcessInfo;
          v43 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
          p_ProcessInfo->Stream.UnusedBits = 0;
          if ( v43 < 1 )
          {
            Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
            v41 = p;
          }
          v44 = p_ProcessInfo->Stream.Pos;
          v45 = p_ProcessInfo->Stream.pBuffer[v44];
          p_ProcessInfo->Stream.Pos = v44 + 1;
          v79 = v45;
          Scaleform::GFx::LoadProcess::ReadRgbaTag(v41, &pc, tagType);
          fs1->pFill.pObject->pGradient.pObject->pRecords[v40].ColorV.Raw = pc.Raw;
          fs1->pFill.pObject->pGradient.pObject->pRecords[v40].Ratio = v79;
          v46 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
          if ( !v46 )
            v46 = &p->ProcessInfo;
          v47 = v46->Stream.DataSize - v46->Stream.Pos;
          v46->Stream.UnusedBits = 0;
          if ( v47 < 1 )
            Scaleform::GFx::Stream::PopulateBuffer1(&v46->Stream);
          v48 = v46->Stream.Pos;
          v49 = v46->Stream.pBuffer[v48];
          v46->Stream.Pos = v48 + 1;
          v80 = v49;
          Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &pc, tagType);
          fs2->pFill.pObject->pGradient.pObject->pRecords[v40].ColorV.Raw = pc.Raw;
          pRecords = (Scaleform::RefCountVImpl *)fs2->pFill.pObject->pGradient.pObject->pRecords;
        }
        Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pRecords);
        if ( v83 == 19 )
        {
          v50 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v50 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v51 = pAltStream->Stream.Pos;
          pc = (Scaleform::Render::Color)*(__int16 *)&pAltStream->Stream.pBuffer[v51];
          Raw = (double)(int)pc.Raw;
          pAltStream->Stream.Pos = v51 + 2;
          v53 = fs1->pFill.pObject->pGradient.pObject;
          *(float *)&pc.Raw = Raw * 0.00390625;
          v53->FocalRatio = *(float *)&pc.Raw;
          v54 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v54 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v55 = pAltStream->Stream.Pos;
          pc = (Scaleform::Render::Color)*(__int16 *)&pAltStream->Stream.pBuffer[v55];
          v56 = (double)(int)pc.Raw;
          pAltStream->Stream.Pos = v55 + 2;
          v57 = fs2->pFill.pObject->pGradient.pObject;
          *(float *)&pc.Raw = v56 * 0.00390625;
          v57->FocalRatio = *(float *)&pc.Raw;
        }
        v58 = (float *)fs1->pFill.pObject;
        v58[4] = v86.M[0][0];
        v58[5] = v86.M[0][1];
        v58 += 4;
        v58[2] = v86.M[0][2];
        v58[3] = v86.M[0][3];
        v58[4] = v86.M[1][0];
        v58[5] = v86.M[1][1];
        v58[6] = v86.M[1][2];
        v58[7] = v86.M[1][3];
        fs2->pFill.pObject->ImageMatrix = result;
        return;
      }
    }
    v82.EntryCount = 0;
    goto LABEL_35;
  }
  if ( (v10 & 0x40) != 0 )
  {
    v59 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v59 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v60 = pAltStream->Stream.Pos;
    v61 = (Scaleform::Render::Color)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v60];
    pAltStream->Stream.Pos = v60 + 2;
    pc = v61;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v61.Raw);
    v87.M[0][0] = 1.0;
    v87.M[0][1] = 0.0;
    v87.M[0][2] = 0.0;
    v87.M[0][3] = 0.0;
    v87.M[1][0] = 0.0;
    v87.M[1][2] = 0.0;
    v87.M[1][3] = 0.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    v87.M[1][1] = 1.0;
    m.M[0][0] = 1.0;
    m.M[1][1] = 1.0;
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &v87);
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &m);
    v62 = 0;
    v82.EntryCount = 0;
    v82.SizeMask = 0;
    Scaleform::Render::Matrix2x4<float>::GetInverse(&v87, &pm);
    Scaleform::Render::Matrix2x4<float>::GetInverse(&m, &result);
    v63 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v63 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v63);
      v62 = v64;
    }
    v65 = (Scaleform::RefCountVImpl *)fs1->pFill.pObject;
    if ( v65 )
      Scaleform::RefCountImpl::Release(v65);
    fs1->pFill.pObject = v62;
    Scaleform::Render::Matrix2x4<float>::operator=(&v62->ImageMatrix, &pm);
    switch ( v10 )
    {
      case '@':
        fs1->pFill.pObject->FillMode.Fill = 2;
        break;
      case 'A':
        fs1->pFill.pObject->FillMode.Fill = 3;
        break;
      case 'B':
        fs1->pFill.pObject->FillMode.Fill = 0;
        break;
      case 'C':
        fs1->pFill.pObject->FillMode.Fill = 1;
        break;
      default:
        break;
    }
    v66 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v66 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v66);
      v68 = v67;
    }
    else
    {
      v68 = 0;
    }
    v69 = (Scaleform::RefCountVImpl *)fs2->pFill.pObject;
    if ( v69 )
      Scaleform::RefCountImpl::Release(v69);
    fs2->pFill.pObject = v68;
    Scaleform::Render::Matrix2x4<float>::operator=(&v68->ImageMatrix, &result);
    fs2->pFill.pObject->FillMode.Fill = fs1->pFill.pObject->FillMode.Fill;
    ResourceHandle = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                       p->pLoadData.pObject,
                       &v82,
                       (Scaleform::GFx::ResourceId)pc);
    SizeMask = v82.SizeMask;
    v25 = ResourceHandle == 0;
    v72 = v82.EntryCount;
    if ( v25 || v82.EntryCount || !v82.SizeMask )
    {
      fs2->Color = -5776071;
      fs1->Color = -5776071;
      if ( v72 == 1 )
      {
        fs1->pFill.pObject->BindIndex = SizeMask;
        fs2->pFill.pObject->BindIndex = v82.SizeMask;
        *needResolve = 1;
      }
      else
      {
        v76 = (Scaleform::RefCountVImpl *)fs2->pFill.pObject;
        if ( v76 )
          Scaleform::RefCountImpl::Release(v76);
        fs2->pFill.pObject = 0;
        v77 = (Scaleform::RefCountVImpl *)fs1->pFill.pObject;
        if ( v77 )
          Scaleform::RefCountImpl::Release(v77);
        fs1->pFill.pObject = fs2->pFill.pObject;
        if ( pc != 0xFFFF )
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)135168,
            "An image with resource id %d is not found in resource table.",
            pc);
      }
    }
    else if ( ((*(int (**)(void))(*(_DWORD *)v82.SizeMask + 8))() & 0xFF00) == 0x100 )
    {
      p_pImage = &fs1->pFill.pObject->pImage;
      v74 = *(Scaleform::Render::Image **)(v82.EntryCount == 0 ? v82.SizeMask + 0xC : 12);
      if ( v74 )
        v74->AddRef(*(struct Scaleform::Render::Image **)(v82.EntryCount == 0 ? v82.SizeMask + 0xC : 12));
      if ( p_pImage->pObject )
        p_pImage->pObject->Release(p_pImage->pObject);
      p_pImage->pObject = v74;
      v75 = &fs2->pFill.pObject->pImage;
      if ( v74 )
        v74->AddRef(v74);
      if ( v75->pObject )
        v75->pObject->Release(v75->pObject);
      v75->pObject = v74;
    }
    if ( !v82.EntryCount && v82.SizeMask )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v82.SizeMask);
  }
}
