void __userpurge Scaleform::GFx::AS2::SharedObjectCtorFunction::SharedObjectCtorFunction(
        Scaleform::GFx::AS2::SharedObjectCtorFunction *this@<ecx>,
        Scaleform::GFx::AS2::LocalFrame **a2@<ebp>,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v5; // [esp+0h] [ebp-Ch]

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::SharedObjectCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::SharedObjectCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::SharedObjectCtorFunction_vtbl *)&Scaleform::GFx::AS2::SharedObjectCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::SharedObjectCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->SharedObjects.mHash.pTable = 0;
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (unsigned __int8 *)psc,
    a2,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::SharedObjectCtorFunction::StaticFunctionTable,
    7u,
    v5);
}
