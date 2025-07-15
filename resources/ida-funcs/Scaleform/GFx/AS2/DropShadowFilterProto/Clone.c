void __cdecl Scaleform::GFx::AS2::DropShadowFilterProto::Clone(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebx
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // ebx
  Scaleform::GFx::AS2::Object *v3; // eax
  Scaleform::GFx::AS2::Object *pObject; // esi
  Scaleform::GFx::AS2::Object *v5; // edi
  Scaleform::MemoryHeap *v6; // eax
  Scaleform::GFx::Resource *v7; // eax
  Scaleform::GFx::Resource *v8; // esi
  Scaleform::RefCountVImpl *v9; // ecx
  unsigned int RefCount; // eax

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_DropShadowFilter )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        v3 = Scaleform::GFx::AS2::Environment::OperatorNew(
               fn->Env,
               fn->Env->StringContext.pContext->FlashFiltersPackage,
               (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[15].AVMVersion,
               0,
               -1);
        pObject = p_pProto[13].pObject;
        v5 = v3;
        v6 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, p_pProto);
        v7 = (Scaleform::GFx::Resource *)((int (__thiscall *)(Scaleform::GFx::AS2::Object *, Scaleform::MemoryHeap *))pObject->Finalize_GC)(
                                           pObject,
                                           v6);
        v8 = v7;
        if ( v7 )
          Scaleform::RefCountImpl::AddRef(v7);
        v9 = (Scaleform::RefCountVImpl *)v5[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
        if ( v9 )
          Scaleform::RefCountImpl::Release(v9);
        v5[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)v8;
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
        if ( v5 )
        {
          RefCount = v5->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v5->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
          }
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "DropShadowFilter");
  }
}
