void __thiscall Scaleform::GFx::AS2::ExecutionContext::InstanceOfOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // esi
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  Scaleform::GFx::AS2::AvmCharacter *v6; // eax
  Scaleform::GFx::AS2::ObjectInterface *v7; // esi
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Environment *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // eax
  unsigned __int8 Flags; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::Value *v15; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  int v17; // edi
  Scaleform::GFx::AS2::Environment *v18; // esi
  Scaleform::GFx::AS2::Value *v19; // eax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v20; // esi
  Scaleform::GFx::AS2::Value *v21; // esi
  Scaleform::GFx::AS2::Environment *v22; // [esp+2h] [ebp-38h]
  bool rv; // [esp+19h] [ebp-21h]
  Scaleform::GFx::AS2::FunctionRef ctorFunc; // [esp+1Eh] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value prototypeVal; // [esp+2Ah] [ebp-10h] BYREF

  pEnv = this->pEnv;
  pCurrent = this->pEnv->Stack.pCurrent;
  pPrevPageTop = pCurrent - 1;
  if ( pCurrent <= pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  rv = 0;
  if ( pCurrent->T.Type == 8 || pCurrent->T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(pCurrent, &ctorFunc, pEnv);
    Function = ctorFunc.Function;
    if ( ctorFunc.Function )
    {
      v22 = this->pEnv;
      if ( pPrevPageTop->T.Type == 7 )
      {
        v6 = Scaleform::GFx::AS2::Value::ToAvmCharacter(pPrevPageTop, v22);
        if ( v6 )
        {
          v7 = &v6->Scaleform::GFx::AS2::ObjectInterface;
          goto LABEL_11;
        }
      }
      else
      {
        v8 = Scaleform::GFx::AS2::Value::ToObject(pPrevPageTop, v22);
        if ( v8 )
        {
          v7 = &v8->Scaleform::GFx::AS2::ObjectInterface;
LABEL_11:
          if ( v7 )
          {
            v9 = this->pEnv;
            prototypeVal.T.Type = 0;
            if ( Function->GetMemberRaw(
                   &Function->Scaleform::GFx::AS2::ObjectInterface,
                   &v9->StringContext,
                   (const Scaleform::GFx::ASString *)&v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
                   &prototypeVal) )
            {
              v10 = Scaleform::GFx::AS2::Value::ToObject(&prototypeVal, this->pEnv);
              rv = v7->InstanceOf(v7, this->pEnv, v10, 1);
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
        v14 = ctorFunc.pLocalFrame->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v14) != 0 )
        {
          ctorFunc.pLocalFrame->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
  }
  v15 = this->pEnv->Stack.pCurrent;
  p_Stack = &this->pEnv->Stack;
  if ( &v15[-2] >= this->pEnv->Stack.pPageStart )
  {
    if ( v15->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v15);
    --p_Stack->pCurrent;
    if ( p_Stack->pCurrent->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
    --p_Stack->pCurrent;
  }
  else
  {
    v17 = 2;
    do
    {
      if ( p_Stack->pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
      if ( --p_Stack->pCurrent < p_Stack->pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
      --v17;
    }
    while ( v17 );
  }
  v18 = this->pEnv;
  v19 = ++v18->Stack.pCurrent;
  v20 = &v18->Stack;
  if ( v19 >= v20->pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v20);
  v21 = v20->pCurrent;
  if ( v21 )
  {
    v21->T.Type = 2;
    v21->V.BooleanValue = rv;
  }
}
