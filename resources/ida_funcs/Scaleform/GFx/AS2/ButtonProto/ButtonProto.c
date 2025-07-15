void __userpurge Scaleform::GFx::AS2::ButtonProto::ButtonProto(
        Scaleform::GFx::AS2::ButtonProto *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  const Scaleform::GFx::ASString *p_AVMVersion; // [esp-Ch] [ebp-28h]
  int v7; // [esp+0h] [ebp-1Ch]
  int v8; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS2::Value val; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ButtonObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ButtonProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ButtonObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ButtonObject,Scaleform::GFx::AS2::Environment>::`vftable';
  LOBYTE(constructor) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    a2,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    this,
    psc,
    GAS_ButtonFunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    v7,
    v8);
  p_AVMVersion = (const Scaleform::GFx::ASString *)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[33].AVMVersion;
  LOBYTE(constructor) = 3;
  val.T.Type = 2;
  val.V.BooleanValue = 1;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    p_AVMVersion,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}
