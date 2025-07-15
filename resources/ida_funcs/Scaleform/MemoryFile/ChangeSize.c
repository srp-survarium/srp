char __thiscall Scaleform::MemoryFile::ChangeSize(Scaleform::MemoryFile *this, int newSize)
{
  this->FileSize = newSize;
  return 1;
}
