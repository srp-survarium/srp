int __thiscall Scaleform::DelegatedFile::ChangeSize(Scaleform::DelegatedFile *this, int newSize)
{
  return ((int (__thiscall *)(Scaleform::File *, int))this->pFile.pObject->ChangeSize)(this->pFile.pObject, newSize);
}
