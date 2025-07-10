void __userpurge Scaleform::GFx::AS2::XmlNodeProto::XmlNodeProto(
        Scaleform::GFx::AS2::XmlNodeProto *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        const Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ObjectInterface *v7; // edi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
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
  Scaleform::GFx::AS2::GlobalContext *v29; // ecx
  Scaleform::GFx::AS2::StringManager *v30; // eax
  Scaleform::GFx::ASStringNode *v31; // eax
  Scaleform::GFx::AS2::GlobalContext *v32; // ecx
  Scaleform::GFx::AS2::StringManager *v33; // eax
  Scaleform::GFx::ASStringNode *v34; // eax
  Scaleform::GFx::AS2::GlobalContext *v35; // ecx
  Scaleform::GFx::AS2::StringManager *v36; // eax
  Scaleform::GFx::ASStringNode *v37; // eax
  Scaleform::GFx::AS2::GlobalContext *v38; // ecx
  Scaleform::GFx::AS2::StringManager *v39; // eax
  Scaleform::GFx::ASStringNode *v40; // eax
  Scaleform::GFx::AS2::GlobalContext *v41; // ecx
  Scaleform::GFx::AS2::StringManager *v42; // eax
  Scaleform::GFx::ASStringNode *v43; // eax
  Scaleform::GFx::AS2::GlobalContext *v44; // ecx
  Scaleform::GFx::AS2::StringManager *v45; // eax
  Scaleform::GFx::ASStringNode *v46; // eax
  Scaleform::GFx::AS2::Value val; // [esp+4h] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  v7 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::XmlNodeProto_vtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::XmlNodeObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::XmlNodeObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::XmlNodeProto::`vftable';
  this->XMLNodeMemberMap.mHash.pTable = 0;
  LOBYTE(constructor) = 6;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    0,
    (Scaleform::GFx::AS2::LocalFrame **)psc,
    this,
    psc,
    Scaleform::GFx::AS2::XmlNodeProto::FunctionTable,
    (Scaleform::GFx::ASStringNode *)&constructor,
    a2,
    a3);
  pContext = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 0;
  StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               StringManager->pStringManager,
                                               "attributes",
                                               0xAu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v10 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v10->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v11 = psc->pContext;
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v12 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v11);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v12->pStringManager,
                                               "childNodes",
                                               0xAu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
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
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v15 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v14);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v15->pStringManager,
                                               "firstChild",
                                               0xAu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
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
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v18 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v17);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v18->pStringManager,
                                               "lastChild",
                                               9u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
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
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v21 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v20);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v21->pStringManager,
                                               "localName",
                                               9u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
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
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v24 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v23);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v24->pStringManager,
                                               "namespaceURI",
                                               0xCu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
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
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v27 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v26);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v27->pStringManager,
                                               "nextSibling",
                                               0xBu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v28 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v28->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v28);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v29 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 0;
  v30 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v29);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v30->pStringManager,
                                               "nodeName",
                                               8u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v31 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v31->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v32 = psc->pContext;
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v33 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v32);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v33->pStringManager,
                                               "nodeType",
                                               8u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v34 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v34->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v34);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v35 = psc->pContext;
  LOBYTE(constructor) = 2;
  val.T.Type = 0;
  v36 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v35);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v36->pStringManager,
                                               "nodeValue",
                                               9u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v37 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v37->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v38 = psc->pContext;
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v39 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v38);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v39->pStringManager,
                                               "parentNode",
                                               0xAu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v40 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v40->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v40);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v41 = psc->pContext;
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v42 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v41);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v42->pStringManager,
                                               "prefix",
                                               6u,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v43 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v43->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  Scaleform::GFx::AS2::Value::~Value(&val);
  v44 = psc->pContext;
  LOBYTE(constructor) = 6;
  val.T.Type = 0;
  v45 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(v44);
  prototype = (Scaleform::GFx::AS2::Object *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                                               v45->pStringManager,
                                               "previousSibling",
                                               0xFu,
                                               0);
  ++prototype->RefCount;
  Scaleform::GFx::AS2::Object::SetMemberRaw(
    (Scaleform::GFx::AS2::Object *)v7,
    psc,
    (const Scaleform::GFx::ASString *)&prototype,
    &val,
    (const Scaleform::GFx::AS2::PropFlags *)&constructor);
  v46 = (Scaleform::GFx::ASStringNode *)prototype;
  --prototype->RefCount;
  if ( !v46->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  Scaleform::GFx::AS2::Value::~Value(&val);
}
