bool __thiscall Scaleform::GFx::ShapeSwfReader::Read(
        Scaleform::GFx::ShapeSwfReader *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::Render::FillStyleType *tagType,
        unsigned int lenInBytes,
        bool withStyle)
{
  Scaleform::GFx::SWFProcessInfo *p_ProcessInfo; // edi
  int v7; // esi
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ebx
  unsigned __int8 *v11; // eax
  Scaleform::MemoryHeap *pHeap; // esi
  Scaleform::Log *Namespace; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // ecx
  bool v16; // bl
  int v17; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // ecx
  unsigned int v19; // esi
  unsigned int v20; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *FillStyles; // eax
  unsigned int v22; // esi
  int StrokeStyles; // eax
  unsigned int v24; // ebx
  unsigned int v25; // edi
  unsigned int v26; // esi
  int v27; // edi
  int v28; // ebx
  int v29; // esi
  unsigned int v30; // esi
  int v31; // ebx
  int v32; // edi
  unsigned int v33; // ecx
  unsigned int v34; // eax
  Scaleform::GFx::ParseControl *pParseControl; // [esp+386Ch] [ebp-2D4h]
  char v36; // [esp+3888h] [ebp-2B8h]
  unsigned int v37; // [esp+3888h] [ebp-2B8h]
  int v38; // [esp+3888h] [ebp-2B8h]
  int v39; // [esp+388Ch] [ebp-2B4h]
  int v40; // [esp+3890h] [ebp-2B0h]
  int v41; // [esp+3898h] [ebp-2A8h]
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v42; // [esp+389Ch] [ebp-2A4h]
  unsigned __int8 *pbuffer; // [esp+38A0h] [ebp-2A0h]
  signed int bitcount; // [esp+38A4h] [ebp-29Ch]
  signed int bitcounta; // [esp+38A4h] [ebp-29Ch]
  Scaleform::GFx::SWFProcessInfo *pAltStream; // [esp+38A8h] [ebp-298h]
  signed int Size; // [esp+38B0h] [ebp-290h]
  unsigned int v49; // [esp+38B8h] [ebp-288h]
  Scaleform::GFx::PathAllocator *pAllocator; // [esp+38BCh] [ebp-284h]
  signed int v51; // [esp+38C0h] [ebp-280h]
  int v52; // [esp+38C4h] [ebp-27Ch]
  signed int v53; // [esp+38C8h] [ebp-278h]
  unsigned int oldSize; // [esp+38CCh] [ebp-274h]
  Scaleform::Render::Rect<float> pr; // [esp+38D0h] [ebp-270h] BYREF
  Scaleform::Render::Rect<float> v56; // [esp+38E0h] [ebp-260h] BYREF
  Scaleform::GFx::Stream v57; // [esp+38F8h] [ebp-248h] BYREF

  if ( this->pAllocator )
    pAllocator = this->pAllocator;
  else
    pAllocator = p->pLoadData.pObject->pPathAllocator;
  if ( p->pAltStream )
  {
    pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
    p_ProcessInfo = pAltStream;
  }
  else
  {
    p_ProcessInfo = &p->ProcessInfo;
    pAltStream = &p->ProcessInfo;
  }
  this->Shape->Flags = 0;
  if ( withStyle )
  {
    v7 = p_ProcessInfo->Stream.FilePos + p_ProcessInfo->Stream.Pos - p_ProcessInfo->Stream.DataSize;
    this->Shape->Flags |= 0x10u;
    pr.x1 = 0.0;
    pr.y1 = 0.0;
    pr.x2 = 0.0;
    pr.y2 = 0.0;
    Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &pr);
    this->Shape->SetBoundsLocal(this->Shape, &pr);
    if ( tagType == (Scaleform::Render::FillStyleType *)83 || tagType == (Scaleform::Render::FillStyleType *)75 )
    {
      v56.x1 = 0.0;
      v56.y1 = 0.0;
      v56.x2 = 0.0;
      v56.y2 = 0.0;
      Scaleform::GFx::Stream::ReadRect(&p_ProcessInfo->Stream, &v56);
      this->Shape->SetRectBoundsLocal(this->Shape, &v56);
      v8 = p_ProcessInfo->Stream.DataSize - p_ProcessInfo->Stream.Pos;
      p_ProcessInfo->Stream.UnusedBits = 0;
      if ( v8 < 1 )
        Scaleform::GFx::Stream::PopulateBuffer1(&p_ProcessInfo->Stream);
      ++p_ProcessInfo->Stream.Pos;
    }
    else
    {
      this->Shape->SetRectBoundsLocal(this->Shape, &pr);
    }
    Scaleform::GFx::ShapeSwfReader::ReadFillStyles(this, p, (Scaleform::GFx::TagType)tagType);
    Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(this, p, tagType);
    v9 = p_ProcessInfo->Stream.FilePos + p_ProcessInfo->Stream.Pos - p_ProcessInfo->Stream.DataSize - v7;
  }
  else
  {
    v9 = 0;
  }
  v10 = lenInBytes - v9;
  v52 = lenInBytes - v9;
  oldSize = lenInBytes - v9;
  v49 = lenInBytes - v9;
  v11 = Scaleform::GFx::PathAllocator::AllocRawPath(pAllocator, lenInBytes - v9);
  pbuffer = v11;
  if ( !v11 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      &p_ProcessInfo->Stream,
      "Corrupted shape detected in file %s",
      (const char *)((p_ProcessInfo->Stream.FileName.HeapTypeBits & 0xFFFFFFFC) + 8));
    return 0;
  }
  p_ProcessInfo->Stream.UnusedBits = 0;
  Scaleform::GFx::Stream::ReadToBuffer(&p_ProcessInfo->Stream, v11, v10);
  if ( tagType == (Scaleform::Render::FillStyleType *)75 )
    this->Shape->Flags |= 2u;
  pHeap = p->pLoadData.pObject->pHeap;
  pParseControl = p_ProcessInfo->Stream.pParseControl;
  Namespace = (Scaleform::Log *)Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)p_ProcessInfo);
  Scaleform::GFx::Stream::Stream(&v57, pbuffer, v10, pHeap, Namespace, pParseControl);
  p->pAltStream = &v57;
  v57.UnusedBits = 0;
  bitcount = Scaleform::GFx::Stream::ReadUInt(&v57, 4);
  v53 = Scaleform::GFx::Stream::ReadUInt(&v57, 4);
  if ( withStyle )
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v15);
  v42 = 0;
  v41 = 0;
  v39 = 0;
  v40 = 0;
  v16 = 0;
  while ( Scaleform::GFx::Stream::ReadUInt1(&v57) )
  {
    ++v39;
    if ( Scaleform::GFx::Stream::ReadUInt1(&v57) )
    {
      v30 = Scaleform::GFx::Stream::ReadUInt(&v57, 4) + 2;
      v31 = 0;
      v32 = 0;
      if ( Scaleform::GFx::Stream::ReadUInt1(&v57) )
      {
        v31 = Scaleform::GFx::Stream::ReadSInt(&v57, v30);
        goto LABEL_72;
      }
      if ( Scaleform::GFx::Stream::ReadUInt1(&v57) )
LABEL_72:
        v32 = Scaleform::GFx::Stream::ReadSInt(&v57, v30);
      else
        v31 = Scaleform::GFx::Stream::ReadSInt(&v57, v30);
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v57) )
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v42);
      v42 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v42 + v31);
      v41 += v32;
      goto LABEL_76;
    }
    v26 = Scaleform::GFx::Stream::ReadUInt(&v57, 4) + 2;
    v27 = Scaleform::GFx::Stream::ReadSInt(&v57, v26);
    v28 = Scaleform::GFx::Stream::ReadSInt(&v57, v26);
    v38 = Scaleform::GFx::Stream::ReadSInt(&v57, v26);
    v29 = Scaleform::GFx::Stream::ReadSInt(&v57, v26);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v57) )
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)(v28 + v41));
    v42 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v42 + v27 + v38);
    v41 += v28 + v29;
