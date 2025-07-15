void __thiscall Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts(
        Scaleform::GFx::AS3::Classes::fl_text::Font *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::Array> *result,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::Font> enumerateDeviceFonts)
{
  Scaleform::GFx::AS3::ASVM *pVM; // edi
  Scaleform::GFx::MovieImpl *pMovieImpl; // esi
  Scaleform::GFx::MovieDef *(__thiscall *GetMovieDef)(Scaleform::GFx::Movie *); // eax
  int v6; // eax
  Scaleform::GFx::State *(__thiscall *GetStateAddRef)(Scaleform::GFx::StateBag *, Scaleform::GFx::State::StateType); // eax
  Scaleform::RefCountVImpl *v8; // eax
  Scaleform::GFx::FontLib *v9; // esi
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > *p_fonts; // ebx
  signed int v11; // esi
  unsigned int v12; // eax
  Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > >::TableType *v13; // edx
  Scaleform::GFx::Resource **v14; // edi
  Scaleform::RefCountVImpl **v15; // ebp
  unsigned int EntryCount; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // ecx
  unsigned int SizeMask; // eax
  unsigned int *v19; // ecx
  Scaleform::RefCountVImpl *v20; // eax
  Scaleform::RefCountVImpl *v21; // esi
  void (__thiscall *Release)(Scaleform::RefCountVImpl *); // edx
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *p_deviceFontNames; // ebx
  unsigned int v24; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v25; // ecx
  signed int v26; // ebp
  Scaleform::GFx::ASString *p_fontName; // esi
  Scaleform::GFx::ASStringNode *StringNode; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS3::Instances::fl_text::Font *pObject; // ecx
  unsigned int v33; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v34; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *v35; // ecx
  Scaleform::GFx::AS3::Instances::fl::Array *pV; // edi
  unsigned int v37; // eax
  Scaleform::GFx::AS3::VMAppDomain *CurrentDomain; // [esp+8h] [ebp-44h]
  Scaleform::HashSet<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > > fonts; // [esp+14h] [ebp-38h] BYREF
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > deviceFontNames; // [esp+18h] [ebp-34h] BYREF
  Scaleform::GFx::AS3::ASVM *asvm; // [esp+1Ch] [ebp-30h]
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl::Array> retVal; // [esp+20h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::Class *fontClass; // [esp+24h] [ebp-28h]
  Scaleform::GFx::StateBag *v44; // [esp+28h] [ebp-24h]
  Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts::__l2::FontsVisitor fontsVisitor; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::StringDataPtr gname; // [esp+34h] [ebp-18h] BYREF
  Scaleform::GFx::AS3::Value v; // [esp+3Ch] [ebp-10h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  pMovieImpl = pVM->pMovieRoot->pMovieImpl;
  GetMovieDef = pMovieImpl->GetMovieDef;
  asvm = pVM;
  v6 = (int)GetMovieDef(pMovieImpl);
  fontsVisitor.Fonts = &fonts;
  fonts.pTable = 0;
  fontsVisitor.__vftable = (Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts::__l2::FontsVisitor_vtbl *)&`Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts'::`2'::FontsVisitor::`vftable';
  (*(void (__thiscall **)(int, Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts::__l2::FontsVisitor *, int))(*(_DWORD *)v6 + 104))(
    v6,
    &fontsVisitor,
    1);
  Scaleform::GFx::MovieImpl::LoadRegisteredFonts(pMovieImpl, (Scaleform::Render::Font *)&fonts);
  GetStateAddRef = pMovieImpl->GetStateAddRef;
  v44 = &pMovieImpl->Scaleform::GFx::StateBag;
  v8 = (Scaleform::RefCountVImpl *)((int (__stdcall *)(int))GetStateAddRef)(17);
  v9 = (Scaleform::GFx::FontLib *)v8;
  if ( v8 )
  {
    Scaleform::RefCountImpl::Release(v8);
    Scaleform::GFx::FontLib::LoadFonts(v9, &fonts);
  }
  CurrentDomain = pVM->CurrentDomain;
  gname.pStr = "flash.text.Font";
  gname.Size = 15;
  fontClass = Scaleform::GFx::AS3::VM::GetClass(pVM, &gname, CurrentDomain);
  Scaleform::GFx::AS3::VM::MakeArray(pVM, &retVal);
  if ( fonts.pTable )
  {
    v12 = 0;
    v13 = fonts.pTable + 1;
    do
    {
      if ( v13->EntryCount != -2 )
        break;
      ++v12;
      v13 = (Scaleform::HashSetBase<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> >,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Font>,2>,Scaleform::HashsetCachedEntry<Scaleform::Ptr<Scaleform::Render::Font>,Scaleform::FixedSizeHash<Scaleform::Ptr<Scaleform::Render::Font> > > >::TableType *)((char *)v13 + 12);
    }
    while ( v12 <= fonts.pTable->SizeMask );
    p_fonts = &fonts;
    v11 = v12;
  }
  else
  {
    p_fonts = 0;
    v11 = 0;
  }
  while ( p_fonts && p_fonts->pTable && v11 <= (signed int)p_fonts->pTable->SizeMask )
  {
    deviceFontNames.mHash.pTable = 0;
    Scaleform::GFx::AS3::ASVM::_constructInstance(
      pVM,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&deviceFontNames,
      fontClass,
      0,
      0);
    v14 = (Scaleform::GFx::Resource **)&p_fonts->pTable[2] + 3 * v11;
    v15 = (Scaleform::RefCountVImpl **)&deviceFontNames.mHash.pTable[4];
    if ( *v14 )
      Scaleform::RefCountImpl::AddRef(*v14);
    if ( *v15 )
      Scaleform::RefCountImpl::Release(*v15);
    *v15 = (Scaleform::RefCountVImpl *)*v14;
    v.Flags = 0;
    v.Bonus.pWeakProxy = 0;
    Scaleform::GFx::AS3::Value::AssignUnsafe(&v, (Scaleform::GFx::AS3::Object *)deviceFontNames.mHash.pTable);
    Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&retVal.pV->SA, &v);
    if ( (v.Flags & 0x1F) > 9 )
    {
      if ( (v.Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
    }
    if ( deviceFontNames.mHash.pTable )
    {
      if ( ((int)deviceFontNames.mHash.pTable & 1) == 0 )
      {
        EntryCount = deviceFontNames.mHash.pTable[2].EntryCount;
        pTable = deviceFontNames.mHash.pTable;
        if ( (EntryCount & 0x3FFFFF) != 0 )
        {
          deviceFontNames.mHash.pTable[2].EntryCount = EntryCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)pTable);
        }
      }
    }
    SizeMask = p_fonts->pTable->SizeMask;
    if ( v11 <= (int)SizeMask && ++v11 <= SizeMask )
    {
      v19 = &p_fonts->pTable[1].EntryCount + 3 * v11;
      do
      {
        if ( *v19 != -2 )
          break;
        ++v11;
        v19 += 3;
      }
      while ( v11 <= SizeMask );
    }
    pVM = asvm;
  }
  if ( LOBYTE(enumerateDeviceFonts.pObject) )
  {
    v20 = (Scaleform::RefCountVImpl *)v44->GetStateAddRef(v44, State_FontProvider);
    v21 = v20;
    if ( v20 )
    {
      Scaleform::RefCountImpl::Release(v20);
      Release = v21->Release;
      deviceFontNames.mHash.pTable = 0;
      ((void (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *))Release)(
        v21,
        &deviceFontNames);
      if ( deviceFontNames.mHash.pTable )
      {
        v24 = 0;
        v25 = deviceFontNames.mHash.pTable + 1;
        do
        {
          if ( v25->EntryCount != -2 )
            break;
          ++v24;
          v25 += 2;
        }
        while ( v24 <= deviceFontNames.mHash.pTable->SizeMask );
        p_deviceFontNames = &deviceFontNames;
      }
      else
      {
        p_deviceFontNames = 0;
        v24 = 0;
      }
      v26 = v24;
      while ( p_deviceFontNames
           && p_deviceFontNames->mHash.pTable
           && v26 <= (signed int)p_deviceFontNames->mHash.pTable->SizeMask )
      {
        enumerateDeviceFonts.pObject = 0;
        Scaleform::GFx::AS3::ASVM::_constructInstance(
          asvm,
          (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&enumerateDeviceFonts,
          fontClass,
          0,
          0);
        p_fontName = &enumerateDeviceFonts.pObject->fontName;
        StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                       enumerateDeviceFonts.pObject->fontName.pNode->pManager,
                       (__m128i *)((p_deviceFontNames->mHash.pTable[2 * v26 + 2].EntryCount & 0xFFFFFFFC) + 8),
                       *(_DWORD *)(p_deviceFontNames->mHash.pTable[2 * v26 + 2].EntryCount & 0xFFFFFFFC) & 0x7FFFFFFF);
        ++StringNode->RefCount;
        pNode = p_fontName->pNode;
        if ( p_fontName->pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        p_fontName->pNode = StringNode;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        Scaleform::GFx::AS3::Value::AssignUnsafe(&v, enumerateDeviceFonts.pObject);
        Scaleform::GFx::AS3::Impl::SparseArray::PushBack(&retVal.pV->SA, &v);
        if ( (v.Flags & 0x1F) > 9 )
        {
          if ( (v.Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v);
          else
            Scaleform::GFx::AS3::Value::ReleaseInternal(&v);
        }
        if ( enumerateDeviceFonts.pObject )
        {
          if ( ((int)enumerateDeviceFonts.pObject & 1) == 0 )
          {
            RefCount = enumerateDeviceFonts.pObject->RefCount;
            pObject = enumerateDeviceFonts.pObject;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              enumerateDeviceFonts.pObject->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
            }
          }
        }
        v33 = p_deviceFontNames->mHash.pTable->SizeMask;
        if ( v26 <= (int)v33 && ++v26 <= v33 )
        {
          v34 = &p_deviceFontNames->mHash.pTable[2 * v26 + 1];
          do
          {
            if ( v34->EntryCount != -2 )
              break;
            ++v26;
            v34 += 2;
          }
          while ( v26 <= v33 );
        }
      }
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear(&deviceFontNames.mHash);
    }
  }
  v35 = result->pObject;
  pV = retVal.pV;
  if ( retVal.pV != result->pObject )
  {
    if ( v35 )
    {
      if ( ((unsigned __int8)v35 & 1) != 0 )
      {
        result->pObject = (Scaleform::GFx::AS3::Instances::fl::Array *)((char *)v35 - 1);
      }
      else
      {
        v37 = v35->RefCount;
        if ( (v37 & 0x3FFFFF) != 0 )
        {
          v35->RefCount = v37 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v35);
        }
      }
    }
    result->pObject = pV;
  }
  fontsVisitor.__vftable = (Scaleform::GFx::AS3::Classes::fl_text::Font::enumerateFonts::__l2::FontsVisitor_vtbl *)&Scaleform::GFx::AS3::VectorBase<unsigned long>::ArrayFunc::`vftable';
  Scaleform::HashSetBase<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::GFx::StateBagImpl::StatePtrHashOp,Scaleform::AllocatorGH<Scaleform::GFx::StateBagImpl::StatePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::StateBagImpl::StatePtr,Scaleform::GFx::StateBagImpl::StatePtrHashOp>>::Clear(&fonts);
}
