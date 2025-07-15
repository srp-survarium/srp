BOOL __thiscall Scaleform::SysFile::IsValid(Scaleform::DelegatedFile *this)
{
  Scaleform::File *pObject; // ecx

  pObject = this->pFile.pObject;
  return pObject && pObject->IsValid(pObject);
}
