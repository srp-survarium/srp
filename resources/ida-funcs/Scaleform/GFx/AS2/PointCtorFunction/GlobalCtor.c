void __cdecl Scaleform::GFx::AS2::PointCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::PointObject *v4; // eax
  Scaleform::GFx::AS2::PointObject *v5; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  unsigned int FirstArgBottomIndex; // ecx
  int v8; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // eax
  const Scaleform::GFx::AS2::Value *v10; // edx
  const Scaleform::GFx::AS2::Value *v11; // eax
  Scaleform::GFx::AS2::Value *v12; // esi
  int i; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value params; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v16; // [esp+1Ch] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+2Ch] [ebp+0h] BYREF

  if ( !fn->ThisPtr
    || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Point
    || fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v4 = (Scaleform::GFx::AS2::PointObject *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v4 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v4, fn->Env);
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  ThisPtr = fn->ThisPtr;
  if ( !ThisPtr )
  {
LABEL_9:
    p_pProto = 0;
    goto LABEL_10;
  }
  p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
  if ( p_pProto )
    p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
LABEL_10:
  v5 = (Scaleform::GFx::AS2::PointObject *)p_pProto;
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    params.T.Type = 0;
    v16.T.Type = 0;
    v8 = (char *)Env->Stack.pCurrent - (char *)Env->Stack.pPageStart;
    p_Stack = &Env->Stack;
    v10 = 0;
    if ( FirstArgBottomIndex <= 32 * (p_Stack->Pages.Data.Size - 1) + (v8 >> 4) )
      v10 = &p_Stack->Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::operator=(&params, v10);
    if ( fn->NArgs > 1 )
    {
      v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      Scaleform::GFx::AS2::Value::operator=(&v16, v11);
    }
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, &fn->Env->StringContext, &params);
    v12 = (Scaleform::GFx::AS2::Value *)&retaddr;
    for ( i = 1; i >= 0; --i )
    {
      --v12;
      if ( v12->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v12);
    }
  }
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}
