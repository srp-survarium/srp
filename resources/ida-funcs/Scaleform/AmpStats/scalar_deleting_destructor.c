Scaleform::AmpStats *__thiscall Scaleform::AmpStats::`scalar deleting destructor'(Scaleform::AmpStats *this, char a2)
{
  this->__vftable = (Scaleform::AmpStats_vtbl *)&Scaleform::AmpStats::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
