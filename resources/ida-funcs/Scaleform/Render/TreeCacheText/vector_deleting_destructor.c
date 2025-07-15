Scaleform::Render::TreeCacheText *__thiscall Scaleform::Render::TreeCacheText::`vector deleting destructor'(
        Scaleform::Render::TreeCacheText *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::TreeCacheText_vtbl *)&Scaleform::Render::TreeCacheText::`vftable';
  Scaleform::Render::TextMeshProvider::~TextMeshProvider(&this->TMProvider);
  Scaleform::Render::TreeCacheMeshBase::~TreeCacheMeshBase(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
