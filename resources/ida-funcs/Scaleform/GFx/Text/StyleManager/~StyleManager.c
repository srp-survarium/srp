void __thiscall Scaleform::GFx::Text::StyleManager::~StyleManager(Scaleform::GFx::Text::StyleManager *this)
{
  volatile LONG *v2; // esi

  this->__vftable = (Scaleform::GFx::Text::StyleManager_vtbl *)&Scaleform::GFx::Text::StyleManager::`vftable';
  Scaleform::GFx::Text::StyleManager::ClearStyles(this);
  v2 = (volatile LONG *)(this->TempKey.Value.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::Text::StyleKey,325>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>,Scaleform::HashNode<Scaleform::GFx::Text::StyleKey,Scaleform::Render::Text::Style *,Scaleform::GFx::Text::StyleHashFunc<Scaleform::GFx::Text::StyleKey>>::NodeHashF>>::Clear(&this->Styles.mHash);
  this->__vftable = (Scaleform::GFx::Text::StyleManager_vtbl *)&Scaleform::GFx::AMP::ConnStatusInterface::`vftable';
}
