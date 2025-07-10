void __thiscall Scaleform::GFx::AS2::XmlObject::AssignXMLDecl(
        Scaleform::GFx::AS2::XmlObject *this,
        Scaleform::GFx::ASStringNode *penv,
        Scaleform::GFx::XML::Document *pdoc)
{
  Scaleform::GFx::XML::Document *v4; // esi
  char *pData; // esi
  unsigned int Size; // ebp
  Scaleform::GFx::AS2::Environment *v7; // edi
  Scaleform::GFx::AS2::StringManager *StringManager; // eax
  Scaleform::GFx::ASStringNode *StringNode; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // ecx
  Scaleform::GFx::AS2::StringManager *v11; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS2::Value v14; // [esp+10h] [ebp-28h] BYREF
  Scaleform::StringBuffer xmlDecl; // [esp+20h] [ebp-18h] BYREF

  Scaleform::StringBuffer::StringBuffer(&xmlDecl, (char *)&buf, Scaleform::Memory::pGlobalHeap);
  v4 = pdoc;
  if ( pdoc )
  {
    Scaleform::StringBuffer::AppendString(&xmlDecl, "<?", 0xFFFFFFFF);
    if ( v4->XMLVersion.pNode->Size )
    {
      Scaleform::StringBuffer::AppendString(&xmlDecl, "xml version=\"", 0xFFFFFFFF);
      Scaleform::StringBuffer::AppendString(&xmlDecl, (char *)v4->XMLVersion.pNode->pData, 0xFFFFFFFF);
      Scaleform::StringBuffer::AppendString(&xmlDecl, "\"", 0xFFFFFFFF);
    }
    if ( v4->Encoding.pNode->Size )
    {
      if ( v4->XMLVersion.pNode->Size )
        Scaleform::StringBuffer::AppendString(&xmlDecl, (char *)&stru_95AF78, 0xFFFFFFFF);
      Scaleform::StringBuffer::AppendString(&xmlDecl, "encoding=\"", 0xFFFFFFFF);
      Scaleform::StringBuffer::AppendString(&xmlDecl, (char *)v4->Encoding.pNode->pData, 0xFFFFFFFF);
      Scaleform::StringBuffer::AppendString(&xmlDecl, "\"", 0xFFFFFFFF);
    }
    if ( v4->Standalone != -1 )
    {
      if ( v4->XMLVersion.pNode->Size || v4->Encoding.pNode->Size )
        Scaleform::StringBuffer::AppendString(&xmlDecl, (char *)&stru_95AF78, 0xFFFFFFFF);
      if ( v4->Standalone )
        Scaleform::StringBuffer::AppendString(&xmlDecl, "standalone=\"yes\"", 0xFFFFFFFF);
      else
        Scaleform::StringBuffer::AppendString(&xmlDecl, "standalone=\"no\"", 0xFFFFFFFF);
    }
    Scaleform::StringBuffer::AppendString(&xmlDecl, "?>", 0xFFFFFFFF);
  }
  if ( v4->XMLVersion.pNode->Size || v4->Encoding.pNode->Size || v4->Standalone != -1 )
  {
    pData = xmlDecl.pData;
    Size = xmlDecl.Size;
    v7 = (Scaleform::GFx::AS2::Environment *)penv;
    if ( !xmlDecl.pData )
      pData = (char *)&buf;
    StringManager = Scaleform::GFx::AS2::GlobalContext::GetStringManager((Scaleform::GFx::AS2::GlobalContext *)penv[4].Size);
    StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(StringManager->pStringManager, pData, Size);
    ++StringNode->RefCount;
    v14.T.Type = 5;
    v14.NV.Int32Value = (int)StringNode;
    ++StringNode->RefCount;
    pContext = v7->StringContext.pContext;
    LOBYTE(pdoc) = 0;
    v11 = Scaleform::GFx::AS2::GlobalContext::GetStringManager(pContext);
    penv = Scaleform::GFx::ASStringManager::CreateConstStringNode(v11->pStringManager, "xmlDecl", 7u, 0);
    ++penv->RefCount;
    this->SetMember(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      v7,
      (const Scaleform::GFx::ASString *)&penv,
      &v14,
      (const Scaleform::GFx::AS2::PropFlags *)&pdoc);
    v12 = penv;
    --penv->RefCount;
    if ( !v12->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    Scaleform::GFx::AS2::Value::~Value(&v14);
    if ( StringNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(StringNode);
  }
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&xmlDecl);
}
