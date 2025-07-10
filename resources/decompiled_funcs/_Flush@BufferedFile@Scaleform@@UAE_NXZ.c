int __thiscall Scaleform::BufferedFile::Flush(Scaleform::BufferedFile *this)
{
  Scaleform::BufferedFile::FlushBuffer(this);
  return ((int (__thiscall *)(Scaleform::File *))this->pFile.pObject->Flush)(this->pFile.pObject);
}
