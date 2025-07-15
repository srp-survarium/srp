Scaleform::Render::PNG::Input *__thiscall Scaleform::Render::PNG::Input::`scalar deleting destructor'(
        Scaleform::Render::PNG::Input *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::PNG::Input_vtbl *)&Scaleform::Render::PNG::Input::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
