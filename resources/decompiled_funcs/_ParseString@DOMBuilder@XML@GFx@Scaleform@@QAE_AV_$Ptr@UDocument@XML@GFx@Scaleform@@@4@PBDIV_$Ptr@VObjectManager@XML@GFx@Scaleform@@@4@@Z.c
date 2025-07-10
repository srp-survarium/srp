Scaleform::Ptr<Scaleform::GFx::XML::Document> *__thiscall Scaleform::GFx::XML::DOMBuilder::ParseString(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::Ptr<Scaleform::GFx::XML::Document> *result,
        const char *pdata,
        unsigned int len,
        Scaleform::Ptr<Scaleform::GFx::XML::ObjectManager> objMgr)
{
  Scaleform::GFx::XML::ObjectManager *pObject; // ecx
  Scaleform::GFx::XML::ObjectManager *v7; // eax
  Scaleform::GFx::XML::ObjectManager *v8; // eax
  Scaleform::GFx::XML::ObjectManager *v9; // edi
  Scaleform::GFx::XML::Document *v10; // ecx
  Scaleform::GFx::XML::Document *v11; // eax
  Scaleform::GFx::XML::Document *v12; // edi
  Scaleform::GFx::XML::SupportBase *v13; // ecx
  Scaleform::GFx::XML::Document *v14; // eax
  Scaleform::GFx::XML::Document *v15; // ecx
  Scaleform::GFx::XML::Document *v16; // eax

  pObject = objMgr.pObject;
  this->bError = 0;
  this->TotalBytesToLoad = 0;
  this->LoadedBytes = 0;
  if ( !objMgr.pObject )
  {
    v7 = (Scaleform::GFx::XML::ObjectManager *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 64,
                                                 0);
    if ( v7 )
    {
      Scaleform::GFx::XML::ObjectManager::ObjectManager(v7, 0);
      v9 = v8;
    }
    else
    {
      v9 = 0;
    }
    pObject = v9;
    objMgr.pObject = v9;
  }
  Scaleform::GFx::XML::ObjectManager::CreateDocument(pObject);
  v10 = this->pDoc.pObject;
  v12 = v11;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  this->pDoc.pObject = v12;
  v13 = this->pXMLParserState.pObject;
  if ( v13 )
    this->bError = !v13->ParseString(v13, pdata, len, this);
  v14 = this->pDoc.pObject;
  if ( v14 )
    ++v14->RefCount;
  v15 = this->pDoc.pObject;
  result->pObject = v15;
  if ( v15 )
    Scaleform::RefCountNTSImpl::Release(v15);
  v16 = result->pObject;
  this->pDoc.pObject = 0;
  if ( v16 && this->bIgnoreWhitespace )
    Scaleform::GFx::XML::DOMBuilder::DropWhiteSpaceNodes(v16);
  if ( objMgr.pObject )
    Scaleform::RefCountNTSImpl::Release(objMgr.pObject);
  return result;
}
