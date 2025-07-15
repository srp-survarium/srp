void __cdecl Scaleform::GFx::AS2::SharedObjectCtorFunction::GetLocal(Scaleform::GFx::ASStringNode *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // esi
  Scaleform::GFx::AS2::Environment *pData; // eax
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::ASStringNode *ConstStringNode; // ebx
  bool v5; // cc
  Scaleform::GFx::AS2::Value *v6; // eax
  Scaleform::GFx::ASStringNode *v7; // edi
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
  Scaleform::GFx::AS3::Instances::fl::Object *v30; // ebp
  int v31; // ecx
  Scaleform::RefCountVImpl *v32; // eax
  Scaleform::GFx::InteractiveObject *Target; // edx
  Scaleform::RefCountVImpl *v34; // eax
  Scaleform::RefCountVImpl *v35; // ebx
  Scaleform::GFx::AS2::FunctionObject *v36; // ebx
  unsigned int v37; // edx
  Scaleform::GFx::AS2::SharedObject *pObject; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *pPrev; // eax
  unsigned int v40; // eax
  unsigned int v41; // eax
  bool v42; // zf
  Scaleform::GFx::AS2::Value *v43; // esi
  Scaleform::RefCountVImpl *v44; // ecx
  const Scaleform::GFx::AS3::RefCountBaseGC<328> *v45; // eax
  unsigned int v46; // eax
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *v48; // ecx
  unsigned int v49; // eax
  Scaleform::GFx::AS2::LocalFrame *v50; // ecx
  unsigned int v51; // eax
  Scaleform::GFx::ASStringNode *v52; // ecx
  unsigned int *p_RefCount; // eax
  Scaleform::GFx::ASStringNode *v54; // ecx
  Scaleform::GFx::AS2::Environment *Env; // [esp-10h] [ebp-64h]
  Scaleform::String v56; // [esp+Ch] [ebp-48h] BYREF
  Scaleform::String v57; // [esp+10h] [ebp-44h] BYREF
  Scaleform::GFx::ASStringNode *v58; // [esp+14h] [ebp-40h] BYREF
  Scaleform::RefCountVImpl *v59; // [esp+18h] [ebp-3Ch]
  Scaleform::GFx::ASStringNode *v60; // [esp+1Ch] [ebp-38h] BYREF
  Scaleform::GFx::AS2::SharedObjectPtr value; // [esp+20h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+28h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS3::ASSharedObjectLoader v63; // [esp+34h] [ebp-20h] BYREF

  v1 = (Scaleform::GFx::AS2::FnCall *)fn;
  if ( (int)fn[1].pManager >= 1 )
  {
    pData = (Scaleform::GFx::AS2::Environment *)fn[1].pData;
    v3 = 0;
    if ( fn[1].pLower <= (Scaleform::GFx::ASStringNode *)(32 * (pData->Stack.Pages.Data.Size - 1)
                                                        + pData->Stack.pCurrent
                                                        - pData->Stack.pPageStart) )
      v3 = &pData->Stack.Pages.Data.Data[(unsigned int)fn[1].pLower >> 5]->Values[(int)fn[1].pLower & 0x1F];
    Scaleform::GFx::AS2::Value::ToStringImpl(v3, (Scaleform::GFx::ASString *)&v58, pData, -1, 0);
    ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                        (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                        (char *)uri,
                        0,
                        0);
    ++ConstStringNode->RefCount;
    v5 = v1->NArgs <= 1;
    v60 = ConstStringNode;
    if ( !v5 )
    {
      Env = v1->Env;
      v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      Scaleform::GFx::AS2::Value::ToStringImpl(v6, (Scaleform::GFx::ASString *)&v60, Env, -1, 0);
      v7 = v60;
      ++v60->RefCount;
      v21 = ConstStringNode->RefCount-- == 1;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
      v21 = v7->RefCount-- == 1;
      ConstStringNode = v7;
      v60 = v7;
      if ( v21 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    }
    Scaleform::String::String(&v57, (const __m128i *)v58->pData);
    Scaleform::String::String(&v56, (const __m128i *)ConstStringNode->pData);
    fn = Scaleform::GFx::ASStringManager::CreateStringNode(
           (Scaleform::GFx::ASStringManager *)v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
           (__m128i *)((v56.HeapTypeBits & 0xFFFFFFFC) + 8),
           *(_DWORD *)(v56.HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF);
    ++fn->RefCount;
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&fn,
      (const __m128i *)":",
      (Scaleform::GFx::ASStringNode *)1);
    Scaleform::GFx::ASString::Append(
      (Scaleform::GFx::ASString *)&fn,
      (const __m128i *)((v57.HeapTypeBits & 0xFFFFFFFC) + 8),
      (Scaleform::GFx::ASStringNode *)((v57.HeapTypeBits & 0xFFFFFFFC)
                                     + 8
                                     + strlen((const char *)((v57.HeapTypeBits & 0xFFFFFFFC) + 8))
                                     + 1
                                     - ((v57.HeapTypeBits & 0xFFFFFFFC)
                                      + 9)));
    Scaleform::GFx::AS2::Environment::GetConstructor(v1->Env, &result, ASBuiltin_SharedObject);
    Function = result.Function;
    pRCC = result.Function[1].pRCC;
    if ( pRCC
      && (v10 = Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>::findIndexCore<Scaleform::GFx::ASString>(
                  (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::GlobalContext::ClassRegEntry,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > *)&result.Function[1].4,
                  (const Scaleform::GFx::ASString *)&fn,
                  fn->HashFlags & pRCC->RefCount),
          v10 >= 0)
      && (v11 = (int)(&pRCC->Roots.Size + 4 * v10)) != 0
      && (v12 = v11 + 4) != 0 )
    {
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, *(Scaleform::GFx::AS2::Object **)(v12 + 4));
      if ( (result.Flags & 2) == 0 )
      {
        if ( Function )
        {
          RefCount = Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      if ( (result.Flags & 1) == 0 )
      {
        pLocalFrame = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v15 = result.pLocalFrame->RefCount;
          if ( (v15 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v15 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
          }
        }
      }
      v16 = fn;
      --fn->RefCount;
      if ( !v16->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      v17 = InterlockedExchangeAdd;
      v18 = (void *)(v56.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v56.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
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
      if ( Scaleform::GFx::AS2::SharedObject::SetNameAndLocalPath(v22, &v57, &v56) )
      {
        v30 = (Scaleform::GFx::AS3::Instances::fl::Object *)Scaleform::GFx::AS2::Environment::OperatorNew(
                                                              v1->Env,
                                                              v1->Env->StringContext.pContext->pGlobal.pObject,
                                                              (const Scaleform::GFx::ASString *)&v1->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
                                                              0,
                                                              -1);
        v63.pVM = (Scaleform::GFx::AS3::VM *)v1->Env;
        v63.RefCount = 1;
        v63.__vftable = (Scaleform::GFx::AS3::ASSharedObjectLoader_vtbl *)&Scaleform::GFx::AS2::GASSharedObjectLoader::`vftable';
        v63.pData = v30;
        memset(&v63.ObjectStack, 0, 13);
        v31 = *(_DWORD *)(*(_DWORD *)(v63.pVM->ExceptionObj.value.VS._1.VInt + 16) + 8);
        v32 = (Scaleform::RefCountVImpl *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(v31 + 8) + 12))(v31 + 8, 32);
        Target = v1->Env->Target;
        v59 = v32;
        v34 = (Scaleform::RefCountVImpl *)Target->pASRoot->pMovieImpl->GetStateAddRef(
                                            &Target->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                                            State_FileOpener);
        v35 = v34;
        if ( v34 )
          Scaleform::RefCountImpl::Release(v34);
        if ( v59
          && ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *, Scaleform::GFx::AS3::ASSharedObjectLoader *, Scaleform::RefCountVImpl *))v59->AddRef)(
               v59,
               &v57,
               &v56,
               &v63,
               v35) )
        {
          Scaleform::GFx::AS2::SharedObject::SetDataObject(
            v22,
            (Scaleform::GFx::ASStringNode *)v1->Env,
            (Scaleform::GFx::AS2::Object *)v30);
          Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v22);
          if ( v22 )
            v22->RefCount = (v22->RefCount + 1) & 0x8FFFFFFF;
          v36 = result.Function;
          value.pObject = v22;
          value.__vftable = (Scaleform::GFx::AS2::SharedObjectPtr_vtbl *)&Scaleform::GFx::AS2::SharedObjectPtr::`vftable';
          Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>>>::Add(
            (Scaleform::Hash<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF>,Scaleform::HashSet<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ASString,324>,Scaleform::GFx::HashsetNodeEntry_GC<Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>,Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::SharedObjectPtr,Scaleform::GFx::ASStringHashFunctor>::NodeHashF> > > *)&result.Function[1].4,
            (const Scaleform::GFx::ASString *)&fn,
            &value);
          value.__vftable = (Scaleform::GFx::AS2::SharedObjectPtr_vtbl *)&Scaleform::GFx::AS2::SharedObjectPtr::`vftable';
          if ( value.pObject )
          {
            v37 = value.pObject->RefCount;
            pObject = value.pObject;
            if ( (v37 & 0x3FFFFFF) != 0 )
            {
              value.pObject->RefCount = v37 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
            }
          }
          Scaleform::RefCountImpl::Release(v59);
          Scaleform::GFx::AS3::ASSharedObjectLoader::~ASSharedObjectLoader(&v63);
          if ( v30 )
          {
            pPrev = v30->pPrev;
            if ( ((unsigned int)pPrev & 0x3FFFFFF) != 0 )
            {
              v30->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)pPrev - 1);
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v30);
            }
          }
          if ( v22 )
          {
            v40 = v22->RefCount;
            if ( (v40 & 0x3FFFFFF) != 0 )
            {
              v22->RefCount = v40 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
            }
          }
          if ( (result.Flags & 2) == 0 )
          {
            if ( v36 )
            {
              v41 = v36->RefCount;
              if ( (v41 & 0x3FFFFFF) != 0 )
              {
                v36->RefCount = v41 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v36);
              }
            }
          }
          v42 = (result.Flags & 1) == 0;
        }
        else
        {
          v43 = v1->Result;
          Scaleform::GFx::AS2::Value::DropRefs(v43);
          v44 = v59;
          v43->T.Type = 1;
          if ( v44 )
            Scaleform::RefCountImpl::Release(v44);
          if ( v63.ObjectStack.Data.Data )
            Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v63.ObjectStack.Data.Data);
          Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&v63);
          if ( v30 )
          {
            v45 = v30->pPrev;
            if ( ((unsigned int)v45 & 0x3FFFFFF) != 0 )
            {
              v30->pPrev = (const Scaleform::GFx::AS3::RefCountBaseGC<328> *)((char *)v45 - 1);
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v30);
            }
          }
          if ( v22 )
          {
            v46 = v22->RefCount;
            if ( (v46 & 0x3FFFFFF) != 0 )
            {
              v22->RefCount = v46 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
            }
          }
          Flags = result.Flags;
          if ( (result.Flags & 2) == 0 )
          {
            v48 = result.Function;
            if ( result.Function )
            {
              v49 = result.Function->RefCount;
              if ( (v49 & 0x3FFFFFF) != 0 )
              {
                result.Function->RefCount = v49 - 1;
                Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
              }
            }
          }
          v42 = (Flags & 1) == 0;
        }
        if ( v42 )
        {
          v50 = result.pLocalFrame;
          if ( result.pLocalFrame )
          {
            v51 = result.pLocalFrame->RefCount;
            if ( (v51 & 0x3FFFFFF) != 0 )
            {
              result.pLocalFrame->RefCount = v51 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v50);
            }
          }
        }
        v52 = fn;
        p_RefCount = &fn->RefCount;
        --fn->RefCount;
        if ( !*p_RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v52);
        Scaleform::String::~String(&v56);
        Scaleform::String::~String(&v57);
        v54 = v60;
        v21 = v60->RefCount-- == 1;
        if ( v21 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v54);
        v20 = v58;
        v21 = v58->RefCount-- == 1;
        goto LABEL_91;
      }
      v23 = v1->Result;
      Scaleform::GFx::AS2::Value::DropRefs(v23);
      v23->T.Type = 1;
      if ( v22 )
      {
        v24 = v22->RefCount;
        if ( (v24 & 0x3FFFFFF) != 0 )
        {
          v22->RefCount = v24 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v22);
        }
      }
      if ( (result.Flags & 2) == 0 )
      {
        if ( Function )
        {
          v25 = Function->RefCount;
          if ( (v25 & 0x3FFFFFF) != 0 )
          {
            Function->RefCount = v25 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      if ( (result.Flags & 1) == 0 )
      {
        v26 = result.pLocalFrame;
        if ( result.pLocalFrame )
        {
          v27 = result.pLocalFrame->RefCount;
          if ( (v27 & 0x3FFFFFF) != 0 )
          {
            result.pLocalFrame->RefCount = v27 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v26);
          }
        }
      }
      v28 = fn;
      --fn->RefCount;
      if ( !v28->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      v17 = InterlockedExchangeAdd;
      v29 = (void *)(v56.HeapTypeBits & 0xFFFFFFFC);
      if ( InterlockedExchangeAdd((volatile LONG *)((v56.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v29);
    }
    v19 = (void *)(v57.HeapTypeBits & 0xFFFFFFFC);
    if ( v17((volatile LONG *)((v57.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v19);
    v21 = ConstStringNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
    v20 = v58;
    v21 = v58->RefCount-- == 1;
LABEL_91:
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
}
