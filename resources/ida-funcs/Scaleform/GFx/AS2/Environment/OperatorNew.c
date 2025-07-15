Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::Environment::OperatorNew(
        Scaleform::GFx::AS2::Environment *this,
        const Scaleform::GFx::AS2::FunctionRef *constructor,
        int nargs,
        int argsTopOff)
{
  int v5; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // ecx
  int v7; // edx
  Scaleform::GFx::ASStringNode *pStringNode; // ecx
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
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::Object *v21; // ebp
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  int v23; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v24; // ecx
  int v25; // edx
  Scaleform::GFx::ASStringNode *v26; // ecx
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
  char v38; // bl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v39; // ecx
  int v40; // eax
  Scaleform::GFx::ASStringNode *v41; // ecx
  int v42; // eax
  int v43; // eax
  Scaleform::GFx::AS2::ObjectInterface *v44; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  char v47; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v49; // ecx
  int v50; // eax
  char v51; // [esp+27h] [ebp-7Dh]
  char v52; // [esp+27h] [ebp-7Dh]
  Scaleform::GFx::ASString v53; // [esp+28h] [ebp-7Ch] BYREF
  Scaleform::GFx::ASString v54; // [esp+2Ch] [ebp-78h] BYREF
  Scaleform::GFx::AS2::Value result; // [esp+30h] [ebp-74h] BYREF
  Scaleform::GFx::AS2::Value v56; // [esp+40h] [ebp-64h] BYREF
  Scaleform::GFx::AS2::Value v57; // [esp+50h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value v58; // [esp+60h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value v59; // [esp+70h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall v60; // [esp+80h] [ebp-24h] BYREF

  v53.pNode = 0;
  if ( argsTopOff < 0 )
    argsTopOff = this->Stack.pCurrent - this->Stack.pPageStart + 32 * this->Stack.Pages.Data.Size - 32;
  if ( nargs != 1
    || (v53.pNode = (Scaleform::GFx::ASStringNode *)1,
        v51 = 1,
        constructor->Function != Scaleform::GFx::AS2::Environment::GetConstructor(
                                   this,
                                   (Scaleform::GFx::AS2::FunctionRef *)&result,
                                   ASBuiltin_Object)->Function) )
  {
    v51 = 0;
  }
  if ( ((int)v53.pNode & 1) != 0 )
  {
    v53.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)v53.pNode & 0xFFFFFFFE);
    if ( (BYTE4(result.NV.NumberValue) & 2) == 0 )
    {
      if ( *(_DWORD *)&result.T.Type )
      {
        v5 = *(_DWORD *)(*(_DWORD *)&result.T.Type + 12);
        v6 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result.T.Type;
        if ( (v5 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(*(_DWORD *)&result.T.Type + 12) = v5 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
        }
      }
    }
    *(_DWORD *)&result.T.Type = 0;
    if ( (BYTE4(result.NV.NumberValue) & 1) == 0 )
    {
      if ( result.NV.Int32Value )
      {
        v7 = *(_DWORD *)(result.NV.Int32Value + 12);
        if ( (v7 & 0x3FFFFFF) != 0 )
        {
          pStringNode = result.V.pStringNode;
          *(_DWORD *)(result.NV.Int32Value + 12) = v7 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)pStringNode);
        }
      }
    }
  }
  if ( !v51 )
    goto LABEL_34;
  pCurrent = this->Stack.pCurrent;
  Type = pCurrent->T.Type;
  v56.T.Type = 0;
  if ( Type == 3 || Type == 4 || Type == 2 || Type == 5 )
  {
    v11 = Scaleform::GFx::AS2::Environment::PrimitiveToTempObject(this, &result, 0);
    Scaleform::GFx::AS2::Value::operator=(&v56, v11);
    if ( result.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&result);
  }
  else
  {
    if ( Type != 6 && Type != 7 )
      goto LABEL_34;
    Scaleform::GFx::AS2::Value::operator=(&v56, pCurrent);
  }
  if ( v56.T.Type && v56.T.Type != 10 )
  {
    v12 = Scaleform::GFx::AS2::Value::ToObject(&v56, this);
    v13 = v12;
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
    if ( v56.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v56);
    return v13;
  }
  if ( v56.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v56);
