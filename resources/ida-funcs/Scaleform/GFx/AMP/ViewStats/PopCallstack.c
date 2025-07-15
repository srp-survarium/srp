void __thiscall Scaleform::GFx::AMP::ViewStats::PopCallstack(
        Scaleform::GFx::AMP::ViewStats *this,
        Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> swdHandle,
        unsigned int swfOffset,
        unsigned __int64 funcTime)
{
  Scaleform::GFx::AMP::FuncTreeItem *pObject; // ebx
  Scaleform::ArrayLH<Scaleform::GFx::AMP::ViewStats::CallInfo,581,Scaleform::ArrayConstPolicy<0,4,1> > *p_Callstack; // esi
  unsigned __int64 v7; // kr00_8
  Scaleform::GFx::Resource *v8; // ecx
  Scaleform::GFx::AMP::FuncTreeItem *v9; // eax
  Scaleform::GFx::AMP::FuncTreeItem *v10; // eax
  int BeginTime; // ecx
  int BeginTime_high; // edx
  int v13; // edx
  Scaleform::AmpServer *Instance; // eax
  unsigned int v15; // ecx
  Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *Data; // eax
  Scaleform::GFx::AMP::FuncTreeItem *v17; // eax
  Scaleform::GFx::AMP::FuncTreeItem *v18; // eax
  Scaleform::GFx::AMP::FuncTreeItem *v19; // esi
  Scaleform::GFx::AMP::FuncTreeItem *v20; // eax
  bool v21; // cf
  unsigned __int64 v22; // kr08_8
  unsigned int v23; // eax
  int *TimesCalled; // edx
  unsigned int v25; // eax
  int v26; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF> >::Iterator *v27; // eax
  const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF> > *pHash; // ecx
  int Index; // eax
  int v30; // edx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF> >::TableType *pTable; // eax
  int v32; // edx
  unsigned int v33; // ecx
  int v34; // esi
  int CallstackDepthPause; // eax
  Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> val; // [esp+8h] [ebp-48h] BYREF
  LPCRITICAL_SECTION lpCriticalSection; // [esp+Ch] [ebp-44h]
  Scaleform::GFx::AMP::ViewStats::AmpFunctionStats result; // [esp+10h] [ebp-40h] BYREF
  Scaleform::GFx::AMP::ViewStats::AmpFunctionStats it; // [esp+20h] [ebp-30h] BYREF
  Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair key; // [esp+30h] [ebp-20h] BYREF
  Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair v41; // [esp+40h] [ebp-10h] BYREF

  pObject = swdHandle.pObject;
  if ( swdHandle.pObject )
  {
    lpCriticalSection = &this->ViewLock.cs;
    EnterCriticalSection(&this->ViewLock.cs);
    if ( this->Callstack.Data.Size )
    {
      p_Callstack = &this->Callstack;
      v7 = ((unsigned __int64)(unsigned int)pObject << 32) + swfOffset;
      if ( v7 == this->Callstack.Data.Data[this->Callstack.Data.Size - 1].FunctionInfo.pObject->FunctionId )
      {
        v8 = (Scaleform::GFx::Resource *)this->Callstack.Data.Data[this->Callstack.Data.Size - 1].FunctionInfo.pObject;
        v9 = (Scaleform::GFx::AMP::FuncTreeItem *)&this->Callstack.Data.Data[this->Callstack.Data.Size - 1];
        val.pObject = v9;
        if ( v8 )
        {
          Scaleform::RefCountImpl::AddRef(v8);
          v9 = val.pObject;
        }
        v10 = (Scaleform::GFx::AMP::FuncTreeItem *)v9->__vftable;
        BeginTime = v10->BeginTime;
        BeginTime_high = HIDWORD(v10->BeginTime);
        val.pObject = v10;
        v13 = HIDWORD(funcTime) + __CFADD__((_DWORD)funcTime, BeginTime) + BeginTime_high;
        LODWORD(v10->EndTime) = funcTime + BeginTime;
        HIDWORD(v10->EndTime) = v13;
        Scaleform::ArrayData<Scaleform::GFx::AMP::ViewStats::CallInfo,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::CallInfo,581>,Scaleform::ArrayConstPolicy<0,4,1>>::Resize(
          &this->Callstack.Data,
          this->Callstack.Data.Size - 1);
        Scaleform::GFx::AMP::ViewStats::RefreshActiveLine(this);
        key.FunctionId = v7;
        if ( this->Callstack.Data.Size )
          key.CallerId = this->Callstack.Data.Data[this->Callstack.Data.Size - 1].FunctionInfo.pObject->FunctionId;
        else
          key.CallerId = 0;
        Instance = Scaleform::AmpServer::GetInstance();
        if ( Instance->IsFunctionAggregation(Instance) )
        {
          Scaleform::Hash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>>::Find(
            &this->FunctionTimingMap,
            (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF> >::Iterator *)&result,
            &key);
          it.TimesCalled = 0;
          *(&it.TimesCalled + 1) = 0;
          if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::ConstIterator::operator==(
                 (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&result,
                 (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&it) )
          {
            if ( !key.CallerId && swdHandle.pObject == (Scaleform::GFx::AMP::FuncTreeItem *)1 && swfOffset - 21 <= 0x2C )
            {
              v41.FunctionId = 0x100000014LL;
              key.CallerId = 0x100000014LL;
              v41.CallerId = 0;
              it.TimesCalled = 0;
              *(&it.TimesCalled + 1) = 0;
              if ( Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>::ConstIterator::operator==(
                     (Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&result,
                     (const Scaleform::HashSetBase<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeAltHashF,Scaleform::AllocatorGH<unsigned long,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >,Scaleform::HashNode<unsigned long,Scaleform::String,Scaleform::FixedSizeHash<unsigned long> >::NodeHashF> >::ConstIterator *)&it) )
              {
                it.TotalTime = funcTime;
                it.TimesCalled = 1;
                Scaleform::Hash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>>::Set(
                  &this->FunctionTimingMap,
                  &v41,
                  &it);
              }
              else
              {
                TimesCalled = (int *)result.TimesCalled;
                v25 = 40 * *(&result.TimesCalled + 1);
                ++*(_DWORD *)(v25 + *(_DWORD *)result.TimesCalled + 32);
                v26 = *TimesCalled;
                v21 = __CFADD__((_DWORD)funcTime, *(_DWORD *)(v25 + v26 + 40));
                *(_DWORD *)(v25 + v26 + 40) += funcTime;
                *(_DWORD *)(v25 + v26 + 44) += HIDWORD(funcTime) + v21;
              }
            }
            result.TimesCalled = 0;
            result.TotalTime = 0;
            Scaleform::Hash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>>::Set(
              &this->FunctionTimingMap,
              &key,
              &result);
            v27 = Scaleform::Hash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair>>::NodeHashF>>>::Find(
                    &this->FunctionTimingMap,
                    (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF> >::Iterator *)&it,
                    &key);
            pHash = v27->pHash;
            Index = v27->Index;
          }
          else
          {
            Index = *(&result.TimesCalled + 1);
            pHash = (const Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >,Scaleform::HashNode<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair,Scaleform::GFx::AMP::ViewStats::AmpFunctionStats,Scaleform::FixedSizeHash<Scaleform::GFx::AMP::ViewStats::ParentChildFunctionPair> >::NodeHashF> > *)result.TimesCalled;
          }
          v30 = 5 * Index;
          pTable = pHash->pTable;
          ++pTable[v30 + 4].EntryCount;
          v32 = (int)&pTable[v30 + 4];
          v33 = 1;
          if ( this->Callstack.Data.Size <= 1 )
          {
LABEL_40:
            v21 = __CFADD__((_DWORD)funcTime, *(_DWORD *)(v32 + 8));
            *(_DWORD *)(v32 + 8) += funcTime;
            *(_DWORD *)(v32 + 12) += HIDWORD(funcTime) + v21;
          }
          else
          {
            v34 = (int)&p_Callstack->Data.Data[1];
            while ( *(_QWORD *)(*(_DWORD *)(v34 - 24) + 8) != key.CallerId
                 || *(_QWORD *)(*(_DWORD *)v34 + 8) != key.FunctionId )
            {
              ++v33;
              v34 += 24;
              if ( v33 >= this->Callstack.Data.Size )
                goto LABEL_40;
            }
          }
        }
        else if ( this->Callstack.Data.Size )
        {
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            &p_Callstack->Data.Data[this->Callstack.Data.Size - 1].FunctionInfo.pObject->Children,
            &val);
        }
        else if ( swdHandle.pObject == (Scaleform::GFx::AMP::FuncTreeItem *)1 && swfOffset - 21 <= 0x2C )
        {
          v15 = 0;
          if ( this->FunctionRoots.Data.Size )
          {
            Data = this->FunctionRoots.Data.Data;
            while ( LODWORD(Data->pObject->FunctionId) != 20 || HIDWORD(Data->pObject->FunctionId) != 1 )
            {
              ++v15;
              ++Data;
              if ( v15 >= this->FunctionRoots.Data.Size )
                goto LABEL_20;
            }
            v20 = this->FunctionRoots.Data.Data[v15].pObject;
            v21 = __CFADD__((_DWORD)funcTime, v20->EndTime);
            LODWORD(v20->EndTime) += funcTime;
            HIDWORD(v20->EndTime) += HIDWORD(funcTime) + v21;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              &this->FunctionRoots.Data.Data[v15].pObject->Children,
              &val);
          }
          else
          {
LABEL_20:
            v17 = (Scaleform::GFx::AMP::FuncTreeItem *)Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::operator new(
                                                         0x30u,
                                                         (Scaleform::MemAddressStub *)this);
            if ( v17 )
            {
              Scaleform::GFx::AMP::FuncTreeItem::FuncTreeItem(v17);
              v19 = v18;
            }
            else
            {
              v19 = 0;
            }
            v22 = funcTime;
            LODWORD(v19->BeginTime) = 0;
            HIDWORD(v19->BeginTime) = 0;
            v19->EndTime = v22;
            LODWORD(v19->FunctionId) = 20;
            HIDWORD(v19->FunctionId) = 1;
            v23 = ++this->NextTreeItemId;
            swdHandle.pObject = v19;
            v19->TreeItemId = v23;
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              &v19->Children,
              &val);
            Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
              &this->FunctionRoots,
              &swdHandle);
            Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19);
          }
        }
        else
        {
          Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
            &this->FunctionRoots,
            &val);
        }
        CallstackDepthPause = this->CallstackDepthPause;
        if ( CallstackDepthPause >= 0 && (signed int)this->Callstack.Data.Size >= CallstackDepthPause )
        {
          Scaleform::Event::ResetEvent(&this->DebugEvent);
          this->CallstackDepthPause = -1;
        }
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)val.pObject);
      }
      LeaveCriticalSection(lpCriticalSection);
    }
    else
    {
      LeaveCriticalSection(&this->ViewLock.cs);
    }
  }
}
