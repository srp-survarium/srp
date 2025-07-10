Scaleform::Render::RenderBufferManager *__thiscall Scaleform::Render::RenderBufferManager::`vector deleting destructor'(
        Scaleform::Render::RenderBufferManager *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::RenderBufferManager_vtbl *)&Scaleform::Render::RenderBufferManager::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
