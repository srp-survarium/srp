void __cdecl Scaleform::GFx::AS2::MovieClipLoaderProto::GetProgress(Scaleform::String fn)
{
  Scaleform::GFx::AS2::FnCall *pData; // esi
  Scaleform::GFx::AS2::Value *RefCount; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *p_pProto; // edi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // ebx
  Scaleform::GFx::AS2::Value *v9; // eax
  Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor> *v10; // eax
  int *p_LoadedBytes; // ebp
  void *v12; // edi
  Scaleform::GFx::ASStringNode *p_StringContext; // eax
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // ecx
  unsigned int v17; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-30h]
  Scaleform::GFx::ASStringNode *v19; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+10h] [ebp-10h] BYREF

  pData = (Scaleform::GFx::AS2::FnCall *)fn.pData;
  if ( fn.pData[2].RefCount >= 1 )
  {
    RefCount = (Scaleform::GFx::AS2::Value *)fn.pData->RefCount;
    Scaleform::GFx::AS2::Value::DropRefs(RefCount);
    RefCount->T.Type = 0;
    if ( pData->ThisPtr->GetObjectType(pData->ThisPtr) == Object_MovieClipLoader )
    {
      ThisPtr = pData->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      pHeap = pData->Env->StringContext.pContext->pHeap;
      v6 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
      if ( v6 )
      {
        Scaleform::GFx::AS2::Object::Object(v6, pData->Env);
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      Env = pData->Env;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(pData, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v9, (Scaleform::GFx::ASString *)&v19, Env, -1, 0);
      Scaleform::String::String(&fn, (const __m128i *)v19->pData);
      v10 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
              p_pProto + 13,
              &fn);
      if ( v10 )
        p_LoadedBytes = &v10->Second.LoadedBytes;
      else
        p_LoadedBytes = 0;
      v12 = (void *)(fn.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((fn.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      if ( p_LoadedBytes )
      {
        p_StringContext = (Scaleform::GFx::ASStringNode *)&pData->Env->StringContext;
        v20.NV.Int32Value = *p_LoadedBytes;
        v20.T.Type = 4;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          "bytesLoaded",
          &v20);
        if ( v20.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v20);
        v14 = (Scaleform::GFx::ASStringNode *)&pData->Env->StringContext;
        v20.NV.Int32Value = p_LoadedBytes[1];
        v20.T.Type = 4;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          v14,
          "bytesTotal",
          &v20);
        if ( v20.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v20);
      }
      Scaleform::GFx::AS2::Value::SetAsObject(pData->Result, v8);
      v15 = v19;
      if ( v19->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      if ( v8 )
      {
        v17 = v8->RefCount;
        if ( (v17 & 0x3FFFFFF) != 0 )
        {
          v8->RefCount = v17 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
    }
  }
}
