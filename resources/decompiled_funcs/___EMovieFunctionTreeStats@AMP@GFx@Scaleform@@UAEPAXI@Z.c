Scaleform::GFx::AMP::MovieFunctionTreeStats *__thiscall Scaleform::GFx::AMP::MovieFunctionTreeStats::`vector deleting destructor'(
        Scaleform::GFx::AMP::MovieFunctionTreeStats *this,
        char a2)
{
  volatile LONG *v3; // edi

  Scaleform::HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned __int64,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>,Scaleform::HashNode<unsigned __int64,Scaleform::Ptr<Scaleform::GFx::AMP::FunctionDesc>,Scaleform::FixedSizeHash<unsigned __int64>>::NodeHashF>>(&this->FunctionInfo.mHash);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::ButtonActionBase>,258>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FunctionRoots);
  v3 = (volatile LONG *)(this->ViewName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v3 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v3);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
