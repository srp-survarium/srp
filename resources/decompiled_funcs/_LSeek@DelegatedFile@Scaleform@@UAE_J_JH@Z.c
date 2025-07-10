int __thiscall Scaleform::DelegatedFile::LSeek(Scaleform::DelegatedFile *this, __int64 offset, int origin)
{
  return ((int (__thiscall *)(Scaleform::File *, _DWORD, _DWORD, int))this->pFile.pObject->LSeek)(
           this->pFile.pObject,
           offset,
           HIDWORD(offset),
           origin);
}
