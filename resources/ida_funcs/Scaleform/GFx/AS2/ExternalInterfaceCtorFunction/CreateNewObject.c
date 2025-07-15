Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::ExternalInterfaceCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::ExternalInterfaceCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // edi
  Scaleform::GFx::AS2::Object *v3; // eax
  Scaleform::GFx::AS2::Object *v4; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax

  p_StringContext = &penv->StringContext;
  v3 = (Scaleform::GFx::AS2::Object *)penv->StringContext.pContext->pHeap->Alloc(
                                        penv->StringContext.pContext->pHeap,
                                        52,
                                        0);
  v4 = v3;
  if ( !v3 )
    return 0;
  Scaleform::GFx::AS2::Object::Object(v3, penv);
  v4->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v4->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StageObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_ExternalInterface);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&v4->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    Prototype);
  return v4;
}
