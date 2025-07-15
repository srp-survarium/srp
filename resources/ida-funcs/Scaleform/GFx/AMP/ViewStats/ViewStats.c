void __thiscall Scaleform::GFx::AMP::ViewStats::ViewStats(Scaleform::GFx::AMP::ViewStats *this)
{
  Scaleform::StringHashLH<unsigned long,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_NativeFunctionIdMap; // ebx
  unsigned int v3; // eax
  unsigned int v4; // eax
  void *v5; // edi
  Scaleform::String v6; // [esp+10h] [ebp-10h] BYREF
  int v7; // [esp+14h] [ebp-Ch] BYREF
  Scaleform::StringLH_HashNode<unsigned long,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [esp+18h] [ebp-8h] BYREF

  this->__vftable = (Scaleform::GFx::AMP::ViewStats_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AMP::ViewStats_vtbl *)&Scaleform::GFx::AMP::ViewStats::`vftable';
  this->FunctionTimingMap.mHash.pTable = 0;
  this->FunctionInfoMap.mHash.pTable = 0;
  this->NativeFunctionIdMap.mHash.pTable = 0;
  this->NextNativeFunctionId = 67;
  this->Callstack.Data.Data = 0;
  this->Callstack.Data.Size = 0;
  this->Callstack.Data.Policy.Capacity = 0;
  p_NativeFunctionIdMap = &this->NativeFunctionIdMap;
  this->FunctionRoots.Data.Data = 0;
  this->FunctionRoots.Data.Size = 0;
  this->FunctionRoots.Data.Policy.Capacity = 0;
  this->NextTreeItemId = 0;
  this->CallstackDepthPause = -1;
  this->ActiveFileId = 0;
  this->ActiveLineNumber = 0;
  Scaleform::Lock::Lock(&this->ActiveLock, 0);
  this->InstructionTimingsMap.mHash.pTable = 0;
  Scaleform::Mutex::Mutex(&this->InstructionTimingMutex, 1, 0);
  this->SourceLineTimingsMap.mHash.pTable = 0;
  this->SourceLineInfoMap.mHash.pTable = 0;
  Scaleform::Lock::Lock(&this->ViewLock, 0);
  this->ViewHandle = 0;
  Scaleform::StringLH::StringLH(&this->ViewName);
  this->Width = 0.0;
  this->Height = 0.0;
  this->CurrentFrame = 0;
  this->FrameRate = 0.0;
  this->Version = 0;
  this->FrameCount = 0;
  Scaleform::Alg::Random::Generator::Generator(&this->RandomGen);
  this->SkipSamples = 0;
  this->LastTimer = 0;
  this->Markers.mHash.pTable = 0;
  this->RootsNumber = 0;
  this->FreedRootsNumber = 0;
  Scaleform::Event::Event(&this->DebugEvent, 0, 0);
  EnterCriticalSection(&this->ViewLock.cs);
  v3 = nextHandle;
  this->ViewHandle = nextHandle;
  nextHandle = v3 + 1;
  Scaleform::Event::SetEvent(&this->DebugEvent);
  Scaleform::GFx::AMP::ViewStats::RegisterScriptFunction(
    this,
    (Scaleform::RefCountVImpl *)1,
    0x14u,
    (const __m128i *)"Object Interface",
    0,
    0,
    0);
  v7 = 20;
  Scaleform::String::String(&v6, (const __m128i *)"Object Interface");
  key.pFirst = &v6;
  key.pSecond = (const unsigned int *)&v7;
  v4 = Scaleform::String::BernsteinHashFunctionCIS(
         (char *)((v6.HeapTypeBits & 0xFFFFFFFC) + 8),
         *(_DWORD *)(v6.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF,
         0x1505u);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<unsigned int,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<unsigned int,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    &p_NativeFunctionIdMap->mHash,
    p_NativeFunctionIdMap,
    &key,
    v4);
  v5 = (void *)(v6.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v6.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  LeaveCriticalSection(&this->ViewLock.cs);
}
