Scaleform::Render::SIF::SIFFileImageSource *__thiscall Scaleform::Render::SIF::SIFFileImageSource::`scalar deleting destructor'(
        Scaleform::Render::SIF::SIFFileImageSource *this,
        char a2)
{
  Scaleform::Render::ImageData *p_Data; // edi
  Scaleform::Render::Palette *pObject; // edi

  p_Data = &this->Data;
  this->__vftable = (Scaleform::Render::SIF::SIFFileImageSource_vtbl *)&Scaleform::Render::SIF::SIFFileImageSource::`vftable';
  Scaleform::Render::ImageData::freePlanes(&this->Data);
  pObject = p_Data->pPalette.pObject;
  if ( pObject && InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  Scaleform::Render::FileImageSource::~FileImageSource(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
