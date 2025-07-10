int __thiscall Scaleform::DelegatedFile::LTell(Scaleform::DelegatedFile *this)
{
  return this->pFile.pObject->LTell(this->pFile.pObject);
}
