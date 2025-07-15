void __thiscall Scaleform::GFx::TextField::AddIdImageDescAssoc(
        Scaleform::GFx::TextField *this,
        const __m128i *idStr,
        Scaleform::RefCountNTSImpl *pdesc)
{
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v4; // eax
  Scaleform::RefCountNTSImpl *v5; // eax
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImageDescAssoc; // ecx
  void *v7; // esi
  Scaleform::RefCountNTSImpl *v8; // [esp+10h] [ebp-Ch] BYREF
  Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+14h] [ebp-8h] BYREF

  if ( !this->pImageDescAssoc )
  {
    v8 = (Scaleform::RefCountNTSImpl *)2;
    v4 = (Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 4, &v8);
    if ( v4 )
      v4->mHash.pTable = 0;
    else
      v4 = 0;
    this->pImageDescAssoc = v4;
  }
  v5 = pdesc;
  if ( pdesc )
    ++pdesc->RefCount;
  v8 = v5;
  Scaleform::String::String((Scaleform::String *)&pdesc, idStr);
  pImageDescAssoc = this->pImageDescAssoc;
  key.pFirst = (const Scaleform::String *)&pdesc;
  key.pSecond = (const Scaleform::Ptr<Scaleform::Render::Text::ImageDesc> *)&v8;
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    &pImageDescAssoc->mHash,
    pImageDescAssoc,
    &key);
  v7 = (void *)((unsigned int)pdesc & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)pdesc & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
  if ( v8 )
    Scaleform::RefCountNTSImpl::Release(v8);
}
