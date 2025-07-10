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
  memcpy((unsigned __int8 *)v3, (unsigned __int8 *)other->Channels, 0x1000u);
}
