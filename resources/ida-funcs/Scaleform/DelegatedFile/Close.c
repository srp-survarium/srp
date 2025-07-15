int __thiscall Scaleform::DelegatedFile::Close(Scaleform::DelegatedFile *this)
{
  return ((int (__thiscall *)(Scaleform::File *))this->pFile.pObject->Close)(this->pFile.pObject);
}
