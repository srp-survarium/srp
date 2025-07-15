void __cdecl Scaleform::GFx::AS2::RectangleCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::RectangleObject *v4; // eax
  Scaleform::GFx::AS2::RectangleObject *v5; // ebp
  Scaleform::GFx::AS2::Environment *Env; // eax
  unsigned int FirstArgBottomIndex; // ecx
  unsigned int Size; // ebx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // eax
  const Scaleform::GFx::AS2::Value *v10; // edx
  int v11; // edi
  const Scaleform::GFx::AS2::Value *v12; // eax
  const Scaleform::GFx::AS2::Value *v13; // eax
  const Scaleform::GFx::AS2::Value *v14; // eax
  Scaleform::GFx::AS2::Value *v15; // esi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v17; // [esp+Ch] [ebp-40h] BYREF
  Scaleform::GFx::AS2::Value v18; // [esp+1Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v19; // [esp+2Ch] [ebp-20h] BYREF
  Scaleform::GFx::AS2::Value v20; // [esp+3Ch] [ebp-10h] BYREF
  _UNKNOWN *retaddr; // [esp+4Ch] [ebp+0h] BYREF

  if ( !fn->ThisPtr
    || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Rectangle
    || fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v4 = (Scaleform::GFx::AS2::RectangleObject *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v4 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v4, fn->Env);
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
  v5 = (Scaleform::GFx::AS2::RectangleObject *)p_pProto;
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v17.T.Type = 0;
    v18.T.Type = 0;
    v19.T.Type = 0;
    v20.T.Type = 0;
    Size = Env->Stack.Pages.Data.Size;
    p_Stack = &Env->Stack;
    v10 = 0;
    if ( FirstArgBottomIndex <= 32 * (Size - 1) + p_Stack->pCurrent - p_Stack->pPageStart )
      v10 = &p_Stack->Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    Scaleform::GFx::AS2::Value::operator=(&v17, v10);
    v11 = 3;
    if ( fn->NArgs > 1 )
    {
      v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      Scaleform::GFx::AS2::Value::operator=(&v18, v12);
      if ( fn->NArgs > 2 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        Scaleform::GFx::AS2::Value::operator=(&v19, v13);
        if ( fn->NArgs > 3 )
        {
          v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 3);
          Scaleform::GFx::AS2::Value::operator=(&v20, v14);
        }
      }
    }
    Scaleform::GFx::AS2::RectangleObject::SetProperties(
      v5,
      (Scaleform::GFx::ASStringNode *)&fn->Env->StringContext,
      &v17);
    v15 = (Scaleform::GFx::AS2::Value *)&retaddr;
    do
    {
      --v15;
      if ( v15->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v15);
      --v11;
    }
    while ( v11 >= 0 );
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
