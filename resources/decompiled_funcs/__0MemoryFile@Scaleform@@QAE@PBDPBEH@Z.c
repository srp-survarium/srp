void __thiscall Scaleform::MemoryFile::MemoryFile(
        Scaleform::MemoryFile *this,
        const char *pfileName,
        const unsigned __int8 *pBuffer,
        int buffSize)
{
  this->__vftable = (Scaleform::MemoryFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::MemoryFile_vtbl *)&Scaleform::MemoryFile::`vftable';
  Scaleform::String::String(&this->FilePath, pfileName);
  this->FileData = pBuffer;
  this->FileSize = buffSize;
  this->FileIndex = 0;
  this->Valid = pfileName && pBuffer && buffSize > 0;
}
