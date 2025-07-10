int __thiscall Scaleform::GFx::ZLibFile::Tell(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // eax

  pImpl = this->pImpl;
  if ( pImpl )
    return pImpl->UserPos;
  else
    return -1;
}
