void __thiscall Scaleform::GFx::AMP::ViewStats::GetStats(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::StatBag *bag,
        bool reset)
{
  Scaleform::StatBag *v3; // edi
  Scaleform::GFx::AMP::ProfileFrame *v5; // eax
  Scaleform::GFx::AMP::ProfileFrame *v6; // eax
  Scaleform::GFx::AMP::ProfileFrame *v7; // esi
  Scaleform::Stat v8[4]; // [esp+10h] [ebp-8h] BYREF
  int v9; // [esp+14h] [ebp-4h]

  v3 = bag;
  if ( bag )
  {
    bag = (Scaleform::StatBag *)578;
    v5 = (Scaleform::GFx::AMP::ProfileFrame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                304,
                                                &bag);
    if ( v5 )
    {
      Scaleform::GFx::AMP::ProfileFrame::ProfileFrame(v5);
      v7 = v6;
    }
    else
    {
      v7 = 0;
    }
    Scaleform::GFx::AMP::ViewStats::CollectTimingStats(this, v7);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->AdvanceTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x157u, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->TimelineTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x15Au, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->ActionTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x158u, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->InputTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x15Bu, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->MouseTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x15Cu, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->GetVariableTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x15Eu, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->SetVariableTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x15Fu, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->InvokeTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x160u, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->DisplayTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x162u, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->TesselationTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x163u, v8);
    *(_DWORD *)v8 = 0;
    v9 = 0;
    *(_DWORD *)v8 = v7->GradientGenTime;
    v9 = 0;
    Scaleform::StatBag::Add(v3, 0x164u, v8);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
  }
  if ( reset )
  {
    EnterCriticalSection(&this->ViewLock.cs);
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::~HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>(&this->FunctionTimingMap.mHash);
    Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::Server::RenderProfile>,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS3::SocketThreadMgr>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FunctionRoots,
      &this->FunctionRoots,
      0);
    this->NextTreeItemId = 0;
    LeaveCriticalSection(&this->ViewLock.cs);
  }
}
