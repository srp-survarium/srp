void __thiscall Scaleform::GFx::FontData::Read(
        Scaleform::GFx::FontData *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::GFx::TagType TagType; // eax
  unsigned int DataSize; // eax
  unsigned int Pos; // edx
  unsigned int v8; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v9; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // edi
  unsigned int v11; // ebx
  int v12; // ecx
  unsigned int v13; // eax
  unsigned __int16 v14; // cx
  unsigned int v15; // edi
  float *v16; // edi
  unsigned int Size; // eax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261,Scaleform::ArrayDefaultPolicy> *p_Glyphs; // edi
  unsigned int v19; // eax
  float v20; // ecx
  unsigned int v21; // ebx
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *i; // eax
  int v23; // ebx
  char *v24; // edi
  int v25; // ebx
  Scaleform::GFx::Resource *v26; // edi
  int v27; // eax
  Scaleform::RefCountVImpl **v28; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object **v29; // eax
  int UInt; // eax
  bool v31; // bl
  bool v32; // al
  int v33; // eax
  unsigned int v34; // eax
  unsigned __int8 v35; // dl
  int v36; // edx
  unsigned int v37; // eax
  int v38; // edi
  char *Name; // eax
  unsigned int v40; // ecx
  const char *v41; // edx
  unsigned int v42; // eax
  unsigned int v43; // edx
  unsigned int v44; // ebx
  int v45; // ecx
  int v46; // eax
  unsigned int v47; // edx
  int v48; // eax
  unsigned int v49; // eax
  int v50; // ecx
  int v51; // eax
  unsigned int v52; // ecx
  int v53; // edi
  unsigned int v54; // eax
  unsigned int v55; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object **v56; // ebx
  int v57; // eax
  unsigned int v58; // edx
  int v59; // eax
  int v60; // edx
  unsigned int v61; // eax
  float v62; // edx
  unsigned int v63; // edi
  float *v64; // edi
  int v65; // eax
  unsigned int v66; // eax
  Scaleform::RefCountVImpl **v67; // edx
  unsigned int v68; // ebx
  unsigned int v69; // eax
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v70; // eax
  unsigned int v71; // ecx
  Scaleform::GFx::TagType v72; // eax
  unsigned int v73; // edi
  unsigned int v74; // ebx
  Scaleform::GFx::AS3::Instances::fl::Object *v75; // eax
  Scaleform::MemoryHeap_vtbl *v76; // edx
  int v77; // eax
  char v78; // al
  Scaleform::RefCountVImpl **v79; // edi
  bool v80; // zf
  Scaleform::RefCountVImpl *v81; // ebx
  double x1; // st6
  _WORD *v83; // edi
  int v84; // eax
  double v85; // st6
  __int16 v86; // cx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *v87; // esi
  unsigned int v88; // edx
  Scaleform::RefCountVImpl **v89; // ebx
  unsigned int v90; // edi
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *j; // eax
  int v92; // edi
  double v93; // st7
  int v94; // edx
  unsigned int v95; // eax
  Scaleform::GFx::FontData *v96; // edi
  int v97; // eax
  unsigned int v98; // eax
  int v99; // eax
  unsigned int v100; // eax
  unsigned int v101; // ebx
  Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy> *v102; // edi
  unsigned int v103; // edi
  int v104; // ebx
  int v105; // eax
  Scaleform::GFx::FontData::AdvanceEntry *v106; // edi
  unsigned int v107; // eax
  double v108; // st6
  unsigned int v109; // edi
  int v110; // edx
  unsigned int v111; // eax
  int v112; // edi
  unsigned int v113; // eax
  unsigned int v114; // ecx
  unsigned int v115; // edx
  int v116; // eax
  unsigned int v117; // eax
  unsigned __int16 v118; // cx
  int v119; // edx
  unsigned __int16 v120; // bx
  unsigned int v121; // eax
  unsigned __int16 v122; // cx
  unsigned int v123; // eax
  unsigned __int16 v124; // di
  unsigned int v125; // eax
  unsigned __int8 v126; // cl
  int v127; // edx
  unsigned int v128; // eax
  unsigned __int8 v129; // cl
  int v130; // eax
  unsigned int v131; // eax
  double v132; // st6
  int v133; // eax
  unsigned int v134; // edx
  BOOL v135; // edi
  char *v136; // eax
  Scaleform::GFx::FontData *v137; // esi
  unsigned int v138; // edx
  int v139; // ecx
  Scaleform::GFx::FontData::AdvanceEntry *v140; // eax
  char v141; // [esp+1Bh] [ebp-85h]
  unsigned __int8 v142; // [esp+1Ch] [ebp-84h]
  Scaleform::GFx::Resource *v143; // [esp+1Ch] [ebp-84h]
  float v144; // [esp+1Ch] [ebp-84h]
  float v145; // [esp+1Ch] [ebp-84h]
  bool v146; // [esp+22h] [ebp-7Eh]
  bool v147; // [esp+23h] [ebp-7Dh]
  unsigned int v148; // [esp+24h] [ebp-7Ch] BYREF
  Scaleform::GFx::FontData *v149; // [esp+28h] [ebp-78h]
  Scaleform::RefCountVImpl **v150; // [esp+2Ch] [ebp-74h]
  int v151; // [esp+30h] [ebp-70h]
  int v152; // [esp+34h] [ebp-6Ch]
  int v153; // [esp+38h] [ebp-68h]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> v154; // [esp+3Ch] [ebp-64h] BYREF
  float v155; // [esp+48h] [ebp-58h] BYREF
  signed int v156; // [esp+4Ch] [ebp-54h]
  unsigned int v157; // [esp+50h] [ebp-50h]
  float v158; // [esp+54h] [ebp-4Ch]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+58h] [ebp-48h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *p_Data; // [esp+64h] [ebp-3Ch]
  unsigned int v161; // [esp+68h] [ebp-38h]
  Scaleform::MemoryHeap *pHeap; // [esp+6Ch] [ebp-34h]
  Scaleform::Render::Rect<float> r; // [esp+70h] [ebp-30h] BYREF
  int v164; // [esp+84h] [ebp-1Ch] BYREF
  Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeRef key; // [esp+88h] [ebp-18h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+90h] [ebp-10h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v149 = this;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  TagType = tagInfo->TagType;
  v141 = 1;
  pHeap = p->pLoadData.pObject->pHeap;
  switch ( TagType )
  {
    case Tag_DefineFont:
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "reading DefineFont\n");
      DataSize = pAltStream->Stream.DataSize;
      Pos = pAltStream->Stream.Pos;
      v151 = Pos + pAltStream->Stream.FilePos - DataSize;
      memset(&pheapAddr, 0, sizeof(pheapAddr));
      pAltStream->Stream.UnusedBits = 0;
      if ( (int)(DataSize - Pos) < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v8 = pAltStream->Stream.Pos;
      v9 = (Scaleform::GFx::AS3::Instances::fl::Object *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v8];
      pAltStream->Stream.Pos = v8 + 2;
      Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &pheapAddr,
        &pheapAddr,
        1u);
      Data = pheapAddr.Data;
      pheapAddr.Size = 1;
      if ( pheapAddr.Data )
        *pheapAddr.Data = v9;
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "offset[0] = %d\n", *Data);
      v156 = (int)*Data >> 1;
      v11 = v156;
      v148 = 1;
      if ( v156 > 1 )
      {
        while ( 1 )
        {
          v12 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v12 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v13 = pAltStream->Stream.Pos;
          v14 = *(_WORD *)&pAltStream->Stream.pBuffer[v13];
          pAltStream->Stream.Pos = v13 + 2;
          if ( !v14 )
            break;
          v15 = pheapAddr.Size + 1;
          LODWORD(v155) = v14;
          if ( pheapAddr.Size + 1 >= pheapAddr.Size )
          {
            if ( v15 >= pheapAddr.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                &pheapAddr,
                &pheapAddr,
                v15 + (v15 >> 2));
          }
          else if ( v15 < pheapAddr.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              pheapAddr.Size + 1);
          }
          pheapAddr.Size = v15;
          v16 = (float *)&pheapAddr.Data[v15 - 1];
          if ( v16 )
            *v16 = v155;
          Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
            &pAltStream->Stream,
            "offset[%d] = %d\n",
            v148,
            pheapAddr.Data[v148]);
          if ( (int)++v148 >= (int)v11 )
            goto LABEL_22;
        }
        v141 = 0;
      }
