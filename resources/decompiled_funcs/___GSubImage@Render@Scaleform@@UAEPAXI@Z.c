Scaleform::Render::SubImage *__thiscall Scaleform::Render::SubImage::`scalar deleting destructor'(
        Scaleform::Render::SubImage *this,
        char a2)
{
  Scaleform::Render::SubImage::~SubImage(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
