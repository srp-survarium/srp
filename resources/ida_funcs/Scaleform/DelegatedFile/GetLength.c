int __thiscall Scaleform::DelegatedFile::GetLength(Scaleform::DelegatedFile *this)
{
  return this->pFile.pObject->GetLength(this->pFile.pObject);
}
