void __thiscall Scaleform::GFx::AS2::ExecutionContext::CastObjectOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // esi
  Scaleform::GFx::AS2::Value *pPrevPageTop; // ecx
  unsigned __int8 Type; // dl
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  Scaleform::GFx::AS2::AvmCharacter *v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *v8; // esi
  Scaleform::GFx::AS2::Object *v9; // eax
  Scaleform::GFx::AS2::Environment *v10; // eax
  Scaleform::GFx::AS2::Object *v11; // eax
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v15; // eax
  Scaleform::GFx::AS2::Value *v16; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  int v18; // edi
  Scaleform::GFx::AS2::Environment *v19; // esi
  Scaleform::GFx::AS2::Value *v20; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v21; // esi
  Scaleform::GFx::AS2::Environment *v22; // [esp-4h] [ebp-44h]
  Scaleform::GFx::AS2::FunctionRef ctorFunc; // [esp+14h] [ebp-2Ch] BYREF
  Scaleform::GFx::AS2::Value prototypeVal; // [esp+20h] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value rv; // [esp+30h] [ebp-10h] BYREF

  pEnv = this->pEnv;
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent <= this->pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  Type = pPrevPageTop->T.Type;
  rv.T.Type = 1;
  if ( Type != 8 && Type != 11 )
    goto LABEL_26;
  Scaleform::GFx::AS2::Value::ToFunction(pPrevPageTop, &ctorFunc, pEnv);
  Function = ctorFunc.Function;
  if ( ctorFunc.Function )
  {
    v22 = this->pEnv;
    if ( pCurrent->T.Type == 7 )
    {
      v7 = Scaleform::GFx::AS2::Value::ToAvmCharacter(pCurrent, v22);
      if ( v7 )
      {
        v8 = &v7->Scaleform::GFx::AS2::ObjectInterface;
        goto LABEL_12;
      }
    }
    else
    {
      v9 = Scaleform::GFx::AS2::Value::ToObject(pCurrent, v22);
      if ( v9 )
      {
        v8 = &v9->Scaleform::GFx::AS2::ObjectInterface;
LABEL_12:
        if ( v8 )
        {
          v10 = this->pEnv;
          prototypeVal.T.Type = 0;
          if ( Function->GetMemberRaw(
                 &Function->Scaleform::GFx::AS2::ObjectInterface,
                 &v10->StringContext,
                 (const Scaleform::GFx::ASString *)&v10->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
                 &prototypeVal) )
          {
            v11 = Scaleform::GFx::AS2::Value::ToObject(&prototypeVal, this->pEnv);
            if ( v8->InstanceOf(v8, this->pEnv, v11, 1) )
              Scaleform::GFx::AS2::Value::SetAsObjectInterface(&rv, v8);
          }
          if ( prototypeVal.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&prototypeVal);
        }
      }
    }
  }
  Flags = ctorFunc.Flags;
  if ( (ctorFunc.Flags & 2) == 0 )
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
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = ctorFunc.pLocalFrame;
    if ( ctorFunc.pLocalFrame )
    {
      v15 = ctorFunc.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v15) != 0 )
      {
        ctorFunc.pLocalFrame->RefCount = v15 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
LABEL_26:
  v16 = this->pEnv->Stack.pCurrent;
  p_Stack = &this->pEnv->Stack;
  if ( &v16[-2] >= this->pEnv->Stack.pPageStart )
  {
    if ( v16->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v16);
    --p_Stack->pCurrent;
    if ( p_Stack->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
    --p_Stack->pCurrent;
  }
  else
  {
    v18 = 2;
    do
    {
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      if ( --p_Stack->pCurrent < p_Stack->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
      --v18;
    }
    while ( v18 );
  }
  v19 = this->pEnv;
  v20 = ++v19->Stack.pCurrent;
  v21 = &v19->Stack;
  if ( v20 >= v21->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v21);
  if ( v21->pCurrent )
    Scaleform::GFx::AS2::Value::Value(v21->pCurrent, &rv);
  if ( rv.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&rv);
}
