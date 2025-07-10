Scaleform::UnopenedFile *__thiscall Scaleform::UnopenedFile::`scalar deleting destructor'(
        Scaleform::UnopenedFile *this,
        char a2)
{
  this->__vftable = (Scaleform::UnopenedFile_vtbl *)&Scaleform::UnopenedFile::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
