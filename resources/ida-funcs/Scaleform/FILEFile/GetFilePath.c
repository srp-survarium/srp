const char *__thiscall Scaleform::FILEFile::GetFilePath(Scaleform::FILEFile *this)
{
  return (const char *)((this->FileName.HeapTypeBits & 0xFFFFFFFC) + 8);
}
