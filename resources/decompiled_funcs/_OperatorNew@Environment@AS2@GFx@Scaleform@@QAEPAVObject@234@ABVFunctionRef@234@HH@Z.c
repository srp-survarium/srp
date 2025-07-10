Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::Environment::OperatorNew(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::AS2::FunctionRef *constructor,
        int nargs,
        int argsTopOff)
{
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v7; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Object *v12; // eax
  Scaleform::GFx::AS2::Object *v13; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // edx
  Scaleform::GFx::AS2::ObjectInterface *v16; // ecx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::Object *Prototype; // eax
  Scaleform::GFx::AS2::Object *v19; // eax
  Scaleform::GFx::AS2::FunctionObject *v20; // esi
  Scaleform::GFx::AS2::Object *v21; // ebp
  Scaleform::GFx::AS2::LocalFrame *v22; // eax
  int v23; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // ecx
  int v25; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
  Scaleform::GFx::AS2::FunctionRef *v27; // eax
  int v28; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v29; // ecx
  int v30; // edx
  Scaleform::GFx::ASStringNode *v31; // ecx
  int v32; // eax
  int v33; // ebp
  void (__thiscall **v34)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *); // edi
  Scaleform::GFx::AS2::Object *v35; // eax
  Scaleform::GFx::AS2::LocalFrame *v36; // eax
  Scaleform::GFx::AS2::FunctionObject *v37; // ecx
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *v39; // ecx
  unsigned int v40; // eax
  Scaleform::GFx::AS2::LocalFrame *v41; // ecx
  unsigned int v42; // eax
  int v43; // eax
  Scaleform::GFx::AS2::ObjectInterface *v44; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  unsigned __int8 v47; // bl
  unsigned int v48; // eax
  Scaleform::GFx::AS2::LocalFrame *v49; // ecx
  unsigned int v50; // eax
  char v51; // [esp+27h] [ebp-7Dh]
  char v52; // [esp+27h] [ebp-7Dh]
  Scaleform::GFx::ASString baseClassName; // [esp+28h] [ebp-7Ch] BYREF
  Scaleform::GFx::ASString thisClassName; // [esp+2Ch] [ebp-78h] BYREF
  Scaleform::GFx::AS2::FunctionRef ctor; // [esp+30h] [ebp-74h] BYREF
  Scaleform::GFx::AS2::Value res; // [esp+40h] [ebp-64h] BYREF
  Scaleform::GFx::AS2::Value __ctor__Val; // [esp+50h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value prototypeVal; // [esp+60h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+70h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v60; // [esp+80h] [ebp-24h] BYREF

  baseClassName.pNode = 0;
  if ( argsTopOff < 0 )
    argsTopOff = this->Stack.pCurrent - this->Stack.pPageStart + 32 * this->Stack.Pages.Data.Size - 32;
  if ( nargs != 1
    || (baseClassName.pNode = (Scaleform::GFx::ASStringNode *)1,
        v51 = 1,
        constructor->Function != Scaleform::GFx::AS2::Environment::GetConstructor(this, &ctor, ASBuiltin_Object)->Function) )
  {
    v51 = 0;
  }
  if ( ((int)baseClassName.pNode & 1) != 0 )
  {
    baseClassName.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)baseClassName.pNode & 0xFFFFFFFE);
    if ( (ctor.Flags & 2) == 0 )
    {
      if ( ctor.Function )
      {
        RefCount = ctor.Function->RefCount;
        Function = ctor.Function;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          ctor.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    ctor.Function = 0;
    if ( (ctor.Flags & 1) == 0 )
    {
      if ( ctor.pLocalFrame )
      {
        v7 = ctor.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v7) != 0 )
        {
          pLocalFrame = ctor.pLocalFrame;
          ctor.pLocalFrame->RefCount = v7 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
  }
  if ( !v51 )
    goto LABEL_34;
  pCurrent = this->Stack.pCurrent;
  Type = pCurrent->T.Type;
  res.T.Type = 0;
  if ( Type == 3 || Type == 4 || Type == 2 || Type == 5 )
  {
    v11 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(this, (Scaleform::GFx::AS2::Value *)&ctor, 0);
    Scaleform::GFx::AS2::Value::operator=(&res, v11);
    if ( LOBYTE(ctor.Function) >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&ctor);
  }
  else
  {
    if ( Type != 6 && Type != 7 )
      goto LABEL_34;
    Scaleform::GFx::AS2::Value::operator=(&res, pCurrent);
  }
  if ( res.T.Type && res.T.Type != 10 )
  {
    v12 = Scaleform::GFx::AS2::Value::ToObject(&res, this);
    v13 = v12;
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
    if ( res.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&res);
    return v13;
  }
  if ( res.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&res);
LABEL_34:
  pContext = this->StringContext.pContext;
  v16 = &constructor->Function->Scaleform::GFx::AS2::ObjectInterface;
  p_StringContext = &this->StringContext;
  prototypeVal.T.Type = 0;
  if ( !v16->GetMemberRaw(
          v16,
          &this->StringContext,
          (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
          &prototypeVal) )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_Object);
    Scaleform::GFx::AS2::Value::SetAsObject(&prototypeVal, Prototype);
  }
  v19 = Scaleform::GFx::AS2::Value::ToObject(&prototypeVal, this);
  v20 = constructor->Function;
  v21 = v19;
  ctor.Flags = 0;
  ctor.Function = v20;
  if ( v20 )
    v20->RefCount = (v20->RefCount + 1) & 0x8FFFFFFF;
  v22 = constructor->pLocalFrame;
  ctor.pLocalFrame = 0;
  if ( v22 )
  {
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&ctor, v22, constructor->Flags & 1);
    v20 = ctor.Function;
  }
  __ctor__Val.T.Type = 0;
  if ( v21
    && v21->GetMemberRaw(
         &v21->Scaleform::GFx::AS2::ObjectInterface,
         &this->StringContext,
         (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &__ctor__Val) )
  {
    if ( __ctor__Val.T.Type != 8 && __ctor__Val.T.Type != 11
      || (baseClassName.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)baseClassName.pNode | 2),
          v52 = 1,
          !Scaleform::GFx::AS2::Value::ToFunction(&__ctor__Val, (Scaleform::GFx::AS2::FunctionRef *)&res, this)->Function) )
    {
      v52 = 0;
    }
    if ( ((int)baseClassName.pNode & 2) != 0 )
    {
      if ( (BYTE4(res.NV.NumberValue) & 2) == 0 )
      {
        if ( *(_DWORD *)&res.T.Type )
        {
          v23 = *(_DWORD *)(*(_DWORD *)&res.T.Type + 12);
          v24 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&res.T.Type;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v23) != 0 )
          {
            *(_DWORD *)(*(_DWORD *)&res.T.Type + 12) = v23 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
          }
        }
      }
      *(_DWORD *)&res.T.Type = 0;
      if ( (BYTE4(res.NV.NumberValue) & 1) == 0 )
      {
        if ( res.NV.Int32Value )
        {
          v25 = *(_DWORD *)(res.NV.Int32Value + 12);
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v25) != 0 )
          {
            pStringNode = res.V.pStringNode;
            *(_DWORD *)(res.NV.Int32Value + 12) = v25 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
          }
        }
      }
    }
    if ( v52 )
    {
      v27 = Scaleform::GFx::AS2::Value::ToFunction(&__ctor__Val, (Scaleform::GFx::AS2::FunctionRef *)&res, this);
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&ctor, v27);
      if ( (BYTE4(res.NV.NumberValue) & 2) == 0 )
      {
        if ( *(_DWORD *)&res.T.Type )
        {
          v28 = *(_DWORD *)(*(_DWORD *)&res.T.Type + 12);
          v29 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&res.T.Type;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v28) != 0 )
          {
            *(_DWORD *)(*(_DWORD *)&res.T.Type + 12) = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v29);
          }
        }
      }
      *(_DWORD *)&res.T.Type = 0;
      if ( (BYTE4(res.NV.NumberValue) & 1) == 0 )
      {
        if ( res.NV.Int32Value )
        {
          v30 = *(_DWORD *)(res.NV.Int32Value + 12);
          v31 = res.V.pStringNode;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v30) != 0 )
          {
            *(_DWORD *)(res.NV.Int32Value + 12) = v30 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v31);
          }
        }
      }
      v20 = ctor.Function;
    }
  }
  v32 = (int)v20->CreateNewObject(v20, this);
  v33 = v32;
  if ( v32 )
  {
    v34 = (void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(*(_DWORD *)(v32 + 16) + 52);
    v35 = Scaleform::GFx::AS2::Value::ToObject(&prototypeVal, this);
    (*v34)(v33 + 16, &this->StringContext, v35);
    Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
      (Scaleform::GFx::AS2::ObjectInterface *)(v33 + 16),
      &this->StringContext,
      constructor);
    v60.Result = &result;
    memset(&v60.ThisFunctionRef, 0, 9);
    v36 = constructor->pLocalFrame;
    v60.FirstArgBottomIndex = argsTopOff;
    v37 = constructor->Function;
    v60.NArgs = nargs;
    result.T.Type = 0;
    v60.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    v60.ThisPtr = (Scaleform::GFx::AS2::ObjectInterface *)(v33 + 16);
    v60.Env = this;
    v37->Invoke(v37, &v60, v36, 0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v60);
    *(_DWORD *)(v33 + 12) = (*(_DWORD *)(v33 + 12) + 1) & 0x8FFFFFFF;
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
    if ( __ctor__Val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&__ctor__Val);
    Flags = ctor.Flags;
    if ( (ctor.Flags & 2) == 0 )
    {
      v39 = ctor.Function;
      v40 = ctor.Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v40) != 0 )
      {
        ctor.Function->RefCount = v40 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v39);
      }
    }
    if ( (Flags & 1) == 0 )
    {
      v41 = ctor.pLocalFrame;
      if ( ctor.pLocalFrame )
      {
        v42 = ctor.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v42) != 0 )
        {
          ctor.pLocalFrame->RefCount = v42 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v41);
        }
      }
    }
    if ( prototypeVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&prototypeVal);
    v43 = *(_DWORD *)(v33 + 12);
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v43) != 0 )
    {
      *(_DWORD *)(v33 + 12) = v43 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v33);
    }
    return (Scaleform::GFx::AS2::Object *)v33;
  }
  else
  {
    if ( constructor->Function )
      v44 = &constructor->Function->Scaleform::GFx::AS2::ObjectInterface;
    else
      v44 = 0;
    Scaleform::GFx::AS2::GlobalContext::FindClassName(p_StringContext->pContext, &thisClassName, this, v44);
    Scaleform::GFx::AS2::GlobalContext::FindClassName(
      p_StringContext->pContext,
      &baseClassName,
      this,
      &v20->Scaleform::GFx::AS2::ObjectInterface);
    Scaleform::GFx::AS2::Environment::LogScriptError(
      this,
      "%s::CreateNewObject returned NULL during creation of %s class instance.",
      baseClassName.pNode->pData,
      thisClassName.pNode->pData);
    pNode = baseClassName.pNode;
    --baseClassName.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v46 = thisClassName.pNode;
    --thisClassName.pNode->RefCount;
    if ( !v46->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v46);
    if ( __ctor__Val.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&__ctor__Val);
    v47 = ctor.Flags;
    if ( (ctor.Flags & 2) == 0 )
    {
      v48 = v20->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v48) != 0 )
      {
        v20->RefCount = v48 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
      }
    }
    if ( (v47 & 1) == 0 )
    {
      v49 = ctor.pLocalFrame;
      if ( ctor.pLocalFrame )
      {
        v50 = ctor.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v50) != 0 )
        {
          ctor.pLocalFrame->RefCount = v50 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v49);
        }
      }
    }
    if ( prototypeVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&prototypeVal);
    return 0;
  }
}
