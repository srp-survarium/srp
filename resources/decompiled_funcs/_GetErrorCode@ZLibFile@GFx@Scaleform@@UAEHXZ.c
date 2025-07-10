int __thiscall Scaleform::GFx::ZLibFile::GetErrorCode(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // eax

  pImpl = this->pImpl;
  if ( pImpl )
    return pImpl->ErrorCode;
  else
    return 0;
}
