Scaleform::GFx::AS2::Object *__thiscall Scaleform::GFx::AS2::AsBroadcasterCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::AsBroadcasterCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // ebx
  Scaleform::GFx::AS2::Object *v3; // eax
  _DWORD *v4; // esi
  Scaleform::GFx::AS2::Object *Prototype; // eax

  p_StringContext = &penv->StringContext;
  v3 = (Scaleform::GFx::AS2::Object *)penv->StringContext.pContext->pHeap->Alloc(
                                        penv->StringContext.pContext->pHeap,
                                        52,
                                        0);
  v4 = &v3->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable;
  if ( !v3 )
    return 0;
  Scaleform::GFx::AS2::Object::Object(v3, penv);
  *v4 = &Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v4[4] = &Scaleform::GFx::AS2::AsBroadcaster::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_AsBroadcaster);
  (*(void (__thiscall **)(_DWORD *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::AS2::Object *))(v4[4] + 52))(
    v4 + 4,
    p_StringContext,
    Prototype);
  return (Scaleform::GFx::AS2::Object *)v4;
}
