void __usercall Scaleform::GFx::AS2::XML_LoadString(
        const Scaleform::GFx::AS2::FnCall *fn@<eax>,
        Scaleform::GFx::AS2::XmlObject *pnode)
{
  Scaleform::GFx::LogState *Log; // ebx
  Scaleform::GFx::MovieImpl *MovieImpl; // esi
  Scaleform::GFx::ExternalLibPtr *pXMLObjectManager; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::XML::ObjectManager *v7; // eax
  Scaleform::GFx::XML::ObjectManager *v8; // eax
  Scaleform::GFx::XML::ObjectManager *v9; // ebp
  Scaleform::GFx::XML::ObjectManager *v10; // eax
  bool v11; // cc
  const Scaleform::GFx::AS2::Value *v12; // eax
  Scaleform::GFx::MovieImpl *v13; // eax
  Scaleform::RefCountVImpl *v14; // eax
  Scaleform::GFx::Resource *v15; // esi
  Scaleform::Ptr<Scaleform::GFx::XML::Document> *v16; // eax
  Scaleform::GFx::XML::Document *Document; // esi
  Scaleform::GFx::AS2::XmlObject *v18; // ebx
  Scaleform::GFx::ASStringNode *v19; // eax
  Scaleform::GFx::XML::DOMStringNode *StringNode; // eax
  Scaleform::GFx::XML::DOMStringNode *RootNode; // eax
  Scaleform::RefCountNTSImpl *pObject; // ecx
  Scaleform::GFx::XML::ShadowRefBase *v23; // eax
  Scaleform::GFx::XML::ShadowRefBase *v24; // ebx
  Scaleform::MemoryHeap *v25; // ecx
  Scaleform::GFx::AS2::XmlNodeObject *v26; // eax
  Scaleform::GFx::XML::ShadowRefBase_vtbl *v27; // eax
  Scaleform::GFx::XML::ShadowRefBase_vtbl *v28; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v29; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *v31; // [esp+10h] [ebp-7Ch] BYREF
  Scaleform::GFx::XML::DOMString v32; // [esp+14h] [ebp-78h] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::Document> result; // [esp+18h] [ebp-74h] BYREF
  Scaleform::GFx::AS2::Value v34; // [esp+1Ch] [ebp-70h] BYREF
  Scaleform::GFx::XML::DOMBuilder v35; // [esp+2Ch] [ebp-60h] BYREF

  Log = (Scaleform::GFx::LogState *)Scaleform::GFx::AS2::FnCall::GetLog(fn);
  MovieImpl = Scaleform::GFx::AS2::Environment::GetMovieImpl(fn->Env);
  pXMLObjectManager = MovieImpl->pXMLObjectManager;
  if ( pXMLObjectManager )
  {
    v10 = (Scaleform::GFx::XML::ObjectManager *)&pXMLObjectManager[-1];
    if ( v10 )
      ++v10->RefCount;
    v9 = v10;
  }
  else
  {
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v7 = (Scaleform::GFx::XML::ObjectManager *)pHeap->Alloc(pHeap, 64u, 0);
    if ( v7 )
      Scaleform::GFx::XML::ObjectManager::ObjectManager(v7, MovieImpl);
    else
      v8 = 0;
    v9 = v8;
    if ( v8 )
      MovieImpl->pXMLObjectManager = &v8->Scaleform::GFx::ExternalLibPtr;
    else
      MovieImpl->pXMLObjectManager = 0;
  }
  v11 = fn->NArgs <= 0;
  v34.T.Type = 0;
  if ( v11 )
    goto LABEL_25;
  v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
  Scaleform::GFx::AS2::Value::operator=(&v34, v12);
  v13 = Scaleform::GFx::AS2::Environment::GetMovieImpl(fn->Env);
  v14 = (Scaleform::RefCountVImpl *)v13->GetStateAddRef(&v13->Scaleform::GFx::StateBag, State_XMLSupport);
  v15 = (Scaleform::GFx::Resource *)v14;
  if ( !v14 )
  {
    if ( Log )
      Scaleform::GFx::LogState::LogMessageByType(
        Log,
        (Scaleform::LogMessageId)212992,
        "No XML parser state set for movie!");
LABEL_25:
    v18 = pnode;
LABEL_26:
    Document = Scaleform::GFx::XML::ObjectManager::CreateDocument(v9);
    goto LABEL_27;
  }
  Scaleform::RefCountImpl::Release(v14);
  Scaleform::RefCountImpl::AddRef(v15);
  Scaleform::GFx::XML::DOMBuilder::DOMBuilder(&v35, (Scaleform::Ptr<Scaleform::GFx::XML::SupportBase>)v15, 1);
  Scaleform::GFx::AS2::Value::ToStringImpl(&v34, (Scaleform::GFx::ASString *)&v31, fn->Env, -1, 0);
  if ( v9 )
    ++v9->RefCount;
  v16 = Scaleform::GFx::XML::DOMBuilder::ParseString(
          &v35,
          &result,
          v31->pData,
          v31->Size,
          (Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager>)v9);
  if ( v16->pObject )
    ++v16->pObject->RefCount;
  Document = v16->pObject;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  v18 = pnode;
  Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(pnode, (Scaleform::GFx::ASStringNode *)fn->Env, Document);
  v19 = v31;
  --v31->RefCount;
  if ( !v19->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(&v35);
  if ( !Document )
    goto LABEL_26;
LABEL_27:
  StringNode = Scaleform::GFx::XML::DOMStringManager::CreateStringNode(&v9->StringPool, "null", 4u);
  Scaleform::GFx::XML::DOMString::DOMString(&v32, StringNode);
  Scaleform::GFx::XML::DOMString::AssignNode(&Document->Value, v32.pNode);
  Scaleform::GFx::XML::DOMString::~DOMString(&v32);
  v18->pRealNode = Document;
  RootNode = (Scaleform::GFx::XML::DOMStringNode *)Scaleform::GFx::XML::ObjectManager::CreateRootNode(v9, Document);
  pObject = v18->pRootNode.pObject;
  v32.pNode = RootNode;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v18->pRootNode.pObject = (Scaleform::GFx::XML::RootNode *)v32.pNode;
  v23 = (Scaleform::GFx::XML::ShadowRefBase *)v9->pHeap->Alloc(v9->pHeap, 12u, 0);
  v24 = 0;
  if ( v23 )
  {
    v23[1].__vftable = 0;
    v23->__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable';
    v23[2].__vftable = 0;
    v24 = v23;
  }
  Document->pShadow = v24;
  v25 = fn->Env->StringContext.pContext->pHeap;
  v26 = (Scaleform::GFx::AS2::XmlNodeObject *)v25->Alloc(v25, 60u, 0);
  if ( v26 )
  {
    Scaleform::GFx::AS2::XmlNodeObject::XmlNodeObject(v26, fn->Env);
    v28 = v27;
  }
  else
  {
    v28 = 0;
  }
  v29 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v24[2].__vftable;
  if ( v29 )
  {
    RefCount = v29->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v29->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v29);
    }
  }
  v24[2].__vftable = v28;
  v24[1].__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)pnode;
  Scaleform::GFx::AS2::Value::~Value(&v34);
  Scaleform::RefCountNTSImpl::Release(Document);
  Scaleform::RefCountNTSImpl::Release(v9);
}
