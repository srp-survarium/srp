void __thiscall Scaleform::GFx::FontDataCompactedSwf::Read(
        Scaleform::GFx::FontDataCompactedSwf *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::GFx::FontCompactorParams *pObject; // eax
  unsigned int v6; // edx
  int UInt; // eax
  bool v8; // bl
  bool v9; // al
  int v10; // ecx
  unsigned int v11; // eax
  unsigned __int8 v12; // bl
  int v13; // ecx
  unsigned int v14; // eax
  unsigned int v15; // edx
  const char *v16; // eax
  unsigned int v17; // ecx
  const char *v18; // edx
  unsigned int v19; // edx
  unsigned int DataSize; // eax
  signed int NumGlyphs; // edi
  unsigned int Size; // ebx
  int v23; // eax
  unsigned int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // ecx
  int v28; // eax
  unsigned int v29; // ecx
  int v30; // edi
  unsigned int v31; // eax
  unsigned int v32; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object **v33; // ebx
  int v34; // eax
  unsigned int v35; // edx
  int v36; // eax
  int v37; // edx
  unsigned int v38; // eax
  Scaleform::GFx::TagType v39; // edx
  unsigned int v40; // edi
  Scaleform::GFx::AS3::Instances::fl::Object **v41; // edi
  int v42; // eax
  unsigned int v43; // eax
  int v44; // edx
  Scaleform::GFx::PathAllocator *v45; // eax
  Scaleform::GFx::PathAllocator *v46; // eax
  int v47; // edi
  Scaleform::GFx::FontDataCompactedSwf *v48; // ebx
  unsigned int v49; // ebx
  Scaleform::Render::ShapePathType v50; // eax
  unsigned int v51; // ebx
  int i; // eax
  int v53; // edi
  unsigned int v54; // ebx
  unsigned int v55; // edi
  int v56; // eax
  unsigned int v57; // eax
  int v58; // eax
  unsigned int v59; // eax
  double v60; // st7
  int v61; // ecx
  unsigned int v62; // eax
  int v63; // eax
  unsigned int v64; // eax
  float *p_Descent; // edi
  int v66; // eax
  unsigned int v67; // eax
  unsigned int v68; // ebx
  unsigned int v69; // edi
  int v70; // ecx
  unsigned int v71; // eax
  unsigned int v72; // edi
  int v73; // edx
  unsigned int v74; // eax
  int v75; // edi
  unsigned int v76; // eax
  unsigned int v77; // eax
  unsigned __int16 v78; // cx
  int v79; // edx
  unsigned __int16 v80; // bx
  unsigned int v81; // eax
  unsigned __int16 v82; // cx
  unsigned __int16 v83; // di
  unsigned int v84; // eax
  unsigned __int16 v85; // dx
  int v86; // ecx
  unsigned int v87; // eax
  unsigned __int8 v88; // cl
  int v89; // ecx
  unsigned int v90; // eax
  void *v91; // esi
  unsigned __int16 v92; // [esp-4h] [ebp-164h]
  unsigned __int16 v93; // [esp-4h] [ebp-164h]
  unsigned int v94; // [esp+Ch] [ebp-154h]
  int v95; // [esp+Ch] [ebp-154h]
  int v96; // [esp+Ch] [ebp-154h]
  int v97; // [esp+Ch] [ebp-154h]
  float v98; // [esp+Ch] [ebp-154h]
  int v99; // [esp+Ch] [ebp-154h]
  int v100; // [esp+Ch] [ebp-154h]
  bool v101; // [esp+13h] [ebp-14Dh]
  Scaleform::GFx::PathAllocator *v102; // [esp+14h] [ebp-14Ch]
  float v103; // [esp+14h] [ebp-14Ch]
  char v104; // [esp+1Ah] [ebp-146h]
  bool v105; // [esp+1Bh] [ebp-145h]
  Scaleform::GFx::TagType tagType; // [esp+1Ch] [ebp-144h]
  Scaleform::GFx::TagType tagTypea; // [esp+1Ch] [ebp-144h]
  float *tagTypeb; // [esp+1Ch] [ebp-144h]
  float tagTypec; // [esp+1Ch] [ebp-144h]
  int v110; // [esp+20h] [ebp-140h]
  int v111; // [esp+20h] [ebp-140h]
  float v112; // [esp+20h] [ebp-140h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+28h] [ebp-138h] BYREF
  int v115; // [esp+34h] [ebp-12Ch]
  Scaleform::String v116; // [esp+38h] [ebp-128h] BYREF
  bool mergeContours[4]; // [esp+3Ch] [ebp-124h]
  int v118; // [esp+40h] [ebp-120h]
  unsigned int nominalSize; // [esp+44h] [ebp-11Ch]
  Scaleform::GFx::ConstShapeNoStyles v120; // [esp+48h] [ebp-118h] BYREF
  int v121; // [esp+58h] [ebp-108h] BYREF
  float coord; // [esp+5Ch] [ebp-104h] BYREF
  float v123; // [esp+60h] [ebp-100h]
  float v124; // [esp+64h] [ebp-FCh]
  float v125; // [esp+68h] [ebp-F8h]
  int v126; // [esp+74h] [ebp-ECh] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+78h] [ebp-E8h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+B0h] [ebp-B0h] BYREF
  unsigned int styles[3]; // [esp+C4h] [ebp-9Ch] BYREF
  Scaleform::GFx::FontCompactor v130; // [esp+D0h] [ebp-90h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v104 = 1;
  if ( tagInfo->TagType == Tag_DefineFont2 || tagInfo->TagType == Tag_DefineFont3 )
  {
    pObject = p->pLoadStates.pObject->pBindStates.pObject->pFontCompactorParams.pObject;
    v6 = pObject->NominalSize;
    LOBYTE(pObject) = pObject->MergeContours;
    nominalSize = v6;
    mergeContours[0] = (char)pObject;
    Scaleform::GFx::FontCompactor::FontCompactor(&v130, &this->Container);
    if ( tagInfo->TagType == Tag_DefineFont2 )
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "reading DefineFont2: ");
    else
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "reading DefineFont3: ");
    UInt = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
    v101 = UInt != 0;
    if ( UInt )
      this->Flags |= 0x2000u;
    else
      this->Flags &= ~0x2000u;
    v8 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
    v9 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    if ( v8 )
    {
      this->Flags = this->Flags & 0xFFFFFCFF | 0x200;
    }
    else if ( v9 )
    {
      this->Flags = this->Flags & 0xFFFFFCFF | 0x100;
    }
    else
    {
      this->Flags &= 0xFFFFFCFF;
    }
    v105 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
      this->Flags |= 0x4000u;
    else
      this->Flags &= ~0x4000u;
    if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
      this->Flags |= 1u;
    else
      this->Flags &= ~1u;
    if ( Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) )
      this->Flags |= 2u;
    else
      this->Flags &= ~2u;
    v10 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v10 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    v11 = pAltStream->Stream.Pos;
    v12 = pAltStream->Stream.pBuffer[v11];
    pAltStream->Stream.Pos = v11 + 1;
    Scaleform::String::String(&v116);
    Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, &v116);
    v13 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v13 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v14 = pAltStream->Stream.Pos;
    v15 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v14];
    pAltStream->Stream.Pos = v14 + 2;
    this->NumGlyphs = v15;
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    {
      if ( (v116.HeapTypeBits & 0xFFFFFFFC) == 0xFFFFFFF8 )
        v16 = "(none)";
      else
        v16 = (const char *)((v116.HeapTypeBits & 0xFFFFFFFC) + 8);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
        &pAltStream->Stream,
        "  Name = %s, %d glyphs\n",
        v16,
        this->NumGlyphs);
      v17 = this->Flags & 0x300;
      v18 = "Unicode";
      if ( v17 == 512 )
      {
        v18 = "ShiftJIS";
      }
      else if ( v17 == 256 )
      {
        v18 = "ANSI";
      }
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
        &pAltStream->Stream,
        "  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n",
        v101,
        v18,
        this->Flags & 1,
        (this->Flags >> 1) & 1);
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  LangCode = %d\n", v12);
    }
    v19 = pAltStream->Stream.Pos;
    DataSize = pAltStream->Stream.DataSize;
    NumGlyphs = this->NumGlyphs;
    Size = 0;
    v115 = pAltStream->Stream.FilePos + v19 - DataSize;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    if ( NumGlyphs )
    {
      v23 = DataSize - v19;
      pAltStream->Stream.UnusedBits = 0;
      if ( v105 )
      {
        if ( v23 < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        v24 = pAltStream->Stream.Pos;
        v25 = pAltStream->Stream.pBuffer[v24]
            | ((pAltStream->Stream.pBuffer[v24 + 1]
              | ((pAltStream->Stream.pBuffer[v24 + 2] | (pAltStream->Stream.pBuffer[v24 + 3] << 8)) << 8)) << 8);
        pAltStream->Stream.Pos += 4;
      }
      else
      {
        if ( v23 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v26 = pAltStream->Stream.Pos;
        v27 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v26];
        pAltStream->Stream.Pos = v26 + 2;
        v25 = v27;
      }
      if ( v25 )
      {
        v121 = v25;
        Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          (Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
          &v121);
        Size = pheapAddr.Size;
      }
      else
      {
        v104 = 0;
        NumGlyphs = 0;
      }
    }
    if ( v105 )
    {
      if ( NumGlyphs > 1 )
      {
        v110 = NumGlyphs - 1;
        do
        {
          v28 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v28 < 4 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
          v29 = pAltStream->Stream.Pos;
          v30 = pAltStream->Stream.pBuffer[v29]
              | ((pAltStream->Stream.pBuffer[v29 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v29 + 2] << 8)) << 8);
          v31 = pheapAddr.Size;
          v32 = pheapAddr.Size + 1;
          pAltStream->Stream.Pos = v29 + 4;
          if ( v32 >= v31 )
          {
            if ( v32 >= pheapAddr.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                &pheapAddr,
                &pheapAddr,
                v32 + (v32 >> 2));
          }
          else if ( v32 < pheapAddr.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v32);
          }
          pheapAddr.Size = v32;
          v33 = &pheapAddr.Data[v32 - 1];
          if ( v33 )
            *v33 = (Scaleform::GFx::AS3::Instances::fl::Object *)v30;
          --v110;
        }
        while ( v110 );
      }
      v34 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v34 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v35 = pAltStream->Stream.Pos;
      v36 = pAltStream->Stream.pBuffer[v35]
          | ((pAltStream->Stream.pBuffer[v35 + 1]
            | ((pAltStream->Stream.pBuffer[v35 + 2] | (pAltStream->Stream.pBuffer[v35 + 3] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v35 + 4;
      v118 = v36;
    }
    else
    {
      if ( NumGlyphs > 1 )
      {
        v111 = NumGlyphs - 1;
        do
        {
          v37 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v37 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v38 = pAltStream->Stream.Pos;
          v39 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v38];
          v40 = Size + 1;
          pAltStream->Stream.Pos = v38 + 2;
          tagType = v39;
          if ( Size + 1 >= Size )
          {
            if ( v40 >= pheapAddr.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                &pheapAddr,
                &pheapAddr,
                v40 + (v40 >> 2));
          }
          else if ( v40 < pheapAddr.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              Size + 1);
          }
          ++Size;
          v41 = &pheapAddr.Data[v40 - 1];
          pheapAddr.Size = Size;
          if ( v41 )
            *v41 = (Scaleform::GFx::AS3::Instances::fl::Object *)tagType;
          --v111;
        }
        while ( v111 );
      }
      v42 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v42 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v43 = pAltStream->Stream.Pos;
      v44 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v43];
      pAltStream->Stream.Pos = v43 + 2;
      v118 = v44;
    }
    Scaleform::GFx::FontCompactor::StartFont(
      &v130,
      (char *)((v116.HeapTypeBits & 0xFFFFFFFC) + 8),
      this->Flags,
      nominalSize,
      0,
      0,
      0);
    if ( v104 )
    {
      tagTypea = Tag_DefineShape2;
      if ( tagInfo->TagType != Tag_DefineFont2 )
        tagTypea = tagInfo->TagType;
      v126 = 258;
      v45 = (Scaleform::GFx::PathAllocator *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               12,
                                               &v126);
      if ( v45 )
      {
        Scaleform::GFx::PathAllocator::PathAllocator(v45, 0x2000u);
        v102 = v46;
      }
      else
      {
        v102 = 0;
      }
      v47 = 0;
      if ( this->NumGlyphs )
      {
        v48 = this;
        do
        {
          Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, (int)pheapAddr.Data[v47] + v115);
          v94 = v47 + 1;
          if ( v47 + 1 >= v48->NumGlyphs )
            v49 = v118 - (unsigned int)pheapAddr.Data[v47];
          else
            v49 = (char *)pheapAddr.Data[v47 + 1] - (char *)pheapAddr.Data[v47];
          Scaleform::GFx::FontCompactor::StartGlyph(&v130);
          v120.RefCount = 1;
          v120.Paths = 0;
          v120.Flags = 0;
          v120.__vftable = (Scaleform::GFx::ConstShapeNoStyles_vtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable';
          Scaleform::GFx::ConstShapeNoStyles::Read(&v120, __SPAIR64__(tagTypea, (unsigned int)p), v49, 0);
          pos.Sfactor = 1.0;
          memset(&pos, 0, 48);
          pos.Initialized = 0;
          v50 = Scaleform::GFx::ShapeDataBase::ReadPathInfo(&v120, &pos, &coord, styles);
          if ( v50 )
          {
            v51 = nominalSize;
            do
            {
              if ( v50 != Shape_NewLayer )
              {
                v112 = (float)v51;
                Scaleform::GFx::FontCompactor::MoveTo(
                  &v130,
                  (int)(v112 * coord * 0.0009765625),
                  (int)(v112 * v123 * 0.0009765625));
                for ( i = Scaleform::GFx::ShapeDataBase::ReadEdge(&v120, &pos, &coord);
                      i;
                      i = Scaleform::GFx::ShapeDataBase::ReadEdge(&v120, &pos, &coord) )
                {
                  if ( i == 1 )
                  {
                    Scaleform::GFx::FontCompactor::LineTo(
                      &v130,
                      (int)(v112 * coord * 0.0009765625),
                      (int)(v112 * v123 * 0.0009765625));
                  }
                  else if ( i == 2 )
                  {
                    Scaleform::GFx::FontCompactor::QuadTo(
                      &v130,
                      (int)(v112 * coord * 0.0009765625),
                      (int)(v112 * v123 * 0.0009765625),
                      (int)(v112 * v124 * 0.0009765625),
                      (int)(v112 * v125 * 0.0009765625));
                  }
                }
              }
              v50 = Scaleform::GFx::ShapeDataBase::ReadPathInfo(&v120, &pos, &coord, styles);
            }
            while ( v50 );
          }
          Scaleform::GFx::FontCompactor::EndGlyph(&v130, mergeContours[0]);
          Scaleform::GFx::PathAllocator::Clear(v102);
          Scaleform::RefCountImplCore::~RefCountImplCore(&v120);
          ++v47;
          v48 = this;
        }
        while ( v94 < this->NumGlyphs );
      }
      if ( v102 )
      {
        Scaleform::GFx::PathAllocator::~PathAllocator(v102);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v102);
      }
      if ( v115 + v118 != pAltStream->Stream.FilePos + pAltStream->Stream.Pos - pAltStream->Stream.DataSize )
        goto LABEL_159;
    }
    else
    {
      v53 = v118 + v115;
      if ( v53 >= Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream) )
      {
LABEL_159:
        if ( pheapAddr.Data )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data);
        v91 = (void *)(v116.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v116.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v91);
        Scaleform::GFx::FontCompactor::~FontCompactor(&v130);
        return;
      }
      Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, v53);
      this->Flags |= 0x1000u;
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "reading code table at offset %d\n",
      pAltStream->Stream.FilePos + pAltStream->Stream.Pos - pAltStream->Stream.DataSize);
    v54 = this->NumGlyphs;
    v55 = 0;
    if ( (this->Flags & 0x4000) != 0 )
    {
      if ( v54 )
      {
        do
        {
          v56 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v56 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v57 = pAltStream->Stream.Pos;
          v92 = *(_WORD *)&pAltStream->Stream.pBuffer[v57];
          pAltStream->Stream.Pos = v57 + 2;
          Scaleform::GFx::FontCompactor::AssignGlyphCode(&v130, v55++, v92);
        }
        while ( v55 < v54 );
      }
    }
    else if ( v54 )
    {
      do
      {
        v58 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v58 < 1 )
          Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
        v59 = pAltStream->Stream.Pos;
        v93 = pAltStream->Stream.pBuffer[v59];
        pAltStream->Stream.Pos = v59 + 1;
        Scaleform::GFx::FontCompactor::AssignGlyphCode(&v130, v55++, v93);
      }
      while ( v55 < v54 );
    }
    if ( v101 )
    {
      if ( tagInfo->TagType == Tag_DefineFont3 )
        v60 = 0.050000001;
      else
        v60 = 1.0;
      v103 = v60;
      v61 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v61 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v62 = pAltStream->Stream.Pos;
      v95 = *(__int16 *)&pAltStream->Stream.pBuffer[v62];
      pAltStream->Stream.Pos = v62 + 2;
      tagTypeb = &this->Ascent;
      this->Ascent = (double)v95 * v103;
      v63 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v63 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v64 = pAltStream->Stream.Pos;
      v96 = *(__int16 *)&pAltStream->Stream.pBuffer[v64];
      pAltStream->Stream.Pos = v64 + 2;
      p_Descent = &this->Descent;
      this->Descent = (double)v96 * v103;
      v66 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v66 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v67 = pAltStream->Stream.Pos;
      v97 = *(__int16 *)&pAltStream->Stream.pBuffer[v67];
      pAltStream->Stream.Pos = v67 + 2;
      *(_DWORD *)mergeContours = &this->Leading;
      v98 = (double)v97 * v103;
      this->Leading = v98;
      v68 = nominalSize;
      Scaleform::GFx::FontCompactor::UpdateMetrics(
        &v130,
        (int)(nominalSize * (int)*tagTypeb) / 1024,
        (int)(nominalSize * (int)*p_Descent) / 1024,
        (int)(nominalSize * (int)v98) / 1024);
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
          &pAltStream->Stream,
          "  Ascent = %d, Descent = %d, Leading = %d\n",
          (int)*tagTypeb,
          (int)*p_Descent,
          (int)**(float **)mergeContours);
      v69 = 0;
      *(_DWORD *)mergeContours = this->NumGlyphs;
      if ( *(_DWORD *)mergeContours )
      {
        do
        {
          v70 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v70 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v71 = pAltStream->Stream.Pos;
          v99 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v71];
          pAltStream->Stream.Pos = v71 + 2;
          Scaleform::GFx::FontCompactor::AssignGlyphAdvance(&v130, v69++, (int)(v68 * (int)((double)v99 * v103)) / 1024);
        }
        while ( v69 < *(_DWORD *)mergeContours );
      }
      v72 = this->NumGlyphs;
      pr.x1 = 0.0;
      pr.y1 = 0.0;
      pr.x2 = 0.0;
      for ( pr.y2 = 0.0; v72; --v72 )
        Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &pr);
      v73 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v73 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v74 = pAltStream->Stream.Pos;
      v75 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v74];
      pAltStream->Stream.Pos = v74 + 2;
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  KerningCount = %d\n", v75);
      if ( v75 > 0 )
      {
        v115 = v75;
        do
        {
          v76 = this->Flags >> 14;
          pAltStream->Stream.UnusedBits = 0;
          if ( (v76 & 1) != 0 )
          {
            if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v77 = pAltStream->Stream.Pos;
            v78 = *(_WORD *)&pAltStream->Stream.pBuffer[v77];
            v77 += 2;
            v79 = pAltStream->Stream.DataSize - v77;
            pAltStream->Stream.Pos = v77;
            v80 = v78;
            pAltStream->Stream.UnusedBits = 0;
            if ( v79 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v81 = pAltStream->Stream.Pos;
            v82 = *(_WORD *)&pAltStream->Stream.pBuffer[v81];
            pAltStream->Stream.Pos = v81 + 2;
            v83 = v82;
          }
          else
          {
            if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v84 = pAltStream->Stream.Pos;
            v85 = pAltStream->Stream.pBuffer[v84++];
            v86 = pAltStream->Stream.DataSize - v84;
            pAltStream->Stream.Pos = v84;
            v80 = v85;
            pAltStream->Stream.UnusedBits = 0;
            if ( v86 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v87 = pAltStream->Stream.Pos;
            v88 = pAltStream->Stream.pBuffer[v87];
            pAltStream->Stream.Pos = v87 + 1;
            v83 = v88;
          }
          v89 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v89 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v90 = pAltStream->Stream.Pos;
          v100 = *(__int16 *)&pAltStream->Stream.pBuffer[v90];
          pAltStream->Stream.Pos = v90 + 2;
          tagTypec = (double)v100 * v103;
          if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
            Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
              &pAltStream->Stream,
              "     Pair: %d - %d,\tadj = %d\n",
              v80,
              v83,
              (int)tagTypec);
          Scaleform::GFx::FontCompactor::AddKerningPair(&v130, v80, v83, (int)(nominalSize * (int)tagTypec) / 1024);
          --v115;
        }
        while ( v115 );
      }
    }
    Scaleform::GFx::FontCompactor::EndFont(&v130);
    Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::AcquireFont(
      &this->CompactedFontValue,
      0);
    goto LABEL_159;
  }
}
