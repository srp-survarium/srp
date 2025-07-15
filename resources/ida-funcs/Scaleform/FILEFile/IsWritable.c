BOOL __thiscall Scaleform::FILEFile::IsWritable(Scaleform::FILEFile *this)
{
  return this->IsValid(this) && (this->OpenFlags & 2) != 0;
}
