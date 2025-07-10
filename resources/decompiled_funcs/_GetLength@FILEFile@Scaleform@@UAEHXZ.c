int __thiscall Scaleform::FILEFile::GetLength(Scaleform::FILEFile *this)
{
  int v2; // edi
  int v3; // ebx

  v2 = this->Tell(this);
  if ( v2 < 0 )
    return -1;
  this->Seek(this, 0, 2);
  v3 = this->Tell(this);
  this->Seek(this, v2, 0);
  return v3;
}
