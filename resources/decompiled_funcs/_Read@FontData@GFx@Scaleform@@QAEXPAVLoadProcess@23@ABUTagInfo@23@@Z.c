void __thiscall Scaleform::GFx::FontData::Read(
        Scaleform::GFx::FontData *this,
        Scaleform::GFx::LoadProcess *p,
        const Scaleform::GFx::TagInfo *tagInfo)
{
  Scaleform::GFx::SWFProcessInfo *pAltStream; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::TagType TagType; // eax
  unsigned int DataSize; // eax
  unsigned int Pos; // edx
  unsigned int v9; // eax
  Scaleform::GFx::AS3::Instances::fl::Object *v10; // ebx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v11; // ecx
  Scaleform::GFx::AS3::Instances::fl::Object **Data; // edi
  unsigned int v13; // ebx
  int v14; // ecx
  unsigned int v15; // eax
  unsigned __int16 v16; // cx
  unsigned int v17; // edi
  float *v18; // edi
  unsigned int Size; // eax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261,Scaleform::ArrayDefaultPolicy> *p_Glyphs; // edi
  int v21; // eax
  float v22; // ecx
  unsigned int v23; // ebx
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *i; // eax
  int v25; // ebx
  char *v26; // edi
  int v27; // ebx
  Scaleform::GFx::Resource *v28; // edi
  int v29; // eax
  Scaleform::RefCountVImpl **v30; // ebx
  void *v31; // eax
  int UInt; // eax
  bool v33; // bl
  bool v34; // al
  int v35; // eax
  int v36; // edx
  unsigned int v37; // eax
  signed int v38; // edi
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v39; // ecx
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v40; // ecx
  unsigned int v41; // eax
  unsigned int v42; // edx
  unsigned int v43; // ebx
  int v44; // ecx
  int v45; // eax
  unsigned int v46; // edx
  int v47; // eax
  unsigned int v48; // eax
  int v49; // ecx
  int v50; // eax
  unsigned int v51; // ecx
  int v52; // edi
  unsigned int v53; // eax
  unsigned int v54; // ebx
  int *v55; // ebx
  int v56; // eax
  unsigned int v57; // edx
  int v58; // eax
  int v59; // edx
  unsigned int v60; // eax
  float v61; // edx
  unsigned int v62; // edi
  float *v63; // edi
  int v64; // eax
  unsigned int v65; // eax
  Scaleform::RefCountVImpl **v66; // edx
  unsigned int v67; // ebx
  unsigned int v68; // eax
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *v69; // eax
  unsigned int v70; // ecx
  Scaleform::GFx::TagType v71; // eax
  unsigned int v72; // edi
  unsigned int v73; // ebx
  Scaleform::RefCountVImpl **v74; // eax
  Scaleform::MemoryHeap_vtbl *v75; // edx
  int v76; // eax
  char v77; // al
  Scaleform::RefCountVImpl **v78; // edi
  bool v79; // zf
  Scaleform::RefCountVImpl *v80; // ebx
  double x1; // st6
  _WORD *v82; // edi
  int v83; // eax
  double v84; // st6
  __int16 v85; // cx
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *v86; // esi
  unsigned int v87; // edx
  Scaleform::RefCountVImpl **v88; // ebx
  unsigned int v89; // edi
  Scaleform::Ptr<Scaleform::GFx::ShapeDataBase> *j; // eax
  int v91; // edi
  double v92; // st7
  int v93; // edx
  unsigned int v94; // eax
  Scaleform::GFx::FontData *v95; // edi
  int v96; // eax
  unsigned int v97; // eax
  int v98; // eax
  unsigned int v99; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v100; // ecx
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
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v113; // ecx
  unsigned int v114; // eax
  unsigned int v115; // ecx
  unsigned int v116; // edx
  int v117; // eax
  unsigned int v118; // eax
  unsigned __int16 v119; // cx
  int v120; // edx
  unsigned __int16 v121; // bx
  unsigned int v122; // eax
  __int16 v123; // cx
  unsigned int v124; // eax
  __int16 v125; // di
  unsigned int v126; // eax
  unsigned __int8 v127; // cl
  int v128; // edx
  unsigned int v129; // eax
  unsigned __int8 v130; // cl
  int v131; // eax
  unsigned int v132; // eax
  double v133; // st6
  int v134; // eax
  unsigned int v135; // edx
  BOOL v136; // edi
  char *Name; // eax
  Scaleform::GFx::FontData *v138; // esi
  unsigned int v139; // edx
  int v140; // ecx
  Scaleform::GFx::FontData::AdvanceEntry *v141; // eax
  char v142; // [esp+A97h] [ebp-85h]
  Scaleform::GFx::Resource *v143; // [esp+A98h] [ebp-84h]
  float v144; // [esp+A98h] [ebp-84h]
  float v145; // [esp+A98h] [ebp-84h]
  bool v146; // [esp+A9Eh] [ebp-7Eh]
  bool v147; // [esp+A9Fh] [ebp-7Dh]
  int v148; // [esp+AA0h] [ebp-7Ch] BYREF
  Scaleform::GFx::FontData *v149; // [esp+AA4h] [ebp-78h]
  Scaleform::RefCountVImpl **v150; // [esp+AA8h] [ebp-74h]
  int v151; // [esp+AACh] [ebp-70h]
  int v152; // [esp+AB0h] [ebp-6Ch]
  int v153; // [esp+AB4h] [ebp-68h]
  Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> > v154; // [esp+AB8h] [ebp-64h] BYREF
  float v155; // [esp+AC4h] [ebp-58h] BYREF
  unsigned int newSize; // [esp+AC8h] [ebp-54h]
  unsigned int v157; // [esp+ACCh] [ebp-50h]
  float v158; // [esp+AD0h] [ebp-4Ch]
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [esp+AD4h] [ebp-48h] BYREF
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy> *p_Data; // [esp+AE0h] [ebp-3Ch]
  unsigned int v161; // [esp+AE4h] [ebp-38h]
  Scaleform::MemoryHeap *v162; // [esp+AE8h] [ebp-34h]
  Scaleform::Render::Rect<float> r; // [esp+AECh] [ebp-30h] BYREF
  int val; // [esp+B00h] [ebp-1Ch] BYREF
  Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair> >::NodeRef key; // [esp+B04h] [ebp-18h] BYREF
  Scaleform::Render::Rect<float> pr; // [esp+B0Ch] [ebp-10h] BYREF

  pAltStream = (Scaleform::GFx::SWFProcessInfo *)p->pAltStream;
  v149 = this;
  if ( !pAltStream )
    pAltStream = &p->ProcessInfo;
  pHeap = p->pLoadData.pObject->pHeap;
  TagType = tagInfo->TagType;
  v142 = 1;
  v162 = pHeap;
  if ( TagType == Tag_DefineFont )
  {
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pHeap);
    DataSize = pAltStream->Stream.DataSize;
    Pos = pAltStream->Stream.Pos;
    v151 = Pos + pAltStream->Stream.FilePos - DataSize;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    pAltStream->Stream.UnusedBits = 0;
    if ( (int)(DataSize - Pos) < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v9 = pAltStream->Stream.Pos;
    v10 = (Scaleform::GFx::AS3::Instances::fl::Object *)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v9];
    pAltStream->Stream.Pos = v9 + 2;
    Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &pheapAddr,
      &pheapAddr,
      1u);
    Data = pheapAddr.Data;
    pheapAddr.Size = 1;
    if ( pheapAddr.Data )
      *pheapAddr.Data = v10;
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(v11);
    newSize = (int)*Data >> 1;
    v13 = newSize;
    v148 = 1;
    if ( (int)newSize > 1 )
    {
      while ( 1 )
      {
        v14 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
        pAltStream->Stream.UnusedBits = 0;
        if ( v14 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v15 = pAltStream->Stream.Pos;
        v16 = *(_WORD *)&pAltStream->Stream.pBuffer[v15];
        pAltStream->Stream.Pos = v15 + 2;
        if ( !v16 )
          break;
        v17 = pheapAddr.Size + 1;
        LODWORD(v155) = v16;
        if ( pheapAddr.Size + 1 >= pheapAddr.Size )
        {
          if ( v17 >= pheapAddr.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &pheapAddr,
              &pheapAddr,
              v17 + (v17 >> 2));
        }
        else if ( v17 < pheapAddr.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &pheapAddr,
            &pheapAddr,
            pheapAddr.Size + 1);
        }
        pheapAddr.Size = v17;
        v18 = (float *)&pheapAddr.Data[v17 - 1];
        if ( v18 )
          *v18 = v155;
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(pheapAddr.Data[v148++]);
        if ( v148 >= (int)v13 )
          goto LABEL_22;
      }
      v142 = 0;
    }
