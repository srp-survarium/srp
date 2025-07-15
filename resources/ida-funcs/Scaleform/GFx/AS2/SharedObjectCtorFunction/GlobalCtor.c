void __cdecl Scaleform::GFx::AS2::SharedObjectCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::SharedObject *v2; // eax
  Scaleform::GFx::AS2::Object *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // esi
  unsigned int RefCount; // eax

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::SharedObject *)pHeap->Alloc(pHeap, 60u, 0);
  if ( v2 )
  {
    Scaleform::GFx::AS2::SharedObject::SharedObject(v2, fn->Env);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
}
