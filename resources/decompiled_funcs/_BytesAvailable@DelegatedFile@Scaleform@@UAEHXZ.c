int __thiscall Scaleform::DelegatedFile::BytesAvailable(Scaleform::DelegatedFile *this)
{
  return this->pFile.pObject->BytesAvailable(this->pFile.pObject);
}