LABEL_22:
    Size = v149->Glyphs.Data.Size;
    p_Glyphs = &v149->Glyphs;
    p_Data = &v149->Glyphs.Data;
    v155 = *(float *)&Size;
    if ( v13 >= Size )
    {
      if ( v13 >= v149->Glyphs.Data.Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &p_Glyphs->Data,
          p_Glyphs,
          v13 + (v13 >> 2));
    }
    else
    {
      v21 = Size - v13;
      v150 = (Scaleform::RefCountVImpl **)&p_Glyphs->Data.Data[v21 - 1 + v13];
      if ( v21 )
      {
        v148 = v21;
        do
        {
          if ( *v150 )
            Scaleform::RefCountImpl::Release(*v150);
          --v150;
          --v148;
        }
        while ( v148 );
      }
      if ( v13 < v149->Glyphs.Data.Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &p_Glyphs->Data,
          p_Glyphs,
          v13);
    }
    v22 = v155;
    v149->Glyphs.Data.Size = v13;
    if ( v13 > LODWORD(v22) )
    {
      v23 = v13 - LODWORD(v22);
      for ( i = &p_Glyphs->Data.Data[LODWORD(v22)]; v23; --v23 )
      {
        if ( i )
          i->pObject = 0;
        ++i;
      }
    }
    if ( v142 )
    {
      v25 = 0;
      if ( (int)newSize > 0 )
      {
        do
        {
          v26 = (char *)pheapAddr.Data[v25] + v151;
          v150 = (Scaleform::RefCountVImpl **)(4 * v25);
          Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, (int)v26);
          v153 = v25 + 1;
          if ( v25 + 1 >= (int)newSize )
            v27 = tagInfo->TagLength + tagInfo->TagDataOffset - (_DWORD)v26;
          else
            v27 = *(char **)((char *)v150 + (unsigned int)pheapAddr.Data + 4)
                - *(char **)((char *)v150 + (unsigned int)pheapAddr.Data);
          v28 = 0;
          v29 = (int)v162->Alloc(v162, 16u, 0);
          if ( v29 )
          {
            *(_DWORD *)v29 = &Scaleform::RefCountImplCore::`vftable';
            *(_DWORD *)(v29 + 8) = 0;
            *(_DWORD *)(v29 + 4) = 1;
            *(_BYTE *)(v29 + 12) = 0;
            *(_DWORD *)v29 = &Scaleform::GFx::ConstShapeNoStyles::`vftable';
            v28 = (Scaleform::GFx::Resource *)v29;
          }
          ((void (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::LoadProcess *, int, int, _DWORD))v28->__vftable[3].GetResourceReport)(
            v28,
            p,
            2,
            v27,
            0);
          v30 = (Scaleform::RefCountVImpl **)((char *)v150 + (unsigned int)p_Data->Data);
          Scaleform::RefCountImpl::AddRef(v28);
          if ( *v30 )
            Scaleform::RefCountImpl::Release(*v30);
          *v30 = (Scaleform::RefCountVImpl *)v28;
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v28);
          v25 = v153;
        }
        while ( v153 < (int)newSize );
        v31 = pheapAddr.Data;
        goto LABEL_242;
      }
    }
    else
    {
      v149->Flags |= 0x1000u;
    }
    v31 = pheapAddr.Data;
