int __thiscall Scaleform::DelegatedFile::CopyFromStream(
        Scaleform::DelegatedFile *this,
        Scaleform::File *pstream,
        int byteSize)
{
  return this->pFile.pObject->CopyFromStream(this->pFile.pObject, pstream, byteSize);
}
