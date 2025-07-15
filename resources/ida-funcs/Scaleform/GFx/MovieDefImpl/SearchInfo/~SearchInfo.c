void __thiscall Scaleform::GFx::MovieDefImpl::SearchInfo::~SearchInfo(Scaleform::GFx::MovieDefImpl::SearchInfo *this)
{
  volatile LONG *v2; // esi

  v2 = (volatile LONG *)(this->ImportFoundUrl.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v2 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v2);
  Scaleform::HashSetBase<Scaleform::String,Scaleform::String::NoCaseHashFunctor,Scaleform::String::NoCaseHashFunctor,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedEntry<Scaleform::String,Scaleform::String::NoCaseHashFunctor>>::Clear(&this->ImportSearchUrls);
}
