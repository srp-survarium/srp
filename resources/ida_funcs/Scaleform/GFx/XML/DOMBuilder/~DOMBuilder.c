void __thiscall Scaleform::GFx::XML::DOMBuilder::~DOMBuilder(Scaleform::GFx::XML::DOMBuilder *this)
{
  Scaleform::GFx::XML::Document *pObject; // ecx
  Scaleform::GFx::XML::TextNode *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx

  pObject = this->pDoc.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  Scaleform::ConstructorMov<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership>::DestructArray(
    this->DefaultNamespaceStack.Data.Data,
    this->DefaultNamespaceStack.Data.Size);
  if ( this->DefaultNamespaceStack.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->DefaultNamespaceStack.Data.Data);
  Scaleform::ConstructorMov<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership>::DestructArray(
    this->PrefixNamespaceStack.Data.Data,
    this->PrefixNamespaceStack.Data.Size);
  if ( this->PrefixNamespaceStack.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->PrefixNamespaceStack.Data.Data);
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::XML::ElementNode>,2>,Scaleform::ArrayDefaultPolicy>(&this->ParseStack.Data);
  Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>::~Array<unsigned char,2,Scaleform::ArrayDefaultPolicy>((Scaleform::Array<char,2,Scaleform::ArrayDefaultPolicy> *)&this->AppendText);
  v3 = this->pAppendChainRoot.pObject;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  v4 = (Scaleform::RefCountVImpl *)this->pXMLParserState.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  this->__vftable = (Scaleform::GFx::XML::DOMBuilder_vtbl *)&Scaleform::GFx::XML::ParserHandler::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
