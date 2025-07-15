Scaleform::Render::Bundle *__thiscall Scaleform::Render::Bundle::`scalar deleting destructor'(
        Scaleform::Render::Bundle *this,
        char a2)
{
  this->__vftable = (Scaleform::Render::Bundle_vtbl *)&Scaleform::Render::Bundle::`vftable';
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Entries.Data.Data);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
