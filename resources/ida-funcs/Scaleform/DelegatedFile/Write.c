int __thiscall Scaleform::DelegatedFile::Write(
        Scaleform::DelegatedFile *this,
        const unsigned __int8 *pbuffer,
        int numBytes)
{
  return this->pFile.pObject->Write(this->pFile.pObject, pbuffer, numBytes);
}
