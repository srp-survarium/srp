Scaleform::GFx::ImageFileHandlerRegistry *__thiscall Scaleform::GFx::ImageFileHandlerRegistry::`scalar deleting destructor'(
        Scaleform::GFx::ImageFileHandlerRegistry *this,
        char a2)
{
  Scaleform::Render::ImageFileHandler **Data; // eax

  this->Scaleform::Render::ImageFileHandlerRegistry::__vftable = (Scaleform::Render::ImageFileHandlerRegistry_vtbl *)&Scaleform::Render::ImageFileHandlerRegistry::`vftable';
  Data = this->Handlers.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  this->Scaleform::GFx::State::Scaleform::RefCountBase<Scaleform::GFx::State,2>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::ImageFileHandlerRegistry_vtbl *)&Scaleform::GFx::State::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
