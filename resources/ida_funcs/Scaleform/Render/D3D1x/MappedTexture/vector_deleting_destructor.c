Scaleform::Render::MappedTextureBase *__thiscall Scaleform::Render::D3D1x::MappedTexture::`vector deleting destructor'(
        Scaleform::Render::MappedTextureBase *this,
        char a2)
{
  Scaleform::Render::ImageData *p_Data; // edi
  Scaleform::Render::Palette *pObject; // edi

  p_Data = &this->Data;
  this->__vftable = (Scaleform::Render::MappedTextureBase_vtbl *)&Scaleform::Render::MappedTextureBase::`vftable';
  Scaleform::Render::ImageData::freePlanes(&this->Data);
  pObject = p_Data->pPalette.pObject;
  if ( pObject && InterlockedExchangeAdd(&pObject->RefCount.Value, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
