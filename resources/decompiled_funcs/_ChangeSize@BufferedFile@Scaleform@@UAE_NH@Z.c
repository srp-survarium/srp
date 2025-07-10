int __thiscall Scaleform::BufferedFile::ChangeSize(Scaleform::BufferedFile *this, int newSize)
{
  Scaleform::BufferedFile::FlushBuffer(this);
  return ((int (__thiscall *)(Scaleform::File *, int))this->pFile.pObject->ChangeSize)(this->pFile.pObject, newSize);
}
