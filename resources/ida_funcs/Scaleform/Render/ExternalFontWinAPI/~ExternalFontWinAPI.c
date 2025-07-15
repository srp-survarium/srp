void __thiscall Scaleform::Render::ExternalFontWinAPI::~ExternalFontWinAPI(Scaleform::Render::ExternalFontWinAPI *this)
{
  HFONT__ *HintedFont; // eax
  volatile LONG *v3; // edi
  Scaleform::RefCountVImpl *pObject; // ecx

  HintedFont = this->HintedFont;
  this->__vftable = (Scaleform::Render::ExternalFontWinAPI_vtbl *)&Scaleform::Render::ExternalFontWinAPI::`vftable';
  if ( HintedFont )
    DeleteObject(HintedFont);
  if ( this->MasterFont )
    DeleteObject(this->MasterFont);
  v3 = (volatile LONG *)(this->Hinting.Typeface.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::Clear(&this->KerningPairs.mHash);
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::Clear(&this->CodeTable.mHash);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Glyphs.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->NameW.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Name.Data.Data);
  pObject = (Scaleform::RefCountVImpl *)this->pFontProvider.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::Render::ExternalFontWinAPI_vtbl *)&Scaleform::Render::Font::`vftable';
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
