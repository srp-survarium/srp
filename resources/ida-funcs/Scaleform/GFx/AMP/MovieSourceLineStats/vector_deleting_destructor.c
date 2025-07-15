Scaleform::GFx::AMP::MovieSourceLineStats *__thiscall Scaleform::GFx::AMP::MovieSourceLineStats::`vector deleting destructor'(
        Scaleform::GFx::AMP::MovieSourceLineStats *this,
        char a2)
{
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::String,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::Clear(&this->SourceFileInfo.mHash);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->SourceLineTimings.Data.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
