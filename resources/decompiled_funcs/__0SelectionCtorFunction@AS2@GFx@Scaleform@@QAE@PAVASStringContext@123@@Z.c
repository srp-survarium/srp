void __userpurge Scaleform::GFx::AS2::SelectionCtorFunction::SelectionCtorFunction(
        Scaleform::GFx::AS2::SelectionCtorFunction *this@<ecx>,
        Scaleform::GFx::AS2::LocalFrame **a2@<ebp>,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v5; // [esp-8h] [ebp-14h]
  int v6; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::SelectionCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::MouseCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::SelectionCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::SelectionCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( this != (Scaleform::GFx::AS2::SelectionCtorFunction *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (unsigned __int8 *)psc,
      a2,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1u,
      v6);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)this,
    (int)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    v6,
    v7);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (unsigned __int8 *)psc,
    a2,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::SelectionCtorFunction::StaticFunctionTable,
    7u,
    v5);
}
