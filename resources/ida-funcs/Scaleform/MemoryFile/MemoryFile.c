void __thiscall Scaleform::MemoryFile::MemoryFile(
        Scaleform::MemoryFile *this,
        const Scaleform::String *fileName,
        const unsigned __int8 *pBuffer,
        int buffSize)
{
  this->__vftable = (Scaleform::MemoryFile_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::MemoryFile_vtbl *)&Scaleform::MemoryFile::`vftable';
  Scaleform::String::String(&this->FilePath, fileName);
  this->FileData = pBuffer;
  this->FileSize = buffSize;
  this->FileIndex = 0;
  this->Valid = (*(_DWORD *)(fileName->HeapTypeBits & 0xFFFFFFFC) & 0x7FFFFFFF) != 0 && pBuffer && buffSize > 0;
}


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
