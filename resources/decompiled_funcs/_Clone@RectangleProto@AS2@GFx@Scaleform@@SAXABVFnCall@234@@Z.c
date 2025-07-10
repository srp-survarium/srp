void __cdecl Scaleform::GFx::AS2::RectangleProto::Clone(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // ebp
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::RectangleObject *v4; // eax
  Scaleform::GFx::AS2::RectangleObject *v5; // eax
  Scaleform::GFx::AS2::RectangleObject *v6; // edi
  Scaleform::GFx::AS2::Value *v7; // esi
  int i; // ebp
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // [esp-10h] [ebp-58h]
  Scaleform::GFx::AS2::Value params[4]; // [esp+8h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+48h] [ebp+0h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Rectangle )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v4 = (Scaleform::GFx::AS2::RectangleObject *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v4 )
    {
      Scaleform::GFx::AS2::RectangleObject::RectangleObject(v4, fn->Env);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    p_StringContext = &fn->Env->StringContext;
    params[0].T.Type = 0;
    params[1].T.Type = 0;
    params[2].T.Type = 0;
    params[3].T.Type = 0;
    Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, p_StringContext, params);
    Scaleform::GFx::AS2::RectangleObject::SetProperties(v6, &fn->Env->StringContext, params);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
    v7 = (Scaleform::GFx::AS2::Value *)&retaddr;
    for ( i = 3; i >= 0; --i )
    {
      --v7;
      if ( v7->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v7);
    }
    if ( v6 )
    {
      RefCount = v6->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v6->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Rectangle");
  }
}
