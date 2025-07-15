void __cdecl Scaleform::GFx::AS2::ColorMatrixFilterProto::Clone(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_pProto; // edi
  Scaleform::GFx::AS2::Object *v3; // eax
  Scaleform::GFx::Resource *pObject; // edi
  Scaleform::GFx::AS2::Object *v5; // esi
  Scaleform::RefCountVImpl *v6; // ecx
  unsigned int RefCount; // eax

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_ColorMatrixFilter )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = &ThisPtr[-2].pProto;
      if ( ThisPtr != (Scaleform::GFx::AS2::ObjectInterface *)16 )
      {
        v3 = Scaleform::GFx::AS2::Environment::OperatorNew(
               fn->Env,
               fn->Env->StringContext.pContext->FlashFiltersPackage,
               (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[16].pASSupport,
               0,
               -1);
        pObject = (Scaleform::GFx::Resource *)p_pProto[13].pObject;
        v5 = v3;
        if ( pObject )
          Scaleform::RefCountImpl::AddRef(pObject);
        v6 = (Scaleform::RefCountVImpl *)v5[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
        if ( v6 )
          Scaleform::RefCountImpl::Release(v6);
        v5[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)pObject;
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
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
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "ColorMatrixFilter");
  }
}
