int __thiscall Scaleform::GFx::ZLibFile::Read(Scaleform::GFx::ZLibFile *this, unsigned __int8 *pbuffer, int numBytes)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // ecx

  pImpl = this->pImpl;
  if ( pImpl )
    return Scaleform::GFx::ZLibFileImpl::Inflate(pImpl, pbuffer, numBytes);
  else
    return -1;
}
