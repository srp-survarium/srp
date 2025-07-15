int __thiscall Scaleform::MemoryFile::Read(Scaleform::MemoryFile *this, unsigned __int8 *pbufer, int numBytes)
{
  int FileIndex; // ecx
  int FileSize; // eax
  signed int v6; // edi

  FileIndex = this->FileIndex;
  FileSize = this->FileSize;
  v6 = numBytes;
  if ( FileIndex + numBytes > FileSize )
    v6 = FileSize - FileIndex;
  if ( v6 > 0 )
  {
    memcpy(pbufer, (unsigned __int8 *)&this->FileData[FileIndex], v6);
    this->FileIndex += v6;
  }
  return v6;
}
