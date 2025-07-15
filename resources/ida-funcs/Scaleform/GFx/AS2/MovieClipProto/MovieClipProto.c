void __userpurge Scaleform::GFx::AS2::MovieClipProto::MovieClipProto(
        Scaleform::GFx::AS2::MovieClipProto *this@<ecx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        Scaleform::GFx::ASStringNode constructor)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // ecx
  const Scaleform::GFx::ASString *p_AVMVersion; // ebx
  int v7; // [esp+0h] [ebp-20h]
  int v8; // [esp+4h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v9; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    (const Scaleform::GFx::AS2::FunctionRef *)constructor.pData);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::MovieClipObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MovieClipProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::MovieClipObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MovieClipProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipObject,Scaleform::GFx::AS2::Environment>::`vftable';
  LOBYTE(constructor.pData) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    1,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    this,
    psc,
    MovieClipFunctionTable,
    &constructor,
    v7,
    v8);
  pMovieRoot = psc->pContext->pMovieRoot;
  v9.V.BooleanValue = 1;
  p_AVMVersion = (const Scaleform::GFx::ASString *)&pMovieRoot->pASMovieRoot.pObject[33].AVMVersion;
  LOBYTE(constructor.pData) = 3;
  v9.T.Type = 2;
  Scaleform::GFx::AS2::MovieClipObject::SetMemberCommon(this, psc, p_AVMVersion, COERCE_FLOAT(&v9));
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    p_AVMVersion,
    &v9,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
}
