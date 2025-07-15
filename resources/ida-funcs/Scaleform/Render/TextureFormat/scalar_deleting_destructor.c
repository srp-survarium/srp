Scaleform::Render::D3D1x::TextureFormat *__thiscall Scaleform::Render::TextureFormat::`scalar deleting destructor'(
        Scaleform::Render::D3D1x::TextureFormat *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::D3D1x::TextureFormat_vtbl *)&Scaleform::Render::TextureFormat::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
