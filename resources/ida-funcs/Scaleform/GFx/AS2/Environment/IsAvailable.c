char __thiscall Scaleform::GFx::AS2::Environment::IsAvailable(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::ASStringNode *varname,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack)
{
  const Scaleform::GFx::ASString *v3; // ebp
  Scaleform::GFx::ASStringNode *RefCount; // esi
  const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *v6; // ebx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::ASStringNode *v8; // eax
  Scaleform::GFx::InteractiveObject *v9; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::GFx::ASStringNode *v11; // ecx
  int v12; // eax
  char v13; // bl
  Scaleform::GFx::ASStringNode *v14; // eax
  Scaleform::GFx::ASStringNode *v15; // ecx
  int i; // esi
  Scaleform::GFx::AS2::Object *pObject; // eax
  int v18; // ecx
  Scaleform::GFx::AS2::Object_vtbl **v19; // ecx
  int v20; // eax
  Scaleform::GFx::AS2::Environment *v21; // esi
  Scaleform::GFx::InteractiveObject *Target; // eax
  int v23; // eax
  _DWORD *v24; // ecx
  const char **p_pData; // eax
  Scaleform::GFx::ASStringNode *v26; // eax
  Scaleform::GFx::ASStringNode *v27; // ecx
  bool v28; // zf
  _DWORD *v29; // ecx
  Scaleform::GFx::ASStringNode *pLower; // edx
  const char *v31; // eax
  bool v32; // cf
  unsigned int v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::AS2::Object *v35; // eax
  Scaleform::GFx::ASStringNode *v36; // eax
  Scaleform::GFx::ASStringNode *v37; // ecx
  Scaleform::GFx::ASStringNode *v38; // [esp+24h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Environment *v39; // [esp+28h] [ebp-2Ch]
  Scaleform::GFx::AS2::Value v40; // [esp+2Ch] [ebp-28h] BYREF
  _DWORD v41[6]; // [esp+3Ch] [ebp-18h] BYREF

  v3 = (const Scaleform::GFx::ASString *)varname;
  v28 = *((_DWORD *)varname->pData + 5) == 0;
  v39 = this;
  if ( v28 )
    return 0;
  RefCount = (Scaleform::GFx::ASStringNode *)this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  v6 = pwithStack;
  p_StringContext = &this->StringContext;
  ++RefCount->RefCount;
  varname = (Scaleform::GFx::ASStringNode *)this->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++varname->RefCount;
  v41[3] = 0;
  v41[4] = 0;
  v38 = RefCount;
  v40.T.Type = 0;
  v41[0] = v3;
  v41[1] = &v40;
  v41[2] = v6;
  v41[5] = 4;
  if ( Scaleform::GFx::AS2::Environment::FindAndGetVariableRaw(this, v3, (Scaleform::GFx::AS2::Object *)v41) )
  {
    if ( v40.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v40);
    v8 = varname;
    --varname->RefCount;
    if ( !v8->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v8);
    v28 = RefCount->RefCount-- == 1;
    if ( v28 )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
      return 1;
    }
    return 1;
  }
  if ( !Scaleform::GFx::AS2::Environment::ParsePath(
          p_StringContext,
          v3,
          (Scaleform::GFx::ASString *)&v38,
          (Scaleform::GFx::ASString *)&varname) )
  {
    if ( v6 )
    {
      for ( i = v6->Data.Size - 1; i >= 0; --i )
      {
        pObject = v6->Data.Data[i].pObject;
        if ( (v6->Data.Data[i].BlockEndPc & 0x80000000) == 0 )
        {
          if ( !pObject )
            continue;
          v19 = &pObject->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable
              + BYTE1(pObject[1].RefCount);
          v20 = ((int (__thiscall *)(Scaleform::GFx::AS2::Object_vtbl **))(*v19)->Finalize_GC)(v19);
          if ( !v20 )
            continue;
          v18 = v20 + 4;
        }
        else
        {
          if ( !pObject )
            continue;
          v18 = (int)&pObject->Scaleform::GFx::AS2::ObjectInterface;
        }
        if ( v18
          && (*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_DWORD *)v18 + 44))(
               v18,
               p_StringContext,
               v3,
               &v40) )
        {
          goto LABEL_43;
        }
      }
    }
    v21 = v39;
    if ( Scaleform::GFx::AS2::Environment::FindLocal(v39, v3) )
      goto LABEL_43;
    Target = v21->Target;
    if ( Target )
    {
      v23 = (*(int (__thiscall **)(int))(*((_DWORD *)&Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                         + Target->AvmObjOffset)
                                       + 4))((int)Target + 4 * Target->AvmObjOffset);
      if ( (*(unsigned __int8 (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_DWORD *)(v23 + 4) + 44))(
             v23 + 4,
             p_StringContext,
             v3,
             &v40) )
      {
        goto LABEL_43;
      }
    }
    if ( v21->StringContext.SWFVersion <= 6u )
    {
      if ( !v3->pNode->pLower )
        Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v3->pNode);
      v29 = &p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject->__vftable;
      p_pData = &v3->pNode->pData;
      pLower = v3->pNode->pLower;
      if ( *(Scaleform::GFx::ASStringNode **)(v29[102] + 8) == pLower )
        goto LABEL_43;
      v6 = (const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *)v29[105];
      if ( (Scaleform::GFx::ASStringNode *)v6->Data.Policy.Capacity == pLower
        || *(Scaleform::GFx::ASStringNode **)(v29[104] + 8) == pLower )
      {
        goto LABEL_43;
      }
    }
    else
    {
      v24 = &p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject->__vftable;
      p_pData = &v3->pNode->pData;
      if ( (Scaleform::GFx::ASStringNode *)v24[102] == v3->pNode
        || (const char **)v24[105] == p_pData
        || (const char **)v24[104] == p_pData )
      {
LABEL_43:
        if ( v40.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v40);
        v26 = varname;
        --varname->RefCount;
        if ( !v26->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v26);
        v27 = v38;
        v28 = v38->RefCount-- == 1;
        goto LABEL_48;
      }
    }
    v31 = *p_pData;
    if ( *v31 != 95
      || (v32 = v21->StringContext.SWFVersion < 6u,
          v28 = v21->StringContext.SWFVersion == 6,
          pwithStack = 0,
          LOBYTE(v39) = !v32 && !v28,
          v33 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(
                  (const char *)v39,
                  (int)v6,
                  v31,
                  (const char **)&pwithStack,
                  (bool)v39),
          v33 == -1)
      || LOBYTE(pwithStack->Data.Data)
      || !Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(
            (Scaleform::GFx::AS2::MovieRoot *)v21->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
            v33) )
    {
      v35 = p_StringContext->pContext->pGlobal.pObject;
      if ( !v35 || !v35->GetMemberRaw(&v35->Scaleform::GFx::AS2::ObjectInterface, p_StringContext, v3, &v40) )
      {
        if ( v40.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v40);
        v36 = varname;
        --varname->RefCount;
        if ( !v36->RefCount )
          Scaleform::GFx::ASStringNode::ReleaseNode(v36);
        v37 = v38;
        v28 = v38->RefCount-- == 1;
        if ( v28 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v37);
        return 0;
      }
    }
    if ( v40.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v40);
    v34 = varname;
    --varname->RefCount;
    if ( !v34->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    v27 = v38;
    v28 = v38->RefCount-- == 1;
LABEL_48:
    if ( v28 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v27);
    return 1;
  }
  v9 = Scaleform::GFx::AS2::Environment::FindTarget(v39, (const Scaleform::GFx::ASString *)&v38, 4);
  if ( !v9 )
  {
    if ( v40.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v40);
    v10 = varname;
    --varname->RefCount;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    v11 = v38;
    v28 = v38->RefCount-- == 1;
    if ( v28 )
    {
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      return 0;
    }
    return 0;
  }
  v12 = (*(int (__thiscall **)(int))(*((_DWORD *)&v9->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                     + v9->AvmObjOffset)
                                   + 4))((int)v9 + 4 * v9->AvmObjOffset);
  v13 = (*(int (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *))(*(_DWORD *)(v12 + 4) + 44))(
          v12 + 4,
          p_StringContext,
          &varname,
          &v40);
  if ( v40.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v40);
  v14 = varname;
  --varname->RefCount;
  if ( !v14->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  v15 = v38;
  v28 = v38->RefCount-- == 1;
  if ( v28 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  return v13;
}
