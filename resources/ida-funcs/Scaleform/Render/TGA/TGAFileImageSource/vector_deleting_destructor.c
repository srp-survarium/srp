Scaleform::Render::TGA::TGAFileImageSource *__thiscall Scaleform::Render::TGA::TGAFileImageSource::`vector deleting destructor'(
        Scaleform::Render::TGA::TGAFileImageSource *this,
        char a2)
{
  Scaleform::Render::Palette *pObject; // edi

  pObject = this->pColorMap.pObject;
  if ( pObject && InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  Scaleform::Render::FileImageSource::~FileImageSource(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
