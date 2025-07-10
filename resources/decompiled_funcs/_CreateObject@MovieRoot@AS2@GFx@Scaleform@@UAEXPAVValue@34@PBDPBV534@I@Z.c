void __thiscall Scaleform::GFx::AS2::MovieRoot::CreateObject(
        Scaleform::GFx::AS2::MovieRoot *this,
        Scaleform::GFx::Value *pvalue,
        char *className,
        const Scaleform::GFx::Value *pargs,
        Scaleform::GFx::ASStringNode *nargs)
{
  Scaleform::GFx::ASStringNode *v5; // ebp
  Scaleform::GFx::InteractiveObject *pMainMovie; // eax
  int AvmObjOffset; // ecx
  int v8; // edx
  Scaleform::GFx::InteractiveObject_vtbl **v9; // ecx
  int (__thiscall *v10)(Scaleform::GFx::InteractiveObject_vtbl **); // eax
  Scaleform::GFx::AS2::Environment *v11; // eax
  Scaleform::GFx::AS2::Environment *v12; // edi
  Scaleform::GFx::AS2::Value **p_pCurrent; // esi
  const Scaleform::GFx::Value *v14; // ebx
  int v15; // eax
  char *v16; // ebp
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::Object *pObject; // ecx
  Scaleform::GFx::AS2::Object **p_pObject; // eax
  Scaleform::GFx::AS2::Object *v20; // edi
  int v21; // eax
  unsigned int v22; // esi
  char *v23; // ebx
  Scaleform::GFx::AS2::GlobalContext *v24; // edx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::Object *v26; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v27; // esi
  unsigned int v28; // eax
  Scaleform::GFx::ASStringNode *v29; // eax
  unsigned int v30; // eax
  Scaleform::GFx::AS2::Object *v31; // esi
  Scaleform::GFx::ASStringNode *v32; // eax
  unsigned int v33; // eax
  Scaleform::GFx::AS2::Value *v34; // eax
  Scaleform::GFx::ASStringNode *v35; // ecx
  unsigned int *p_RefCount; // eax
  unsigned int v37; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS2::Value *v39; // eax
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString v41; // [esp+10h] [ebp-120h] BYREF
  Scaleform::GFx::AS2::Environment *penv; // [esp+14h] [ebp-11Ch]
  Scaleform::GFx::ASString memberName; // [esp+18h] [ebp-118h] BYREF
  Scaleform::GFx::AS2::Value pkgObjVal; // [esp+1Ch] [ebp-114h] BYREF
  Scaleform::GFx::ASString v45; // [esp+2Ch] [ebp-104h] BYREF
  char buf[256]; // [esp+30h] [ebp-100h] BYREF

  v5 = (Scaleform::GFx::ASStringNode *)this;
  pMainMovie = this->pMovieImpl->pMainMovie;
  AvmObjOffset = pMainMovie->AvmObjOffset;
  v8 = *((_DWORD *)&pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + AvmObjOffset);
  v9 = &pMainMovie->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
     + AvmObjOffset;
  v10 = *(int (__thiscall **)(Scaleform::GFx::InteractiveObject_vtbl **))(v8 + 124);
  v41.pNode = v5;
  v11 = (Scaleform::GFx::AS2::Environment *)v10(v9);
  v12 = v11;
  penv = v11;
  if ( !className )
  {
    v31 = Scaleform::GFx::AS2::Environment::OperatorNew(
            v11,
            v11->StringContext.pContext->pGlobal.pObject,
            (const Scaleform::GFx::ASString *)&v11->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
            0,
            -1);
    Scaleform::GFx::AS2::Value::Value(&pkgObjVal, v31);
    Scaleform::GFx::AS2::MovieRoot::ASValue2Value((Scaleform::GFx::AS2::MovieRoot *)v5, v12, v39, pvalue);
    if ( pkgObjVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&pkgObjVal);
LABEL_59:
    if ( v31 )
    {
      RefCount = v31->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v31->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v31);
      }
    }
    return;
  }
  if ( nargs && (int)&nargs[-1].Size + 3 > -1 )
  {
    p_pCurrent = &v11->Stack.pCurrent;
    v14 = &pargs[(int)nargs - 1];
    memberName.pNode = nargs;
    do
    {
      pkgObjVal.T.Type = 0;
      Scaleform::GFx::AS2::MovieRoot::Value2ASValue((Scaleform::GFx::AS2::MovieRoot *)v5, v14, &pkgObjVal);
      ++*p_pCurrent;
      if ( v12->Stack.pCurrent >= v12->Stack.pPageEnd )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v12->Stack);
      if ( *p_pCurrent )
        Scaleform::GFx::AS2::Value::Value(*p_pCurrent, &pkgObjVal);
      if ( pkgObjVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pkgObjVal);
      --v14;
      --memberName.pNode;
    }
    while ( memberName.pNode );
  }
  strchr(className, 0x2Eu);
  if ( !v15 )
  {
    v41.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                  (Scaleform::GFx::ASStringManager *)v12->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  className);
    ++v41.pNode->RefCount;
    v31 = Scaleform::GFx::AS2::Environment::OperatorNew(
            v12,
            v12->StringContext.pContext->pGlobal.pObject,
            &v41,
            (int)nargs,
            -1);
    pNode = v41.pNode;
    --v41.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_38:
    if ( v31 )
    {
      Scaleform::GFx::AS2::Value::Value(&pkgObjVal, v31);
      Scaleform::GFx::AS2::MovieRoot::ASValue2Value((Scaleform::GFx::AS2::MovieRoot *)v5, v12, v34, pvalue);
      if ( pkgObjVal.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&pkgObjVal);
    }
    else
    {
      if ( (pvalue->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))pvalue->pObjectInterface->ObjectRelease)(
          pvalue,
          pvalue->mValue.IValue);
        pvalue->pObjectInterface = 0;
      }
      pvalue->Type = VT_Undefined;
    }
    if ( nargs )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop(&v12->Stack, (unsigned int)nargs);
    goto LABEL_59;
  }
  v16 = className;
  pContext = v12->StringContext.pContext;
  pObject = pContext->pGlobal.pObject;
  p_pObject = &pContext->pGlobal.pObject;
  if ( pObject )
    pObject->RefCount = (pObject->RefCount + 1) & 0x8FFFFFFF;
  v20 = *p_pObject;
  while ( 1 )
  {
    strchr(v16, 0x2Eu);
    if ( !v21 )
    {
LABEL_32:
      v45.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                    (Scaleform::GFx::ASStringManager *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                    v16);
      ++v45.pNode->RefCount;
      v31 = Scaleform::GFx::AS2::Environment::OperatorNew(penv, v20, &v45, (int)nargs, -1);
      v32 = v45.pNode;
      --v45.pNode->RefCount;
      if ( !v32->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v32);
      if ( v20 )
      {
        v33 = v20->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v33) != 0 )
        {
          v20->RefCount = v33 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
        }
      }
      v12 = penv;
      v5 = v41.pNode;
      goto LABEL_38;
    }
    v22 = v21 - (_DWORD)v16 + 1;
    v23 = (char *)(v21 + 1);
    if ( v22 > 0x100 )
      v22 = 256;
    memcpy((unsigned __int8 *)buf, (unsigned __int8 *)v16, v22 - 1);
    *((_BYTE *)&v45.pNode + v22 + 3) = 0;
    v24 = penv->StringContext.pContext;
    pkgObjVal.T.Type = 0;
    p_StringContext = &penv->StringContext;
    v16 = v23;
    memberName.pNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                         (Scaleform::GFx::ASStringManager *)v24->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                         buf);
    ++memberName.pNode->RefCount;
    if ( !v20->GetMemberRaw(&v20->Scaleform::GFx::AS2::ObjectInterface, p_StringContext, &memberName, &pkgObjVal) )
      break;
    v26 = Scaleform::GFx::AS2::Value::ToObject(&pkgObjVal, 0);
    v27 = v26;
    if ( v26 )
      v26->RefCount = (((v26->RefCount + 1) & 0x8FFFFFFF) + 1) & 0x8FFFFFFF;
    v28 = v20->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v28) != 0 )
    {
      v20->RefCount = v28 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
    }
    v29 = memberName.pNode;
    --memberName.pNode->RefCount;
    v20 = (Scaleform::GFx::AS2::Object *)v27;
    if ( !v29->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v29);
    if ( v27 )
    {
      v30 = v27->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v30) != 0 )
      {
        v27->RefCount = v30 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
      }
    }
    if ( pkgObjVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&pkgObjVal);
    if ( !v23 )
      goto LABEL_32;
  }
  if ( (pvalue->Type & 0x40) != 0 )
  {
    ((void (__stdcall *)(Scaleform::GFx::Value *, int))pvalue->pObjectInterface->ObjectRelease)(
      pvalue,
      pvalue->mValue.IValue);
    pvalue->pObjectInterface = 0;
  }
  v35 = memberName.pNode;
  p_RefCount = &memberName.pNode->RefCount;
  pvalue->Type = VT_Undefined;
  if ( !--*p_RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( pkgObjVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&pkgObjVal);
  if ( v20 )
  {
    v37 = v20->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v37) != 0 )
    {
      v20->RefCount = v37 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
    }
  }
}
