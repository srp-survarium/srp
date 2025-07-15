void __thiscall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::InitASXml(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::XML::ShadowRefBase_vtbl *pTarget)
{
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::GFx::XML::ObjectManager *pObjectManager; // eax
  Scaleform::GFx::XML::Document *v6; // eax
  Scaleform::GFx::XML::RootNode *RootNode; // eax
  Scaleform::GFx::XML::RootNode *v8; // ecx
  Scaleform::GFx::XML::RootNode *v9; // ebp
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
  int v20; // [esp+4h] [ebp-90h]
  int v21; // [esp+18h] [ebp-7Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::XML::Document> result; // [esp+1Ch] [ebp-78h] BYREF
  Scaleform::GFx::ASStringNode *ConstStringNode; // [esp+20h] [ebp-74h] BYREF
  Scaleform::GFx::AS2::Value v24; // [esp+24h] [ebp-70h] BYREF
  Scaleform::GFx::XML::DOMBuilder v25; // [esp+34h] [ebp-60h] BYREF

  if ( this->pFileData )
  {
    bIgnoreWhitespace = this->bIgnoreWhitespace;
    pObject = (Scaleform::GFx::Resource *)this->pParser.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::AddRef(pObject);
    Scaleform::GFx::XML::DOMBuilder::DOMBuilder(&v25, this->pParser, bIgnoreWhitespace);
    pObjectManager = this->pObjectManager;
    if ( pObjectManager )
      ++pObjectManager->RefCount;
    Scaleform::GFx::XML::DOMBuilder::ParseString(
      &v25,
      &result,
      (const char *)this->pFileData,
      this->FileLength,
      (Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager>)pObjectManager);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pFileData);
    v6 = result.pObject;
    this->pFileData = 0;
    pTarget[14].~Scaleform::GFx::XML::ShadowRefBase = (void (__thiscall *)(Scaleform::GFx::XML::ShadowRefBase *))v6;
    RootNode = Scaleform::GFx::XML::ObjectManager::CreateRootNode(this->pObjectManager, v6);
    v8 = (Scaleform::GFx::XML::RootNode *)pTarget[13].~Scaleform::GFx::XML::ShadowRefBase;
    v9 = RootNode;
    if ( v8 )
      Scaleform::RefCountNTSImpl::Release(v8);
    pTarget[13].~Scaleform::GFx::XML::ShadowRefBase = (void (__thiscall *)(Scaleform::GFx::XML::ShadowRefBase *))v9;
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
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v12->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v12);
      }
    }
    v11[2].__vftable = 0;
    v11[1].__vftable = pTarget;
    result.pObject->pShadow = v11;
    Scaleform::GFx::AS2::XmlObject::AssignXMLDecl((Scaleform::GFx::AS2::XmlObject *)pTarget, penv, result.pObject);
    if ( !v25.bError || v25.TotalBytesToLoad )
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
      (*((void (__thiscall **)(Scaleform::GFx::XML::ShadowRefBase_vtbl *, unsigned int *, Scaleform::GFx::ASStringNode **, Scaleform::GFx::AS2::Value *, char *))pTarget[4].~Scaleform::GFx::XML::ShadowRefBase
       + 10))(
        pTarget + 4,
        &penv[4].Size,
        &ConstStringNode,
        &v24,
        (char *)&v21 + 3);
      v17 = ConstStringNode;
      --ConstStringNode->RefCount;
      if ( !v17->RefCount )
        Scaleform::GFx::ASStringNode::ReleaseNode(v17);
      Scaleform::GFx::AS2::Value::~Value(&v24);
      TotalBytesToLoad = v25.TotalBytesToLoad;
      *(double *)&pTarget[16].~Scaleform::GFx::XML::ShadowRefBase = (double)v25.LoadedBytes;
      v14 = (double)(int)v25.TotalBytesToLoad;
      if ( TotalBytesToLoad < 0 )
        v14 = v14 + 4294967296.0;
      v20 = 1;
    }
    else
    {
      *(double *)&pTarget[16].~Scaleform::GFx::XML::ShadowRefBase = (double)v25.LoadedBytes;
      v20 = 0;
      v14 = -1.0;
    }
    *(long double *)&pTarget[18].~Scaleform::GFx::XML::ShadowRefBase = v14;
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(
      (Scaleform::GFx::AS2::XmlObject *)pTarget,
      (Scaleform::GFx::AS2::Environment *)penv,
      (Scaleform::GFx::ASStringNode *)v20);
    if ( result.pObject )
      Scaleform::RefCountNTSImpl::Release(result.pObject);
    Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(&v25);
  }
  else
  {
    *(double *)&pTarget[16].~Scaleform::GFx::XML::ShadowRefBase = 0.0;
    *(double *)&pTarget[18].~Scaleform::GFx::XML::ShadowRefBase = -1.0;
    Scaleform::GFx::AS2::XmlObject::NotifyOnLoad(
      (Scaleform::GFx::AS2::XmlObject *)pTarget,
      (Scaleform::GFx::AS2::Environment *)penv,
      0);
  }
}
