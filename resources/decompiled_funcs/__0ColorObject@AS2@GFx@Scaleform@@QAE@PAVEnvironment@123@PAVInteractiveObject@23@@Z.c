void __thiscall Scaleform::GFx::AS2::ColorObject::ColorObject(
        Scaleform::GFx::AS2::ColorObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *pcharacter)
{
  Scaleform::WeakPtrProxy *WeakProxy; // eax
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ColorObject_vtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ColorObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( pcharacter )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pcharacter);
  else
    WeakProxy = 0;
  this->pCharacter.pProxy.pObject = WeakProxy;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_Color);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}
