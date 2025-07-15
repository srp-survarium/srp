Scaleform::FILEFile *__userpurge Scaleform::FILEFile::`scalar deleting destructor'@<eax>(
        Scaleform::FILEFile *this@<ecx>,
        int ebx0@<ebx>,
        char a2)
{
  bool v4; // zf
  volatile LONG *v5; // esi

  v4 = !this->Opened;
  this->__vftable = (Scaleform::FILEFile_vtbl *)&Scaleform::FILEFile::`vftable';
  if ( !v4 )
    Scaleform::FILEFile::Close(this, ebx0);
  v5 = (volatile LONG *)(this->FileName.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd(v5 + 1, -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, (void *)v5);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
