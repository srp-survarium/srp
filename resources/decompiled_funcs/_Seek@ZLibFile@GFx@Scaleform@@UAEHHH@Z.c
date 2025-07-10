int __thiscall Scaleform::GFx::ZLibFile::Seek(Scaleform::GFx::ZLibFile *this, int offset, int origin)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // ecx

  pImpl = this->pImpl;
  if ( !pImpl )
    return -1;
  if ( pImpl->ErrorCode )
    return pImpl->UserPos;
  if ( origin )
  {
    if ( origin == 1 )
    {
      Scaleform::GFx::ZLibFileImpl::SetPosition(pImpl, pImpl->UserPos + offset);
      return this->pImpl->UserPos;
    }
    if ( origin == 2 )
    {
      Scaleform::GFx::ZLibFileImpl::SetPosition(pImpl, 0x7FFFFFFF);
      if ( offset )
      {
        Scaleform::GFx::ZLibFileImpl::SetPosition(this->pImpl, this->pImpl->UserPos + offset);
        return this->pImpl->UserPos;
      }
    }
  }
  else
  {
    Scaleform::GFx::ZLibFileImpl::SetPosition(pImpl, offset);
  }
  return this->pImpl->UserPos;
}
