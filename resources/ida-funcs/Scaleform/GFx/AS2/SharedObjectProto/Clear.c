void __usercall Scaleform::GFx::AS2::SharedObjectProto::Clear(
        Scaleform::GFx::ASStringNode *a1@<ebx>,
        int a2@<ebp>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // edi
  Scaleform::GFx::AS2::SharedObject *p_pProto; // edi
  Scaleform::GFx::AS2::Object *pObject; // ebp
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::RefCountVImpl *v8; // ebx
  Scaleform::GFx::MovieImpl *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ebp
  unsigned int RefCount; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> pdataObj; // [esp+14h] [ebp-4h]
  Scaleform::GFx::ASStringNode *pwriter; // [esp+1Ch] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_SharedObject )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::SharedObject *)&ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        pObject = Scaleform::GFx::AS2::Environment::OperatorNew(
                    fn->Env,
                    fn->Env->StringContext.pContext->pGlobal.pObject,
                    (const Scaleform::GFx::ASString *)&fn->Env->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].pMovieImpl,
                    0,
                    -1);
        pdataObj.pObject = pObject;
        Scaleform::GFx::AS2::SharedObject::SetDataObject(p_pProto, fn->Env, pObject);
        pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
        v8 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(
                                           &pMovieImpl->Scaleform::GFx::StateBag,
                                           State_SharedObject);
        if ( v8 )
        {
          v9 = fn->Env->Target->pASRoot->pMovieImpl;
          v10 = (Scaleform::RefCountVImpl *)v9->GetStateAddRef(&v9->Scaleform::GFx::StateBag, State_FileOpener);
          pwriter = (Scaleform::GFx::ASStringNode *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *, Scaleform::RefCountVImpl *))v8->Release)(
                                                      v8,
                                                      &p_pProto->Name,
                                                      &p_pProto->LocalPath,
                                                      v10);
          if ( v10 )
            Scaleform::RefCountImpl::Release(v10);
          Scaleform::GFx::AS2::SharedObject::Flush(p_pProto, (int)v10, (int)fn, fn->Env, pwriter, a2, a1);
          if ( pwriter )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)pwriter);
          Scaleform::RefCountImpl::Release(v8);
          pObject = pdataObj.pObject;
        }
        if ( pObject )
        {
          RefCount = pObject->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            pObject->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
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
      "SharedObject");
  }
}
