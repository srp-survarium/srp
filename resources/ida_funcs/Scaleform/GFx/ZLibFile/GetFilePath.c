const char *__thiscall Scaleform::GFx::ZLibFile::GetFilePath(Scaleform::GFx::ZLibFile *this)
{
  Scaleform::GFx::ZLibFileImpl *pImpl; // eax

  pImpl = this->pImpl;
  if ( pImpl )
    return pImpl->pIn.pObject->GetFilePath(pImpl->pIn.pObject);
  else
    return 0;
}
