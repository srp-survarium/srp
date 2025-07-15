void __thiscall Scaleform::GFx::AS2::StringObject::StringObject(
        Scaleform::GFx::AS2::StringObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::ASStringNode *RefCount; // eax
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StringObject_vtbl *)&Scaleform::GFx::AS2::StringObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StringObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  RefCount = (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  this->sValue.pNode = RefCount;
  ++RefCount->RefCount;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_String);
  this->Set__proto__(&this->Scaleform::GFx::AS2::ObjectInterface, &penv->StringContext, Prototype);
}
