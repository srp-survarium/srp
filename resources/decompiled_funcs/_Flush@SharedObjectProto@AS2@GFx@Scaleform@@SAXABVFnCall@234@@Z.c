void __usercall Scaleform::GFx::AS2::SharedObjectProto::Flush(
        Scaleform::GFx::ASStringNode *a1@<edi>,
        int a2@<esi>,
        const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // ebx
  Scaleform::GFx::AS2::SharedObject *p_pProto; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::RefCountVImpl *v7; // edi
  Scaleform::GFx::MovieImpl *v8; // ecx
  Scaleform::RefCountVImpl *v9; // esi
  Scaleform::GFx::ASStringNode *pwriter; // [esp+14h] [ebp+4h]

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_SharedObject )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::GFx::AS2::SharedObject *)&ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
        v7 = (Scaleform::RefCountVImpl *)pMovieImpl->GetStateAddRef(
                                           &pMovieImpl->Scaleform::GFx::StateBag,
                                           State_SharedObject);
        if ( v7 )
        {
          v8 = fn->Env->Target->pASRoot->pMovieImpl;
          v9 = (Scaleform::RefCountVImpl *)v8->GetStateAddRef(&v8->Scaleform::GFx::StateBag, State_FileOpener);
          pwriter = (Scaleform::GFx::ASStringNode *)((int (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::String *, Scaleform::String *, Scaleform::RefCountVImpl *))v7->Release)(
                                                      v7,
                                                      &p_pProto->Name,
                                                      &p_pProto->LocalPath,
                                                      v9);
          if ( v9 )
            Scaleform::RefCountImpl::Release(v9);
          Scaleform::GFx::AS2::SharedObject::Flush(p_pProto, (int)fn, (int)v9, fn->Env, pwriter, a2, a1);
          if ( pwriter )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)pwriter);
          Scaleform::RefCountImpl::Release(v7);
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
