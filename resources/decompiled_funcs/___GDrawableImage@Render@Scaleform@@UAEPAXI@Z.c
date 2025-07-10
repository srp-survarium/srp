Scaleform::Render::DrawableImage *__thiscall Scaleform::Render::DrawableImage::`scalar deleting destructor'(
        Scaleform::Render::DrawableImage *this,
        char a2)
{
  Scaleform::Render::DrawableImage::~DrawableImage(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
