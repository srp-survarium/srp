void __thiscall Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::XMLFileLoaderAndParserImpl(
        Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl *this,
        Scaleform::GFx::Resource *pparser,
        Scaleform::GFx::XML::ObjectManager *objMgr,
        bool ignorews)
{
  this->__vftable = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl_vtbl *)&Scaleform::GFx::AS2::XMLFileLoaderAndParserImpl::`vftable';
  if ( pparser )
    Scaleform::RefCountImpl::AddRef(pparser);
  this->pParser.pObject = (Scaleform::GFx::XML::SupportBase *)pparser;
  this->pObjectManager = objMgr;
  this->pFileData = 0;
  this->FileLength = 0;
  this->bIgnoreWhitespace = ignorews;
}
