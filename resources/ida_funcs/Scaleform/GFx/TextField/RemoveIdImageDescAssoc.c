void __thiscall Scaleform::GFx::TextField::RemoveIdImageDescAssoc(Scaleform::GFx::TextField *this, char *idStr)
{
  void *v3; // esi

  if ( this->pImageDescAssoc )
  {
    Scaleform::String::String((Scaleform::String *)&idStr, idStr);
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::String>(
      &this->pImageDescAssoc->mHash,
      (const Scaleform::String *)&idStr);
    v3 = (void *)((unsigned int)idStr & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)idStr & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
}
