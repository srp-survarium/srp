void __thiscall Scaleform::GFx::FontDataCompactedSwf::Read(
        Scaleform::GFx::FontDataCompactedSwf *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::GFx::FontCompactorParams *pObject; // eax
  unsigned int NominalSize; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // ecx
  int UInt; // eax
  bool v9; // bl
  bool v10; // al
  int v11; // ecx
  int v12; // ecx
  unsigned int Pos; // eax
  unsigned int v14; // edx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v15; // ecx
  unsigned int v16; // edx
  unsigned int DataSize; // eax
  signed int NumGlyphs; // edi
  unsigned int Size; // ebx
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  unsigned int v23; // eax
  int v24; // ecx
  int v25; // eax
  unsigned int v26; // ecx
  int v27; // edi
  unsigned int v28; // eax
  unsigned int v29; // ebx
  int *v30; // ebx
  int v31; // eax
  unsigned int v32; // edx
  int v33; // eax
  int v34; // edx
  unsigned int v35; // eax
  Scaleform::GFx::TagType v36; // edx
  unsigned int v37; // edi
  int *v38; // edi
  int v39; // eax
  unsigned int v40; // eax
  int v41; // edx
  Scaleform::GFx::PathAllocator *v42; // eax
  Scaleform::GFx::PathAllocator *v43; // eax
  int v44; // edi
  Scaleform::GFx::FontDataCompactedSwf *v45; // ebx
  unsigned int v46; // ebx
  Scaleform::Render::ShapePathType v47; // eax
  unsigned int v48; // ebx
  Scaleform::Render::PathEdgeType i; // eax
  int v50; // edi
  unsigned int v51; // ebx
  unsigned int v52; // edi
  int v53; // eax
  unsigned int v54; // eax
  int v55; // eax
  unsigned int v56; // eax
  double v57; // st7
  int v58; // ecx
  unsigned int v59; // eax
  int v60; // eax
  unsigned int v61; // eax
  int v62; // eax
  unsigned int v63; // eax
  unsigned int v64; // ebx
  unsigned int v65; // edi
  int v66; // ecx
  unsigned int v67; // eax
  unsigned int v68; // edi
  int v69; // edx
  unsigned int v70; // eax
  int v71; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v72; // ecx
  unsigned int v73; // eax
  unsigned int v74; // eax
  unsigned __int16 v75; // cx
  int v76; // edx
  unsigned __int16 v77; // bx
  unsigned int v78; // eax
  unsigned __int16 v79; // cx
  unsigned __int16 v80; // di
  unsigned int v81; // eax
  unsigned __int16 v82; // dx
  int v83; // ecx
  unsigned int v84; // eax
  unsigned __int8 v85; // cl
  int v86; // ecx
  unsigned int v87; // eax
  void *v88; // esi
  unsigned int v89; // [esp+15E6h] [ebp-164h]
  unsigned int v90; // [esp+15E6h] [ebp-164h]
  unsigned int v91; // [esp+15F6h] [ebp-154h]
  int v92; // [esp+15F6h] [ebp-154h]
  int v93; // [esp+15F6h] [ebp-154h]
  int v94; // [esp+15F6h] [ebp-154h]
  float v95; // [esp+15F6h] [ebp-154h]
  int v96; // [esp+15F6h] [ebp-154h]
  int v97; // [esp+15F6h] [ebp-154h]
  bool v98; // [esp+15FDh] [ebp-14Dh]
  Scaleform::GFx::PathAllocator *v99; // [esp+15FEh] [ebp-14Ch]
  float v100; // [esp+15FEh] [ebp-14Ch]
  char v101; // [esp+1604h] [ebp-146h]
  bool v102; // [esp+1605h] [ebp-145h]
  Scaleform::GFx::TagType tagType; // [esp+1606h] [ebp-144h]
  Scaleform::GFx::TagType tagTypea; // [esp+1606h] [ebp-144h]
  float tagTypeb; // [esp+1606h] [ebp-144h]
  int v106; // [esp+160Ah] [ebp-140h]
  int v107; // [esp+160Ah] [ebp-140h]
  float v108; // [esp+160Ah] [ebp-140h]
  Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> > pheapAddr; // [esp+1612h] [ebp-138h] BYREF
  int v111; // [esp+161Eh] [ebp-12Ch]
  Scaleform::String pstr; // [esp+1622h] [ebp-128h] BYREF
  bool v113[4]; // [esp+1626h] [ebp-124h]
  int v114; // [esp+162Ah] [ebp-120h]
  unsigned int v115; // [esp+162Eh] [ebp-11Ch]
  Scaleform::GFx::ConstShapeNoStyles v116; // [esp+1632h] [ebp-118h] BYREF
  int val; // [esp+1642h] [ebp-108h] BYREF
  float v118; // [esp+1646h] [ebp-104h] BYREF
  float v119; // [esp+164Ah] [ebp-100h]
  float v120; // [esp+164Eh] [ebp-FCh]
  float v121; // [esp+1652h] [ebp-F8h]
  int v122; // [esp+165Eh] [ebp-ECh] BYREF
  Scaleform::Render::ShapePosInfo v123; // [esp+1662h] [ebp-E8h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+169Ah] [ebp-B0h] BYREF
  unsigned int v125[3]; // [esp+16AEh] [ebp-9Ch] BYREF
  Scaleform::GFx::FontCompactor v126; // [esp+16BAh] [ebp-90h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  v101 = 1;
  if ( tagInfo->TagType == Tag_DefineFont2 || tagInfo->TagType == Tag_DefineFont3 )
  {
    pObject = p->pLoadStates.pObject->pBindStates.pObject->pFontCompactorParams.pObject;
    NominalSize = pObject->NominalSize;
    LOBYTE(pObject) = pObject->MergeContours;
    v115 = NominalSize;
    v113[0] = (char)pObject;
    Scaleform::GFx::FontCompactor::FontCompactor(&v126, &this->Container);
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v7);
    UInt = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
    v98 = UInt != 0;
    if ( UInt )
      this->Flags |= 0x2000u;
    else
      this->Flags &= ~0x2000u;
    v9 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
    v10 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    if ( v9 )
    {
      this->Flags = this->Flags & 0xFFFFFCFF | 0x200;
    }
    else if ( v10 )
    {
      this->Flags = this->Flags & 0xFFFFFCFF | 0x100;
    }
    else
    {
      this->Flags &= 0xFFFFFCFF;
    }
    v102 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
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
    v11 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v11 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    ++pAltStream->Stream.Pos;
    Scaleform::String::String(&pstr);
    Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, &pstr);
    v12 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v12 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    Pos = pAltStream->Stream.Pos;
    v14 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[Pos];
    pAltStream->Stream.Pos = Pos + 2;
    this->NumGlyphs = v14;
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    {
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8));
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v98);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v15);
    }
    v16 = pAltStream->Stream.Pos;
    DataSize = pAltStream->Stream.DataSize;
    NumGlyphs = this->NumGlyphs;
    Size = 0;
    v111 = pAltStream->Stream.FilePos + v16 - DataSize;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    if ( NumGlyphs )
    {
      v20 = DataSize - v16;
      pAltStream->Stream.UnusedBits = 0;
      if ( v102 )
      {
        if ( v20 < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        v21 = pAltStream->Stream.Pos;
        v22 = pAltStream->Stream.pBuffer[v21]
            | ((pAltStream->Stream.pBuffer[v21 + 1]
              | ((pAltStream->Stream.pBuffer[v21 + 2] | (pAltStream->Stream.pBuffer[v21 + 3] << 8)) << 8)) << 8);
        pAltStream->Stream.Pos += 4;
      }
      else
      {
        if ( v20 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v23 = pAltStream->Stream.Pos;
        v24 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v23];
        pAltStream->Stream.Pos = v23 + 2;
        v22 = v24;
      }
      if ( v22 )
      {
        val = v22;
        Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          &pheapAddr,
          &val);
        Size = pheapAddr.Data.Size;
      }
      else
      {
        v101 = 0;
        NumGlyphs = 0;
      }
    }
    if ( v102 )
    {
      if ( NumGlyphs > 1 )
      {
        v106 = NumGlyphs - 1;
        do
        {
          v25 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v25 < 4 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
          v26 = pAltStream->Stream.Pos;
          v27 = pAltStream->Stream.pBuffer[v26]
              | ((pAltStream->Stream.pBuffer[v26 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v26 + 2] << 8)) << 8);
          v28 = pheapAddr.Data.Size;
          v29 = pheapAddr.Data.Size + 1;
          pAltStream->Stream.Pos = v26 + 4;
          if ( v29 >= v28 )
          {
            if ( v29 >= pheapAddr.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                &pheapAddr,
                v29 + (v29 >> 2));
          }
          else if ( v29 < pheapAddr.Data.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
              &pheapAddr,
              v29);
          }
          pheapAddr.Data.Size = v29;
          v30 = &pheapAddr.Data.Data[v29 - 1];
          if ( v30 )
            *v30 = v27;
          --v106;
        }
        while ( v106 );
      }
      v31 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v31 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v32 = pAltStream->Stream.Pos;
      v33 = pAltStream->Stream.pBuffer[v32]
          | ((pAltStream->Stream.pBuffer[v32 + 1]
            | ((pAltStream->Stream.pBuffer[v32 + 2] | (pAltStream->Stream.pBuffer[v32 + 3] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v32 + 4;
      v114 = v33;
    }
    else
    {
      if ( NumGlyphs > 1 )
      {
        v107 = NumGlyphs - 1;
        do
        {
          v34 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v34 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v35 = pAltStream->Stream.Pos;
          v36 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v35];
          v37 = Size + 1;
          pAltStream->Stream.Pos = v35 + 2;
          tagType = v36;
          if ( Size + 1 >= Size )
          {
            if ( v37 >= pheapAddr.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                &pheapAddr,
                v37 + (v37 >> 2));
          }
          else if ( v37 < pheapAddr.Data.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
              &pheapAddr,
              Size + 1);
          }
          ++Size;
          v38 = &pheapAddr.Data.Data[v37 - 1];
          pheapAddr.Data.Size = Size;
          if ( v38 )
            *v38 = tagType;
          --v107;
        }
        while ( v107 );
      }
      v39 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v39 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v40 = pAltStream->Stream.Pos;
      v41 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v40];
      pAltStream->Stream.Pos = v40 + 2;
      v114 = v41;
    }
    Scaleform::GFx::FontCompactor::StartFont(
      &v126,
      (const char *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 8),
      this->Flags,
      v115,
      0,
      0,
      0);
    if ( v101 )
    {
      tagTypea = Tag_DefineShape2;
      if ( tagInfo->TagType != Tag_DefineFont2 )
        tagTypea = tagInfo->TagType;
      v122 = 258;
      v42 = (Scaleform::GFx::PathAllocator *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               this,
                                               12,
                                               &v122);
      if ( v42 )
      {
        Scaleform::GFx::PathAllocator::PathAllocator(v42, 0x2000u);
        v99 = v43;
      }
      else
      {
        v99 = 0;
      }
      v44 = 0;
      if ( this->NumGlyphs )
      {
        v45 = this;
        do
        {
          Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, v111 + pheapAddr.Data.Data[v44]);
          v91 = v44 + 1;
          if ( v44 + 1 >= v45->NumGlyphs )
            v46 = v114 - pheapAddr.Data.Data[v44];
          else
            v46 = pheapAddr.Data.Data[v44 + 1] - pheapAddr.Data.Data[v44];
          Scaleform::GFx::FontCompactor::StartGlyph(&v126);
          v116.RefCount = 1;
          v116.Paths = 0;
          v116.Flags = 0;
          v116.__vftable = (Scaleform::GFx::ConstShapeNoStyles_vtbl *)&Scaleform::GFx::ConstShapeNoStyles::`vftable';
          Scaleform::GFx::ConstShapeNoStyles::Read(&v116, p, tagTypea, v46, 0);
          v123.Sfactor = 1.0;
          memset(&v123, 0, 48);
          v123.Initialized = 0;
          v47 = Scaleform::GFx::ShapeDataBase::ReadPathInfo(&v116, &v123, &v118, v125);
          if ( v47 )
          {
            v48 = v115;
            do
            {
              if ( v47 != Shape_NewLayer )
              {
                v108 = (float)v48;
                Scaleform::GFx::FontCompactor::MoveTo(
                  &v126,
                  (int)(v108 * v118 * 0.0009765625),
                  (int)(v108 * v119 * 0.0009765625));
                for ( i = Scaleform::GFx::ShapeDataBase::ReadEdge(&v116, &v123, &v118);
                      i;
                      i = Scaleform::GFx::ShapeDataBase::ReadEdge(&v116, &v123, &v118) )
                {
                  if ( i == Edge_LineTo )
                  {
                    Scaleform::GFx::FontCompactor::LineTo(
                      &v126,
                      (int)(v108 * v118 * 0.0009765625),
                      (int)(v108 * v119 * 0.0009765625));
                  }
                  else if ( i == Edge_QuadTo )
                  {
                    Scaleform::GFx::FontCompactor::QuadTo(
                      &v126,
                      (int)(v108 * v118 * 0.0009765625),
                      (int)(v108 * v119 * 0.0009765625),
                      (int)(v108 * v120 * 0.0009765625),
                      (int)(v108 * v121 * 0.0009765625));
                  }
                }
              }
              v47 = Scaleform::GFx::ShapeDataBase::ReadPathInfo(&v116, &v123, &v118, v125);
            }
            while ( v47 );
          }
          Scaleform::GFx::FontCompactor::EndGlyph(&v126, v113[0]);
          Scaleform::GFx::PathAllocator::Clear(v99);
          Scaleform::RefCountImplCore::~RefCountImplCore(&v116);
          ++v44;
          v45 = this;
        }
        while ( v91 < this->NumGlyphs );
      }
      if ( v99 )
      {
        Scaleform::GFx::PathAllocator::~PathAllocator(v99);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v99);
      }
      if ( v111 + v114 != pAltStream->Stream.FilePos + pAltStream->Stream.Pos - pAltStream->Stream.DataSize )
        goto LABEL_149;
    }
    else
    {
      v50 = v114 + v111;
      if ( v50 >= Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream) )
      {
LABEL_149:
        if ( pheapAddr.Data.Data )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data.Data);
        v88 = (void *)(pstr.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((pstr.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v88);
        Scaleform::GFx::FontCompactor::~FontCompactor(&v126);
        return;
      }
      Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, v50);
      this->Flags |= 0x1000u;
    }
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)(pAltStream->Stream.FilePos
                                                                                                 + pAltStream->Stream.Pos
                                                                                                 - pAltStream->Stream.DataSize));
    v51 = this->NumGlyphs;
    v52 = 0;
    if ( (this->Flags & 0x4000) != 0 )
    {
      if ( v51 )
      {
        do
        {
          v53 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v53 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v54 = pAltStream->Stream.Pos;
          v89 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v54];
          pAltStream->Stream.Pos = v54 + 2;
          Scaleform::GFx::FontCompactor::AssignGlyphCode(&v126, v52++, v89);
        }
        while ( v52 < v51 );
      }
    }
    else if ( v51 )
    {
      do
      {
        v55 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v55 < 1 )
          Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
        v56 = pAltStream->Stream.Pos;
        v90 = pAltStream->Stream.pBuffer[v56];
        pAltStream->Stream.Pos = v56 + 1;
        Scaleform::GFx::FontCompactor::AssignGlyphCode(&v126, v52++, v90);
      }
      while ( v52 < v51 );
    }
    if ( v98 )
    {
      if ( tagInfo->TagType == Tag_DefineFont3 )
        v57 = 0.050000001;
      else
        v57 = 1.0;
      v100 = v57;
      v58 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v58 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v59 = pAltStream->Stream.Pos;
      v92 = *(__int16 *)&pAltStream->Stream.pBuffer[v59];
      pAltStream->Stream.Pos = v59 + 2;
      this->Ascent = (double)v92 * v100;
      v60 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v60 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v61 = pAltStream->Stream.Pos;
      v93 = *(__int16 *)&pAltStream->Stream.pBuffer[v61];
      pAltStream->Stream.Pos = v61 + 2;
      this->Descent = (double)v93 * v100;
      v62 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v62 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v63 = pAltStream->Stream.Pos;
      v94 = *(__int16 *)&pAltStream->Stream.pBuffer[v63];
      pAltStream->Stream.Pos = v63 + 2;
      *(_DWORD *)v113 = &this->Leading;
      v95 = (double)v94 * v100;
      this->Leading = v95;
      v64 = v115;
      Scaleform::GFx::FontCompactor::UpdateMetrics(
        &v126,
        (int)(v115 * (int)this->Ascent) / 1024,
        (int)(v115 * (int)this->Descent) / 1024,
        (int)(v115 * (int)v95) / 1024);
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(*(Scaleform::GFx::AS3::RefCountBaseGC<328> **)v113);
      v65 = 0;
      *(_DWORD *)v113 = this->NumGlyphs;
      if ( *(_DWORD *)v113 )
      {
        do
        {
          v66 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v66 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v67 = pAltStream->Stream.Pos;
          v96 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v67];
          pAltStream->Stream.Pos = v67 + 2;
          Scaleform::GFx::FontCompactor::AssignGlyphAdvance(&v126, v65++, (int)(v64 * (int)((double)v96 * v100)) / 1024);
        }
        while ( v65 < *(_DWORD *)v113 );
      }
      v68 = this->NumGlyphs;
      pr.x1 = 0.0;
      pr.y1 = 0.0;
      pr.x2 = 0.0;
      for ( pr.y2 = 0.0; v68; --v68 )
        Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &pr);
      v69 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v69 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v70 = pAltStream->Stream.Pos;
      v71 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v70];
      pAltStream->Stream.Pos = v70 + 2;
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v72);
      if ( v71 > 0 )
      {
        v111 = v71;
        do
        {
          v73 = this->Flags >> 14;
          pAltStream->Stream.UnusedBits = 0;
          if ( (v73 & 1) != 0 )
          {
            if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v74 = pAltStream->Stream.Pos;
            v75 = *(_WORD *)&pAltStream->Stream.pBuffer[v74];
            v74 += 2;
            v76 = pAltStream->Stream.DataSize - v74;
            pAltStream->Stream.Pos = v74;
            v77 = v75;
            pAltStream->Stream.UnusedBits = 0;
            if ( v76 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v78 = pAltStream->Stream.Pos;
            v79 = *(_WORD *)&pAltStream->Stream.pBuffer[v78];
            pAltStream->Stream.Pos = v78 + 2;
            v80 = v79;
          }
          else
          {
            if ( (signed int)(pAltStream->Stream.DataSize - pAltStream->Stream.Pos) < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v81 = pAltStream->Stream.Pos;
            v82 = pAltStream->Stream.pBuffer[v81++];
            v83 = pAltStream->Stream.DataSize - v81;
            pAltStream->Stream.Pos = v81;
            v77 = v82;
            pAltStream->Stream.UnusedBits = 0;
            if ( v83 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v84 = pAltStream->Stream.Pos;
            v85 = pAltStream->Stream.pBuffer[v84];
            pAltStream->Stream.Pos = v84 + 1;
            v80 = v85;
          }
          v86 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v86 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v87 = pAltStream->Stream.Pos;
          v97 = *(__int16 *)&pAltStream->Stream.pBuffer[v87];
          pAltStream->Stream.Pos = v87 + 2;
          if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
            Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v77);
          tagTypeb = (double)v97 * v100;
          Scaleform::GFx::FontCompactor::AddKerningPair(&v126, v77, v80, (int)(v115 * (int)tagTypeb) / 1024);
          --v111;
        }
        while ( v111 );
      }
    }
    Scaleform::GFx::FontCompactor::EndFont(&v126);
    Scaleform::GFx::CompactedFont<Scaleform::ArrayPagedLH_POD<unsigned char,12,256,261>>::AcquireFont(
      &this->CompactedFontValue,
      0);
    goto LABEL_149;
  }
}
