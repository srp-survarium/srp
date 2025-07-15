Scaleform::RefCountVImpl *__thiscall Scaleform::GFx::FileOpener::OpenFileEx(
        Scaleform::GFx::FileOpener *this,
        const char *pfilename,
        Scaleform::Log *plog,
        int flags,
        int modes)
{
  Scaleform::File *v5; // eax
  Scaleform::RefCountVImpl *v6; // esi

  v5 = this->OpenFile(this, pfilename, flags, modes);
  v6 = (Scaleform::RefCountVImpl *)v5;
  if ( v5 && !v5->GetErrorCode(v5) )
    return v6;
  if ( plog )
    Scaleform::Log::LogError(plog, "Loader failed to open '%s'", pfilename);
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  return 0;
}
