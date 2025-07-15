int __thiscall Scaleform::MemoryFile::BytesAvailable(Scaleform::MemoryFile *this)
{
  return this->FileSize - this->FileIndex;
}
