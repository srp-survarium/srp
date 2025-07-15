int __thiscall Scaleform::MemoryFile::Seek(Scaleform::MemoryFile *this, int offset, int origin)
{
  int result; // eax

  if ( origin )
  {
    if ( origin == 1 )
    {
      this->FileIndex += offset;
      return this->FileIndex;
    }
    if ( origin == 2 )
    {
      result = this->FileSize - offset;
      this->FileIndex = result;
      return result;
    }
  }
  else
  {
    this->FileIndex = offset;
  }
  return this->FileIndex;
}
