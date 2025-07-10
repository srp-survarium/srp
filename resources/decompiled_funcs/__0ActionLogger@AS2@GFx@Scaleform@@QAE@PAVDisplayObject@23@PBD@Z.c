void __thiscall Scaleform::GFx::AS2::ActionLogger::ActionLogger(
        Scaleform::GFx::AS2::ActionLogger *this,
        Scaleform::GFx::DisplayObject *ptarget,
        const char *suffixStr)
{
  Scaleform::GFx::MovieImpl *MovieImpl; // edi
  int v5; // eax
  Scaleform::Log *CachedLog; // eax
  bool v7; // zf
  int v8; // eax
  const char *LogSuffix; // edx
  char v10; // cl

  this->__vftable = (Scaleform::GFx::AS2::ActionLogger_vtbl *)&Scaleform::GFx::AS2::ActionLogger::`vftable';
  MovieImpl = Scaleform::GFx::DisplayObjectBase::FindMovieImpl(ptarget);
  this->VerboseAction = (MovieImpl->Flags & 4) != 0;
  this->VerboseActionErrors = (MovieImpl->Flags & 0x40) == 0;
  this->LogSuffix = suffixStr;
  if ( suffixStr )
  {
    v5 = (int)MovieImpl->GetMovieDef(MovieImpl);
    if ( !strcmp((const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 48))(v5), this->LogSuffix) )
      this->UseSuffix = (MovieImpl->Flags & 8) != 0;
    else
      this->UseSuffix = (MovieImpl->Flags & 0x10) != 0;
  }
  else
  {
    this->UseSuffix = 0;
  }
  CachedLog = Scaleform::GFx::MovieImpl::GetCachedLog(MovieImpl);
  v7 = !this->UseSuffix;
  this->pLog = CachedLog;
  if ( !v7 && (MovieImpl->Flags & 0x20) == 0 )
  {
    v8 = strlen(suffixStr);
    if ( v8 > 0 )
    {
      LogSuffix = this->LogSuffix;
      while ( 1 )
      {
        v10 = LogSuffix[v8];
        if ( v10 == 47 || v10 == 92 )
          break;
        if ( --v8 <= 0 )
          return;
      }
      this->LogSuffix = &LogSuffix[v8 + 1];
    }
  }
}
