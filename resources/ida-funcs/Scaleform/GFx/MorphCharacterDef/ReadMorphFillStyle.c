void __thiscall Scaleform::GFx::MorphCharacterDef::ReadMorphFillStyle(
        Scaleform::GFx::MorphCharacterDef *this,
        Scaleform::GFx::LoadProcess *p,
        int tagType,
        Scaleform::Render::FillStyleType *fs1,
        Scaleform::Render::FillStyleType *fs2,
        bool *needResolve)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  int v7; // eax
  unsigned int Pos; // eax
  unsigned __int8 v9; // bl
  unsigned int EntryCount; // eax
  double v11; // st7
  int v12; // edx
  unsigned int v13; // eax
  unsigned __int8 v14; // cl
  Scaleform::Render::ComplexFill *v15; // eax
  Scaleform::Render::ComplexFill *v16; // eax
  Scaleform::Render::ComplexFill *v17; // ebx
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::Render::ComplexFill *v19; // eax
  Scaleform::Render::ComplexFill *v20; // eax
  Scaleform::Render::ComplexFill *v21; // ebx
  Scaleform::RefCountVImpl *v22; // ecx
  bool v23; // zf
  unsigned int v24; // eax
  unsigned int v25; // eax
  Scaleform::Render::GradientData *v26; // eax
  Scaleform::Render::GradientData *v27; // eax
  Scaleform::Render::GradientData *v28; // ebx
  Scaleform::Render::ComplexFill *v29; // edi
  Scaleform::RefCountVImpl *v30; // ecx
  Scaleform::Ptr<Scaleform::Render::GradientData> *p_pGradient; // edi
  Scaleform::Render::GradientData *v32; // eax
  Scaleform::Render::GradientData *v33; // eax
  Scaleform::Render::GradientData *v34; // ebx
  Scaleform::Render::ComplexFill *v35; // edi
  Scaleform::RefCountVImpl *v36; // ecx
  Scaleform::Ptr<Scaleform::Render::GradientData> *v37; // edi
  unsigned int v38; // edi
  Scaleform::GFx::LoadProcess *v39; // ecx
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // ebx
  int v41; // edx
  unsigned int v42; // eax
  unsigned __int8 v43; // dl
  Scaleform::GFx::SWFProcessInfo *v44; // ebx
  int v45; // edx
  unsigned int v46; // eax
  unsigned __int8 v47; // dl
  int v48; // ecx
  unsigned int v49; // eax
  double Raw; // st7
  Scaleform::Render::GradientData *v51; // edx
  int v52; // eax
  unsigned int v53; // eax
  double v54; // st7
  Scaleform::Render::GradientData *v55; // edx
  float *v56; // eax
  int v57; // edx
  unsigned int v58; // eax
  unsigned __int16 v59; // dx
  Scaleform::Render::ComplexFill *v60; // esi
  Scaleform::Render::ComplexFill *v61; // eax
  Scaleform::Render::ComplexFill *v62; // eax
  Scaleform::RefCountVImpl *v63; // ecx
  Scaleform::Render::ComplexFill *v64; // eax
  Scaleform::Render::ComplexFill *v65; // eax
  Scaleform::Render::ComplexFill *v66; // edi
  Scaleform::RefCountVImpl *v67; // ecx
  char ResourceHandle; // al
  unsigned int SizeMask; // ecx
  unsigned int v70; // eax
  Scaleform::Ptr<Scaleform::Render::Image> *p_pImage; // ebx
  Scaleform::Render::Image *v72; // edi
  Scaleform::Ptr<Scaleform::Render::Image> *v73; // esi
  Scaleform::RefCountVImpl *v74; // ecx
  Scaleform::RefCountVImpl *v75; // ecx
  unsigned __int8 v76; // [esp+21h] [ebp-B1h]
  unsigned __int8 v77; // [esp+21h] [ebp-B1h]
  unsigned __int8 v78; // [esp+21h] [ebp-B1h]
  Scaleform::Render::Color pc; // [esp+22h] [ebp-B0h] BYREF
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> >::TableType v80; // [esp+26h] [ebp-ACh] BYREF
  unsigned __int8 v81; // [esp+31h] [ebp-A1h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+32h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+52h] [ebp-80h] BYREF
  Scaleform::Render::Matrix2x4<float> v84; // [esp+72h] [ebp-60h] BYREF
  Scaleform::Render::Matrix2x4<float> v85; // [esp+92h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> pm; // [esp+B2h] [ebp-20h] BYREF

  if ( p->pAltStream )
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  else
    pAltStream = &p->ProcessInfo;
  v7 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v7 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  Pos = pAltStream->Stream.Pos;
  v81 = pAltStream->Stream.pBuffer[Pos];
  v9 = v81;
  pAltStream->Stream.Pos = Pos + 1;
  v80.EntryCount = v9;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "morph fill style type = 0x%X\n", v9);
  if ( !v9 )
  {
    Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, &pc);
    Scaleform::GFx::Stream::ReadRgba(&pAltStream->Stream, (Scaleform::Render::Color *)&v80);
    EntryCount = v80.EntryCount;
    fs1->Color = pc.Raw;
    fs2->Color = EntryCount;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "morph fill style begin color: ");
    Scaleform::GFx::Stream::LogParseClass(&pAltStream->Stream, pc);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "morph fill style end color: ");
    Scaleform::GFx::Stream::LogParseClass(&pAltStream->Stream, (Scaleform::Render::Color)v80.EntryCount);
    return;
  }
  if ( (v9 & 0x10) != 0 )
  {
    pm.M[0][0] = 1.0;
    pm.M[0][1] = 0.0;
    pm.M[0][2] = 0.0;
    pm.M[0][3] = 0.0;
    pm.M[1][0] = 0.0;
    pm.M[1][2] = 0.0;
    pm.M[1][3] = 0.0;
    v85.M[0][1] = 0.0;
    v85.M[0][2] = 0.0;
    v85.M[0][3] = 0.0;
    v85.M[1][0] = 0.0;
    v85.M[1][2] = 0.0;
    v85.M[1][3] = 0.0;
    pm.M[1][1] = 1.0;
    v85.M[0][0] = 1.0;
    v85.M[1][1] = 1.0;
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &pm);
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &v85);
    v84.M[0][0] = 1.0;
    v84.M[0][1] = 0.0;
    v84.M[0][2] = 0.0;
    v84.M[0][3] = 0.0;
    v84.M[1][0] = 0.0;
    v84.M[1][2] = 0.0;
    v84.M[1][3] = 0.0;
    result.M[0][1] = 0.0;
    result.M[0][2] = 0.0;
    result.M[0][3] = 0.0;
    result.M[1][0] = 0.0;
    result.M[1][2] = 0.0;
    result.M[1][3] = 0.0;
    v84.M[1][1] = 1.0;
    result.M[0][0] = 1.0;
    result.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::AppendScaling(&v84, 0.000030517578);
    v84.M[0][3] = v84.M[0][3] + 0.5;
    if ( v9 == 16 )
    {
      v84.M[1][3] = v84.M[1][3] + 0.0;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(&result, 0.000030517578);
      result.M[0][3] = result.M[0][3] + 0.5;
      v11 = result.M[1][3] + 0.0;
    }
    else
    {
      v84.M[1][3] = v84.M[1][3] + 0.5;
      Scaleform::Render::Matrix2x4<float>::AppendScaling(&result, 0.000030517578);
      result.M[0][3] = result.M[0][3] + 0.5;
      v11 = result.M[1][3] + 0.5;
    }
    result.M[1][3] = v11;
    m.M[0][0] = 1.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    m.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&m, &pm);
    Scaleform::Render::Matrix2x4<float>::Prepend(&v84, &m);
    m.M[0][0] = 1.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    m.M[1][1] = 1.0;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&m, &v85);
    Scaleform::Render::Matrix2x4<float>::Prepend(&result, &m);
    v12 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v12 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    v13 = pAltStream->Stream.Pos;
    v14 = pAltStream->Stream.pBuffer[v13];
    v76 = v14;
    pAltStream->Stream.Pos = v13 + 1;
    pc.Channels.Blue = 0;
    if ( tagType == 84 || v9 == 19 )
    {
      if ( (v14 & 0x10) != 0 )
        pc.Channels.Blue = 1;
      v76 = v14 & 0xF;
    }
    v15 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v15 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v15);
      v17 = v16;
    }
    else
    {
      v17 = 0;
    }
    pObject = (Scaleform::RefCountVImpl *)fs1->pFill.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::Release(pObject);
    fs1->pFill.pObject = v17;
    v19 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v19 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v19);
      v21 = v20;
    }
    else
    {
      v21 = 0;
    }
    v22 = (Scaleform::RefCountVImpl *)fs2->pFill.pObject;
    if ( v22 )
      Scaleform::RefCountImpl::Release(v22);
    v24 = v80.EntryCount - 16;
    v23 = v80.EntryCount == 16;
    fs2->pFill.pObject = v21;
    if ( !v23 )
    {
      v25 = v24 - 2;
      if ( !v25 )
      {
        v80.EntryCount = 1;
        goto LABEL_35;
      }
      if ( v25 == 1 )
      {
        v80.EntryCount = 2;
LABEL_35:
        v26 = (Scaleform::Render::GradientData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   24,
                                                   0);
        if ( v26 )
        {
          Scaleform::Render::GradientData::GradientData(
            v26,
            (Scaleform::Render::GradientType)v80.EntryCount,
            v76,
            pc.Channels.Blue);
          v28 = v27;
        }
        else
        {
          v28 = 0;
        }
        v29 = fs1->pFill.pObject;
        v30 = (Scaleform::RefCountVImpl *)v29->pGradient.pObject;
        p_pGradient = &v29->pGradient;
        if ( v30 )
          Scaleform::RefCountImpl::Release(v30);
        p_pGradient->pObject = v28;
        v32 = (Scaleform::Render::GradientData *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   24,
                                                   0);
        if ( v32 )
        {
          Scaleform::Render::GradientData::GradientData(
            v32,
            (Scaleform::Render::GradientType)v80.EntryCount,
            v76,
            pc.Channels.Blue);
          v34 = v33;
        }
        else
        {
          v34 = 0;
        }
        v35 = fs2->pFill.pObject;
        v36 = (Scaleform::RefCountVImpl *)v35->pGradient.pObject;
        v37 = &v35->pGradient;
        if ( v36 )
          Scaleform::RefCountImpl::Release(v36);
        v37->pObject = v34;
        v38 = 0;
        for ( v80.EntryCount = v76; v38 < v80.EntryCount; fs2->pFill.pObject->pGradient.pObject->pRecords[v38++].Ratio = v78 )
        {
          v39 = p;
          p_ProcessInfo = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
          if ( !p_ProcessInfo )
            p_ProcessInfo = &p->ProcessInfo;
          v41 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
          p_ProcessInfo->Stream.UnusedBits = 0;
          if ( v41 < 1 )
          {
            Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
            v39 = p;
          }
          v42 = p_ProcessInfo->Stream.Pos;
          v43 = p_ProcessInfo->Stream.pBuffer[v42];
          p_ProcessInfo->Stream.Pos = v42 + 1;
          v77 = v43;
          Scaleform::GFx::LoadProcess::ReadRgbaTag(v39, &pc, tagType);
          fs1->pFill.pObject->pGradient.pObject->pRecords[v38].ColorV.Raw = pc.Raw;
          fs1->pFill.pObject->pGradient.pObject->pRecords[v38].Ratio = v77;
          v44 = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
          if ( !v44 )
            v44 = &p->ProcessInfo;
          v45 = v44->Stream.DataSize - v44->Stream.Pos;
          v44->Stream.UnusedBits = 0;
          if ( v45 < 1 )
            Scaleform::GFx::Stream::PopulateBuffer1(&v44->Stream);
          v46 = v44->Stream.Pos;
          v47 = v44->Stream.pBuffer[v46];
          v44->Stream.Pos = v46 + 1;
          v78 = v47;
          Scaleform::GFx::LoadProcess::ReadRgbaTag(p, &pc, tagType);
          fs2->pFill.pObject->pGradient.pObject->pRecords[v38].ColorV.Raw = pc.Raw;
        }
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
          &pAltStream->Stream,
          "morph fsr: numGradients = %d\n",
          v80.EntryCount);
        if ( v81 == 19 )
        {
          v48 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v48 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v49 = pAltStream->Stream.Pos;
          pc = (Scaleform::Render::Color)*(__int16 *)&pAltStream->Stream.pBuffer[v49];
          Raw = (double)(int)pc.Raw;
          pAltStream->Stream.Pos = v49 + 2;
          v51 = fs1->pFill.pObject->pGradient.pObject;
          *(float *)&pc.Raw = Raw * 0.00390625;
          v51->FocalRatio = *(float *)&pc.Raw;
          v52 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v52 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v53 = pAltStream->Stream.Pos;
          pc = (Scaleform::Render::Color)*(__int16 *)&pAltStream->Stream.pBuffer[v53];
          v54 = (double)(int)pc.Raw;
          pAltStream->Stream.Pos = v53 + 2;
          v55 = fs2->pFill.pObject->pGradient.pObject;
          *(float *)&pc.Raw = v54 * 0.00390625;
          v55->FocalRatio = *(float *)&pc.Raw;
        }
        v56 = (float *)fs1->pFill.pObject;
        v56[4] = v84.M[0][0];
        v56[5] = v84.M[0][1];
        v56 += 4;
        v56[2] = v84.M[0][2];
        v56[3] = v84.M[0][3];
        v56[4] = v84.M[1][0];
        v56[5] = v84.M[1][1];
        v56[6] = v84.M[1][2];
        v56[7] = v84.M[1][3];
        fs2->pFill.pObject->ImageMatrix = result;
        return;
      }
    }
    v80.EntryCount = 0;
    goto LABEL_35;
  }
  if ( (v9 & 0x40) != 0 )
  {
    v57 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v57 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v58 = pAltStream->Stream.Pos;
    v59 = *(_WORD *)&pAltStream->Stream.pBuffer[v58];
    pAltStream->Stream.Pos = v58 + 2;
    pc = (Scaleform::Render::Color)v59;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "morph fsr BitmapChar = %d\n", v59);
    v85.M[0][0] = 1.0;
    v85.M[0][1] = 0.0;
    v85.M[0][2] = 0.0;
    v85.M[0][3] = 0.0;
    v85.M[1][0] = 0.0;
    v85.M[1][2] = 0.0;
    v85.M[1][3] = 0.0;
    m.M[0][1] = 0.0;
    m.M[0][2] = 0.0;
    m.M[0][3] = 0.0;
    m.M[1][0] = 0.0;
    m.M[1][2] = 0.0;
    m.M[1][3] = 0.0;
    v85.M[1][1] = 1.0;
    m.M[0][0] = 1.0;
    m.M[1][1] = 1.0;
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &v85);
    Scaleform::GFx::Stream::ReadMatrix(&pAltStream->Stream, &m);
    v60 = 0;
    v80.EntryCount = 0;
    v80.SizeMask = 0;
    Scaleform::Render::Matrix2x4<float>::GetInverse(&v85, &pm);
    Scaleform::Render::Matrix2x4<float>::GetInverse(&m, &result);
    v61 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v61 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v61);
      v60 = v62;
    }
    v63 = (Scaleform::RefCountVImpl *)fs1->pFill.pObject;
    if ( v63 )
      Scaleform::RefCountImpl::Release(v63);
    fs1->pFill.pObject = v60;
    Scaleform::Render::Matrix2x4<float>::operator=(&v60->ImageMatrix, &pm);
    switch ( v9 )
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
    v64 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 64, 0);
    if ( v64 )
    {
      Scaleform::Render::ComplexFill::ComplexFill(v64);
      v66 = v65;
    }
    else
    {
      v66 = 0;
    }
    v67 = (Scaleform::RefCountVImpl *)fs2->pFill.pObject;
    if ( v67 )
      Scaleform::RefCountImpl::Release(v67);
    fs2->pFill.pObject = v66;
    Scaleform::Render::Matrix2x4<float>::operator=(&v66->ImageMatrix, &result);
    fs2->pFill.pObject->FillMode.Fill = fs1->pFill.pObject->FillMode.Fill;
    ResourceHandle = Scaleform::GFx::MovieDataDef::LoadTaskData::GetResourceHandle(
                       p->pLoadData.pObject,
                       &v80,
                       (Scaleform::GFx::ResourceId)pc);
    SizeMask = v80.SizeMask;
    v23 = ResourceHandle == 0;
    v70 = v80.EntryCount;
    if ( v23 || v80.EntryCount || !v80.SizeMask )
    {
      fs2->Color = -5776071;
      fs1->Color = -5776071;
      if ( v70 == 1 )
      {
        fs1->pFill.pObject->BindIndex = SizeMask;
        fs2->pFill.pObject->BindIndex = v80.SizeMask;
        *needResolve = 1;
      }
      else
      {
        v74 = (Scaleform::RefCountVImpl *)fs2->pFill.pObject;
        if ( v74 )
          Scaleform::RefCountImpl::Release(v74);
        fs2->pFill.pObject = 0;
        v75 = (Scaleform::RefCountVImpl *)fs1->pFill.pObject;
        if ( v75 )
          Scaleform::RefCountImpl::Release(v75);
        fs1->pFill.pObject = fs2->pFill.pObject;
        if ( pc != 0xFFFF )
          Scaleform::LogDebugMessage(
            (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)&loc_20FFD + 3),
            "An image with resource id %d is not found in resource table.",
            pc);
      }
    }
    else if ( ((*(int (**)(void))(*(_DWORD *)v80.SizeMask + 8))() & 0xFF00) == 0x100 )
    {
      p_pImage = &fs1->pFill.pObject->pImage;
      v72 = *(Scaleform::Render::Image **)(v80.EntryCount == 0 ? v80.SizeMask + 0xC : 12);
      if ( v72 )
        v72->AddRef(*(struct Scaleform::Render::Image **)(v80.EntryCount == 0 ? v80.SizeMask + 0xC : 12));
      if ( p_pImage->pObject )
        p_pImage->pObject->Release(p_pImage->pObject);
      p_pImage->pObject = v72;
      v73 = &fs2->pFill.pObject->pImage;
      if ( v72 )
        v72->AddRef(v72);
      if ( v73->pObject )
        v73->pObject->Release(v73->pObject);
      v73->pObject = v72;
    }
    if ( !v80.EntryCount && v80.SizeMask )
      Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v80.SizeMask);
  }
}
