Scaleform::BufferedFile *__thiscall Scaleform::BufferedFile::`scalar deleting destructor'(
        Scaleform::BufferedFile *this,
        char a2)
{
  bool v3; // zf
  Scaleform::File *pObject; // ecx

  v3 = this->pFile.pObject == 0;
  this->__vftable = (Scaleform::BufferedFile_vtbl *)&Scaleform::BufferedFile::`vftable';
  if ( !v3 )
    Scaleform::BufferedFile::FlushBuffer(this);
  if ( this->pBuffer )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->pBuffer);
  pObject = this->pFile.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pObject);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
