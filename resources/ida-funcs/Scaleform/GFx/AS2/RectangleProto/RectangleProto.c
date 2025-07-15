void __userpurge Scaleform::GFx::AS2::RectangleProto::RectangleProto(
        Scaleform::GFx::AS2::RectangleProto *this@<ecx>,
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
  Scaleform::GFx::MovieImpl *v16; // ecx
  Scaleform::GFx::ASStringNode *v17; // eax
  Scaleform::GFx::MovieImpl *v18; // ecx
  Scaleform::GFx::ASStringNode *v19; // eax
  int v20; // [esp+0h] [ebp-20h]
  int v21; // [esp+4h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value v22; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    pprototype,
    (const Scaleform::GFx::AS2::FunctionRef *)constructor.pData);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::RectangleProto_vtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::RectangleObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::RectangleObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::RectangleProto::`vftable';
  LOBYTE(constructor.pData) = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    a2,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    Scaleform::GFx::AS2::RectangleProto::FunctionTable,
    &constructor,
    v20,
    v21);
  pMovieImpl = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v22.T.Type = 4;
  v22.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)pMovieImpl,
                                                "left",
                                                4u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v22,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v7 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v7->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  v8 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v22.T.Type = 4;
  v22.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v8,
                                                "top",
                                                3u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v22,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v9 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  v10 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v22.T.Type = 4;
  v22.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v10,
                                                "right",
                                                5u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v22,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v11 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v11->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  v12 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v22.T.Type = 4;
  v22.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v12,
                                                "bottom",
                                                6u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v22,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v13 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  v14 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v22.T.Type = 4;
  v22.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v14,
                                                "topLeft",
                                                7u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v22,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v15 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v15->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  v16 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v22.T.Type = 4;
  v22.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v16,
                                                "bottomRight",
                                                0xBu,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v22,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v17 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v17->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
  v18 = psc->pContext->pMovieRoot->pASMovieRoot.pObject[39].pMovieImpl;
  LOBYTE(constructor.pData) = 2;
  v22.T.Type = 4;
  v22.NV.Int32Value = 0;
  pprototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                                (Scaleform::GFx::ASStringManager *)v18,
                                                "size",
                                                4u,
                                                0);
  ++pprototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&pprototype,
    &v22,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v19 = (Scaleform::GFx::ASStringNode *)pprototype;
  --pprototype->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v22.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v22);
}
