void __thiscall Scaleform::GFx::AS2::ExecutionContext::ExtendsOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // ebx
  Scaleform::GFx::AS2::Environment *pEnv; // eax
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::ObjectProto *v9; // eax
  Scaleform::GFx::AS2::Object *v10; // eax
  Scaleform::GFx::AS2::Object *v11; // edi
  unsigned int RefCount; // eax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Environment *v14; // esi
  Scaleform::GFx::AS2::Value *v15; // ecx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // esi
  int v17; // edi
  unsigned __int8 Flags; // bl
  Scaleform::GFx::AS2::FunctionObject *v19; // ecx
  unsigned int v20; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v22; // eax
  unsigned __int8 v23; // bl
  Scaleform::GFx::AS2::FunctionObject *v24; // ecx
  unsigned int v25; // eax
  Scaleform::GFx::AS2::LocalFrame *v26; // ecx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [esp+14h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::FunctionRef v29; // [esp+20h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::Value v30; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v31; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v32; // [esp+4Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Value::Value(&v32, this->pEnv->Stack.pCurrent);
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent <= this->pEnv->Stack.pPageStart )
    pPrevPageTop = this->pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  Scaleform::GFx::AS2::Value::Value(&v31, pPrevPageTop);
  Scaleform::GFx::AS2::Value::ToFunction(&v32, &result, this->pEnv);
  Scaleform::GFx::AS2::Value::ToFunction(&v31, &v29, this->pEnv);
  if ( result.Function && (Function = v29.Function) != 0 )
  {
    pEnv = this->pEnv;
    v30.T.Type = 0;
    if ( result.Function->GetMemberRaw(
           &result.Function->Scaleform::GFx::AS2::ObjectInterface,
           &pEnv->StringContext,
           (const Scaleform::GFx::ASString *)&pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
           &v30)
      && v30.T.Type == 6 )
    {
      v6 = Scaleform::GFx::AS2::Value::ToObject(&v30, this->pEnv);
      v7 = v6;
      if ( v6 )
        v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
      pHeap = this->pEnv->StringContext.pContext->pHeap;
      v9 = (Scaleform::GFx::AS2::ObjectProto *)pHeap->Alloc(pHeap, 84u, 0);
      if ( v9 )
      {
        Scaleform::GFx::AS2::ObjectProto::ObjectProto(v9, &this->pEnv->StringContext, v7);
        v11 = v10;
      }
      else
      {
        v11 = 0;
      }
      Scaleform::GFx::AS2::FunctionObject::SetPrototype(Function, &this->pEnv->StringContext, v11);
      Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
        &v11->Scaleform::GFx::AS2::ObjectInterface,
        &this->pEnv->StringContext,
        &result);
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      if ( v7 )
      {
        v13 = v7->RefCount;
        if ( (v13 & 0x3FFFFFF) != 0 )
        {
          v7->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
    }
    else if ( (*((_BYTE *)this + 54) & 1) != 0 )
    {
      Scaleform::GFx::AS2::ActionLogger::LogScriptError(&this->LogF, "can't extend by the class w/o prototype.");
    }
    if ( v30.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v30);
  }
  else if ( (*((_BYTE *)this + 54) & 1) != 0 )
  {
    if ( result.Function )
      Scaleform::GFx::AS2::ActionLogger::LogScriptError(&this->LogF, "Can't extend the unknown class.");
    else
      Scaleform::GFx::AS2::ActionLogger::LogScriptError(&this->LogF, "Can't extend with unknown super class.");
  }
  v14 = this->pEnv;
  v15 = v14->Stack.pCurrent;
  p_Stack = &v14->Stack;
  if ( &v15[-2] >= p_Stack->pPageStart )
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
  Flags = v29.Flags;
  if ( (v29.Flags & 2) == 0 )
  {
    v19 = v29.Function;
    if ( v29.Function )
    {
      v20 = v29.Function->RefCount;
      if ( (v20 & 0x3FFFFFF) != 0 )
      {
        v29.Function->RefCount = v20 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v19);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = v29.pLocalFrame;
    if ( v29.pLocalFrame )
    {
      v22 = v29.pLocalFrame->RefCount;
      if ( (v22 & 0x3FFFFFF) != 0 )
      {
        v29.pLocalFrame->RefCount = v22 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  v23 = result.Flags;
  if ( (result.Flags & 2) == 0 )
  {
    v24 = result.Function;
    if ( result.Function )
    {
      v25 = result.Function->RefCount;
      if ( (v25 & 0x3FFFFFF) != 0 )
      {
        result.Function->RefCount = v25 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
      }
    }
  }
  if ( (v23 & 1) == 0 )
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
  if ( v31.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v31);
  if ( v32.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v32);
}
