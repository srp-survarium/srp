int __thiscall Scaleform::GFx::ZLibFile::BytesAvailable(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // eax
  int UserPos; // edi
  int v5; // ebx

  pImpl = this->pImpl;
  if ( !pImpl || pImpl->ErrorCode )
    return 0;
  UserPos = pImpl->UserPos;
  v5 = this->Seek(this, 0, 2);
  this->Seek(this, UserPos, 0);
  return v5 - UserPos;
}
