void __thiscall Scaleform::GFx::AMP::ViewStats::CollectTimingStats(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::GFx::AMP::ProfileFrame *pFrameInfo)
{
  Scaleform::AmpServer *Instance; // eax
  unsigned int v4; // ebx
  Scaleform::GFx::AMP::FuncTreeItem *pObject; // esi
  unsigned int i; // edi
  Scaleform::GFx::AMP::ProfileFrame *FrameInfo; // ebx
  Scaleform::GFx::AMP::ViewStats *CallingView; // esi
  void (__thiscall *v9)(struct Scaleform::GFx::AMP::ProfileFrame *); // eax
  Scaleform::GFx::AMP::ProfileFrame_vtbl *v10; // ecx
  Scaleform::Lock *p_ViewLock; // [esp+10h] [ebp-Ch]
  Scaleform::GFx::AMP::FuncStatsVisitor frameProfile; // [esp+14h] [ebp-8h] BYREF

  p_ViewLock = &this->ViewLock;
  EnterCriticalSection(&this->ViewLock.cs);
  Instance = Scaleform::AmpServer::GetInstance();
  if ( Instance->IsFunctionAggregation(Instance) )
  {
    Scaleform::Hash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>>::Begin(
      (Scaleform::Hash<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> > > *)&this->FunctionTimingMap,
      (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>,Scaleform::HashNode<Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Value::HashFunctor>::NodeHashF> >::Iterator *)&frameProfile);
    FrameInfo = frameProfile.FrameInfo;
    CallingView = frameProfile.CallingView;
    while ( FrameInfo
         && FrameInfo->__vftable
         && (int)CallingView <= (int)FrameInfo->__vftable[1].~Scaleform::GFx::AMP::ProfileFrame )
    {
      Scaleform::GFx::AMP::ViewStats::UpdateStats(
        this,
        *(_QWORD *)&FrameInfo->__vftable[10 * (_DWORD)CallingView + 6].~Scaleform::GFx::AMP::ProfileFrame,
        (unsigned int)FrameInfo->__vftable[10 * (_DWORD)CallingView + 10].~Scaleform::GFx::AMP::ProfileFrame,
        (unsigned int)FrameInfo->__vftable[10 * (_DWORD)CallingView + 8].~Scaleform::GFx::AMP::ProfileFrame,
        pFrameInfo);
      v9 = FrameInfo->__vftable[1].~Scaleform::GFx::AMP::ProfileFrame;
      if ( (int)CallingView <= (int)v9 )
      {
        CallingView = (Scaleform::GFx::AMP::ViewStats *)((char *)CallingView + 1);
        if ( CallingView <= (Scaleform::GFx::AMP::ViewStats *)v9 )
        {
          v10 = &FrameInfo->__vftable[10 * (_DWORD)CallingView + 2];
          do
          {
            if ( v10->~Scaleform::GFx::AMP::ProfileFrame != (void (__thiscall *)(struct Scaleform::GFx::AMP::ProfileFrame *))-2 )
              break;
            CallingView = (Scaleform::GFx::AMP::ViewStats *)((char *)CallingView + 1);
            v10 += 10;
          }
          while ( CallingView <= (Scaleform::GFx::AMP::ViewStats *)v9 );
        }
      }
    }
  }
  else
  {
    v4 = 0;
    frameProfile.FrameInfo = pFrameInfo;
    for ( frameProfile.CallingView = this; v4 < this->FunctionRoots.Data.Size; ++v4 )
    {
      pObject = this->FunctionRoots.Data.Data[v4].pObject;
      Scaleform::GFx::AMP::ViewStats::UpdateStats(
        frameProfile.CallingView,
        pObject->FunctionId,
        LODWORD(pObject->EndTime) - LODWORD(pObject->BeginTime),
        1u,
        frameProfile.FrameInfo);
      for ( i = 0; i < pObject->Children.Data.Size; ++i )
        Scaleform::GFx::AMP::FuncTreeItem::Visit<Scaleform::GFx::AMP::FuncStatsVisitor>(
          pObject->Children.Data.Data[i].pObject,
          &frameProfile);
    }
  }
  LeaveCriticalSection(&p_ViewLock->cs);
}
