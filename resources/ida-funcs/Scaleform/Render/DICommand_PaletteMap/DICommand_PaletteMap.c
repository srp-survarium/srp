void __thiscall Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(
        Scaleform::Render::DICommand_PaletteMap *this,
        const Scaleform::Render::DICommand_PaletteMap *other)
{
  unsigned int *v3; // eax

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(this, other);
  this->__vftable = (Scaleform::Render::DICommand_PaletteMap_vtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable';
  this->ChannelMask = other->ChannelMask;
  v3 = (unsigned int *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 4096, 0);
  this->Channels = v3;
  memcpy((int)v3, (const __m128i *)other->Channels, 0x1000u);
}


void __thiscall Scaleform::Render::DICommand_PaletteMap::DICommand_PaletteMap(
        Scaleform::Render::DICommand_PaletteMap *this,
        Scaleform::Render::DrawableImage *image,
        Scaleform::Render::DrawableImage *source,
        const Scaleform::Render::Rect<long> *sr,
        const Scaleform::Render::Point<long> *dp,
        const void **channels)
{
  unsigned int *v7; // eax

  Scaleform::Render::DICommand_SourceRect::DICommand_SourceRect(this, image, source, sr, dp);
  this->__vftable = (Scaleform::Render::DICommand_PaletteMap_vtbl *)&Scaleform::Render::DICommand_PaletteMap::`vftable';
  this->ChannelMask = 0;
  v7 = (unsigned int *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 4096, 0);
  this->Channels = v7;
  memset((int)v7, 0, 4096);
  if ( *channels )
  {
    this->ChannelMask |= 1u;
    qmemcpy(this->Channels, *channels, 0x400u);
  }
  if ( channels[1] )
  {
    this->ChannelMask |= 2u;
    qmemcpy(this->Channels + 256, channels[1], 0x400u);
  }
  if ( channels[2] )
  {
    this->ChannelMask |= 4u;
    qmemcpy(this->Channels + 512, channels[2], 0x400u);
  }
  if ( channels[3] )
  {
    this->ChannelMask |= 8u;
    qmemcpy(this->Channels + 768, channels[3], 0x400u);
  }
}
