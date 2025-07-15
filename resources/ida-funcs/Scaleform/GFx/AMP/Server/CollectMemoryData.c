void __thiscall Scaleform::GFx::AMP::Server::CollectMemoryData(
        Scaleform::GFx::AMP::Server *this,
        Scaleform::GFx::AMP::ProfileFrame *frameProfile)
{
  Scaleform::GFx::AMP::Server *v2; // esi
  Scaleform::Lock *p_ImageLock; // edi
  unsigned int v4; // eax
  Scaleform::Render::ImageBase *pImage; // edi
  Scaleform::StringLH *v6; // eax
  Scaleform::StringLH *v7; // esi
  Scaleform::StringLH *v8; // ebx
  int v9; // eax
  int v10; // ecx
  const __m128i *v11; // eax
  Scaleform::String *v12; // eax
  void *v13; // ebp
  unsigned int *v14; // eax
  Scaleform::Render::Size<unsigned long> *(__thiscall *GetSize)(Scaleform::Render::ImageBase *, Scaleform::Render::Size<unsigned long> *); // edx
  int v16; // eax
  Scaleform::Render::ImageBase_vtbl *v17; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // edx
  unsigned int Size; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_ImageList; // ebp
  unsigned int v23; // edi
  Scaleform::RefCountVImpl **v24; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // ecx
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v26; // edi
  void *v27; // edi
  void *v28; // edi
  void *v29; // edi
  _DWORD *v30; // ebp
  _RTL_CRITICAL_SECTION *p_cs; // esi
  bool v32; // bl
  Scaleform::GFx::AMP::ProfileFrame *v33; // edi
  Scaleform::MemItem *pObject; // esi
  unsigned int Value; // ebx
  unsigned int v36; // eax
  Scaleform::MemItem *v37; // ecx
  unsigned int v38; // eax
  Scaleform::MemItem *v39; // ecx
  unsigned int v40; // eax
  Scaleform::MemItem *v41; // ecx
  unsigned int v42; // eax
  unsigned int MaxId; // esi
  Scaleform::MemItem *v44; // eax
  Scaleform::MemItem *v45; // ebx
  unsigned int v46; // esi
  Scaleform::StringLH *v47; // eax
  Scaleform::MemItem *v48; // esi
  unsigned int v49; // ebp
  Scaleform::MemItem *v50; // ebx
  unsigned int v51; // esi
  unsigned int v52; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Children; // ebx
  unsigned int v54; // esi
  unsigned int v55; // eax
  Scaleform::RefCountVImpl **v56; // ebp
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v57; // edx
  Scaleform::GFx::Resource **v58; // esi
  unsigned int v59; // ebp
  unsigned int v60; // ebp
  volatile int v61; // edx
  const char *v62; // esi
  unsigned int v63; // ebp
  unsigned int v64; // eax
  Scaleform::ArrayLH<Scaleform::Ptr<Scaleform::GFx::AMP::ImageInfo>,2,Scaleform::ArrayDefaultPolicy> *v65; // esi
  Scaleform::RefCountVImpl **v66; // ebx
  unsigned int v67; // ebp
  void *v68; // esi
  unsigned int v69; // esi
  Scaleform::MemItem *v70; // eax
  unsigned int TotalMemory; // eax
  Scaleform::MemItem *v72; // ecx
  unsigned int v73; // ebx
  void *pTable; // ecx
  unsigned int v75; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v76; // edx
  Scaleform::StringLH *v77; // eax
  Scaleform::MemItem *v78; // esi
  unsigned int v79; // edi
  int v80; // eax
  Scaleform::MemItem *v81; // edi
  unsigned int v82; // ebp
  unsigned int v83; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v84; // edi
  unsigned int v85; // ebp
  Scaleform::GFx::Resource *v86; // eax
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v87; // eax
  Scaleform::MemItem **v88; // ebp
  unsigned int v89; // eax
  unsigned int v90; // edx
  _DWORD *v91; // ecx
  unsigned int v92; // [esp+44h] [ebp-3F0h]
  _DWORD *v93; // [esp+58h] [ebp-3DCh]
  int v94; // [esp+58h] [ebp-3DCh]
  unsigned int v95; // [esp+58h] [ebp-3DCh]
  Scaleform::GFx::ResourceLibBase *i; // [esp+58h] [ebp-3DCh]
  Scaleform::RefCountVImpl **v97; // [esp+58h] [ebp-3DCh]
  Scaleform::Lock *v98; // [esp+5Ch] [ebp-3D8h]
  unsigned int v99; // [esp+5Ch] [ebp-3D8h]
  int v100; // [esp+5Ch] [ebp-3D8h]
  void *v101; // [esp+5Ch] [ebp-3D8h]
  signed int v102; // [esp+60h] [ebp-3D4h]
  Scaleform::GFx::Resource *v103; // [esp+64h] [ebp-3D0h]
  Scaleform::GFx::Resource *v104; // [esp+64h] [ebp-3D0h]
  Scaleform::GFx::Resource *v105; // [esp+64h] [ebp-3D0h]
  Scaleform::String v106; // [esp+68h] [ebp-3CCh] BYREF
  Scaleform::String v107; // [esp+6Ch] [ebp-3C8h] BYREF
  Scaleform::StringHash<Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::AllocatorGH<Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,2> > fontMap; // [esp+70h] [ebp-3C4h] BYREF
  Scaleform::GFx::AMP::Server *v109; // [esp+74h] [ebp-3C0h]
  Scaleform::String v110; // [esp+78h] [ebp-3BCh] BYREF
  Scaleform::String v111; // [esp+7Ch] [ebp-3B8h] BYREF
  int v112; // [esp+80h] [ebp-3B4h] BYREF
  unsigned int v113; // [esp+84h] [ebp-3B0h] BYREF
  Scaleform::String v114; // [esp+88h] [ebp-3ACh] BYREF
  int v115; // [esp+8Ch] [ebp-3A8h] BYREF
  unsigned int v116; // [esp+90h] [ebp-3A4h] BYREF
  int v117; // [esp+94h] [ebp-3A0h] BYREF
  int v118; // [esp+98h] [ebp-39Ch] BYREF
  int v119; // [esp+9Ch] [ebp-398h] BYREF
  const char *v120; // [esp+A0h] [ebp-394h] BYREF
  Scaleform::MsgFormat::Sink r; // [esp+A4h] [ebp-390h] BYREF
  Scaleform::MsgFormat::Sink v122; // [esp+B0h] [ebp-384h] BYREF
  Scaleform::Render::Size<unsigned long> v123; // [esp+BCh] [ebp-378h] BYREF
  Scaleform::Render::Size<unsigned long> v124; // [esp+C4h] [ebp-370h] BYREF
  _DWORD v125[10]; // [esp+CCh] [ebp-368h] BYREF
  Scaleform::Render::Rect<unsigned long> v126; // [esp+F4h] [ebp-340h] BYREF
  Scaleform::Render::Rect<unsigned long> v127; // [esp+104h] [ebp-330h] BYREF
  Scaleform::Render::Rect<unsigned long> v128; // [esp+114h] [ebp-320h] BYREF
  Scaleform::Render::Rect<unsigned long> v129; // [esp+124h] [ebp-310h] BYREF
  Scaleform::MsgFormat v130; // [esp+134h] [ebp-300h] BYREF

  v2 = this;
  p_ImageLock = &this->ImageLock;
  v109 = this;
  fontMap.mHash.pTable = 0;
  v98 = &this->ImageLock;
  EnterCriticalSection(&this->ImageLock.cs);
  Scaleform::GFx::AMP::Server::CollectFontData(v2, &fontMap);
  v4 = 0;
  v103 = 0;
  if ( v2->Images.Data.Size )
  {
    do
    {
      pImage = v2->Images.Data.Data[v4]->pImage;
      v93 = &v2->Images.Data.Data[v4]->__vftable;
      if ( pImage )
      {
        v117 = 578;
        v6 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      v2,
                                      44,
                                      &v117);
        v7 = v6;
        if ( v6 )
        {
          v6->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
          v6[1].HeapTypeBits = 1;
          v6->HeapTypeBits = (unsigned int)&Scaleform::GFx::AMP::ImageInfo::`vftable';
          v6[2].HeapTypeBits = 0;
          Scaleform::StringLH::StringLH(v6 + 3);
          v7[4].HeapTypeBits = 0;
          LOBYTE(v7[5].pData) = 0;
          v7[6].HeapTypeBits = 0;
          v7[7].HeapTypeBits = 0;
          v7[8].HeapTypeBits = 0;
          v7[9].HeapTypeBits = 0;
          v7[10].HeapTypeBits = 0;
          v8 = v7;
        }
        else
        {
          v8 = 0;
        }
        v8[2].HeapTypeBits = pImage->GetImageId(pImage);
        v9 = pImage->GetBytes(pImage, &v119);
        v8[4].HeapTypeBits = v9;
        if ( v119 )
        {
          if ( v119 == 1 )
            frameProfile->ImageGraphicsMemory += v9;
          else
            LOBYTE(v8[5].pData) = 1;
        }
        else
        {
          frameProfile->ImageMemory += v9;
        }
        Scaleform::String::String(&v107);
        v10 = v93[10];
        if ( v10 )
          v11 = (const __m128i *)(*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 24))(v10, v93[11]);
        else
          v11 = 0;
        Scaleform::String::String(&v111, v11);
        if ( (*(_DWORD *)(v111.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 )
        {
          v12 = Scaleform::String::operator+(&v111, &v114, (const __m128i *)" ");
          Scaleform::String::operator+=(&v107, v12);
          v13 = (void *)(v114.HeapTypeBits & 0xFFFFFFFC);
          if ( InterlockedExchangeAdd((volatile LONG *)((v114.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v13);
        }
        if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v93 + 8))(v93) == 2 )
        {
          Scaleform::String::AppendString(&v107, (const __m128i *)"Gradient", 0xFFFFFFFF);
        }
        else if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v93 + 8))(v93) == 1 )
        {
          Scaleform::String::AppendString(&v107, (const __m128i *)"Bitmap", 0xFFFFFFFF);
        }
        v14 = (unsigned int *)pImage->GetSize(pImage, &v124);
        GetSize = pImage->GetSize;
        v113 = *v14;
        v16 = (int)GetSize(pImage, &v123);
        v17 = pImage->__vftable;
        v112 = *(_DWORD *)(v16 + 4);
        if ( v17->GetImageType(pImage) == Type_SubImage )
        {
          v8[7].pData = (Scaleform::String::DataDesc *)pImage->GetRect(pImage, &v129)->y1;
          v8[8].pData = (Scaleform::String::DataDesc *)pImage->GetRect(pImage, &v128)->y2;
          v8[9].pData = (Scaleform::String::DataDesc *)pImage->GetRect(pImage, &v126)->x1;
          v8[10].pData = (Scaleform::String::DataDesc *)pImage->GetRect(pImage, &v127)->x2;
          v18 = pImage->GetBaseImageId(pImage);
          v19 = v8[10].HeapTypeBits - v8[9].HeapTypeBits;
          v20 = v8[8].HeapTypeBits - v8[7].HeapTypeBits;
          v8[6].HeapTypeBits = v18;
          v113 = v19;
          v112 = v20;
        }
        Scaleform::String::String(&v106);
        switch ( pImage->GetFormat(pImage) )
        {
          case Image_R8G8B8A8:
            Scaleform::String::operator=(&v106, (const __m128i *)"R8G8B8A8");
            break;
          case Image_B8G8R8A8:
            Scaleform::String::operator=(&v106, (const __m128i *)"B8G8R8A8");
            break;
          case Image_R8G8B8:
            Scaleform::String::operator=(&v106, (const __m128i *)"R8G8B8");
            break;
          case Image_B8G8R8:
            Scaleform::String::operator=(&v106, (const __m128i *)"B8G8R8");
            break;
          case Image_A8:
            Scaleform::String::operator=(&v106, (const __m128i *)"A8");
            break;
          case Image_DXT1:
            Scaleform::String::operator=(&v106, (const __m128i *)"DXT1");
            break;
          case Image_DXT3:
            Scaleform::String::operator=(&v106, (const __m128i *)"DXT3");
            break;
          case Image_DXT5:
            Scaleform::String::operator=(&v106, (const __m128i *)"DXT5");
            break;
          default:
            break;
        }
        v120 = (const char *)((v107.HeapTypeBits & 0xFFFFFFFC) + 8);
        v122.SinkData.pStr = v8 + 3;
        v122.Type = tStr;
        Scaleform::Format<char const *,unsigned long,unsigned long,Scaleform::String>(
          &v122,
          "{1}x{2} {0} ({3})",
          &v120,
          &v113,
          (unsigned int *)&v112,
          (Scaleform::StringLH *)&v106);
        Size = frameProfile->ImageList.Data.Size;
        p_ImageList = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&frameProfile->ImageList;
        v23 = Size + 1;
        if ( Size + 1 >= Size )
        {
          if ( v23 >= frameProfile->ImageList.Data.Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ImageList,
              p_ImageList,
              v23 + (v23 >> 2));
        }
        else
        {
          v24 = (Scaleform::RefCountVImpl **)&p_ImageList->Data[Size - 1];
          v94 = -1;
          do
          {
            if ( *v24 )
              Scaleform::RefCountImpl::Release(*v24);
            --v24;
            --v94;
          }
          while ( v94 );
          if ( v23 < frameProfile->ImageList.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              p_ImageList,
              p_ImageList,
              v23);
        }
        Data = p_ImageList->Data;
        frameProfile->ImageList.Data.Size = v23;
        v26 = &Data[v23 - 1];
        if ( v26 )
        {
          Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v8);
          v26->pObject = (Scaleform::GFx::AS3::ClassTraits::Traits *)v8;
        }
        v27 = (void *)(v106.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v106.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v27);
        v28 = (void *)(v111.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v111.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v28);
        v29 = (void *)(v107.HeapTypeBits & 0xFFFFFFFC);
        if ( InterlockedExchangeAdd((volatile LONG *)((v107.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v29);
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v8);
        v2 = v109;
        v4 = (unsigned int)v103;
      }
      v103 = (Scaleform::GFx::Resource *)++v4;
    }
    while ( v4 < v2->Images.Data.Size );
    p_ImageLock = v98;
  }
  LeaveCriticalSection(&p_ImageLock->cs);
  v30 = &v109->Scaleform::RefCountBase<Scaleform::GFx::AMP::Server,579>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,579>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable;
  p_cs = &v109->CurrentStateLock.cs;
  EnterCriticalSection(&v109->CurrentStateLock.cs);
  v32 = (v30[6] & 0x20) != 0;
  LeaveCriticalSection(p_cs);
  if ( v32 )
  {
    v33 = frameProfile;
    Scaleform::MemoryHeap::MemReport(
      Scaleform::Memory::pGlobalHeap,
      frameProfile->MemoryByStatId.pObject,
      MemReportHeapDetailed);
    pObject = frameProfile->MemoryByStatId.pObject;
    Value = Scaleform::MemItem::GetValue(pObject, "Total Footprint");
    v36 = Scaleform::MemItem::GetValue(pObject, "Debug Data");
    v37 = frameProfile->MemoryByStatId.pObject;
    frameProfile->TotalMemory = Value - v36;
    v38 = Scaleform::MemItem::SumValues(v37, "Video Heaps");
    v39 = frameProfile->MemoryByStatId.pObject;
    frameProfile->VideoMemory = v38;
    v40 = Scaleform::MemItem::GetValue(v39, "Movie Data Heaps");
    v41 = frameProfile->MemoryByStatId.pObject;
    frameProfile->MovieDataMemory = v40;
    frameProfile->MovieViewMemory = Scaleform::MemItem::GetValue(v41, "Movie View Heaps");
    v42 = v30[127];
    frameProfile->SoundMemory = v42;
    if ( v42 )
    {
      MaxId = Scaleform::MemItem::GetMaxId(frameProfile->MemoryByStatId.pObject);
      v44 = Scaleform::MemItem::SearchForName(frameProfile->MemoryByStatId.pObject, "Global Heap");
      v45 = v44;
      if ( v44 )
      {
        v46 = MaxId + 1;
        Scaleform::MemItem::AddChild(v44, v46++, "Font Cache", frameProfile->FontCacheMemory);
        Scaleform::MemItem::AddChild(v45, v46, "Mesh Cache", frameProfile->MeshCacheMemory);
        Scaleform::MemItem::AddChild(v45, v46 + 1, "Sound", frameProfile->SoundMemory);
      }
    }
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->GetRootStats(
      Scaleform::Memory::pGlobalHeap,
      (Scaleform::MemoryHeap::RootStats *)v125);
    v33 = frameProfile;
    v115 = 2;
    frameProfile->TotalMemory = v125[0] - v125[6] - v125[8];
    v47 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   v30,
                                   40,
                                   &v115);
    v48 = (Scaleform::MemItem *)v47;
    if ( v47 )
    {
      v47->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
      v47[1].HeapTypeBits = 1;
      v47->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
      Scaleform::StringLH::StringLH(v47 + 2);
      v48->Value = 0;
      v48->HasValue = 0;
      v48->StartExpanded = 0;
      v48->ID = 0;
      v48->ImageExtraData.pObject = 0;
      v48->Children.Data.Data = 0;
      v48->Children.Data.Size = 0;
      v48->Children.Data.Policy.Capacity = 0;
    }
    else
    {
      v48 = 0;
    }
    v104 = (Scaleform::GFx::Resource *)v48;
    Scaleform::MemoryHeap::MemReport(Scaleform::Memory::pGlobalHeap, v48, MemReportBrief);
    v49 = Scaleform::MemItem::GetMaxId(v48) + 1;
    v48->ID = v49;
    v50 = frameProfile->MemoryByStatId.pObject;
    v51 = v50->Children.Data.Size;
    v52 = v51;
    p_Children = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v50->Children;
    v54 = v51 + 1;
    v99 = v49;
    if ( v54 >= v52 )
    {
      if ( v54 >= p_Children->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Children,
          p_Children,
          v54 + (v54 >> 2));
    }
    else
    {
      v55 = v52 - v54;
      v56 = (Scaleform::RefCountVImpl **)&p_Children->Data[v55 - 1 + v54];
      if ( v55 )
      {
        v95 = v55;
        do
        {
          if ( *v56 )
            Scaleform::RefCountImpl::Release(*v56);
          --v56;
          --v95;
        }
        while ( v95 );
      }
      if ( v54 < p_Children->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          p_Children,
          p_Children,
          v54);
      v49 = v99;
    }
    v57 = p_Children->Data;
    p_Children->Size = v54;
    v58 = (Scaleform::GFx::Resource **)&v57[v54 - 1];
    if ( v58 )
    {
      Scaleform::RefCountImpl::AddRef(v104);
      *v58 = v104;
    }
    v59 = v49 + 1;
    Scaleform::MemItem::AddChild((Scaleform::MemItem *)v104, v59, "Font Cache", frameProfile->FontCacheMemory);
    v60 = v59 + 1;
    Scaleform::MemItem::AddChild((Scaleform::MemItem *)v104, v60, "Mesh Cache", frameProfile->MeshCacheMemory);
    for ( i = 0; i < v104[2].pLib; i = (Scaleform::GFx::ResourceLibBase *)((char *)i + 1) )
    {
      v61 = v104[2].RefCount.Value;
      v62 = (const char *)((*(_DWORD *)(*(_DWORD *)(v61 + 4 * (_DWORD)i) + 8) & 0xFFFFFFFC) + 8);
      v100 = *(_DWORD *)(v61 + 4 * (_DWORD)i);
      if ( !strcmp((const char *)((*(_DWORD *)(*(_DWORD *)(v61 + 4 * (_DWORD)i) + 8) & 0xFFFFFFFC) + 8), "Video") )
      {
        frameProfile->VideoMemory = *(_DWORD *)(v100 + 12);
      }
      else if ( !strcmp(v62, "Sound") )
      {
        frameProfile->SoundMemory = *(_DWORD *)(v100 + 12);
      }
      else if ( !strcmp(v62, "Movie Data") )
      {
        frameProfile->MovieDataMemory = *(_DWORD *)(v100 + 12);
      }
      else if ( !strcmp(v62, "Movie View") )
      {
        frameProfile->MovieViewMemory = *(_DWORD *)(v100 + 12);
      }
    }
    v92 = v109->SoundMemory.Value;
    v63 = v60 + 1;
    frameProfile->SoundMemory = v92;
    Scaleform::MemItem::AddChild((Scaleform::MemItem *)v104, v63, "Sound", v92);
    if ( frameProfile->ImageList.Data.Size > 0xA )
    {
      Scaleform::String::operator=(&frameProfile->Images.pObject->Name, (const __m128i *)"Total Image Memory");
      Scaleform::MemItem::SetValue(frameProfile->Images.pObject, 0);
      Scaleform::String::String(&v110);
      v116 = frameProfile->ImageList.Data.Size;
      r.Type = tStr;
      r.SinkData.pStr = &v110;
      Scaleform::MsgFormat::MsgFormat(&v130, &r);
      Scaleform::MsgFormat::Parse(&v130, "{0} Images");
      Scaleform::MsgFormat::FormatD1<unsigned int>(&v130, &v116);
      Scaleform::MsgFormat::FinishFormatD(&v130);
      Scaleform::MsgFormat::~MsgFormat(&v130);
      Scaleform::MemItem::AddChild(
        frameProfile->Images.pObject,
        v63 + 1,
        (char *)((v110.HeapTypeBits & 0xFFFFFFFC) + 8));
      v64 = frameProfile->ImageList.Data.Size;
      v65 = &frameProfile->ImageList;
      if ( v64 )
      {
        v66 = (Scaleform::RefCountVImpl **)&v65->Data.Data[v64 - 1];
        v67 = frameProfile->ImageList.Data.Size;
        do
        {
          if ( *v66 )
            Scaleform::RefCountImpl::Release(*v66);
          --v66;
          --v67;
        }
        while ( v67 );
        if ( (frameProfile->ImageList.Data.Policy.Capacity & 0xFFFFFFFE) != 0 )
        {
          if ( v65->Data.Data )
          {
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v65->Data.Data);
            v65->Data.Data = 0;
          }
          frameProfile->ImageList.Data.Policy.Capacity = 0;
        }
      }
      else if ( !frameProfile->ImageList.Data.Policy.Capacity )
      {
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&frameProfile->ImageList,
          &frameProfile->ImageList,
          0);
      }
      frameProfile->ImageList.Data.Size = 0;
      v68 = (void *)(v110.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v110.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v68);
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v104);
  }
  v69 = v33->FontCacheMemory
      + v33->SoundMemory
      + v33->ImageMemory
      + v33->MovieDataMemory
      + v33->MovieViewMemory
      + v33->MeshCacheMemory
      + v33->VideoMemory;
  v70 = Scaleform::MemItem::SearchForName(v33->MemoryByStatId.pObject, "Unused Memory");
  if ( v70 )
    v69 += v70->Value;
  TotalMemory = v33->TotalMemory;
  if ( v69 >= TotalMemory )
    TotalMemory = v69;
  v72 = v33->MemoryByStatId.pObject;
  v33->OtherMemory = TotalMemory - v69;
  v73 = Scaleform::MemItem::GetMaxId(v72) + 1;
  Scaleform::MemItem::AddChild(v33->Fonts.pObject, v73, "Font Cache", v33->FontCacheMemory);
  pTable = fontMap.mHash.pTable;
  if ( fontMap.mHash.pTable )
  {
    v75 = 0;
    v76 = fontMap.mHash.pTable + 1;
    do
    {
      if ( v76->EntryCount != -2 )
        break;
      ++v75;
      v76 += 3;
    }
    while ( v75 <= fontMap.mHash.pTable->SizeMask );
    pTable = &fontMap;
  }
  else
  {
    v75 = 0;
  }
  v101 = pTable;
  v102 = v75;
  while ( v101 && *(_DWORD *)v101 && v102 <= *(_DWORD *)(*(_DWORD *)v101 + 4) )
  {
    v118 = 2;
    v77 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                   Scaleform::Memory::pGlobalHeap,
                                   v109,
                                   40,
                                   &v118);
    v78 = (Scaleform::MemItem *)v77;
    if ( v77 )
    {
      v77->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
      ++v73;
      v77[1].HeapTypeBits = 1;
      v77->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
      Scaleform::StringLH::StringLH(v77 + 2);
      v78->Value = 0;
      v78->HasValue = 0;
      v78->StartExpanded = 0;
      v78->ID = v73;
      v78->ImageExtraData.pObject = 0;
      v78->Children.Data.Data = 0;
      v78->Children.Data.Size = 0;
      v78->Children.Data.Policy.Capacity = 0;
    }
    else
    {
      v78 = 0;
    }
    Scaleform::String::operator=(&v78->Name, (const Scaleform::String *)(*(_DWORD *)v101 + 24 * v102 + 16));
    v78->StartExpanded = 1;
    v79 = 0;
    v80 = *(_DWORD *)v101 + 24 * v102;
    if ( *(_DWORD *)(v80 + 24) )
    {
      do
      {
        Scaleform::MemItem::AddChild(
          v78,
          ++v73,
          (char *)((*(_DWORD *)(*(_DWORD *)(v80 + 20) + 4 * v79++) & 0xFFFFFFFC) + 8));
        v80 = 24 * v102 + *(_DWORD *)v101;
      }
      while ( v79 < *(_DWORD *)(v80 + 24) );
    }
    v81 = frameProfile->Fonts.pObject;
    v82 = v81->Children.Data.Size;
    v83 = v82;
    v84 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v81->Children;
    v85 = v82 + 1;
    if ( v85 >= v83 )
    {
      if ( v85 >= v84->Policy.Capacity )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v84,
          v84,
          v85 + (v85 >> 2));
    }
    else
    {
      v86 = (Scaleform::GFx::Resource *)(v83 - v85);
      v97 = (Scaleform::RefCountVImpl **)&v84->Data[(_DWORD)v86 + v85 - 1];
      if ( v86 )
      {
        v105 = v86;
        do
        {
          if ( *v97 )
            Scaleform::RefCountImpl::Release(*v97);
          --v97;
          v105 = (Scaleform::GFx::Resource *)((char *)v105 - 1);
        }
        while ( v105 );
      }
      if ( v85 < v84->Policy.Capacity >> 1 )
        Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          v84,
          v84,
          v85);
    }
    v87 = v84->Data;
    v84->Size = v85;
    v88 = (Scaleform::MemItem **)&v87[v85 - 1];
    if ( v88 )
    {
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v78);
      *v88 = v78;
    }
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v78);
    v89 = *(_DWORD *)(*(_DWORD *)v101 + 4);
    if ( v102 <= (int)v89 )
    {
      v90 = v102 + 1;
      v102 = v90;
      if ( v90 <= v89 )
      {
        v91 = (_DWORD *)(*(_DWORD *)v101 + 24 * v90 + 8);
        do
        {
          if ( *v91 != -2 )
            break;
          v91 += 6;
          ++v102;
        }
        while ( v102 <= v89 );
      }
    }
  }
  frameProfile->Fonts.pObject->StartExpanded = 1;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>(&fontMap.mHash);
}