LABEL_22:
      Size = v149->Glyphs.Data.Size;
      p_Glyphs = &v149->Glyphs;
      p_Data = &v149->Glyphs.Data;
      v155 = *(float *)&Size;
      if ( v11 >= Size )
      {
        if ( v11 >= v149->Glyphs.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_Glyphs->Data,
            p_Glyphs,
            v11 + (v11 >> 2));
      }
      else
      {
        v19 = Size - v11;
        v150 = (Scaleform::RefCountVImpl **)&p_Glyphs->Data.Data[v19 - 1 + v11];
        if ( v19 )
        {
          v148 = v19;
          do
          {
            if ( *v150 )
              Scaleform::RefCountImpl::Release(*v150);
            --v150;
            --v148;
          }
          while ( v148 );
        }
        if ( v11 < v149->Glyphs.Data.Policy.Capacity >> 1 )
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &p_Glyphs->Data,
            p_Glyphs,
            v11);
      }
      v20 = v155;
      v149->Glyphs.Data.Size = v11;
      if ( v11 > LODWORD(v20) )
      {
        v21 = v11 - LODWORD(v20);
        for ( i = &p_Glyphs->Data.Data[LODWORD(v20)]; v21; --v21 )
        {
          if ( i )
            i->pObject = 0;
          ++i;
        }
      }
      if ( v141 )
      {
        v23 = 0;
        if ( v156 > 0 )
        {
          do
          {
            v24 = (char *)pheapAddr.Data[v23] + v151;
            v150 = (Scaleform::RefCountVImpl **)(4 * v23);
            Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, (int)v24);
            v153 = v23 + 1;
            if ( v23 + 1 >= v156 )
              v25 = tagInfo->TagLength + tagInfo->TagDataOffset - (_DWORD)v24;
            else
              v25 = *(char **)((char *)v150 + (unsigned int)pheapAddr.Data + 4)
                  - *(char **)((char *)v150 + (unsigned int)pheapAddr.Data);
            v26 = 0;
            v27 = (int)pHeap->Alloc(pHeap, 16u, 0);
            if ( v27 )
            {
              *(_DWORD *)v27 = &Scaleform::RefCountImplCore::`vftable';
              *(_DWORD *)(v27 + 8) = 0;
              *(_DWORD *)(v27 + 4) = 1;
              *(_BYTE *)(v27 + 12) = 0;
              *(_DWORD *)v27 = &Scaleform::GFx::ConstShapeNoStyles::`vftable';
              v26 = (Scaleform::GFx::Resource *)v27;
            }
            ((void (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::LoadProcess *, int, int, _DWORD))v26->__vftable[3].GetResourceReport)(
              v26,
              p,
              2,
              v25,
              0);
            v28 = (Scaleform::RefCountVImpl **)((char *)v150 + (unsigned int)p_Data->Data);
            Scaleform::RefCountImpl::AddRef(v26);
            if ( *v28 )
              Scaleform::RefCountImpl::Release(*v28);
            *v28 = (Scaleform::RefCountVImpl *)v26;
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v26);
            v23 = v153;
          }
          while ( v153 < v156 );
          v29 = pheapAddr.Data;
          goto LABEL_249;
        }
      }
      else
      {
        v149->Flags |= 0x1000u;
      }
      v29 = pheapAddr.Data;
