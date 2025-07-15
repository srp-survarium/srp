int __thiscall Scaleform::MemoryFile::SkipBytes(Scaleform::MemoryFile *this, int numBytes)
{
  int result; // eax
  int FileSize; // edx
  int FileIndex; // esi

  result = numBytes;
  FileSize = this->FileSize;
  FileIndex = this->FileIndex;
  if ( FileIndex + numBytes > FileSize )
    result = FileSize - FileIndex;
  this->FileIndex = result + FileIndex;
  return result;
}
