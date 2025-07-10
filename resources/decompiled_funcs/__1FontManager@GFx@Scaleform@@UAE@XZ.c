void __thiscall Scaleform::GFx::FontManager::~FontManager(Scaleform::GFx::FontManager *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  volatile LONG *v3; // edi
  Scaleform::RefCountVImpl *v4; // ecx

  this->__vftable = (Scaleform::GFx::FontManager_vtbl *)&Scaleform::GFx::FontManager::`vftable';
  pObject = (Scaleform::RefCountVImpl *)this->pIMECandidateFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (volatile LONG *)(this->FontMapEntry.Name.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  v4 = (Scaleform::RefCountVImpl *)this->pEmptyFont.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FontMovies);
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> > *)&this->CreatedFonts);
  this->__vftable = (Scaleform::GFx::FontManager_vtbl *)&Scaleform::Render::Text::FontManagerBase::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
