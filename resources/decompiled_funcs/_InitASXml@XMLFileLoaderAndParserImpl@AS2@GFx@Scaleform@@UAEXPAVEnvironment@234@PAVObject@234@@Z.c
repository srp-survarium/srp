void __thiscall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::InitASXml(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::AS2::XmlObject *pTarget)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::XML::ObjectManager *pObjectManager; // eax
  Scaleform::GFx::AS2::RefCountCollector<323> *v6; // eax
  Scaleform::GFx::XML::RootNode *RootNode; // eax
  Scaleform::RefCountNTSImpl *v8; // ecx
  Scaleform::GFx::AS2::Object_vtbl *v9; // ebp
  Scaleform::GFx::XML::ShadowRefBase *v10; // eax
  Scaleform::GFx::XML::ShadowRefBase *v11; // esi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v12; // ecx
  unsigned int RefCount; // eax
  long double v14; // st7
  Scaleform::GFx::AS2::GlobalContext *Size; // ecx
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *v17; // eax
  signed int TotalBytesToLoad; // ecx
  bool bIgnoreWhitespace; // [esp+4h] [ebp-90h]
  Scaleform::GFx::ASString v20; // [esp+4h] [ebp-90h]
  int v21; // [esp+18h] [ebp-7Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::Document> ploadedDoc; // [esp+1Ch] [ebp-78h] BYREF
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+20h] [ebp-74h] BYREF
  Scaleform::GFx::AS2::Value v24; // [esp+24h] [ebp-70h] BYREF
  Scaleform::GFx::XML::DOMBuilder documentBuilder; // [esp+34h] [ebp-60h] BYREF

  if ( this->pFileData )
  {
    bIgnoreWhitespace = this->bIgnoreWhitespace;
    pObject = (Scaleform::GFx::Resource *)this->pParser.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::AddRef(pObject);
    Scaleform::GFx::XML::DOMBuilder::DOMBuilder(&documentBuilder, this->pParser, bIgnoreWhitespace);
    pObjectManager = this->pObjectManager;
    if ( pObjectManager )
      ++pObjectManager->RefCount;
    Scaleform::GFx::XML::DOMBuilder::ParseString(
      &documentBuilder,
      &ploadedDoc,
      (const char *)this->pFileData,
      this->FileLength,
      (Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager>)pObjectManager);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pFileData);
    v6 = (Scaleform::GFx::AS2::RefCountCollector<323> *)ploadedDoc.pObject;
    this->pFileData = 0;
    pTarget->pRealNode = (Scaleform::GFx::XML::Node *)v6;
    RootNode = Scaleform::GFx::XML::ObjectManager::CreateRootNode(this->pObjectManager, (Scaleform::GFx::XML::Node *)v6);
    v8 = pTarget->pRootNode.pObject;
    v9 = (Scaleform::GFx::AS2::Object_vtbl *)RootNode;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    pTarget->pRootNode.pObject = (Scaleform::GFx::XML::RootNode *)v9;
    v10 = (Scaleform::GFx::XML::ShadowRefBase *)this->pObjectManager->pHeap->Alloc(this->pObjectManager->pHeap, 12, 0);
    if ( v10 )
    {
      v10->__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)&Scaleform::GFx::AS2::XMLShadowRef::`vftable';
      v10[1].__vftable = 0;
      v10[2].__vftable = 0;
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    v12 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11[2].__vftable;
    if ( v12 )
    {
      RefCount = v12->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v12->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
      }
    }
    v11[2].__vftable = 0;
    v11[1].__vftable = (Scaleform::GFx::XML::ShadowRefBase_vtbl *)pTarget;
    ploadedDoc.pObject->pShadow = v11;
    Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(pTarget, penv, ploadedDoc.pObject);
    if ( !documentBuilder.bError || documentBuilder.TotalBytesToLoad )
    {
      Size = (Scaleform::GFx::AS2::GlobalContext *)penv[4].Size;
      HIBYTE(v21) = 2;
      v24.T.Type = 2;
      v24.V.BooleanValue = 1;
      StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager(Size);
      ConstStringNode = Scaleform::GFx::ASStringManager::CreateConstStringNode(
                          StringManager->pStringManager,
                          "loaded",
                          6u,
                          0);
      ++ConstStringNode->RefCount;
      pTarget->SetMemberRaw(
        &pTarget->Scaleform::GFx::AS2::ObjectInterface,
        (Scaleform::GFx::AS2::ASStringContext *)&penv[4].Size,
        (const Scaleform::GFx::ASString *)&ConstStringNode,
        &v24,
        (const Scaleform::GFx::AS2::PropFlags *)&v21 + 3);
      v17 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      Scaleform::GFx::AS2::Value::~Value(&v24);
      TotalBytesToLoad = documentBuilder.TotalBytesToLoad;
      pTarget->BytesLoadedCurrent = (double)documentBuilder.LoadedBytes;
      v14 = (double)(int)documentBuilder.TotalBytesToLoad;
      if ( TotalBytesToLoad < 0 )
        v14 = v14 + 4294967296.0;
      v20.pNode = (Scaleform::GFx::ASStringNode *)1;
    }
    else
    {
      pTarget->BytesLoadedCurrent = (double)documentBuilder.LoadedBytes;
      v20.pNode = 0;
      v14 = -1.0;
    }
    pTarget->BytesLoadedTotal = v14;
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(pTarget, (Scaleform::GFx::AS2::Environment *)penv, v20);
    if ( ploadedDoc.pObject )
      Scaleform::RefCountNTSImpl::Release(ploadedDoc.pObject);
    Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(&documentBuilder);
  }
  else
  {
    pTarget->BytesLoadedCurrent = 0.0;
    pTarget->BytesLoadedTotal = -1.0;
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(pTarget, (Scaleform::GFx::AS2::Environment *)penv, 0);
  }
}
