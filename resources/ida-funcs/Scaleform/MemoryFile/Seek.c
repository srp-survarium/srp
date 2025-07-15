int __thiscall Scaleform::MemoryFile::Seek(Scaleform::MemoryFile *this, int offset, int origin)
{
  int v3; // eax

  switch ( origin )
  {
    case 0:
      v3 = offset;
      goto LABEL_7;
    case 1:
      this->FileIndex += offset;
      break;
    case 2:
      v3 = this->FileSize - offset;
LABEL_7:
      this->FileIndex = v3;
      break;
  }
  return this->FileIndex;
}
