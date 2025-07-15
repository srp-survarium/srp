void __thiscall Scaleform::GFx::XML::DOMBuilder::DOMBuilder(
        Scaleform::GFx::XML::DOMBuilder *this,
        Scaleform::Ptr<Scaleform::GFx::XML::SupportBase> pxmlParser,
        bool ignorews)
{
  Scaleform::GFx::XML::SupportBase *pObject; // ecx

  pObject = pxmlParser.pObject;
  this->__vftable = (Scaleform::GFx::XML::DOMBuilder_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::XML::DOMBuilder_vtbl *)&Scaleform::GFx::XML::DOMBuilder::`vftable';
  if ( pxmlParser.pObject )
  {
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pxmlParser.pObject);
    pObject = pxmlParser.pObject;
  }
  this->pXMLParserState.pObject = pObject;
  this->pAppendChainRoot.pObject = 0;
  Scaleform::StringBuffer::StringBuffer(&this->AppendText, Scaleform::Memory::pGlobalHeap);
  this->pLocator = 0;
  this->ParseStack.Data.Data = 0;
  this->ParseStack.Data.Size = 0;
  this->ParseStack.Data.Policy.Capacity = 0;
  this->PrefixNamespaceStack.Data.Data = 0;
  this->PrefixNamespaceStack.Data.Size = 0;
  this->PrefixNamespaceStack.Data.Policy.Capacity = 0;
  this->DefaultNamespaceStack.Data.Data = 0;
  this->DefaultNamespaceStack.Data.Size = 0;
  this->DefaultNamespaceStack.Data.Policy.Capacity = 0;
  this->pDoc.pObject = 0;
  this->bIgnoreWhitespace = ignorews;
  this->bError = 0;
  if ( pxmlParser.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pxmlParser.pObject);
}
