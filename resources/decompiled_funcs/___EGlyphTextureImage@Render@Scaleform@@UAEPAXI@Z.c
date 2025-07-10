Scaleform::Render::GlyphTextureImage *__thiscall Scaleform::Render::GlyphTextureImage::`vector deleting destructor'(
        Scaleform::Render::GlyphTextureImage *this,
        char a2)
{
  Scaleform::Render::Image::~Image(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
