int __thiscall Scaleform::DelegatedFile::SkipBytes(Scaleform::DelegatedFile *this, int numBytes)
{
  return this->pFile.pObject->SkipBytes(this->pFile.pObject, numBytes);
}
