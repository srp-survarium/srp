Scaleform::Render::PNG::PNGFileImageSource *__thiscall Scaleform::Render::PNG::PNGFileImageSource::`scalar deleting destructor'(
        Scaleform::Render::PNG::PNGFileImageSource *this,
        char a2)
{
  Scaleform::Render::PNG::Input *pOriginalInput; // ecx

  pOriginalInput = this->pOriginalInput;
  this->__vftable = (Scaleform::Render::PNG::PNGFileImageSource_vtbl *)&Scaleform::Render::PNG::PNGFileImageSource::`vftable';
  if ( pOriginalInput )
    ((void (__thiscall *)(Scaleform::Render::PNG::Input *, int))pOriginalInput->~Scaleform::Render::PNG::Input)(
      pOriginalInput,
      1);
  Scaleform::Render::FileImageSource::~FileImageSource(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