LABEL_249:
      if ( v29 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v29);
      return;
    case Tag_DefineFont2:
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "reading DefineFont2: ");
      break;
    case Tag_DefineFont3:
      Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "reading DefineFont3: ");
      break;
    default:
      return;
  }
  UInt = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
  v147 = UInt != 0;
  if ( UInt )
    this->Flags |= 0x2000u;
  else
    this->Flags &= ~0x2000u;
  v31 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  v146 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  v32 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
  if ( v31 )
  {
    this->Flags = this->Flags & 0xFFFFFCFF | 0x200;
  }
  else if ( v32 )
  {
    this->Flags = this->Flags & 0xFFFFFCFF | 0x100;
  }
  else
  {
    this->Flags &= 0xFFFFFCFF;
  }
  if ( v146 )
    this->Flags |= 0x8000u;
  else
    this->Flags &= ~0x8000u;
  v146 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
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
  v33 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v33 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
  v34 = pAltStream->Stream.Pos;
  v35 = pAltStream->Stream.pBuffer[v34];
  pAltStream->Stream.Pos = v34 + 1;
  v142 = v35;
  this->Name = Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, p->pLoadData.pObject->pHeap);
  v36 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
  pAltStream->Stream.UnusedBits = 0;
  if ( v36 < 2 )
    Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
  v37 = pAltStream->Stream.Pos;
  v38 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v37];
  pAltStream->Stream.Pos = v37 + 2;
  v156 = v38;
  if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
  {
    Name = v149->Name;
    if ( !Name )
      Name = "(none)";
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "  Name = %s, %d glyphs\n",
      Name,
      v38);
    v40 = v149->Flags & 0x300;
    v41 = "Unicode";
    if ( v40 == 512 )
    {
      v41 = "ShiftJIS";
    }
    else if ( v40 == 256 )
    {
      v41 = "ANSI";
    }
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
      &pAltStream->Stream,
      "  HasLayout = %d, CodePage = %s, Italic = %d, Bold = %d\n",
      v147,
      v41,
      v149->Flags & 1,
      (v149->Flags >> 1) & 1);
    Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  LangCode = %d\n", v142);
  }
  v42 = pAltStream->Stream.DataSize;
  v43 = pAltStream->Stream.Pos;
  v44 = 0;
  v161 = v43 + pAltStream->Stream.FilePos - v42;
  v45 = v38;
  memset(&v154, 0, sizeof(v154));
  v150 = (Scaleform::RefCountVImpl **)v38;
  if ( v38 > 0 )
  {
    v46 = v42 - v43;
    pAltStream->Stream.UnusedBits = 0;
    if ( v146 )
    {
      if ( v46 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v47 = pAltStream->Stream.Pos;
      v48 = pAltStream->Stream.pBuffer[v47]
          | ((pAltStream->Stream.pBuffer[v47 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v47 + 2] << 8)) << 8);
      pAltStream->Stream.Pos = v47 + 4;
    }
    else
    {
      if ( v46 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v49 = pAltStream->Stream.Pos;
      v50 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v49];
      pAltStream->Stream.Pos = v49 + 2;
      v48 = v50;
    }
    if ( v48 )
    {
      v164 = v48;
      Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        (Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> > *)&v154,
        &v164);
      v44 = v154.Size;
    }
    else
    {
      v141 = 0;
      v150 = 0;
    }
    v45 = (int)v150;
  }
  if ( v146 )
  {
    if ( v45 > 1 )
    {
      v148 = v45 - 1;
      do
      {
        v51 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v51 < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        v52 = pAltStream->Stream.Pos;
        v53 = pAltStream->Stream.pBuffer[v52]
            | ((pAltStream->Stream.pBuffer[v52 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v52 + 2] << 8)) << 8);
        v54 = v154.Size;
        v55 = v154.Size + 1;
        pAltStream->Stream.Pos = v52 + 4;
        if ( v55 >= v54 )
        {
          if ( v55 >= v154.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &v154,
              &v154,
              v55 + (v55 >> 2));
        }
        else if ( v55 < v154.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v154,
            &v154,
            v55);
        }
        v154.Size = v55;
        v56 = &v154.Data[v55 - 1];
        if ( v56 )
          *v56 = (Scaleform::GFx::AS3::Instances::fl::Object *)v53;
        --v148;
      }
      while ( v148 );
    }
    v57 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v57 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
    v58 = pAltStream->Stream.Pos;
    v59 = pAltStream->Stream.pBuffer[v58]
        | ((pAltStream->Stream.pBuffer[v58 + 1]
          | ((pAltStream->Stream.pBuffer[v58 + 2] | (pAltStream->Stream.pBuffer[v58 + 3] << 8)) << 8)) << 8);
    pAltStream->Stream.Pos = v58 + 4;
    v150 = (Scaleform::RefCountVImpl **)v59;
  }
  else
  {
    if ( v45 > 1 )
    {
      v148 = v45 - 1;
      do
      {
        v60 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v60 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v61 = pAltStream->Stream.Pos;
        LODWORD(v62) = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v61];
        v63 = v44 + 1;
        pAltStream->Stream.Pos = v61 + 2;
        v155 = v62;
        if ( v44 + 1 >= v44 )
        {
          if ( v63 >= v154.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &v154,
              &v154,
              v63 + (v63 >> 2));
        }
        else if ( v63 < v154.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v154,
            &v154,
            v44 + 1);
        }
        ++v44;
        v64 = (float *)&v154.Data[v63 - 1];
        v154.Size = v44;
        if ( v64 )
          *v64 = v155;
        --v148;
      }
      while ( v148 );
    }
    v65 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v65 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v66 = pAltStream->Stream.Pos;
    v67 = (Scaleform::RefCountVImpl **)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v66];
    pAltStream->Stream.Pos = v66 + 2;
    v150 = v67;
  }
  v68 = v156;
  v69 = v149->Glyphs.Data.Size;
  p_Data = &v149->Glyphs.Data;
  v148 = v69;
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &v149->Glyphs.Data,
    &v149->Glyphs,
    v156);
  if ( v68 > v148 )
  {
    v70 = &v149->Glyphs.Data.Data[v148];
    v71 = v68 - v148;
    if ( v68 != v148 )
    {
      do
      {
        if ( v70 )
          v70->pObject = 0;
        ++v70;
        --v71;
      }
      while ( v71 );
    }
  }
  if ( !v141 )
  {
    v92 = (int)v150 + v161;
    if ( v92 >= Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream) )
    {
LABEL_248:
      v29 = v154.Data;
      goto LABEL_249;
    }
    Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, v92);
    v149->Flags |= 0x1000u;
    goto LABEL_190;
  }
  v72 = tagInfo->TagType;
  v151 = 22;
  if ( v72 != Tag_DefineFont2 )
    v151 = v72;
  if ( v147 )
  {
    if ( v68 >= v149->AdvanceTable.Data.Size )
    {
      if ( v68 >= v149->AdvanceTable.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v149->AdvanceTable.Data,
          &v149->AdvanceTable,
          v68 + (v68 >> 2));
    }
    else if ( v68 < v149->AdvanceTable.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v149->AdvanceTable.Data,
        &v149->AdvanceTable,
        v68);
    }
    v149->AdvanceTable.Data.Size = v68;
  }
  v73 = 0;
  if ( (int)v68 > 0 )
  {
    v157 = 0;
    while ( 1 )
    {
      v74 = v73;
      Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, (int)v154.Data[v73] + v161);
      v152 = v73 + 1;
      v75 = (int)(v73 + 1) >= v156 ? (Scaleform::GFx::AS3::Instances::fl::Object *)v150 : v154.Data[v74 + 1];
      v76 = pHeap->__vftable;
      v153 = (char *)v75 - (char *)v154.Data[v74];
      v77 = (int)v76->Alloc(pHeap, 16u, 0);
      if ( v77 )
      {
        *(_DWORD *)v77 = &Scaleform::RefCountImplCore::`vftable';
        *(_DWORD *)(v77 + 4) = 1;
        *(_DWORD *)(v77 + 8) = 0;
        *(_BYTE *)(v77 + 12) = 0;
        *(_DWORD *)v77 = &Scaleform::GFx::ConstShapeNoStyles::`vftable';
        v143 = (Scaleform::GFx::Resource *)v77;
        v78 = ((int (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::LoadProcess *, int, int, _DWORD))v143->__vftable[3].GetResourceReport)(
                v143,
                p,
                v151,
                v153,
                0);
      }
      else
      {
        v143 = 0;
        v78 = (*(int (__thiscall **)(_DWORD, Scaleform::GFx::LoadProcess *, int, int, _DWORD))(MEMORY[0] + 60))(
                0,
                p,
                v151,
                v153,
                0);
      }
      if ( !v78 )
        break;
      v79 = (Scaleform::RefCountVImpl **)&p_Data->Data[v74];
      Scaleform::RefCountImpl::AddRef(v143);
      if ( *v79 )
        Scaleform::RefCountImpl::Release(*v79);
      v80 = !v147;
      v81 = (Scaleform::RefCountVImpl *)v143;
      *v79 = (Scaleform::RefCountVImpl *)v143;
      if ( !v80 )
      {
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        Scaleform::GFx::ShapeDataBase::ComputeBound((Scaleform::GFx::ShapeDataBase *)v143, &r);
        x1 = r.x1;
        v83 = (_WORD *)((char *)v149->AdvanceTable.Data.Data + v157);
        if ( r.x1 > (double)r.x2 || r.y1 > (double)r.y2 )
        {
          v83[3] = 0;
          v83[2] = 0;
          v86 = 0;
          v83[4] = 0;
        }
        else
        {
          v144 = r.x2 - x1;
          v158 = r.y2 - r.y1;
          v84 = (int)(x1 * 20.0);
          v85 = r.y1 * 20.0;
          v83[2] = v84;
          v83[3] = (int)v85;
          v153 = (int)(v144 * 20.0);
          v83[4] = v153;
          LODWORD(v158) = (int)(20.0 * v158);
          v86 = LOWORD(v158);
        }
        v83[5] = v86;
      }
      Scaleform::RefCountImpl::Release(v81);
      v73 = v152;
      v157 += 12;
      if ( v152 >= v156 )
        goto LABEL_162;
    }
    if ( v73 >= v149->AdvanceTable.Data.Size )
    {
      if ( v73 >= v149->AdvanceTable.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &v149->AdvanceTable.Data,
          &v149->AdvanceTable,
          v73 + (v73 >> 2));
    }
    else if ( v73 < v149->AdvanceTable.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &v149->AdvanceTable.Data,
        &v149->AdvanceTable,
        v73);
    }
    v149->AdvanceTable.Data.Size = v73;
    v87 = p_Data;
    v88 = p_Data->Size;
    v157 = v88;
    if ( v73 >= v88 )
    {
      if ( v73 < p_Data->Policy.Capacity )
        goto LABEL_181;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Data,
        p_Data,
        v73 + (v73 >> 2));
    }
    else
    {
      v89 = (Scaleform::RefCountVImpl **)&p_Data->Data[v88 - 1];
      if ( v88 != v73 )
      {
        v151 = v88 - v73;
        do
        {
          if ( *v89 )
          {
            Scaleform::RefCountImpl::Release(*v89);
            v88 = v157;
          }
          --v89;
          --v151;
        }
        while ( v151 );
      }
      if ( v73 >= v87->Policy.Capacity >> 1 )
        goto LABEL_181;
      Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v87,
        v87,
        v73);
    }
    v88 = v157;
