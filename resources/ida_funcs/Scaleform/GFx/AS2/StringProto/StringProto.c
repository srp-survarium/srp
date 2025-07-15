void __thiscall Scaleform::GFx::AS2::StringProto::StringProto(
        Scaleform::GFx::AS2::StringProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::ASStringNode *v5; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  int v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+4h] [ebp-Ch]

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::StringObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::StringProto_vtbl *)&Scaleform::GFx::AS2::StringProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::StringObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::StringObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::StringProto::`vftable';
  v5 = (Scaleform::GFx::ASStringNode *)psc->pContext->pMovieRoot->pASMovieRoot.pObject[25].__vftable;
  ++v5->RefCount;
  pNode = this->sValue.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->sValue.pNode = v5;
  LOBYTE(constructor) = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)&this->Scaleform::GFx::AS2::GASPrototypeBase,
    (Scaleform::GFx::AS2::LocalFrame **)this,
    this,
    psc,
    GAS_StringFunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    v8,
    v9);
}
