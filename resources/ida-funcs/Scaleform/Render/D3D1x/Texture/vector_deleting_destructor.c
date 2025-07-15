Scaleform::Render::D3D1x::Texture *__thiscall Scaleform::Render::D3D1x::Texture::`vector deleting destructor'(
        Scaleform::Render::D3D1x::Texture *this,
        char a2)
{
  Scaleform::Render::D3D1x::Texture::~Texture(this, (int)this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
