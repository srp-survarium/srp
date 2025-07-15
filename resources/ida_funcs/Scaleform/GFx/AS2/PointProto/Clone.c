void __cdecl Scaleform::GFx::AS2::PointProto::Clone(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::PointObject *p_pProto; // ebx
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::PointObject *v4; // eax
  Scaleform::GFx::AS2::PointObject *v5; // eax
  Scaleform::GFx::AS2::PointObject *v6; // ebp
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::Value *v8; // esi
  int i; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value params[2]; // [esp+8h] [ebp-20h] BYREF
  _UNKNOWN *retaddr; // [esp+28h] [ebp+0h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Point )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      p_pProto = (Scaleform::GFx::AS2::PointObject *)&ThisPtr[-2].pProto;
    else
      p_pProto = 0;
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v4 = (Scaleform::GFx::AS2::PointObject *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v4 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v4, fn->Env);
      v6 = v5;
    }
    else
    {
      v6 = 0;
    }
    p_StringContext = &fn->Env->StringContext;
    params[0].T.Type = 0;
    params[1].T.Type = 0;
    Scaleform::GFx::AS2::PointObject::GetProperties(p_pProto, p_StringContext, params);
    Scaleform::GFx::AS2::PointObject::SetProperties(v6, p_StringContext, params);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
    v8 = (Scaleform::GFx::AS2::Value *)&retaddr;
    for ( i = 1; i >= 0; --i )
    {
      --v8;
      if ( v8->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v8);
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
      "Point");
  }
}
