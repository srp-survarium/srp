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
  bool v23; // [esp+19h] [ebp-21h]
  Scaleform::GFx::AS2::FunctionRef result; // [esp+1Eh] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v25; // [esp+2Ah] [ebp-10h] BYREF

  pEnv = this->pEnv;
  pCurrent = this->pEnv->Stack.pCurrent;
  pPrevPageTop = pCurrent - 1;
  if ( pCurrent <= pEnv->Stack.pPageStart )
    pPrevPageTop = pEnv->Stack.pPrevPageTop;
  v23 = 0;
  if ( pCurrent->T.Type == 8 || pCurrent->T.Type == 11 )
  {
    Scaleform::GFx::AS2::Value::ToFunction(pCurrent, &result, pEnv);
    Function = result.Function;
    if ( result.Function )
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
            v25.T.Type = 0;
            if ( Function->GetMemberRaw(
                   &Function->Scaleform::GFx::AS2::ObjectInterface,
                   &v9->StringContext,
                   (const Scaleform::GFx::ASString *)&v9->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
                   &v25) )
            {
              v10 = Scaleform::GFx::AS2::Value::ToObject(&v25, this->pEnv);
              v23 = v7->InstanceOf(v7, this->pEnv, v10, 1);
            }
            else if ( (*((_BYTE *)this + 54) & 1) != 0 )
            {
              Scaleform::GFx::AS2::ActionLogger::LogScriptError(
                &this->LogF,
                "The constructor function in InstanceOf should have 'prototype'.");
            }
            if ( v25.T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(&v25);
          }
        }
      }
    }
    Flags = result.Flags;
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
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v14 = result.pLocalFrame->RefCount;
        if ( (v14 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
    goto LABEL_28;
  }
  if ( (*((_BYTE *)this + 54) & 1) != 0 )
    Scaleform::GFx::AS2::ActionLogger::LogScriptError(&this->LogF, "The parameter of InstanceOf should be a function.");
LABEL_28:
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
    v21->V.BooleanValue = v23;
  }
}
