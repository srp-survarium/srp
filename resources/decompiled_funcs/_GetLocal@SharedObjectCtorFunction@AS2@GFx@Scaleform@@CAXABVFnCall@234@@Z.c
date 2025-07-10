void __cdecl Scaleform::GFx::AS2::SharedObjectCtorFunction::GetLocal(Scaleform::GFx::ASStringNode *fn)
{
  const Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *pData; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // ebx
  bool v5; // cc
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // edi
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
  Scaleform::GFx::AS2::RefCountCollector<323> *pRCC; // edi
  signed int v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  LONG (__stdcall *v17)(volatile LONG *, LONG); // edi
  void *v18; // esi
  void *v19; // esi
  Scaleform::GFx::ASStringNode *v20; // ecx
  bool v21; // zf
  Scaleform::GFx::AS2::SharedObject *v22; // edi
  Scaleform::GFx::AS2::Value *v23; // esi
  unsigned int v24; // eax
  unsigned int v25; // eax
  Scaleform::GFx::AS2::LocalFrame *v26; // ecx
  unsigned int v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  void *v29; // esi
  Scaleform::GFx::AS2::Object *v30; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::SharedObjectManagerBase *v32; // eax
  Scaleform::GFx::InteractiveObject *Target; // edx
  Scaleform::RefCountVImpl *v34; // eax
  Scaleform::GFx::FileOpenerBase *v35; // ebx
  Scaleform::GFx::AS2::FunctionObject *v36; // ebx
  unsigned int v37; // edx
  Scaleform::GFx::AS2::SharedObject *pObject; // ecx
  unsigned int v39; // eax
  unsigned int v40; // eax
  unsigned int v41; // eax
  bool v42; // zf
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::RefCountVImpl *v44; // ecx
  unsigned int v45; // eax
  unsigned int v46; // eax
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *v48; // ecx
  unsigned int v49; // eax
  Scaleform::GFx::AS2::LocalFrame *v50; // ecx
  unsigned int v51; // eax
  Scaleform::GFx::ASStringNode *v52; // ecx
  Scaleform::GFx::AS2::FunctionRef *p_RefCount; // eax
  Scaleform::GFx::ASStringNode *v54; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-64h]
  Scaleform::String strLocalPath; // [esp+Ch] [ebp-48h] BYREF
  Scaleform::String strName; // [esp+10h] [ebp-44h] BYREF
  Scaleform::GFx::ASString name; // [esp+14h] [ebp-40h] BYREF
  Scaleform::Ptr<Scaleform::GFx::SharedObjectManagerBase> psoMgr; // [esp+18h] [ebp-3Ch]
  Scaleform::GFx::ASString localPath; // [esp+1Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS2::SharedObjectPtr value; // [esp+20h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FunctionRef fref; // [esp+28h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::GASSharedObjectLoader loader; // [esp+34h] [ebp-20h] BYREF

  v1 = (const Scaleform::GFx::AS2::FnCall *)fn;
  if ( (int)fn[1].pManager >= 1 )
  {
    pData = (Scaleform::GFx::AS2::Environment *)fn[1].pData;
    v3 = 0;
    if ( fn[1].pLower <= (Scaleform::GFx::ASStringNode *)(32 * (pData->Stack.Pages.Data.Size - 1)
                                                        + pData->Stack.pCurrent
                                                        - pData->Stack.pPageStart) )
      v3 = &pData->Stack.Pages.Data.Data[(unsigned int)fn[1].pLower >> 5]->Values[(int)fn[1].pLower & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, &name, pData, -1, 0);
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        (char *)&buf,
                        0,
                        0);
    ++ConstStringNode->RefCount;
    v5 = v1->NArgs <= 1;
    localPath.pNode = ConstStringNode;
    if ( !v5 )
    {
      Env = v1->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      Scaleform::GFx::AS2::Value::ToStringImpl(v6, &localPath, Env, -1, 0);
      pNode = localPath.pNode;
      ++localPath.pNode->RefCount;
      v21 = ConstStringNode->RefCount-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      v21 = pNode->RefCount-- == 1;
      ConstStringNode = pNode;
      localPath.pNode = pNode;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    Scaleform::String::String(&strName, (char *)name.pNode->pData);
    Scaleform::String::String(&strLocalPath, (char *)ConstStringNode->pData);
    fn = Scaleform::GFx::ASStringManager::CreateStringNode(
           (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
           (char *)((strLocalPath.HeapTypeBits & 0xFFFFFFFC) + 8),
           *(_DWORD *)(strLocalPath.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++fn->RefCount;
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&fn,
      (char *)&stru_95963C.m_max_end,
      (Scaleform::GFx::ASStringNode *)1);
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&fn,
      (char *)((strName.HeapTypeBits & 0xFFFFFFFC) + 8),
      (Scaleform::GFx::ASStringNode *)((strName.HeapTypeBits & 0xFFFFFFFC)
                                     + 8
                                     + strlen((const char *)((strName.HeapTypeBits & 0xFFFFFFFC) + 8))
                                     + 1
                                     - ((strName.HeapTypeBits & 0xFFFFFFFC)
                                      + 9)));
    Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, &fref, ASBuiltin_SharedObject);
    Function = fref.Function;
    pRCC = fref.Function[1].pRCC;
    if ( pRCC
      && (v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&fref.Function[1].4,
                  (const Scaleform::GFx::ASString *)&fn,
                  fn->HashFlags & pRCC->RefCount),
          v10 >= 0)
      && (v11 = (int)(&pRCC->Roots.Size + 4 * v10)) != 0
      && (v12 = v11 + 4) != 0 )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, *(Scaleform::GFx::AS2::Object **)(v12 + 4));
      if ( (fref.Flags & 2) == 0 )
      {
        if ( Function )
        {
          RefCount = Function->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      if ( (fref.Flags & 1) == 0 )
      {
        pLocalFrame = fref.pLocalFrame;
        if ( fref.pLocalFrame )
        {
          v15 = fref.pLocalFrame->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v15) != 0 )
          {
            fref.pLocalFrame->RefCount = v15 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      v16 = fn;
      --fn->RefCount;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      v17 = InterlockedExchangeAdd;
      v18 = (void *)(strLocalPath.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((strLocalPath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v18);
    }
    else
    {
      v22 = (Scaleform::GFx::AS2::SharedObject *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                   v1->Env,
                                                   v1->Env->StringContext.pContext->pGlobal.pObject,
                                                   (const Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[17],
                                                   0,
                                                   -1);
      if ( Scaleform::GFx::AS2::SharedObject::SetNameAndLocalPath(v22, &strName, &strLocalPath) )
      {
        v30 = Scaleform::GFx::AS2::Environment::OperatorNew(
                v1->Env,
                v1->Env->StringContext.pContext->pGlobal.pObject,
                (const Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
                0,
                -1);
        loader.pEnv = v1->Env;
        loader.RefCount = 1;
        loader.__vftable = (Scaleform::GFx::AS2::GASSharedObjectLoader_vtbl *)&Scaleform::GFx::AS2::GASSharedObjectLoader::`vftable';
        loader.pData = v30;
        memset(&loader.ObjectStack, 0, 13);
        pMovieImpl = loader.pEnv->Target->pASRoot->pMovieImpl;
        v32 = (Scaleform::GFx::SharedObjectManagerBase *)pMovieImpl->GetStateAddRef(
                                                           &pMovieImpl->Scaleform::GFx::StateBag,
                                                           State_SharedObject);
        Target = v1->Env->Target;
        psoMgr.pObject = v32;
        v34 = (Scaleform::RefCountVImpl *)Target->pASRoot->pMovieImpl->GetStateAddRef(
                                            &Target->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                            State_FileOpener);
        v35 = (Scaleform::GFx::FileOpenerBase *)v34;
        if ( v34 )
          Scaleform::RefCountImpl::Release(v34);
        if ( psoMgr.pObject && psoMgr.pObject->LoadSharedObject(psoMgr.pObject, &strName, &strLocalPath, &loader, v35) )
        {
          Scaleform::GFx::AS2::SharedObject::SetDataObject(v22, v1->Env, v30);
          Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v22);
          if ( v22 )
            v22->RefCount = (v22->RefCount + 1) & 0x8FFFFFFF;
          v36 = fref.Function;
          value.pObject = v22;
          value.__vftable = (Scaleform::GFx::AS2::SharedObjectPtr_vtbl *)&Scaleform::GFx::AS2::SharedObjectPtr::`vftable';
          Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Add(
            (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *)&fref.Function[1].4,
            (const Scaleform::GFx::ASString *)&fn,
            &value);
          value.__vftable = (Scaleform::GFx::AS2::SharedObjectPtr_vtbl *)&Scaleform::GFx::AS2::SharedObjectPtr::`vftable';
          if ( value.pObject )
          {
            v37 = value.pObject->RefCount;
            pObject = value.pObject;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v37) != 0 )
            {
              value.pObject->RefCount = v37 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
            }
          }
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)psoMgr.pObject);
          Scaleform::GFx::AS3::ASSharedObjectLoader::~ASSharedObjectLoader((Scaleform::GFx::AS3::ASSharedObjectLoader *)&loader);
          if ( v30 )
          {
            v39 = v30->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v39) != 0 )
            {
              v30->RefCount = v39 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
            }
          }
          if ( v22 )
          {
            v40 = v22->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v40) != 0 )
            {
              v22->RefCount = v40 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
            }
          }
          if ( (fref.Flags & 2) == 0 )
          {
            if ( v36 )
            {
              v41 = v36->RefCount;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v41) != 0 )
              {
                v36->RefCount = v41 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
              }
            }
          }
          v42 = (fref.Flags & 1) == 0;
        }
        else
        {
          Result = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(Result);
          v44 = (Scaleform::RefCountVImpl *)psoMgr.pObject;
          Result->T.Type = 1;
          if ( v44 )
            Scaleform::RefCountImpl::Release(v44);
          if ( loader.ObjectStack.Data.Data )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, loader.ObjectStack.Data.Data);
          Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&loader);
          if ( v30 )
          {
            v45 = v30->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v45) != 0 )
            {
              v30->RefCount = v45 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v30);
            }
          }
          if ( v22 )
          {
            v46 = v22->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v46) != 0 )
            {
              v22->RefCount = v46 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
            }
          }
          Flags = fref.Flags;
          if ( (fref.Flags & 2) == 0 )
          {
            v48 = fref.Function;
            if ( fref.Function )
            {
              v49 = fref.Function->RefCount;
              if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v49) != 0 )
              {
                fref.Function->RefCount = v49 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
              }
            }
          }
          v42 = (Flags & 1) == 0;
        }
        if ( v42 )
        {
          v50 = fref.pLocalFrame;
          if ( fref.pLocalFrame )
          {
            v51 = fref.pLocalFrame->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v51) != 0 )
            {
              fref.pLocalFrame->RefCount = v51 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v50);
            }
          }
        }
        v52 = fn;
        p_RefCount = (Scaleform::GFx::AS2::FunctionRef *)&fn->RefCount;
        --fn->RefCount;
        if ( !p_RefCount->Function )
          Scaleform::GFx::ASStringNode::ReleaseNode(v52);
        Scaleform::String::~String(&strLocalPath);
        Scaleform::String::~String(&strName);
        v54 = localPath.pNode;
        v21 = localPath.pNode->RefCount-- == 1;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v54);
        v20 = name.pNode;
        v21 = name.pNode->RefCount-- == 1;
        goto LABEL_91;
      }
      v23 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v23);
      v23->T.Type = 1;
      if ( v22 )
      {
        v24 = v22->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v24) != 0 )
        {
          v22->RefCount = v24 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
        }
      }
      if ( (fref.Flags & 2) == 0 )
      {
        if ( Function )
        {
          v25 = Function->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v25) != 0 )
          {
            Function->RefCount = v25 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      if ( (fref.Flags & 1) == 0 )
      {
        v26 = fref.pLocalFrame;
        if ( fref.pLocalFrame )
        {
          v27 = fref.pLocalFrame->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v27) != 0 )
          {
            fref.pLocalFrame->RefCount = v27 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
          }
        }
      }
      v28 = fn;
      --fn->RefCount;
      if ( !v28->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      v17 = InterlockedExchangeAdd;
      v29 = (void *)(strLocalPath.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((strLocalPath.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v29);
    }
    v19 = (void *)(strName.HeapTypeBits & 0xFFFFFFFC);
    if ( v17((volatile LONG *)((strName.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    v21 = ConstStringNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
    v20 = name.pNode;
    v21 = name.pNode->RefCount-- == 1;
LABEL_91:
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
}
