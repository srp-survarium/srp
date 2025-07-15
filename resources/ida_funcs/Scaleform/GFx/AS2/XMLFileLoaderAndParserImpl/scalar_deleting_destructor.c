Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *__thiscall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::`scalar deleting destructor'(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        char a2)
{
  unsigned __int8 *pFileData; // eax
  Scaleform::RefCountVImpl *pObject; // ecx

  pFileData = this->pFileData;
  this->__vftable = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl_vtbl *)&Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::`vftable';
  if ( pFileData )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pFileData);
  pObject = (Scaleform::RefCountVImpl *)this->pParser.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->__vftable = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl_vtbl *)&Scaleform::GFx::AS2::ASCSSFileLoader::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
