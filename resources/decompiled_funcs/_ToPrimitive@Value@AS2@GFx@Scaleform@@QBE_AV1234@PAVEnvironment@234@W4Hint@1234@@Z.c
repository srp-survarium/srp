Scaleform::GFx::AS2::Value *__thiscall Scaleform::GFx::AS2::Value::ToPrimitive(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Value *result,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value::Hint __formal)
{
  unsigned __int8 Type; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // esi
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::LocalFrame *v12; // ecx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // esi
  Scaleform::GFx::AS2::AvmCharacter *v15; // eax
  Scaleform::GFx::AS2::ObjectInterface *v16; // ebx
  Scaleform::GFx::AS2::Object *v17; // eax
  unsigned __int16 FuncCallNestingLevel; // ax
  Scaleform::GFx::AS2::FunctionObject *v19; // edi
  Scaleform::GFx::AS2::LocalFrame *v20; // ebp
  unsigned __int8 v21; // bl
  unsigned int v22; // eax
  unsigned int v23; // eax
  Scaleform::GFx::AS2::Value *v24; // esi
  Scaleform::GFx::AS2::Value *p_resulta; // ecx
  Scaleform::GFx::AS2::LocalFrame *pNode; // eax
  char *v27; // eax
  Scaleform::GFx::AS2::LocalFrame *StringNode; // eax
  bool v29; // zf
  Scaleform::GFx::AS2::LocalFrame *v30; // ecx
  Scaleform::GFx::AS2::FunctionRef funcRef; // [esp+10h] [ebp-54h] BYREF
  Scaleform::GFx::AS2::Value toValueFunc; // [esp+20h] [ebp-44h] BYREF
  Scaleform::GFx::AS2::Value resulta; // [esp+30h] [ebp-34h] BYREF
  Scaleform::GFx::AS2::FnCall fnCall; // [esp+40h] [ebp-24h] BYREF

  Type = this->T.Type;
  if ( this->T.Type != 6 && Type != 7 && Type != 8 )
  {
    if ( Type == 11 )
    {
      Scaleform::GFx::AS2::Value::ResolveFunctionName(this, &funcRef, penv);
      Function = funcRef.Function;
      if ( funcRef.Function )
      {
        Scaleform::GFx::AS2::Value::Value(result, &funcRef);
        Flags = funcRef.Flags;
        if ( (funcRef.Flags & 2) == 0 )
        {
          RefCount = Function->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
        if ( (Flags & 1) == 0 )
        {
          pLocalFrame = funcRef.pLocalFrame;
          if ( funcRef.pLocalFrame )
          {
            v10 = funcRef.pLocalFrame->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v10) != 0 )
            {
              funcRef.pLocalFrame->RefCount = v10 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
        return result;
      }
      if ( (funcRef.Flags & 1) == 0 )
      {
        v12 = funcRef.pLocalFrame;
        if ( funcRef.pLocalFrame )
        {
          v13 = funcRef.pLocalFrame->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v13) != 0 )
          {
            funcRef.pLocalFrame->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
          }
        }
      }
    }
    Scaleform::GFx::AS2::Value::Value(result, this);
    return result;
  }
  v14 = penv;
  toValueFunc.T.Type = 0;
  if ( Type != 7 )
  {
    v17 = Scaleform::GFx::AS2::Value::ToObject(this, penv);
    if ( v17 )
    {
      v16 = &v17->Scaleform::GFx::AS2::ObjectInterface;
      goto LABEL_25;
    }
LABEL_24:
    v16 = 0;
    goto LABEL_25;
  }
  v15 = Scaleform::GFx::AS2::Value::ToAvmCharacter(this, penv);
  if ( !v15 )
    goto LABEL_24;
  v16 = &v15->Scaleform::GFx::AS2::ObjectInterface;
LABEL_25:
  if ( v14
    && v16
    && v16->GetMemberRaw(
         v16,
         &v14->StringContext,
         (const Scaleform::GFx::ASString *)&v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[25].pASSupport,
         &toValueFunc) )
  {
    FuncCallNestingLevel = v14->FuncCallNestingLevel;
    resulta.T.Type = 0;
    v14->FuncCallNestingLevel = FuncCallNestingLevel + 1;
    if ( FuncCallNestingLevel < 0xFFu )
    {
      Scaleform::GFx::AS2::Value::ToFunction(&toValueFunc, &funcRef, v14);
      v19 = funcRef.Function;
      v20 = funcRef.pLocalFrame;
      if ( funcRef.Function )
      {
        Scaleform::GFx::AS2::FnCall::FnCall(&fnCall, &resulta, v16, v14, 0, 0);
        v19->Invoke(v19, &fnCall, v20, 0);
        Scaleform::GFx::AS2::FnCall::~FnCall(&fnCall);
      }
      v21 = funcRef.Flags;
      if ( (funcRef.Flags & 2) == 0 )
      {
        if ( v19 )
        {
          v22 = v19->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v22) != 0 )
          {
            v19->RefCount = v22 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v19);
          }
        }
      }
      if ( (v21 & 1) == 0 )
      {
        if ( v20 )
        {
          v23 = v20->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v23) != 0 )
          {
            v20->RefCount = v23 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v20);
          }
        }
      }
    }
    --v14->FuncCallNestingLevel;
    v24 = result;
    Scaleform::GFx::AS2::Value::Value(result, &resulta);
    if ( resulta.T.Type < 5u )
      goto LABEL_54;
    p_resulta = &resulta;
    goto LABEL_53;
  }
  if ( this->T.Type == 7 && this->NV.Int32Value )
  {
    pNode = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::GFx::AS2::Value::GetCharacterNamePath(this, v14)->pNode;
    ++pNode->RefCount;
    LOBYTE(funcRef.Function) = 5;
    funcRef.pLocalFrame = pNode;
    goto LABEL_51;
  }
  if ( this->T.Type == 6
    && this->NV.Int32Value
    && (v27 = (char *)(*(int (__thiscall **)(int, Scaleform::GFx::AS2::Environment *))(*(_DWORD *)(this->NV.Int32Value
                                                                                                 + 16)
                                                                                     + 4))(
                        this->NV.Int32Value + 16,
                        v14)) != 0 )
  {
    StringNode = (Scaleform::GFx::AS2::LocalFrame *)Scaleform::GFx::ASStringManager::CreateStringNode(
                                                      (Scaleform::GFx::ASStringManager *)v14->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl,
                                                      v27);
    ++StringNode->RefCount;
    v29 = ++StringNode->RefCount == 1;
    --StringNode->RefCount;
    LOBYTE(funcRef.Function) = 5;
    funcRef.pLocalFrame = StringNode;
    if ( !v29 )
      goto LABEL_51;
    v30 = StringNode;
  }
  else
  {
    Scaleform::GFx::AS2::Value::ToStringImpl(this, (Scaleform::GFx::ASString *)&penv, v14, -1, 0);
    v30 = (Scaleform::GFx::AS2::LocalFrame *)penv;
    ++penv->Stack.pPageEnd;
    v29 = v30->RefCount-- == 1;
    LOBYTE(funcRef.Function) = 5;
    funcRef.pLocalFrame = v30;
    if ( !v29 )
      goto LABEL_51;
  }
  Scaleform::GFx::ASStringNode::ReleaseNode((Scaleform::GFx::ASStringNode *)v30);
LABEL_51:
  v24 = result;
  Scaleform::GFx::AS2::Value::Value(result, (const Scaleform::GFx::AS2::Value *)&funcRef);
  if ( LOBYTE(funcRef.Function) >= 5u )
  {
    p_resulta = (Scaleform::GFx::AS2::Value *)&funcRef;
LABEL_53:
    Scaleform::GFx::AS2::Value::DropRefs(p_resulta);
  }
LABEL_54:
  if ( toValueFunc.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&toValueFunc);
  return v24;
}
