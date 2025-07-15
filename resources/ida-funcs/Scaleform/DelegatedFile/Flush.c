int __thiscall Scaleform::DelegatedFile::Flush(Scaleform::DelegatedFile *this)
{
  return ((int (__thiscall *)(Scaleform::File *))this->pFile.pObject->Flush)(this->pFile.pObject);
}
