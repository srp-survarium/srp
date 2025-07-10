int __thiscall Scaleform::DelegatedFile::Seek(Scaleform::DelegatedFile *this, int offset, int origin)
{
  return this->pFile.pObject->Seek(this->pFile.pObject, offset, origin);
}
