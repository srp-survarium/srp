Scaleform::Render::MappedTextureBase *__thiscall Scaleform::Render::D3D1x::MappedTexture::`vector deleting destructor'(
        Scaleform::Render::MappedTextureBase *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::MappedTextureBase_vtbl *)&Scaleform::Render::MappedTextureBase::`vftable';
  Scaleform::Render::ImageData::~ImageData(&this->Data);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
