const char *__thiscall Scaleform::MemoryFile::GetFilePath(Scaleform::MemoryFile *this)
{
  return (const char *)((this->FilePath.HeapTypeBits & 0xFFFFFFFC) + 8);
}
