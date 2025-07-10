Scaleform::Render::DICommand_PaletteMap *__thiscall Scaleform::Render::DICommand_PaletteMap::`vector deleting destructor'(
        Scaleform::Render::DICommand_PaletteMap *this,
        char a2)
{
  unsigned int *Channels; // eax
  Scaleform::Render::DrawableImage *pObject; // ecx
  Scaleform::Render::DrawableImage *v5; // ecx

  Channels = this->Channels;
  this->__vftable = (Scaleform::Render::DICommand_PaletteMap_vtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable';
  if ( Channels )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Channels);
  this->Channels = 0;
  pObject = this->pSource.pObject;
  if ( pObject )
    pObject->Release(pObject);
  this->__vftable = (Scaleform::Render::DICommand_PaletteMap_vtbl *)&Scaleform::Render::DICommand::`vftable';
  v5 = this->pImage.pObject;
  if ( v5 )
    v5->Release(v5);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
