void __thiscall Scaleform::GFx::AS2::ColorTransformProto::ColorTransformProto(
        Scaleform::GFx::AS2::ColorTransformProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ObjectInterface *v5; // edi
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
  Scaleform::GFx::MovieImpl *v16; // ecx
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::MovieImpl *v18; // ecx
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::MovieImpl *v20; // ecx
  Scaleform::GFx::ASStringNode *v21; // eax
  Scaleform::GFx::MovieImpl *v22; // ecx
  Scaleform::GFx::ASStringNode *v23; // eax
  int v24; // [esp+0h] [ebp-24h]
  int v25; // [esp+4h] [ebp-20h]
  Scaleform::GFx::AS2::Value val; // [esp+14h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    constructor);
  v5 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ColorTransformProto_vtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::ColorTransformObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::ColorTransformObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::ColorTransformProto::`vftable';
  LOBYTE(constructor) = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)this,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    Scaleform::GFx::AS2::ColorTransformProto::FunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    v24,
    v25);
  pMovieImpl = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)pMovieImpl,
                                                "redMultiplier",
                                                0xDu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v7 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v8 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v8,
                                                "greenMultiplier",
                                                0xFu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v9 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v10 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v10,
                                                "blueMultiplier",
                                                0xEu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v11 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v12 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v12,
                                                "alphaMultiplier",
                                                0xFu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v13 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v14 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v14,
                                                "redOffset",
                                                9u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v15 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v16 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v16,
                                                "greenOffset",
                                                0xBu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v17 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v18 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v18,
                                                "blueOffset",
                                                0xAu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v19 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v20 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v20,
                                                "alphaOffset",
                                                0xBu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v21 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v21->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
  v22 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v22,
                                                "rgb",
                                                3u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v5,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v23 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v23->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( val.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&val);
}
