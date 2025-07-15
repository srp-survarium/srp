void __thiscall Scaleform::GFx::AS2::ExecutionContext::ExtendsOpCode(Scaleform::GFx::AS2::ExecutionContext *this)
{
  Scaleform::GFx::AS2::Value *pCurrent; // ecx
  Scaleform::GFx::AS2::Value *pPrevPageTop; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // ebp
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
  unsigned int v19; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v21; // eax
  unsigned __int8 v22; // bl
  Scaleform::GFx::AS2::FunctionObject *v23; // ecx
  unsigned int v24; // eax
  Scaleform::GFx::AS2::LocalFrame *v25; // ecx
  unsigned int v26; // eax
  Scaleform::GFx::AS2::FunctionRef subClassCtor; // [esp+14h] [ebp-48h] BYREF
  Scaleform::GFx::AS2::FunctionRef superClassCtor; // [esp+20h] [ebp-3Ch] BYREF
  Scaleform::GFx::AS2::Value superProtoVal; // [esp+2Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value subClassCtorVal; // [esp+3Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value superClassCtorVal; // [esp+4Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Value::Value(&superClassCtorVal, this->pEnv->Stack.pCurrent);
  pCurrent = this->pEnv->Stack.pCurrent;
  if ( pCurrent <= this->pEnv->Stack.pPageStart )
    pPrevPageTop = this->pEnv->Stack.pPrevPageTop;
  else
    pPrevPageTop = pCurrent - 1;
  Scaleform::GFx::AS2::Value::Value(&subClassCtorVal, pPrevPageTop);
  Scaleform::GFx::AS2::Value::ToFunction(&superClassCtorVal, &superClassCtor, this->pEnv);
  Scaleform::GFx::AS2::Value::ToFunction(&subClassCtorVal, &subClassCtor, this->pEnv);
  Function = subClassCtor.Function;
  if ( superClassCtor.Function && subClassCtor.Function )
  {
    pEnv = this->pEnv;
    superProtoVal.T.Type = 0;
    if ( superClassCtor.Function->GetMemberRaw(
           &superClassCtor.Function->Scaleform::GFx::AS2::ObjectInterface,
           &pEnv->StringContext,
           (const Scaleform::GFx::ASString *)&pEnv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pASSupport,
           &superProtoVal)
      && superProtoVal.T.Type == 6 )
    {
      v6 = Scaleform::GFx::AS2::Value::ToObject(&superProtoVal, this->pEnv);
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
      Scaleform::GFx::AS2::FunctionObject::SetPrototype(subClassCtor.Function, &this->pEnv->StringContext, v11);
      Scaleform::GFx::AS2::ObjectInterface::Set__constructor__(
        &v11->Scaleform::GFx::AS2::ObjectInterface,
        &this->pEnv->StringContext,
        &superClassCtor);
      if ( v11 )
      {
        RefCount = v11->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
        {
          v11->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
        }
      }
      if ( v7 )
      {
        v13 = v7->RefCount;
        if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v13) != 0 )
        {
          v7->RefCount = v13 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
        }
      }
      Function = subClassCtor.Function;
    }
    if ( superProtoVal.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&superProtoVal);
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
  Flags = subClassCtor.Flags;
  if ( (subClassCtor.Flags & 2) == 0 )
  {
    if ( Function )
    {
      v19 = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v19) != 0 )
      {
        Function->RefCount = v19 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  if ( (Flags & 1) == 0 )
  {
    pLocalFrame = subClassCtor.pLocalFrame;
    if ( subClassCtor.pLocalFrame )
    {
      v21 = subClassCtor.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v21) != 0 )
      {
        subClassCtor.pLocalFrame->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  v22 = superClassCtor.Flags;
  if ( (superClassCtor.Flags & 2) == 0 )
  {
    v23 = superClassCtor.Function;
    if ( superClassCtor.Function )
    {
      v24 = superClassCtor.Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v24) != 0 )
      {
        superClassCtor.Function->RefCount = v24 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v23);
      }
    }
  }
  if ( (v22 & 1) == 0 )
  {
    v25 = superClassCtor.pLocalFrame;
    if ( superClassCtor.pLocalFrame )
    {
      v26 = superClassCtor.pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v26) != 0 )
      {
        superClassCtor.pLocalFrame->RefCount = v26 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v25);
      }
    }
  }
  if ( subClassCtorVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&subClassCtorVal);
  if ( superClassCtorVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&superClassCtorVal);
}
