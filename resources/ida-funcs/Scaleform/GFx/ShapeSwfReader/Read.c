bool __thiscall Scaleform::GFx::ShapeSwfReader::Read(
        Scaleform::GFx::ShapeSwfReader *this,
        __int64 p,
        unsigned int lenInBytes,
        bool withStyle)
{
  Scaleform::GFx::Stream *v5; // edi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  unsigned int v9; // ebx
  unsigned __int8 *v10; // eax
  Scaleform::MemoryHeap *v12; // esi
  Scaleform::Log *Namespace; // eax
  int v14; // esi
  int v15; // eax
  bool v16; // bl
  int v17; // eax
  int v18; // esi
  int v19; // ebx
  int v20; // ebx
  int v21; // eax
  int v22; // ebx
  unsigned int v23; // edi
  int FillStyles; // eax
  unsigned int v25; // esi
  int StrokeStyles; // eax
  unsigned int v27; // ebx
  unsigned int v28; // edi
  int v29; // esi
  int v30; // edi
  int v31; // ebx
  int v32; // esi
  int v33; // esi
  int v34; // ebx
  int v35; // edi
  unsigned int v36; // ecx
  unsigned int v37; // eax
  Scaleform::GFx::ParseControl *pParseControl; // [esp+2Ch] [ebp-2D4h]
  char v39; // [esp+48h] [ebp-2B8h]
  unsigned int v40; // [esp+48h] [ebp-2B8h]
  int v41; // [esp+48h] [ebp-2B8h]
  int v42; // [esp+4Ch] [ebp-2B4h]
  int v43; // [esp+50h] [ebp-2B0h]
  int v44; // [esp+58h] [ebp-2A8h]
  int v45; // [esp+5Ch] [ebp-2A4h]
  unsigned __int8 *ptr; // [esp+60h] [ebp-2A0h]
  int v47; // [esp+64h] [ebp-29Ch]
  signed int v48; // [esp+64h] [ebp-29Ch]
  Scaleform::GFx::Stream *v49; // [esp+68h] [ebp-298h]
  signed int Size; // [esp+70h] [ebp-290h]
  float v52; // [esp+74h] [ebp-28Ch]
  unsigned int v53; // [esp+78h] [ebp-288h]
  Scaleform::GFx::PathAllocator *pAllocator; // [esp+7Ch] [ebp-284h]
  signed int v55; // [esp+80h] [ebp-280h]
  int v56; // [esp+84h] [ebp-27Ch]
  int v57; // [esp+88h] [ebp-278h]
  unsigned int oldSize; // [esp+8Ch] [ebp-274h]
  Scaleform::Render::Rect<float> pr; // [esp+90h] [ebp-270h] BYREF
  Scaleform::Render::Rect<float> v60; // [esp+A0h] [ebp-260h] BYREF
  Scaleform::GFx::Stream v61; // [esp+B8h] [ebp-248h] BYREF

  if ( this->pAllocator )
    pAllocator = this->pAllocator;
  else
    pAllocator = *(Scaleform::GFx::PathAllocator **)(*(_DWORD *)(p + 32) + 24);
  if ( *(_DWORD *)(p + 852) )
  {
    v49 = *(Scaleform::GFx::Stream **)(p + 852);
    v5 = v49;
  }
  else
  {
    v5 = (Scaleform::GFx::Stream *)(p + 48);
    v49 = (Scaleform::GFx::Stream *)(p + 48);
  }
  this->Shape->Flags = 0;
  if ( withStyle )
  {
    v6 = v5->FilePos + v5->Pos - v5->DataSize;
    this->Shape->Flags |= 0x10u;
    pr.x1 = 0.0;
    pr.y1 = 0.0;
    pr.x2 = 0.0;
    pr.y2 = 0.0;
    Scaleform::GFx::Stream::ReadRect(v5, &pr);
    this->Shape->SetBoundsLocal(this->Shape, &pr);
    if ( HIDWORD(p) == 83 || HIDWORD(p) == 75 )
    {
      v60.x1 = 0.0;
      v60.y1 = 0.0;
      v60.x2 = 0.0;
      v60.y2 = 0.0;
      Scaleform::GFx::Stream::ReadRect(v5, &v60);
      this->Shape->SetRectBoundsLocal(this->Shape, &v60);
      v7 = v5->DataSize - v5->Pos;
      v5->UnusedBits = 0;
      if ( v7 < 1 )
        Scaleform::GFx::Stream::PopulateBuffer1(v5);
      ++v5->Pos;
    }
    else
    {
      this->Shape->SetRectBoundsLocal(this->Shape, &pr);
    }
    Scaleform::GFx::ShapeSwfReader::ReadFillStyles(this, (Scaleform::GFx::LoadProcess *)p, SHIDWORD(p));
    Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(this, (Scaleform::GFx::LoadProcess *)p, (unsigned int *)HIDWORD(p));
    v8 = v5->FilePos + v5->Pos - v5->DataSize - v6;
  }
  else
  {
    v8 = 0;
  }
  v9 = lenInBytes - v8;
  v56 = lenInBytes - v8;
  oldSize = lenInBytes - v8;
  v53 = lenInBytes - v8;
  v10 = (unsigned __int8 *)Scaleform::GFx::PathAllocator::AllocRawPath(pAllocator, lenInBytes - v8);
  ptr = v10;
  if ( !v10 )
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      v5,
      "Corrupted shape detected in file %s",
      (const char *)((v5->FileName.HeapTypeBits & 0xFFFFFFFC) + 8));
    return 0;
  }
  v5->UnusedBits = 0;
  Scaleform::GFx::Stream::ReadToBuffer(v5, v10, v9);
  v52 = 1.0;
  if ( HIDWORD(p) == 75 )
  {
    v52 = 0.050000001;
    this->Shape->Flags |= 2u;
  }
  v12 = *(Scaleform::MemoryHeap **)(*(_DWORD *)(p + 32) + 28);
  pParseControl = v5->pParseControl;
  Namespace = (Scaleform::Log *)Scaleform::GFx::AS3::Multiname::GetNamespace((Scaleform::GFx::AS3::SoundObject *)v5);
  Scaleform::GFx::Stream::Stream(&v61, ptr, v9, v12, Namespace, pParseControl);
  *(_DWORD *)(p + 852) = &v61;
  v61.UnusedBits = 0;
  v14 = Scaleform::GFx::Stream::ReadUInt(&v61, 4);
  v47 = v14;
  v15 = Scaleform::GFx::Stream::ReadUInt(&v61, 4);
  v57 = v15;
  if ( withStyle )
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &v61,
      "  ShapeCharacter read: nfillbits = %d, nlinebits = %d\n",
      v14,
      v15);
  Size = 0;
  v55 = 0;
  v45 = 0;
  v44 = 0;
  v42 = 0;
  v43 = 0;
  v16 = 0;
  while ( Scaleform::GFx::Stream::ReadUInt1(&v61) )
  {
    ++v42;
    if ( Scaleform::GFx::Stream::ReadUInt1(&v61) )
    {
      v33 = Scaleform::GFx::Stream::ReadUInt(&v61, 4) + 2;
      v34 = 0;
      v35 = 0;
      if ( Scaleform::GFx::Stream::ReadUInt1(&v61) )
      {
        v34 = Scaleform::GFx::Stream::ReadSInt(&v61, v33);
        goto LABEL_78;
      }
      if ( Scaleform::GFx::Stream::ReadUInt1(&v61) )
LABEL_78:
        v35 = Scaleform::GFx::Stream::ReadSInt(&v61, v33);
      else
        v34 = Scaleform::GFx::Stream::ReadSInt(&v61, v33);
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v61) )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
          &v61,
          "  ShapeCharacter read: straight edge = %4g %4g - %4g %4g\n",
          v52 * (double)v45,
          (double)v44 * v52,
          (double)(v34 + v45) * v52,
          (double)(v35 + v44) * v52);
      v45 += v34;
      v44 += v35;
      goto LABEL_82;
    }
    v29 = Scaleform::GFx::Stream::ReadUInt(&v61, 4) + 2;
    v30 = Scaleform::GFx::Stream::ReadSInt(&v61, v29);
    v31 = Scaleform::GFx::Stream::ReadSInt(&v61, v29);
    v41 = Scaleform::GFx::Stream::ReadSInt(&v61, v29);
    v32 = Scaleform::GFx::Stream::ReadSInt(&v61, v29);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v61) )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        &v61,
        "  ShapeCharacter read: curved edge   = %4g %4g - %4g %4g - %4g %4g\n",
        v52 * (double)v45,
        (double)v44 * v52,
        (double)(v30 + v45) * v52,
        (double)(v31 + v44) * v52,
        (double)(v45 + v41 + v30) * v52,
        (double)(v44 + v32 + v31) * v52);
    v45 += v30 + v41;
    v44 += v31 + v32;
