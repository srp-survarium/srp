void __userpurge Scaleform::GFx::AS2::PointProto::PointProto(
        Scaleform::GFx::AS2::PointProto *this@<ecx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::ASStringNode constructor)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::ASStringNode *v6; // eax
  int v7; // [esp+0h] [ebp-1Ch]
  int v8; // [esp+4h] [ebp-18h]
  Scaleform::GFx::AS2::Value v9; // [esp+Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    (const Scaleform::GFx::AS2::FunctionRef *)constructor.pData);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::PointObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::PointProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::PointObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::PointProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::PointObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::PointProto::`vftable';
  LOBYTE(constructor.pData) = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)&this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    this,
    psc,
    Scaleform::GFx::AS2::PointProto::FunctionTable,
    &constructor,
    v7,
    v8);
  pMovieImpl = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v9.T.Type = 4;
  v9.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)pMovieImpl,
                                                "length",
                                                6u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v9,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v6 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  if ( v9.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v9);
}
