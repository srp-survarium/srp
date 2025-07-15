void __thiscall Scaleform::Render::ImageData::~ImageData(Scaleform::Render::ImageData *this)
{
  Scaleform::Render::Palette *pObject; // esi

  Scaleform::Render::ImageData::freePlanes(this);
  pObject = this->pPalette.pObject;
  if ( pObject )
  {
    if ( InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  }
}