LABEL_34:
  pContext = this->StringContext.pContext;
  v16 = &constructor->Function->Scaleform::GFx::AS2::ObjectInterface;
  p_StringContext = &this->StringContext;
  v58.T.Type = 0;
  if ( !v16->GetMemberRaw(
          v16,
          &this->StringContext,
          (const Scaleform::GFx::ASString *)&pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
          &v58) )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_Object);
    Scaleform::GFx::AS2::Value::SetAsObject(&v58, Prototype);
  }
  v19 = Scaleform::GFx::AS2::Value::ToObject(&v58, this);
  Function = constructor->Function;
  v21 = v19;
  BYTE4(result.NV.NumberValue) = 0;
  *(_DWORD *)&result.T.Type = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  pLocalFrame = constructor->pLocalFrame;
  result.NV.Int32Value = 0;
  if ( pLocalFrame )
  {
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&result,
      pLocalFrame,
      constructor->Flags & 1);
    Function = *(Scaleform::GFx::AS2::FunctionObject **)&result.T.Type;
  }
  v57.T.Type = 0;
  if ( v21
    && v21->GetMemberRaw(
         &v21->Scaleform::GFx::AS2::ObjectInterface,
         &this->StringContext,
         (const Scaleform::GFx::ASString *)&p_StringContext->pContext->pMovieRoot->pASMovieRoot.pObject[24],
         &v57) )
  {
    if ( v57.T.Type != 8 && v57.T.Type != 11
      || (v53.pNode = (Scaleform::GFx::ASStringNode *)((unsigned int)v53.pNode | 2),
          v52 = 1,
          !Scaleform::GFx::AS2::Value::ToFunction(&v57, (Scaleform::GFx::AS2::FunctionRef *)&v56, this)->Function) )
    {
      v52 = 0;
    }
    if ( ((int)v53.pNode & 2) != 0 )
    {
      if ( (BYTE4(v56.NV.NumberValue) & 2) == 0 )
      {
        if ( *(_DWORD *)&v56.T.Type )
        {
          v23 = *(_DWORD *)(*(_DWORD *)&v56.T.Type + 12);
          v24 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v56.T.Type;
          if ( (v23 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(*(_DWORD *)&v56.T.Type + 12) = v23 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
          }
        }
      }
      *(_DWORD *)&v56.T.Type = 0;
      if ( (BYTE4(v56.NV.NumberValue) & 1) == 0 )
      {
        if ( v56.NV.Int32Value )
        {
          v25 = *(_DWORD *)(v56.NV.Int32Value + 12);
          if ( (v25 & 0x3FFFFFF) != 0 )
          {
            v26 = v56.V.pStringNode;
            *(_DWORD *)(v56.NV.Int32Value + 12) = v25 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v26);
          }
        }
      }
    }
    if ( v52 )
    {
      v27 = Scaleform::GFx::AS2::Value::ToFunction(&v57, (Scaleform::GFx::AS2::FunctionRef *)&v56, this);
      Scaleform::GFx::AS2::FunctionRefBase::Assign((Scaleform::GFx::AS2::FunctionRefBase *)&result, v27);
      if ( (BYTE4(v56.NV.NumberValue) & 2) == 0 )
      {
        if ( *(_DWORD *)&v56.T.Type )
        {
          v28 = *(_DWORD *)(*(_DWORD *)&v56.T.Type + 12);
          v29 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&v56.T.Type;
          if ( (v28 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(*(_DWORD *)&v56.T.Type + 12) = v28 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v29);
          }
        }
      }
      *(_DWORD *)&v56.T.Type = 0;
      if ( (BYTE4(v56.NV.NumberValue) & 1) == 0 )
      {
        if ( v56.NV.Int32Value )
        {
          v30 = *(_DWORD *)(v56.NV.Int32Value + 12);
          v31 = v56.V.pStringNode;
          if ( (v30 & 0x3FFFFFF) != 0 )
          {
            *(_DWORD *)(v56.NV.Int32Value + 12) = v30 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v31);
          }
        }
      }
      Function = *(Scaleform::GFx::AS2::FunctionObject **)&result.T.Type;
    }
  }
  v32 = (int)Function->CreateNewObject(Function, this);
  v33 = v32;
  if ( v32 )
  {
    v34 = (void (__thiscall **)(int, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(*(_DWORD *)(v32 + 16) + 52);
    v35 = Scaleform::GFx::AS2::Value::ToObject(&v58, this);
    (*v34)(v33 + 16, &this->StringContext, v35);
    Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
      (Scaleform::GFx::AS2::ObjectInterface *)(v33 + 16),
      &this->StringContext,
      constructor);
    v60.Result = &v59;
    memset(&v60.ThisFunctionRef, 0, 9);
    v36 = constructor->pLocalFrame;
    v60.FirstArgBottomIndex = argsTopOff;
    v37 = constructor->Function;
    v60.NArgs = nargs;
    v59.T.Type = 0;
    v60.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    v60.ThisPtr = (Scaleform::GFx::AS2::ObjectInterface *)(v33 + 16);
    v60.Env = this;
    v37->Invoke(v37, &v60, v36, 0);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v60);
    *(_DWORD *)(v33 + 12) = (*(_DWORD *)(v33 + 12) + 1) & 0x8FFFFFFF;
    if ( v59.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v59);
    if ( v57.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v57);
    v38 = BYTE4(result.NV.NumberValue);
    if ( (BYTE4(result.NV.NumberValue) & 2) == 0 )
    {
      v39 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)&result.T.Type;
      v40 = *(_DWORD *)(*(_DWORD *)&result.T.Type + 12);
      if ( (v40 & 0x3FFFFFF) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)&result.T.Type + 12) = v40 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v39);
      }
    }
    if ( (v38 & 1) == 0 )
    {
      v41 = result.V.pStringNode;
      if ( result.NV.Int32Value )
      {
        v42 = *(_DWORD *)(result.NV.Int32Value + 12);
        if ( (v42 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(result.NV.Int32Value + 12) = v42 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v41);
        }
      }
    }
    if ( v58.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v58);
    v43 = *(_DWORD *)(v33 + 12);
    if ( (v43 & 0x3FFFFFF) != 0 )
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
    Scaleform::GFx::AS2::GlobalContext::FindClassName(p_StringContext->pContext, &v54, this, v44);
    Scaleform::GFx::AS2::GlobalContext::FindClassName(
      p_StringContext->pContext,
      &v53,
      this,
      &Function->Scaleform::GFx::AS2::ObjectInterface);
    Scaleform::GFx::AS2::Environment::LogScriptError(
      this,
      "%s::CreateNewObject returned NULL during creation of %s class instance.",
      v53.pNode->pData,
      v54.pNode->pData);
    pNode = v53.pNode;
    --v53.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v46 = v54.pNode;
    --v54.pNode->RefCount;
    if ( !v46->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v46);
    if ( v57.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v57);
    v47 = BYTE4(result.NV.NumberValue);
    if ( (BYTE4(result.NV.NumberValue) & 2) == 0 )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
    if ( (v47 & 1) == 0 )
    {
      v49 = result.V.pStringNode;
      if ( result.NV.Int32Value )
      {
        v50 = *(_DWORD *)(result.NV.Int32Value + 12);
        if ( (v50 & 0x3FFFFFF) != 0 )
        {
          *(_DWORD *)(result.NV.Int32Value + 12) = v50 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v49);
        }
      }
    }
    if ( v58.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v58);
    return 0;
  }
}


Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::Environment::OperatorNew(
        Scaleform::GFx::AS2::Environment *this,
        Scaleform::GFx::AS2::Object *ppackageObj,
        const Scaleform::GFx::ASString *className,
        int nargs,
        int argsTopOff)
{
  bool (__thiscall *GetMember)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, const Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *); // eax
  const Scaleform::GFx::AS2::FunctionRef *v7; // eax
  Scaleform::GFx::AS2::Object *v8; // esi
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  Scaleform::GFx::AS2::FunctionRef result; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v15; // [esp+18h] [ebp-10h] BYREF

  GetMember = ppackageObj->GetMember;
  v15.T.Type = 0;
  if ( GetMember(&ppackageObj->Scaleform::GFx::AS2::ObjectInterface, this, className, &v15)
    && (v15.T.Type == 8 || v15.T.Type == 11) )
  {
    v7 = Scaleform::GFx::AS2::Value::ToFunction(&v15, &result, this);
    v8 = Scaleform::GFx::AS2::Environment::OperatorNew(this, v7, nargs, argsTopOff);
    if ( (result.Flags & 2) == 0 )
    {
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        Function = result.Function;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
        }
      }
    }
    result.Function = 0;
    if ( (result.Flags & 1) == 0 )
    {
      if ( result.pLocalFrame )
      {
        v11 = result.pLocalFrame->RefCount;
        pLocalFrame = result.pLocalFrame;
        if ( (v11 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v11 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    result.pLocalFrame = 0;
    if ( v15.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
    return v8;
  }
  else
  {
    if ( v15.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v15);
    return 0;
  }
}
