BOOL __thiscall Scaleform::Render::FileImageSource::seekFileToDecodeStart(Scaleform::Render::FileImageSource *this)
{
  Scaleform::File *pObject; // ecx
  int v3; // edx

  pObject = this->pFile.pObject;
  return pObject
      && ((int (__thiscall *)(Scaleform::File *, _DWORD, _DWORD, _DWORD))pObject->LSeek)(
           pObject,
           this->FilePos,
           HIDWORD(this->FilePos),
           0) == LODWORD(this->FilePos)
      && v3 == HIDWORD(this->FilePos);
}
