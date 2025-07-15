Scaleform::Render::JPEG::Input *__thiscall Scaleform::Render::JPEG::Input::`vector deleting destructor'(
        Scaleform::Render::JPEG::Input *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::JPEG::Input_vtbl *)&Scaleform::Render::JPEG::Input::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
