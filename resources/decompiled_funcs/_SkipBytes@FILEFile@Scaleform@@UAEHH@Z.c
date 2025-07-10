int __thiscall Scaleform::FILEFile::SkipBytes(Scaleform::FILEFile *this, int numBytes)
{
  __int64 v3; // kr00_8
  int v4; // eax
  int v5; // edx

  v3 = this->LTell(this);
  v4 = ((int (__thiscall *)(Scaleform::FILEFile *, int, int, int))this->LSeek)(this, numBytes, numBytes >> 31, 1);
  if ( (HIDWORD(v3) & (unsigned int)v3) == 0xFFFFFFFF || (v5 & v4) == 0xFFFFFFFF )
    return -1;
  else
    return v4 - v3;
}
