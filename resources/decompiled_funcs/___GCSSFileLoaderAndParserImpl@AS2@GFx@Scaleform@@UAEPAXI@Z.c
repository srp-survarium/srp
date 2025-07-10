Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl *__thiscall Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl::`scalar deleting destructor'(
        Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl *this,
        char a2)
{
  unsigned __int8 *pFileData; // eax

  pFileData = this->pFileData;
  this->__vftable = (Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl_vtbl *)&Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl::`vftable';
  if ( pFileData )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pFileData);
  this->__vftable = (Scaleform::GFx::AS2::CSSFileLoaderAndParserImpl_vtbl *)&Scaleform::GFx::AS2::ASCSSFileLoader::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
