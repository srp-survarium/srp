BOOL __thiscall Scaleform::FILEFile::Flush(Scaleform::FILEFile *this)
{
  return fflush(this->fs) == 0;
}
