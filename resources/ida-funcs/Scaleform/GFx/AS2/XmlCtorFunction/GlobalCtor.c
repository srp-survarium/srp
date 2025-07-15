void __cdecl Scaleform::GFx::AS2::XmlCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::XmlObject *p_pProto; // esi
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::XmlObject *v4; // eax
  Scaleform::GFx::AS2::XmlObject *v5; // eax
  unsigned int RefCount; // eax

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_XML )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::XmlObject *)&ThisPtr[-2].pProto;
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
    v4 = (Scaleform::GFx::AS2::XmlObject *)pHeap->Alloc(pHeap, 80u, 0);
    if ( v4 )
      Scaleform::GFx::AS2::XmlObject::XmlObject(v4, fn->Env);
    else
      v5 = 0;
    p_pProto = v5;
  }
  Scaleform::GFx::AS2::XML_LoadString(fn, p_pProto);
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
