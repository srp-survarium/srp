Scaleform::Render::ImageFileHandlerRegistry *__thiscall Scaleform::Render::ImageFileHandlerRegistry::`vector deleting destructor'(
        Scaleform::Render::ImageFileHandlerRegistry *this,
        char a2)
{
  Scaleform::Render::ImageFileHandler **Data; // eax

  this->__vftable = (Scaleform::Render::ImageFileHandlerRegistry_vtbl *)&Scaleform::Render::ImageFileHandlerRegistry::`vftable';
  Data = this->Handlers.Data.Data;
  if ( Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
