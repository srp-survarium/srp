char __cdecl Scaleform::GFx::AS2::GAS_Invoke(
        Scaleform::GFx::AS2::Value *method,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv,
        int nargs,
        int firstArgBottomIndex,
        const char *pmethodName)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // edi
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  unsigned int v11; // eax
  const char *v13; // edi
  Scaleform::GFx::DisplayObject *v14; // eax
  Scaleform::GFx::CharacterHandle *pObject; // eax
  const char *v16; // eax
  Scaleform::GFx::AS2::LocalFrame *v17; // ecx
  unsigned int v18; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FnCall v20; // [esp+18h] [ebp-24h] BYREF

  Scaleform::GFx::AS2::Value::ToFunction(method, &result, penv);
  if ( presult )
  {
    Scaleform::GFx::AS2::Value::DropRefs(presult);
    presult->T.Type = 0;
  }
  Function = result.Function;
  if ( result.Function )
  {
    v20.FirstArgBottomIndex = firstArgBottomIndex;
    v20.Result = presult;
    pLocalFrame = result.pLocalFrame;
    v20.ThisPtr = pthis;
    v20.NArgs = nargs;
    v20.__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
    memset(&v20.ThisFunctionRef, 0, 9);
    v20.Env = penv;
    result.Function->Invoke(result.Function, &v20, result.pLocalFrame, pmethodName);
    Scaleform::GFx::AS2::FnCall::~FnCall(&v20);
    Flags = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
    if ( (Flags & 1) == 0 && pLocalFrame )
    {
      v11 = pLocalFrame->RefCount;
      if ( (v11 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
    return 1;
  }
  else
  {
    if ( penv && penv->IsVerboseActionErrors(penv) )
    {
      if ( pthis && (unsigned int)(pthis->GetObjectType(pthis) - 2) <= 3 )
      {
        v13 = pmethodName;
        if ( !pmethodName )
          v13 = "<unknown>";
        v14 = (Scaleform::GFx::DisplayObject *)Scaleform::GFx::AS2::ObjectInterface::ToCharacter(pthis);
        if ( v14->pNameHandle.pObject )
          pObject = v14->pNameHandle.pObject;
        else
          pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v14);
        Scaleform::GFx::AS2::Environment::LogScriptError(
          penv,
          "Invoked method %s.%s is not a function",
          pObject->NamePath.pNode->pData,
          v13);
      }
      else
      {
        v16 = pmethodName;
        if ( !pmethodName )
          v16 = "<unknown>";
        Scaleform::GFx::AS2::Environment::LogScriptError(penv, "Invoked method %s is not a function", v16);
      }
    }
    if ( (result.Flags & 1) == 0 )
    {
      v17 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v18 = result.pLocalFrame->RefCount;
        if ( (v18 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v18 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v17);
        }
      }
    }
    return 0;
  }
}