LABEL_76:
    p_ProcessInfo = pAltStream;
LABEL_77:
    v33 = v57.FilePos + v57.Pos - v57.DataSize;
    v16 = v33 > v49;
    if ( v33 > v49 )
      goto LABEL_82;
  }
  v17 = Scaleform::GFx::Stream::ReadUInt(&v57, 5);
  v36 = v17;
  if ( !v17 )
    goto LABEL_82;
  if ( (v17 & 1) != 0 )
  {
    if ( v39 > 0 )
    {
      ++v40;
      v39 = 0;
    }
    v19 = Scaleform::GFx::Stream::ReadUInt(&v57, 5);
    v42 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)Scaleform::GFx::Stream::ReadSInt(&v57, v19);
    v41 = Scaleform::GFx::Stream::ReadSInt(&v57, v19);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v57) )
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v57);
  }
  if ( (v36 & 2) != 0 && bitcount > 0 )
  {
    if ( v39 > 0 )
    {
      ++v40;
      v39 = 0;
    }
    Scaleform::GFx::Stream::ReadUInt(&v57, bitcount);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v57) )
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v18);
  }
  if ( (v36 & 4) != 0 && bitcount > 0 )
  {
    if ( v39 > 0 )
    {
      ++v40;
      v39 = 0;
    }
    Scaleform::GFx::Stream::ReadUInt(&v57, bitcount);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v57) )
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v18);
  }
  if ( (v36 & 8) != 0 && v53 > 0 )
  {
    if ( v39 > 0 )
    {
      ++v40;
      v39 = 0;
    }
    Scaleform::GFx::Stream::ReadUInt(&v57, v53);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v57) )
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v57);
  }
  if ( (v36 & 0x10) == 0 )
    goto LABEL_77;
  Scaleform::Render::JPEG::JPEGRwSource::TermSource(v18);
  if ( v40 > 0 )
    v40 = 0;
  if ( v39 > 0 )
  {
    ++v40;
    v39 = 0;
  }
  v20 = v57.FilePos + v57.Pos - v57.DataSize;
  Size = this->FillStyles.Data.Size;
  v51 = this->StrokeStyles.Data.Size;
  FillStyles = Scaleform::GFx::ShapeSwfReader::ReadFillStyles(this, p, (Scaleform::GFx::TagType)tagType);
  v22 = v57.FilePos + v57.Pos - v57.DataSize;
  bitcounta = (signed int)FillStyles;
  StrokeStyles = Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(this, p, tagType);
  v24 = v57.FilePos + v57.Pos - v57.DataSize;
  v37 = StrokeStyles;
  if ( bitcounta == v22 )
    goto LABEL_59;
  if ( bitcounta <= (int)v22 && v22 <= v49 )
  {
    if ( (signed int)this->FillStyles.Data.Size > Size )
    {
      pbuffer[v20 + 1] = BYTE2(Size);
      pbuffer[v20 + 2] = BYTE1(Size);
      pbuffer[v20] = -1;
      pbuffer[v20 + 3] = Size;
      bitcounta = v20 + 4;
    }
    v25 = StrokeStyles - v22;
    memmove(&pbuffer[bitcounta], &pbuffer[v22], StrokeStyles - v22);
    v22 = bitcounta;
    v37 = bitcounta + v25;
    StrokeStyles = bitcounta + v25;
LABEL_59:
    if ( StrokeStyles != v24 )
    {
      if ( StrokeStyles > (int)v24 || v24 > v49 )
        goto LABEL_81;
      if ( (signed int)this->StrokeStyles.Data.Size > v51 )
      {
        pbuffer[v22 + 1] = BYTE2(v51);
        pbuffer[v22 + 2] = BYTE1(v51);
        pbuffer[v22] = -1;
        pbuffer[v22 + 3] = v51;
        v37 = v22 + 4;
        StrokeStyles = v22 + 4;
      }
      memmove(&pbuffer[StrokeStyles], &pbuffer[v24], v52 - v24);
      StrokeStyles = v37;
      v52 += v37 - v24;
    }
    Scaleform::GFx::Stream::SetPosition(&v57, StrokeStyles);
    bitcount = Scaleform::GFx::Stream::ReadUInt(&v57, 4);
    v53 = Scaleform::GFx::Stream::ReadUInt(&v57, 4);
    goto LABEL_76;
  }
LABEL_81:
  p_ProcessInfo = pAltStream;
  v16 = 1;
LABEL_82:
  v34 = v52 + oldSize - v49;
  if ( v16 || v34 >= 0x200000 )
  {
    v16 = 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      &v57,
      "Corrupted shape detected in file %s",
      (const char *)((p_ProcessInfo->Stream.FileName.HeapTypeBits & 0xFFFFFFFC) + 8));
    *pbuffer = 0;
    pbuffer[1] = 0;
    if ( oldSize > 2 )
      Scaleform::GFx::PathAllocator::ReallocLastBlock(pAllocator, pbuffer, oldSize, 2u);
  }
  else if ( oldSize > v34 )
  {
    Scaleform::GFx::PathAllocator::ReallocLastBlock(pAllocator, pbuffer, oldSize, v52 + oldSize - v49);
  }
  this->Shape->Paths = pbuffer;
  p->pAltStream = 0;
  Scaleform::GFx::Stream::~Stream(&v57);
  return !v16;
}
