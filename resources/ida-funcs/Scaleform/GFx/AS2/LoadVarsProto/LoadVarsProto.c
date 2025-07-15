void __userpurge Scaleform::GFx::AS2::LoadVarsProto::LoadVarsProto(
        Scaleform::GFx::AS2::LoadVarsProto *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::ASStringNode constructor)
{
  const Scaleform::GFx::AS2::Value *v6; // eax
  int v7; // [esp+0h] [ebp-1Ch]
  int v8; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS2::Value v9; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    (const Scaleform::GFx::AS2::FunctionRef *)constructor.pData);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::LoadVarsObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::LoadVarsProto_vtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::LoadVarsObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::LoadVarsProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::LoadVarsObject,Scaleform::GFx::AS2::Environment>::`vftable';
  LOBYTE(constructor.pData) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    a2,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    this,
    psc,
    Scaleform::GFx::AS2::LoadVarsProto::FunctionTable,
    &constructor,
    v7,
    v8);
  LOBYTE(constructor.pData) = 1;
  Scaleform::GFx::AS2::Value::Value(
    &v9,
    psc,
    (void (__cdecl *)(const Scaleform::GFx::AS2::FnCall *))Scaleform::GFx::AS2::LoadVarsProto::DefaultOnData);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::ASStringNode *)psc,
    "onData",
    v6,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
}
