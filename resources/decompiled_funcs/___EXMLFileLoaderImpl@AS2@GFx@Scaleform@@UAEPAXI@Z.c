Scaleform::GFx::AS2::XMLFileLoaderImpl *__thiscall Scaleform::GFx::AS2::XMLFileLoaderImpl::`vector deleting destructor'(
        Scaleform::GFx::AS2::XMLFileLoaderImpl *this,
        char a2)
{
  unsigned __int8 *pFileData; // eax

  pFileData = this->pFileData;
  this->__vftable = (Scaleform::GFx::AS2::XMLFileLoaderImpl_vtbl *)&Scaleform::GFx::AS2::XMLFileLoaderImpl::`vftable';
  if ( pFileData )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pFileData);
  this->__vftable = (Scaleform::GFx::AS2::XMLFileLoaderImpl_vtbl *)&Scaleform::GFx::AS2::ASCSSFileLoader::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
