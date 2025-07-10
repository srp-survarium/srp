void __thiscall Scaleform::GFx::FontHandle::~FontHandle(Scaleform::GFx::FontHandle *this)
{
  Scaleform::Render::Text::FontManagerBase *pFontManager; // eax
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::MovieDef *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  volatile LONG *v6; // edi
  Scaleform::GFx::FontHandle *key; // [esp+8h] [ebp-4h] BYREF

  pFontManager = this->pFontManager;
  this->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::GFx::FontHandle::`vftable';
  if ( pFontManager )
  {
    key = this;
    if ( this != (Scaleform::GFx::FontHandle *)pFontManager[4].RefCount )
      Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp>>::RemoveAlt<Scaleform::GFx::FontHandle *>(
        (Scaleform::HashSetBase<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::GFx::FontManager::NodePtrHashOp,Scaleform::AllocatorLH<Scaleform::GFx::FontManager::NodePtr,2>,Scaleform::HashsetCachedEntry<Scaleform::GFx::FontManager::NodePtr,Scaleform::GFx::FontManager::NodePtrHashOp> > *)&pFontManager[1],
        (const Scaleform::GFx::FontHandle **)&key);
  }
  pObject = (Scaleform::RefCountVImpl *)this->pFont.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFont.pObject = 0;
  v4 = this->pSourceMovieDef.pObject;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  this->__vftable = (Scaleform::GFx::FontHandle_vtbl *)&Scaleform::Render::Text::FontHandle::`vftable';
  v5 = (Scaleform::RefCountVImpl *)this->pFont.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (volatile LONG *)(this->FontName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v6 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v6);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
