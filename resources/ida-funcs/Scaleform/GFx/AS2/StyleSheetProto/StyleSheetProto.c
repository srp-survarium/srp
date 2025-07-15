void __userpurge Scaleform::GFx::AS2::StyleSheetProto::StyleSheetProto(
        Scaleform::GFx::AS2::StyleSheetProto *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  int v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+4h] [ebp-4h]

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::StyleSheetObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StyleSheetProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::StyleSheetObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::StyleSheetProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StyleSheetObject,Scaleform::GFx::AS2::Environment>::`vftable';
  LOBYTE(constructor) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    a2,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    this,
    psc,
    GAS_StyleSheetFunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    v6,
    v7);
}
