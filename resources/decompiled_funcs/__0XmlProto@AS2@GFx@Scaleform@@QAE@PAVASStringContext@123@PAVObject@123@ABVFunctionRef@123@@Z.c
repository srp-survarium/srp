void __thiscall Scaleform::GFx::AS2::XmlProto::XmlProto(
        Scaleform::GFx::AS2::XmlProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *ConstStringNode; // ebp
  Scaleform::GFx::AS2::StringManager *v8; // eax
  Scaleform::GFx::ASStringNode *v9; // eax
  Scaleform::GFx::AS2::GlobalContext *v11; // ecx
  Scaleform::GFx::AS2::StringManager *v12; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::GFx::AS2::GlobalContext *v14; // ecx
  Scaleform::GFx::AS2::StringManager *v15; // eax
  Scaleform::GFx::ASStringNode *v16; // eax
  Scaleform::GFx::AS2::GlobalContext *v17; // ecx
  Scaleform::GFx::AS2::StringManager *v18; // eax
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::AS2::GlobalContext *v20; // ecx
  Scaleform::GFx::AS2::StringManager *v21; // eax
  Scaleform::GFx::ASStringNode *v22; // eax
  Scaleform::GFx::AS2::GlobalContext *v23; // ecx
  Scaleform::GFx::AS2::StringManager *v24; // eax
  Scaleform::GFx::ASStringNode *v25; // eax
  Scaleform::GFx::AS2::GlobalContext *v26; // ecx
  Scaleform::GFx::AS2::StringManager *v27; // eax
  Scaleform::GFx::ASStringNode *v28; // eax
  const Scaleform::GFx::AS2::Value *v29; // eax
  int v30; // [esp+0h] [ebp-20h]
  int v31; // [esp+4h] [ebp-1Ch]
  Scaleform::GFx::AS2::Value val; // [esp+10h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlObject::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::XmlProto_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlObject::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::XmlProto::`vftable';
  LOBYTE(constructor) = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    (int)this,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    Scaleform::GFx::AS2::XmlProto::FunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    v30,
    v31);
  pContext = psc->pContext;
  LOBYTE(constructor) = 2;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
  ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                      StringManager->pStringManager,
                      "application/x-www-form-urlencoded",
                      0x21u,
                      0);
  ++ConstStringNode->RefCount;
  val.T.Type = 5;
  val.NV.Int32Value = (int)ConstStringNode;
  ++ConstStringNode->RefCount;
  v8 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(psc->pContext);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v8->pStringManager,
                                               "contentType",
                                               0xBu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v9 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v9->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
  Scaleform::GFx::AS2::Value::~Value(&val);
  if ( ConstStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(ConstStringNode);
  v11 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 0;
  v12 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v11);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v12->pStringManager,
                                               "docTypeDecl",
                                               0xBu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v13 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v13->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v14 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 0;
  v15 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v14);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v15->pStringManager,
                                               "idMap",
                                               5u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v16 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v16->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v17 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 2;
  val.V.BooleanValue = 0;
  v18 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v17);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v18->pStringManager,
                                               "ignoreWhite",
                                               0xBu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v19 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v20 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 0;
  v21 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v20);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v21->pStringManager,
                                               "loaded",
                                               6u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v22 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v22->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v23 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 4;
  val.NV.Int32Value = 0;
  v24 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v23);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v24->pStringManager,
                                               "status",
                                               6u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v25 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v25->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v26 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 0;
  v27 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v26);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v27->pStringManager,
                                               "xmlDecl",
                                               7u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v28 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v28->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  Scaleform::GFx::AS2::Value::~Value(&val);
  LOBYTE(constructor) = 1;
  Scaleform::GFx::AS2::Value::Value(&val, psc, Scaleform::GFx::AS2::XmlProto::DefaultOnData);
  Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    "onData",
    v29,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  Scaleform::GFx::AS2::Value::~Value(&val);
}
