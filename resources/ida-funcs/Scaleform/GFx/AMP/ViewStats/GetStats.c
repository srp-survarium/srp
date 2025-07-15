void __thiscall Scaleform::GFx::AMP::ViewStats::GetStats(Scaleform::GFx::AMP::ViewStats *this, int bag, bool reset)
{
  Scaleform::GFx::AMP::ProfileFrame *v4; // eax
  Scaleform::GFx::AMP::ProfileFrame *v5; // eax
  Scaleform::GFx::AMP::ProfileFrame *v6; // edi

  if ( bag )
  {
    bag = 578;
    v4 = (Scaleform::GFx::AMP::ProfileFrame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                304,
                                                &bag);
    if ( v4 )
    {
      Scaleform::GFx::AMP::ProfileFrame::ProfileFrame(v4);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    Scaleform::GFx::AMP::ViewStats::CollectTimingStats(this, v6);
    if ( v6 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v6);
  }
  if ( reset )
  {
    EnterCriticalSection(&this->ViewLock.cs);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::Clear(&this->FunctionTimingMap.mHash);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FunctionRoots,
      &this->FunctionRoots,
      0);
    this->NextTreeItemId = 0;
    LeaveCriticalSection(&this->ViewLock.cs);
  }
}
