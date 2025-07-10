void __thiscall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *ActualPrototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MovieClipObject_vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pSprite.pProxy.pObject = 0;
  this->ButtonEventMask = 0;
  this->HasButtonHandlers = 0;
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      penv->StringContext.pContext,
                      penv,
                      ASBuiltin_MovieClip);
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    ActualPrototype);
}
