void __cdecl Scaleform::GFx::AS2::BitmapDataCtorFunction::GlobalCtor(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::Object *v2; // eax
  Scaleform::GFx::AS2::BitmapData *v3; // esi
  Scaleform::GFx::AS2::Environment *Env; // edi
  unsigned int RefCount; // eax

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::Object *)pHeap->Alloc(pHeap, 60u, 0);
  v3 = (Scaleform::GFx::AS2::BitmapData *)v2;
  if ( v2 )
  {
    Env = fn->Env;
    Scaleform::GFx::AS2::Object::Object(v2, Env);
    v3->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::BitmapData_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v3->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::BitmapData::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v3->pImageRes.pObject = 0;
    v3->pMovieDef.pObject = 0;
    Scaleform::GFx::AS2::BitmapData::commonInit(v3, Env);
  }
  else
  {
    v3 = 0;
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v3);
  if ( v3 )
  {
    RefCount = v3->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v3->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v3);
    }
  }
}
