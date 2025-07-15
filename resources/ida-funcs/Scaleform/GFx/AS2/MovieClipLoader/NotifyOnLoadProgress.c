void __thiscall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadProgress(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::String ptarget,
        int loadedBytes,
        int totalBytes)
{
  Scaleform::GFx::DisplayObject *pData; // ebx
  int v6; // ebp
  int v8; // edi
  Scaleform::StringHashLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_ProgressInfo; // esi
  Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor> *v10; // eax
  Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc *p_Second; // eax
  void *v12; // esi
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  Scaleform::GFx::AS2::Value *pCurrent; // eax
  Scaleform::GFx::AS2::Value *v15; // eax
  Scaleform::GFx::AS2::Value *v16; // edi
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::ObjectInterface *v18; // edi
  unsigned int v19; // ebx
  Scaleform::GFx::ASStringNode *v20; // eax
  Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc value; // [esp+14h] [ebp-Ch] BYREF
  unsigned int v23; // [esp+1Ch] [ebp-4h]

  pData = (Scaleform::GFx::DisplayObject *)ptarget.pData;
  v6 = loadedBytes;
  v8 = totalBytes;
  if ( ptarget.pData )
  {
    Scaleform::String::String(&ptarget);
    Scaleform::GFx::DisplayObject::GetAbsolutePath(pData, &ptarget);
    p_ProgressInfo = &this->ProgressInfo;
    v10 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
            &p_ProgressInfo->mHash,
            &ptarget);
    if ( v10 && (p_Second = &v10->Second) != 0 )
    {
      p_Second->LoadedBytes = v6;
      p_Second->TotalBytes = v8;
    }
    else
    {
      value.LoadedBytes = v6;
      value.TotalBytes = v8;
      Scaleform::StringHashLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Add(
        p_ProgressInfo,
        &ptarget,
        &value);
    }
    v12 = (void *)(ptarget.HeapTypeBits & 0xFFFFFFFC);
    if ( InterlockedExchangeAdd((volatile LONG *)((ptarget.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
  }
  ++penv->Stack.pCurrent;
  p_Stack = &penv->Stack;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  pCurrent = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    pCurrent->T.Type = 4;
    pCurrent->NV.Int32Value = v8;
  }
  ++p_Stack->pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  v15 = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    v15->T.Type = 4;
    v15->NV.Int32Value = v6;
  }
  ++p_Stack->pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
  v16 = p_Stack->pCurrent;
  if ( p_Stack->pCurrent )
  {
    v16->T.Type = 7;
    if ( pData )
    {
      pObject = pData->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pData);
      v16->NV.Int32Value = (int)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v16->NV.Int32Value = 0;
    }
  }
  if ( this )
    v18 = &this->Scaleform::GFx::AS2::ObjectInterface;
  else
    v18 = 0;
  v19 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  ptarget.pData = (Scaleform::String::DataDesc *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                   (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                   "onLoadProgress",
                                                   0xEu,
                                                   0);
  ++ptarget.pData[1].Size;
  if ( v18 )
  {
    value.LoadedBytes = (int)&`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    value.TotalBytes = 3;
    v23 = v19;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      penv,
      v18,
      (const Scaleform::GFx::ASString *)&ptarget,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&value);
  }
  v20 = (Scaleform::GFx::ASStringNode *)ptarget.pData;
  --ptarget.pData[1].Size;
  if ( !v20->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(p_Stack);
}