bool __cdecl Scaleform::GFx::AS2::GAS_Invoke(
        Scaleform::GFx::ASStringNode *pmethodName,
        Scaleform::GFx::AS2::Value *presult,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::Environment *penv,
        int numArgs,
        int firstArgBottomIndex)
{
  const char *v6; // ebp
  Scaleform::GFx::AS2::Environment *v7; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  bool v9; // zf
  Scaleform::GFx::ASStringNode *v10; // eax
  bool v11; // bl
  Scaleform::GFx::AS2::ObjectInterface *v12; // edi
  Scaleform::GFx::DisplayObject *v13; // eax
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  Scaleform::GFx::AS2::ObjectInterface *v17; // edi
  Scaleform::GFx::DisplayObject *v18; // eax
  Scaleform::GFx::CharacterHandle *CharacterHandle; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int RefCount; // eax
  int v22; // eax
  Scaleform::GFx::AS2::ObjectInterface *v23; // eax
  char v24; // al
  unsigned __int8 Flags; // bl
  unsigned int v26; // eax
  Scaleform::GFx::AS2::LocalFrame *v27; // ecx
  unsigned int v28; // eax
  __int64 v29; // [esp-20h] [ebp-54h]
  __int64 v30; // [esp-18h] [ebp-4Ch]
  int v31; // [esp+4h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::FunctionRef result; // [esp+8h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value v33; // [esp+14h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v34; // [esp+24h] [ebp-10h] BYREF

  v6 = (const char *)pmethodName;
  if ( !pmethodName || !LOBYTE(pmethodName->pData) )
    return 0;
  v7 = penv;
  pContext = penv->StringContext.pContext;
  v31 = 0;
  v34.T.Type = 0;
  v33.T.Type = 0;
  pmethodName = Scaleform::GFx::ASStringManager::CreateStringNode(
                  (Scaleform::GFx::ASStringManager *)pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                  (__m128i *)pmethodName);
  ++pmethodName->RefCount;
  HIDWORD(v30) = &v31;
  LODWORD(v30) = 0;
  HIDWORD(v29) = &v34;
  LODWORD(v29) = &pmethodName;
  v9 = !Scaleform::GFx::AS2::Environment::GetVariable(v7, v29, v30, &v33, 0);
  v10 = pmethodName;
  v11 = v9;
  --pmethodName->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v11 )
  {
    v12 = pthis;
    if ( pthis && (unsigned int)(pthis->GetObjectType(pthis) - 2) <= 3 )
    {
      v13 = (Scaleform::GFx::DisplayObject *)Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v12);
      if ( v13->pNameHandle.pObject )
        pObject = v13->pNameHandle.pObject;
      else
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v13);
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v7,
        "Can't find method '%s.%s' to invoke.",
        pObject->NamePath.pNode->pData,
        v6);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(v7, "Can't find method '%s' to invoke.", v6);
    }
LABEL_12:
    if ( v33.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v33);
    if ( v34.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v34);
    return 0;
  }
  Scaleform::GFx::AS2::Value::ToFunction(&v34, &result, v7);
  Function = result.Function;
  if ( !result.Function )
  {
    v17 = pthis;
    if ( pthis && (unsigned int)(pthis->GetObjectType(pthis) - 2) <= 3 )
    {
      v18 = (Scaleform::GFx::DisplayObject *)Scaleform::GFx::AS2::ObjectInterface::ToCharacter(v17);
      if ( v18->pNameHandle.pObject )
        CharacterHandle = v18->pNameHandle.pObject;
      else
        CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v18);
      Scaleform::GFx::AS2::Environment::LogScriptError(
        v7,
        "Invoked method '%s.%s' is not a function",
        CharacterHandle->NamePath.pNode->pData,
        v6);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(v7, "Invoked method '%s' is not a function", v6);
    }
    if ( (result.Flags & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        RefCount = result.pLocalFrame->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    goto LABEL_12;
  }
  if ( v33.T.Type == 7 || v33.T.Type == 6 )
  {
    v23 = Scaleform::GFx::AS2::Value::ToObjectInterface(&v33, v7);
  }
  else if ( v31 )
  {
    v22 = (*(int (__thiscall **)(int))(*(_DWORD *)(v31 + 4 * *(unsigned __int8 *)(v31 + 65)) + 4))(v31 + 4 * *(unsigned __int8 *)(v31 + 65));
    if ( v22 )
      v23 = (Scaleform::GFx::AS2::ObjectInterface *)(v22 + 4);
    else
      v23 = 0;
  }
  else
  {
    v23 = pthis;
  }
  v24 = Scaleform::GFx::AS2::GAS_Invoke(&v34, presult, v23, v7, numArgs, firstArgBottomIndex, v6);
  Flags = result.Flags;
  LOBYTE(pmethodName) = v24;
  if ( (result.Flags & 2) == 0 )
  {
    v26 = Function->RefCount;
    if ( (v26 & 0x3FFFFFF) != 0 )
    {
      Function->RefCount = v26 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
    }
  }
  if ( (Flags & 1) == 0 )
  {
    v27 = result.pLocalFrame;
    if ( result.pLocalFrame )
    {
      v28 = result.pLocalFrame->RefCount;
      if ( (v28 & 0x3FFFFFF) != 0 )
      {
        result.pLocalFrame->RefCount = v28 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v27);
      }
    }
  }
  if ( v33.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v33);
  if ( v34.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v34);
  return (char)pmethodName;
}
