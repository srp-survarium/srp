void __userpurge Scaleform::GFx::AS2::StageProto::StageProto(
        Scaleform::GFx::AS2::StageProto *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::ASStringNode constructor)
{
  int v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+4h] [ebp-4h]

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ExternalInterface,Scaleform::GFx::AS2::Environment> *)this,
    psc,
    pprototype,
    (const Scaleform::GFx::AS2::FunctionRef *)constructor.pData);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::StageObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StageProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::StageObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StageProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StageObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::ExternalInterfaceProto::`vftable';
  LOBYTE(constructor.pData) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    a2,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    this,
    psc,
    GFx_StageFunctionTable,
    &constructor,
    v6,
    v7);
}
