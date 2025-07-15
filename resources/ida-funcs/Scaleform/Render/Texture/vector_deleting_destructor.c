Scaleform::Render::Texture *__thiscall Scaleform::Render::Texture::`vector deleting destructor'(
        Scaleform::Render::Texture *this,
        char a2)
{
  Scaleform::Render::Texture::~Texture(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
