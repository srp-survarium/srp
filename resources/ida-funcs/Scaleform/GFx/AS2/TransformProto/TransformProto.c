void __userpurge Scaleform::GFx::AS2::TransformProto::TransformProto(
        Scaleform::GFx::AS2::TransformProto *this@<ecx>,
        int a2@<ebx>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        Scaleform::GFx::ASStringNode constructor)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // ecx
  Scaleform::GFx::ASStringNode *v7; // eax
  Scaleform::GFx::MovieImpl *v8; // ecx
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::MovieImpl *v10; // ecx
  Scaleform::GFx::ASStringNode *v11; // eax
  Scaleform::GFx::MovieImpl *v12; // ecx
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::MovieImpl *v14; // ecx
  Scaleform::GFx::ASStringNode *v15; // eax
  int v16; // [esp+0h] [ebp-20h]
  int v17; // [esp+4h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v18; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    (const Scaleform::GFx::AS2::FunctionRef *)constructor.pData);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::TransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TransformProto_vtbl *)&Scaleform::GFx::AS2::TransformProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::TransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TransformProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::TransformProto::`vftable';
  LOBYTE(constructor.pData) = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    a2,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    Scaleform::GFx::AS2::TransformProto::FunctionTable,
    &constructor,
    v16,
    v17);
  pMovieImpl = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  v18.T.Type = 0;
  LOBYTE(constructor.pData) = 2;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)pMovieImpl,
                                                "matrix",
                                                6u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v18,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v7 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v8 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 6;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v8,
                                                "concatenatedMatrix",
                                                0x12u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v18,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v9 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  v10 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v10,
                                                "colorTransform",
                                                0xEu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v18,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v11 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v12 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 6;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v12,
                                                "concatenatedColorTransform",
                                                0x1Au,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v18,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v13 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  v14 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v14,
                                                "pixelBounds",
                                                0xBu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v18,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v15 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v18.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v18);
}