LABEL_242:
    if ( v31 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v31);
    return;
  }
  if ( TagType == Tag_DefineFont2 || TagType == Tag_DefineFont3 )
  {
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pHeap);
    UInt = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1);
    v147 = UInt != 0;
    if ( UInt )
      this->Flags |= 0x2000u;
    else
      this->Flags &= ~0x2000u;
    v33 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    v146 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    v34 = Scaleform::GFx::Stream::ReadUInt(&pAltStream->Stream, 1) != 0;
    if ( v33 )
    {
      this->Flags = this->Flags & 0xFFFFFCFF | 0x200;
    }
    else if ( v34 )
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
    v35 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v35 < 1 )
      Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
    ++pAltStream->Stream.Pos;
    this->Name = Scaleform::GFx::Stream::ReadStringWithLength(&pAltStream->Stream, p->pLoadData.pObject->pHeap);
    v36 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
    pAltStream->Stream.UnusedBits = 0;
    if ( v36 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
    v37 = pAltStream->Stream.Pos;
    v38 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v37];
    pAltStream->Stream.Pos = v37 + 2;
    newSize = v38;
    if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
    {
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v39);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v147);
      Scaleform::Render::JPEG::JPEGRwSource::TermSource(v40);
    }
    v41 = pAltStream->Stream.DataSize;
    v42 = pAltStream->Stream.Pos;
    v43 = 0;
    v161 = v42 + pAltStream->Stream.FilePos - v41;
    v44 = v38;
    memset(&v154, 0, sizeof(v154));
    v150 = (Scaleform::RefCountVImpl **)v38;
    if ( v38 > 0 )
    {
      v45 = v41 - v42;
      pAltStream->Stream.UnusedBits = 0;
      if ( v146 )
      {
        if ( v45 < 4 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
        v46 = pAltStream->Stream.Pos;
        v47 = pAltStream->Stream.pBuffer[v46]
            | ((pAltStream->Stream.pBuffer[v46 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v46 + 2] << 8)) << 8);
        pAltStream->Stream.Pos = v46 + 4;
      }
      else
      {
        if ( v45 < 2 )
          Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
        v48 = pAltStream->Stream.Pos;
        v49 = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v48];
        pAltStream->Stream.Pos = v48 + 2;
        v47 = v49;
      }
      if ( v47 )
      {
        val = v47;
        Scaleform::ArrayBase<Scaleform::ArrayData<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
          &v154,
          &val);
        v43 = v154.Data.Size;
      }
      else
      {
        v142 = 0;
        v150 = 0;
      }
      v44 = (int)v150;
    }
    if ( v146 )
    {
      if ( v44 > 1 )
      {
        v148 = v44 - 1;
        do
        {
          v50 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v50 < 4 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
          v51 = pAltStream->Stream.Pos;
          v52 = pAltStream->Stream.pBuffer[v51]
              | ((pAltStream->Stream.pBuffer[v51 + 1] | (*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v51 + 2] << 8)) << 8);
          v53 = v154.Data.Size;
          v54 = v154.Data.Size + 1;
          pAltStream->Stream.Pos = v51 + 4;
          if ( v54 >= v53 )
          {
            if ( v54 >= v154.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&v154,
                &v154,
                v54 + (v54 >> 2));
          }
          else if ( v54 < v154.Data.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&v154,
              &v154,
              v54);
          }
          v154.Data.Size = v54;
          v55 = &v154.Data.Data[v54 - 1];
          if ( v55 )
            *v55 = v52;
          --v148;
        }
        while ( v148 );
      }
      v56 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v56 < 4 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 4);
      v57 = pAltStream->Stream.Pos;
      v58 = pAltStream->Stream.pBuffer[v57]
          | ((pAltStream->Stream.pBuffer[v57 + 1]
            | ((pAltStream->Stream.pBuffer[v57 + 2] | (pAltStream->Stream.pBuffer[v57 + 3] << 8)) << 8)) << 8);
      pAltStream->Stream.Pos = v57 + 4;
      v150 = (Scaleform::RefCountVImpl **)v58;
    }
    else
    {
      if ( v44 > 1 )
      {
        v148 = v44 - 1;
        do
        {
          v59 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v59 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v60 = pAltStream->Stream.Pos;
          LODWORD(v61) = *(unsigned __int16 *)&pAltStream->Stream.pBuffer[v60];
          v62 = v43 + 1;
          pAltStream->Stream.Pos = v60 + 2;
          v155 = v61;
          if ( v43 + 1 >= v43 )
          {
            if ( v62 >= v154.Data.Policy.Capacity )
              Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&v154,
                &v154,
                v62 + (v62 >> 2));
          }
          else if ( v62 < v154.Data.Policy.Capacity >> 1 )
          {
            Scaleform::ArrayDataBase<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Instances::fl::Object *,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Instances::fl::Object *,2>,Scaleform::ArrayDefaultPolicy> *)&v154,
              &v154,
              v43 + 1);
          }
          ++v43;
          v63 = (float *)&v154.Data.Data[v62 - 1];
          v154.Data.Size = v43;
          if ( v63 )
            *v63 = v155;
          --v148;
        }
        while ( v148 );
      }
      v64 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v64 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v65 = pAltStream->Stream.Pos;
      v66 = (Scaleform::RefCountVImpl **)*(unsigned __int16 *)&pAltStream->Stream.pBuffer[v65];
      pAltStream->Stream.Pos = v65 + 2;
      v150 = v66;
    }
    v67 = newSize;
    v68 = v149->Glyphs.Data.Size;
    p_Data = &v149->Glyphs.Data;
    v148 = v68;
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &v149->Glyphs.Data,
      &v149->Glyphs,
      newSize);
    if ( v67 > v148 )
    {
      v69 = &v149->Glyphs.Data.Data[v148];
      v70 = v67 - v148;
      if ( v67 != v148 )
      {
        do
        {
          if ( v69 )
            v69->pObject = 0;
          ++v69;
          --v70;
        }
        while ( v70 );
      }
    }
    if ( v142 )
    {
      v71 = tagInfo->TagType;
      v151 = 22;
      if ( v71 != Tag_DefineFont2 )
        v151 = v71;
      if ( v147 )
      {
        if ( v67 >= v149->AdvanceTable.Data.Size )
        {
          if ( v67 >= v149->AdvanceTable.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &v149->AdvanceTable.Data,
              &v149->AdvanceTable,
              v67 + (v67 >> 2));
        }
        else if ( v67 < v149->AdvanceTable.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v149->AdvanceTable.Data,
            &v149->AdvanceTable,
            v67);
        }
        v149->AdvanceTable.Data.Size = v67;
      }
      v72 = 0;
      if ( (int)v67 > 0 )
      {
        v157 = 0;
        while ( 1 )
        {
          v73 = v72;
          Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, v161 + v154.Data.Data[v72]);
          v152 = v72 + 1;
          v74 = (int)(v72 + 1) >= (int)newSize ? v150 : (Scaleform::RefCountVImpl **)v154.Data.Data[v73 + 1];
          v75 = v162->__vftable;
          v153 = (int)v74 - v154.Data.Data[v73];
          v76 = (int)v75->Alloc(v162, 16u, 0);
          if ( v76 )
          {
            *(_DWORD *)v76 = &Scaleform::RefCountImplCore::`vftable';
            *(_DWORD *)(v76 + 4) = 1;
            *(_DWORD *)(v76 + 8) = 0;
            *(_BYTE *)(v76 + 12) = 0;
            *(_DWORD *)v76 = &Scaleform::GFx::ConstShapeNoStyles::`vftable';
            v143 = (Scaleform::GFx::Resource *)v76;
            v77 = ((int (__thiscall *)(Scaleform::GFx::Resource *, Scaleform::GFx::LoadProcess *, int, int, _DWORD))v143->__vftable[3].GetResourceReport)(
                    v143,
                    p,
                    v151,
                    v153,
                    0);
          }
          else
          {
            v143 = 0;
            v77 = (*(int (__thiscall **)(_DWORD, Scaleform::GFx::LoadProcess *, int, int, _DWORD))(MEMORY[0] + 60))(
                    0,
                    p,
                    v151,
                    v153,
                    0);
          }
          if ( !v77 )
            break;
          v78 = (Scaleform::RefCountVImpl **)&p_Data->Data[v73];
          Scaleform::RefCountImpl::AddRef(v143);
          if ( *v78 )
            Scaleform::RefCountImpl::Release(*v78);
          v79 = !v147;
          v80 = (Scaleform::RefCountVImpl *)v143;
          *v78 = (Scaleform::RefCountVImpl *)v143;
          if ( !v79 )
          {
            r.x1 = 0.0;
            r.y1 = 0.0;
            r.x2 = 0.0;
            r.y2 = 0.0;
            Scaleform::GFx::ShapeDataBase::ComputeBound((Scaleform::GFx::ShapeDataBase *)v143, &r);
            x1 = r.x1;
            v82 = (_WORD *)((char *)v149->AdvanceTable.Data.Data + v157);
            if ( r.x1 > (double)r.x2 || r.y1 > (double)r.y2 )
            {
              v82[3] = 0;
              v82[2] = 0;
              v85 = 0;
              v82[4] = 0;
            }
            else
            {
              v144 = r.x2 - x1;
              v158 = r.y2 - r.y1;
              v83 = (int)(x1 * 20.0);
              v84 = r.y1 * 20.0;
              v82[2] = v83;
              v82[3] = (int)v84;
              v153 = (int)(v144 * 20.0);
              v82[4] = v153;
              LODWORD(v158) = (int)(20.0 * v158);
              v85 = LOWORD(v158);
            }
            v82[5] = v85;
          }
          Scaleform::RefCountImpl::Release(v80);
          v72 = v152;
          v157 += 12;
          if ( v152 >= (int)newSize )
            goto LABEL_155;
        }
        if ( v72 >= v149->AdvanceTable.Data.Size )
        {
          if ( v72 >= v149->AdvanceTable.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
              &v149->AdvanceTable.Data,
              &v149->AdvanceTable,
              v72 + (v72 >> 2));
        }
        else if ( v72 < v149->AdvanceTable.Data.Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v149->AdvanceTable.Data,
            &v149->AdvanceTable,
            v72);
        }
        v149->AdvanceTable.Data.Size = v72;
        v86 = p_Data;
        v87 = p_Data->Size;
        v157 = v87;
        if ( v72 >= v87 )
        {
          if ( v72 < p_Data->Policy.Capacity )
            goto LABEL_174;
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
            p_Data,
            p_Data,
            v72 + (v72 >> 2));
        }
        else
        {
          v88 = (Scaleform::RefCountVImpl **)&p_Data->Data[v87 - 1];
          if ( v87 != v72 )
          {
            v151 = v87 - v72;
            do
            {
              if ( *v88 )
              {
                Scaleform::RefCountImpl::Release(*v88);
                v87 = v157;
              }
              --v88;
              --v151;
            }
            while ( v151 );
          }
          if ( v72 >= v86->Policy.Capacity >> 1 )
            goto LABEL_174;
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ShapeDataBase>,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v86,
            v86,
            v72);
        }
        v87 = v157;
