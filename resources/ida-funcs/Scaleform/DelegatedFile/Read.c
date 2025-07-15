int __thiscall Scaleform::DelegatedFile::Read(Scaleform::DelegatedFile *this, unsigned __int8 *pbuffer, int numBytes)
{
  return this->pFile.pObject->Read(this->pFile.pObject, pbuffer, numBytes);
}
