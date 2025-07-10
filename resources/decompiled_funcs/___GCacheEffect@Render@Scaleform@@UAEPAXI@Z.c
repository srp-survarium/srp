Scaleform::Render::CacheEffect *__thiscall Scaleform::Render::CacheEffect::`scalar deleting destructor'(
        Scaleform::Render::CacheEffect *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::CacheEffect_vtbl *)&Scaleform::Render::CacheEffect::`vftable';
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
