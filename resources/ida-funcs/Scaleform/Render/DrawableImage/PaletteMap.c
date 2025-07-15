void __thiscall Scaleform::Render::DrawableImage::PaletteMap(
        Scaleform::Render::DrawableImage *this,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sourceRect,
        const Scaleform::Render::Point<long> *destPoint,
        const void **channels)
{
  Scaleform::Render::DICommand_PaletteMap *v6; // eax
  Scaleform::Render::DICommand_PaletteMap v7; // [esp+4h] [ebp-2Ch] BYREF

  Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(&v7, this, source, sourceRect, destPoint, channels);
  Scaleform::Render::DrawableImage::addCommand<Scaleform::Render::DICommand_PaletteMap>(this, v6);
  v7.__vftable = (Scaleform::Render::DICommand_PaletteMap_vtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable';
  if ( v7.Channels )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7.Channels);
  v7.Channels = 0;
  if ( v7.pSource.pObject )
    ((void (__thiscall *)(Scaleform::Render::DrawableImage *, Scaleform::Render::DICommand_PaletteMap_vtbl *))v7.pSource.pObject->Release)(
      v7.pSource.pObject,
      v7.__vftable);
  v7.__vftable = (Scaleform::Render::DICommand_PaletteMap_vtbl *)&Scaleform::Render::DICommand::`vftable';
  if ( v7.pImage.pObject )
    ((void (__cdecl *)(Scaleform::Render::DICommand_PaletteMap_vtbl *))v7.pImage.pObject->Release)(v7.__vftable);
}
