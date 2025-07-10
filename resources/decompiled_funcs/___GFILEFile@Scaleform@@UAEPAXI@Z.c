Scaleform::FILEFile *__thiscall Scaleform::FILEFile::`scalar deleting destructor'(Scaleform::FILEFile *this, char a2)
{
  bool v3; // zf
  volatile LONG *v4; // esi

  v3 = !this->Opened;
  this->__vftable = (Scaleform::FILEFile_vtbl *)&Scaleform::FILEFile::`vftable';
  if ( !v3 )
    Scaleform::FILEFile::Close(this);
  v4 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v4 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v4);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
