Scaleform::Render::JPEG::TablesHeader *__thiscall Scaleform::Render::JPEG::ExtraData::`vector deleting destructor'(
        Scaleform::Render::JPEG::TablesHeader *this,
        char a2)
{
  unsigned __int8 *Data; // edx

  Data = this->Data;
  this->__vftable = (Scaleform::Render::JPEG::TablesHeader_vtbl *)&Scaleform::Render::JPEG::ExtraData::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
