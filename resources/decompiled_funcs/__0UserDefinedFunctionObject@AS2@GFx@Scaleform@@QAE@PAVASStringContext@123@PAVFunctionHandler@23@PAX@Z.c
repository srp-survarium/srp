void __thiscall Scaleform::GFx::AS2::UserDefinedFunctionObject::UserDefinedFunctionObject(
        Scaleform::GFx::AS2::UserDefinedFunctionObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::Resource *pcontext,
        void *puserData)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::UserDefinedFunctionObject_vtbl *)&Scaleform::GFx::AS2::UserDefinedFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::UserDefinedFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( pcontext )
    Scaleform::RefCountImpl::AddRef(pcontext);
  this->pContext.pObject = (Scaleform::GFx::FunctionHandler *)pcontext;
  this->pUserData = puserData;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
}
