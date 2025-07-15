void __cdecl Scaleform::GFx::AS2::StyleSheetCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::Object *p_pProto; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::StyleSheetObject *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // eax
  unsigned int RefCount; // eax

  if ( fn->ThisPtr
    && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_StyleSheet
    && !fn->ThisPtr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::Object *)&ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
        p_pProto->RefCount = (p_pProto->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      p_pProto = 0;
    }
  }
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v4 = (Scaleform::GFx::AS2::StyleSheetObject *)pHeap->Alloc(pHeap, 76u, 0);
    if ( v4 )
      Scaleform::GFx::AS2::StyleSheetObject::StyleSheetObject(v4, (int)fn, fn->Env);
    else
      v5 = 0;
    p_pProto = v5;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, p_pProto);
  if ( p_pProto )
  {
    RefCount = p_pProto->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      p_pProto->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(p_pProto);
    }
  }
}