LABEL_181:
    v87->Size = v73;
    if ( v73 > v88 )
    {
      v90 = v73 - v88;
      for ( j = &v87->Data[v88]; v90; --v90 )
      {
        if ( j )
          j->pObject = 0;
        ++j;
      }
    }
    if ( v143 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v143);
    goto LABEL_248;
  }
LABEL_162:
  if ( (Scaleform::RefCountVImpl **)((char *)v150 + v161) == (Scaleform::RefCountVImpl **)(pAltStream->Stream.Pos
                                                                                         + pAltStream->Stream.FilePos
                                                                                         - pAltStream->Stream.DataSize) )
  {
LABEL_190:
    Scaleform::GFx::FontData::ReadCodeTable(v149, &pAltStream->Stream);
    if ( v147 )
    {
      if ( tagInfo->TagType == Tag_DefineFont3 )
        v93 = 0.050000001;
      else
        v93 = 1.0;
      v145 = v93;
      v94 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v94 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v95 = pAltStream->Stream.Pos;
      v96 = v149;
      v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v95];
      pAltStream->Stream.Pos = v95 + 2;
      v96->Ascent = v145 * (double)v152;
      v97 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v97 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v98 = pAltStream->Stream.Pos;
      v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v98];
      pAltStream->Stream.Pos = v98 + 2;
      v96->Descent = v145 * (double)v152;
      v99 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v99 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v100 = pAltStream->Stream.Pos;
      v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v100];
      pAltStream->Stream.Pos = v100 + 2;
      v96->Leading = v145 * (double)v152;
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
          &pAltStream->Stream,
          "  Ascent = %d, Descent = %d, Leading = %d\n",
          (int)v96->Ascent,
          (int)v96->Descent,
          (int)v96->Leading);
      v101 = v96->Glyphs.Data.Size;
      if ( v96->AdvanceTable.Data.Size != v101 )
      {
        v102 = &v96->AdvanceTable.Data;
        if ( v101 >= v102->Size )
        {
          if ( v101 >= v102->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v102,
              v102,
              v101 + (v101 >> 2));
        }
        else if ( v101 < v102->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v102,
            v102,
            v101);
        }
        v102->Size = v101;
        v96 = v149;
      }
      v103 = v96->AdvanceTable.Data.Size;
      if ( v103 )
      {
        v104 = 0;
        v151 = v103;
        do
        {
          v105 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          v106 = &v149->AdvanceTable.Data.Data[v104];
          pAltStream->Stream.UnusedBits = 0;
          if ( v105 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v107 = pAltStream->Stream.Pos;
          v152 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v107];
          ++v104;
          v80 = v151-- == 1;
          v108 = (double)v152;
          pAltStream->Stream.Pos = v107 + 2;
          v106->Advance = v145 * v108;
        }
        while ( !v80 );
      }
      v109 = v149->Glyphs.Data.Size;
      pr.x1 = 0.0;
      pr.y1 = 0.0;
      pr.x2 = 0.0;
      for ( pr.y2 = 0.0; v109; --v109 )
        Scaleform::GFx::Stream::ReadRect(&pAltStream->Stream, &pr);
      v110 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v110 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v111 = pAltStream->Stream.Pos;
      v112 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v111];
      pAltStream->Stream.Pos = v111 + 2;
      v158 = *(float *)&v112;
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(&pAltStream->Stream, "  KerningCount = %d\n", v112);
      v151 = 0;
      if ( v112 > 0 )
      {
        while ( 1 )
        {
          v113 = pAltStream->Stream.DataSize;
          v114 = pAltStream->Stream.Pos;
          if ( (int)(v114 + pAltStream->Stream.FilePos - v113) >= tagInfo->TagDataOffset + tagInfo->TagLength )
            break;
          v115 = v149->Flags >> 14;
          v116 = v113 - v114;
          pAltStream->Stream.UnusedBits = 0;
          if ( (v115 & 1) != 0 )
          {
            if ( v116 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v117 = pAltStream->Stream.Pos;
            v118 = *(_WORD *)&pAltStream->Stream.pBuffer[v117];
            v117 += 2;
            v119 = pAltStream->Stream.DataSize - v117;
            pAltStream->Stream.Pos = v117;
            v120 = v118;
            pAltStream->Stream.UnusedBits = 0;
            if ( v119 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v121 = pAltStream->Stream.Pos;
            v122 = *(_WORD *)&pAltStream->Stream.pBuffer[v121];
            v123 = v121 + 2;
            v124 = v122;
          }
          else
          {
            if ( v116 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v125 = pAltStream->Stream.Pos;
            v126 = pAltStream->Stream.pBuffer[v125++];
            v127 = pAltStream->Stream.DataSize - v125;
            pAltStream->Stream.Pos = v125;
            v120 = v126;
            pAltStream->Stream.UnusedBits = 0;
            if ( v127 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v128 = pAltStream->Stream.Pos;
            v129 = pAltStream->Stream.pBuffer[v128];
            v123 = v128 + 1;
            v124 = v129;
          }
          pAltStream->Stream.Pos = v123;
          v130 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v130 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v131 = pAltStream->Stream.Pos;
          v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v131];
          v132 = (double)v152;
          pAltStream->Stream.Pos = v131 + 2;
          LOWORD(v148) = v120;
          HIWORD(v148) = v124;
          v155 = v145 * v132;
          if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
            Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogParse(
              &pAltStream->Stream,
              "     Pair: %d - %d,\tadj = %d\n",
              v120,
              v124,
              (int)v155);
          key.pFirst = (const Scaleform::GFx::FontData::KerningPair *)&v148;
          key.pSecond = &v155;
          v133 = 4;
          v134 = 5381;
          do
          {
            v135 = *(&v147 + v133--);
            v134 = v135 + 65599 * v134;
          }
          while ( v133 );
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeRef>(
            &v149->KerningPairs.mHash,
            &v149->KerningPairs,
            &key,
            v134);
          if ( ++v151 >= SLODWORD(v158) )
            goto LABEL_244;
        }
        v136 = v149->Name;
        if ( !v136 )
          v136 = "<noname>";
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
          &pAltStream->Stream,
          "Corrupted file %s, kerning table of the font '%s' is longer than tagLength.",
          (const char *)((pAltStream->Stream.FileName.HeapTypeBits & 0xFFFFFFFC) + 8),
          v136);
      }
    }
LABEL_244:
    if ( !v141 )
    {
      v137 = v149;
      v138 = v149->AdvanceTable.Data.Size;
      if ( v138 )
      {
        v139 = 0;
        do
        {
          v140 = &v137->AdvanceTable.Data.Data[v139++];
          --v138;
          v140->Width = 0;
          v140->Height = 0;
          v140->Top = 0;
          v140->Left = 0;
        }
        while ( v138 );
      }
    }
    goto LABEL_248;
  }
  if ( v154.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v154.Data);
}