LABEL_174:
        v86->Size = v72;
        if ( v72 > v87 )
        {
          v89 = v72 - v87;
          for ( j = &v86->Data[v87]; v89; --v89 )
          {
            if ( j )
              j->pObject = 0;
            ++j;
          }
        }
        if ( v143 )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v143);
        goto LABEL_241;
      }
LABEL_155:
      if ( (Scaleform::RefCountVImpl **)((char *)v150 + v161) != (Scaleform::RefCountVImpl **)(pAltStream->Stream.Pos
                                                                                             + pAltStream->Stream.FilePos
                                                                                             - pAltStream->Stream.DataSize) )
      {
        if ( v154.Data.Data )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v154.Data.Data);
        return;
      }
    }
    else
    {
      v91 = (int)v150 + v161;
      if ( v91 >= Scaleform::GFx::Stream::GetTagEndPosition(&pAltStream->Stream) )
      {
LABEL_241:
        v31 = v154.Data.Data;
        goto LABEL_242;
      }
      Scaleform::GFx::Stream::SetPosition(&pAltStream->Stream, v91);
      v149->Flags |= 0x1000u;
    }
    Scaleform::GFx::FontData::ReadCodeTable(v149, &pAltStream->Stream);
    if ( v147 )
    {
      if ( tagInfo->TagType == Tag_DefineFont3 )
        v92 = 0.050000001;
      else
        v92 = 1.0;
      v145 = v92;
      v93 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v93 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v94 = pAltStream->Stream.Pos;
      v95 = v149;
      v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v94];
      pAltStream->Stream.Pos = v94 + 2;
      v95->Ascent = v145 * (double)v152;
      v96 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v96 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v97 = pAltStream->Stream.Pos;
      v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v97];
      pAltStream->Stream.Pos = v97 + 2;
      v95->Descent = v145 * (double)v152;
      v98 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
      pAltStream->Stream.UnusedBits = 0;
      if ( v98 < 2 )
        Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
      v99 = pAltStream->Stream.Pos;
      v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v99];
      pAltStream->Stream.Pos = v99 + 2;
      v95->Leading = v145 * (double)v152;
      if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v100);
      v101 = v95->Glyphs.Data.Size;
      if ( v95->AdvanceTable.Data.Size != v101 )
      {
        v102 = &v95->AdvanceTable.Data;
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
        v95 = v149;
      }
      v103 = v95->AdvanceTable.Data.Size;
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
          v79 = v151-- == 1;
          v108 = (double)v152;
          pAltStream->Stream.Pos = v107 + 2;
          v106->Advance = v145 * v108;
        }
        while ( !v79 );
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
        Scaleform::Render::JPEG::JPEGRwSource::TermSource(v113);
      v151 = 0;
      if ( v112 > 0 )
      {
        while ( 1 )
        {
          v114 = pAltStream->Stream.DataSize;
          v115 = pAltStream->Stream.Pos;
          if ( (int)(v115 + pAltStream->Stream.FilePos - v114) >= tagInfo->TagDataOffset + tagInfo->TagLength )
            break;
          v116 = v149->Flags >> 14;
          v117 = v114 - v115;
          pAltStream->Stream.UnusedBits = 0;
          if ( (v116 & 1) != 0 )
          {
            if ( v117 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v118 = pAltStream->Stream.Pos;
            v119 = *(_WORD *)&pAltStream->Stream.pBuffer[v118];
            v118 += 2;
            v120 = pAltStream->Stream.DataSize - v118;
            pAltStream->Stream.Pos = v118;
            v121 = v119;
            pAltStream->Stream.UnusedBits = 0;
            if ( v120 < 2 )
              Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
            v122 = pAltStream->Stream.Pos;
            v123 = *(_WORD *)&pAltStream->Stream.pBuffer[v122];
            v124 = v122 + 2;
            v125 = v123;
          }
          else
          {
            if ( v117 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v126 = pAltStream->Stream.Pos;
            v127 = pAltStream->Stream.pBuffer[v126++];
            v128 = pAltStream->Stream.DataSize - v126;
            pAltStream->Stream.Pos = v126;
            v121 = v127;
            pAltStream->Stream.UnusedBits = 0;
            if ( v128 < 1 )
              Scaleform::GFx::Stream::PopulateBuffer1(&pAltStream->Stream);
            v129 = pAltStream->Stream.Pos;
            v130 = pAltStream->Stream.pBuffer[v129];
            v124 = v129 + 1;
            v125 = v130;
          }
          pAltStream->Stream.Pos = v124;
          v131 = pAltStream->Stream.DataSize - pAltStream->Stream.Pos;
          pAltStream->Stream.UnusedBits = 0;
          if ( v131 < 2 )
            Scaleform::GFx::Stream::PopulateBuffer(&pAltStream->Stream, 2);
          v132 = pAltStream->Stream.Pos;
          v152 = *(__int16 *)&pAltStream->Stream.pBuffer[v132];
          v133 = (double)v152;
          pAltStream->Stream.Pos = v132 + 2;
          LOWORD(v148) = v121;
          HIWORD(v148) = v125;
          v155 = v145 * v133;
          if ( (unsigned __int8)Scaleform::GFx::Stream::IsVerboseParse(&pAltStream->Stream) )
            Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)v121);
          key.pFirst = (const Scaleform::GFx::FontData::KerningPair *)&v148;
          key.pSecond = &v155;
          v134 = 4;
          v135 = 5381;
          do
          {
            v136 = *(&v147 + v134--);
            v135 = v136 + 65599 * v135;
          }
          while ( v134 );
          Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::FontData::KerningPair,261>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>,Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::FontData::KerningPair,float,Scaleform::FixedSizeHash<Scaleform::GFx::FontData::KerningPair>>::NodeRef>(
            &v149->KerningPairs.mHash,
            &v149->KerningPairs,
            &key,
            v135);
          if ( ++v151 >= SLODWORD(v158) )
            goto LABEL_237;
        }
        Name = v149->Name;
        if ( !Name )
          Name = "<noname>";
        Scaleform::GFx::LogBase<Scaleform::GFx::Stream>::LogError(
          &pAltStream->Stream,
          "Corrupted file %s, kerning table of the font '%s' is longer than tagLength.",
          (const char *)((pAltStream->Stream.FileName.HeapTypeBits & 0xFFFFFFFC) + 8),
          Name);
      }
    }
LABEL_237:
    if ( !v142 )
    {
      v138 = v149;
      v139 = v149->AdvanceTable.Data.Size;
      if ( v139 )
      {
        v140 = 0;
        do
        {
          v141 = &v138->AdvanceTable.Data.Data[v140++];
          --v139;
          v141->Width = 0;
          v141->Height = 0;
          v141->Top = 0;
          v141->Left = 0;
        }
        while ( v139 );
      }
    }
    goto LABEL_241;
  }
}