LABEL_82:
    v5 = v49;
LABEL_83:
    v36 = v61.FilePos + v61.Pos - v61.DataSize;
    v16 = v36 > v53;
    if ( v36 > v53 )
      goto LABEL_88;
  }
  v17 = Scaleform::GFx::Stream::ReadUInt(&v61, 5);
  v39 = v17;
  if ( !v17 )
    goto LABEL_88;
  if ( (v17 & 1) != 0 )
  {
    if ( v42 > 0 )
    {
      ++v43;
      v42 = 0;
    }
    v18 = Scaleform::GFx::Stream::ReadUInt(&v61, 5);
    v45 = Scaleform::GFx::Stream::ReadSInt(&v61, v18);
    v44 = Scaleform::GFx::Stream::ReadSInt(&v61, v18);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v61) )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(
        &v61,
        "  ShapeCharacter read: moveto %4g %4g\n",
        v52 * (double)v45,
        (double)v44 * v52);
  }
  if ( (v39 & 2) != 0 && v47 > 0 )
  {
    if ( v42 > 0 )
    {
      ++v43;
      v42 = 0;
    }
    v19 = Scaleform::GFx::Stream::ReadUInt(&v61, v47);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v61) )
    {
      if ( v19 > 0 )
        v19 += Size;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v61, "  ShapeCharacter read: fill0 = %d\n", v19);
    }
  }
  if ( (v39 & 4) != 0 && v47 > 0 )
  {
    if ( v42 > 0 )
    {
      ++v43;
      v42 = 0;
    }
    v20 = Scaleform::GFx::Stream::ReadUInt(&v61, v47);
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v61) )
    {
      if ( v20 > 0 )
        v20 += Size;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v61, "  ShapeCharacter read: fill1 = %d\n", v20);
    }
  }
  if ( (v39 & 8) != 0 && v57 > 0 )
  {
    if ( v42 > 0 )
    {
      ++v43;
      v42 = 0;
    }
    v21 = Scaleform::GFx::Stream::ReadUInt(&v61, v57);
    v22 = v21;
    if ( v21 > 0 )
      v22 = v55 + v21;
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParseShape(&v61) )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParseShape(&v61, "  ShapeCharacter read: line = %d\n", v22);
  }
  if ( (v39 & 0x10) == 0 )
    goto LABEL_83;
  Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&v61, "  ShapeCharacter read: more fill styles\n");
  if ( v43 > 0 )
    v43 = 0;
  if ( v42 > 0 )
  {
    ++v43;
    v42 = 0;
  }
  v23 = v61.FilePos + v61.Pos - v61.DataSize;
  Size = this->FillStyles.Data.Size;
  v55 = this->StrokeStyles.Data.Size;
  FillStyles = Scaleform::GFx::ShapeSwfReader::ReadFillStyles(this, (Scaleform::GFx::LoadProcess *)p, SHIDWORD(p));
  v25 = v61.FilePos + v61.Pos - v61.DataSize;
  v48 = FillStyles;
  StrokeStyles = Scaleform::GFx::ShapeSwfReader::ReadStrokeStyles(
                   this,
                   (Scaleform::GFx::LoadProcess *)p,
                   (unsigned int *)HIDWORD(p));
  v27 = v61.FilePos + v61.Pos - v61.DataSize;
  v40 = StrokeStyles;
  if ( v48 == v25 )
    goto LABEL_65;
  if ( v48 <= (int)v25 && v25 <= v53 )
  {
    if ( (signed int)this->FillStyles.Data.Size > Size )
    {
      ptr[v23 + 1] = BYTE2(Size);
      ptr[v23 + 2] = BYTE1(Size);
      ptr[v23] = -1;
      ptr[v23 + 3] = Size;
      v48 = v23 + 4;
    }
    v28 = StrokeStyles - v25;
    memmove((int)&ptr[v48], (const __m128i *)&ptr[v25], StrokeStyles - v25);
    v25 = v48;
    v40 = v48 + v28;
    StrokeStyles = v48 + v28;
LABEL_65:
    if ( StrokeStyles != v27 )
    {
      if ( StrokeStyles > (int)v27 || v27 > v53 )
        goto LABEL_87;
      if ( (signed int)this->StrokeStyles.Data.Size > v55 )
      {
        ptr[v25 + 1] = BYTE2(v55);
        ptr[v25 + 2] = BYTE1(v55);
        ptr[v25] = -1;
        ptr[v25 + 3] = v55;
        v40 = v25 + 4;
        StrokeStyles = v25 + 4;
      }
      memmove((int)&ptr[StrokeStyles], (const __m128i *)&ptr[v27], v56 - v27);
      StrokeStyles = v40;
      v56 += v40 - v27;
    }
    Scaleform::GFx::Stream::SetPosition(&v61, StrokeStyles);
    v47 = Scaleform::GFx::Stream::ReadUInt(&v61, 4);
    v57 = Scaleform::GFx::Stream::ReadUInt(&v61, 4);
    goto LABEL_82;
  }
LABEL_87:
  v5 = v49;
  v16 = 1;
LABEL_88:
  v37 = v56 + oldSize - v53;
  if ( v16 || v37 >= (unsigned int)&loc_200000 )
  {
    v16 = 1;
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogWarning(
      &v61,
      "Corrupted shape detected in file %s",
      (const char *)((v5->FileName.HeapTypeBits & 0xFFFFFFFC) + 8));
    *ptr = 0;
    ptr[1] = 0;
    if ( oldSize > 2 )
      Scaleform::GFx::PathAllocator::ReallocLastBlock(pAllocator, ptr, oldSize, 2u);
  }
  else if ( oldSize > v37 )
  {
    Scaleform::GFx::PathAllocator::ReallocLastBlock(pAllocator, ptr, oldSize, v56 + oldSize - v53);
  }
  this->Shape->Paths = ptr;
  *(_DWORD *)(p + 852) = 0;
  Scaleform::GFx::Stream::~Stream(&v61);
  return !v16;
}
