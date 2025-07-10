void __cdecl Scaleform::GFx::AS2::MovieClipLoaderProto::GetProgress(const Scaleform::GFx::AS2::FnCall *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Value *Result; // edi
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
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // eax
  Scaleform::GFx::AS2::ASStringContext *v14; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-30h]
  Scaleform::GFx::ASString path; // [esp+Ch] [ebp-14h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+10h] [ebp-10h] BYREF

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
    if ( v1->ThisPtr->GetObjectType(v1->ThisPtr) == Object_MovieClipLoader )
    {
      ThisPtr = v1->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      pHeap = v1->Env->StringContext.pContext->pHeap;
      v6 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 52u, 0);
      if ( v6 )
      {
        Scaleform::GFx::AS2::Object::Object(v6, v1->Env);
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      Env = v1->Env;
      v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToStringImpl(v9, &path, Env, -1, 0);
      Scaleform::String::String((Scaleform::String *)&fn, (char *)path.pNode->pData);
      v10 = Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::GetAlt<Scaleform::String>(
              p_pProto + 13,
              (const Scaleform::String *)&fn);
      if ( v10 )
        p_LoadedBytes = &v10->Second.LoadedBytes;
      else
        p_LoadedBytes = 0;
      v12 = (void *)((unsigned int)fn & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)(((unsigned int)fn & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v12);
      if ( p_LoadedBytes )
      {
        p_StringContext = &v1->Env->StringContext;
        val.NV.Int32Value = *p_LoadedBytes;
        val.T.Type = 4;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          p_StringContext,
          "bytesLoaded",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v14 = &v1->Env->StringContext;
        val.NV.Int32Value = p_LoadedBytes[1];
        val.T.Type = 4;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v8->Scaleform::GFx::AS2::ObjectInterface,
          v14,
          "bytesTotal",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
      }
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v8);
      pNode = path.pNode;
      if ( path.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v8 )
      {
        RefCount = v8->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v8->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
        }
      }
    }
  }
}
