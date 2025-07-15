void __userpurge Scaleform::GFx::AS2::MathCtorFunction::MathCtorFunction(
        Scaleform::GFx::AS2::MathCtorFunction *this@<ecx>,
        unsigned __int8 *a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Object *Prototype; // eax
  int v5; // [esp+0h] [ebp-20h]
  Scaleform::GFx::AS2::Value v6; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MathCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::MouseCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
  v6.NV.NumberValue = 2.718281828459045;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MathCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "E",
    &v6);
  LOBYTE(a2) = 5;
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  v6.NV.NumberValue = 0.6931471805599453;
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "LN2",
    &v6);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  v6.NV.NumberValue = 1.442695040888963;
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "LOG2E",
    &v6);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  v6.NV.NumberValue = 2.302585092994046;
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "LN10",
    &v6);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  v6.NV.NumberValue = 0.4342944819032518;
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "LOG10E",
    &v6);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  v6.NV.NumberValue = 3.141592653589793;
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "PI",
    &v6);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  v6.NV.NumberValue = 0.7071067811865476;
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "SQRT1_2",
    &v6);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  v6.NV.NumberValue = 1.414213562373095;
  v6.T.Type = 3;
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "SQRT2",
    &v6);
  if ( v6.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v6);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    a2,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::MathCtorFunction::StaticFunctionTable,
    7u,
    v5);
}
