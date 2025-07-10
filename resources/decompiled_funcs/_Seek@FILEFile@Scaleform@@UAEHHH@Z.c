int __thiscall Scaleform::FILEFile::Seek(Scaleform::FILEFile *this, int offset, int origin)
{
  unsigned int v3; // edi

  v3 = 0;
  if ( !origin )
  {
    v3 = 0;
    goto LABEL_9;
  }
  if ( origin != 1 )
  {
    if ( origin == 2 )
    {
      v3 = 2;
      goto LABEL_5;
    }
LABEL_9:
    if ( offset == this->Tell(this) )
      return this->Tell(this);
    goto LABEL_5;
  }
  v3 = 1;
LABEL_5:
  if ( fseek(this->fs, offset, v3) )
    return -1;
  return this->Tell(this);
}
