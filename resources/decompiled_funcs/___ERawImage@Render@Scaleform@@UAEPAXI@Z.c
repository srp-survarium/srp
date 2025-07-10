Scaleform::Render::RawImage *__thiscall Scaleform::Render::RawImage::`vector deleting destructor'(
        Scaleform::Render::RawImage *this,
        char a2)
{
  Scaleform::Render::RawImage::~RawImage(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
