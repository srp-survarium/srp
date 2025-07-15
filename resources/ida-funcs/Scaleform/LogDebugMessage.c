void Scaleform::LogDebugMessage(Scaleform::GFx::AS3::RefCountBaseGC<328> *id, const char *fmt, ...)
{
  Scaleform::Log *GlobalLog; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, fmt);
  GlobalLog = Scaleform::Log::GetGlobalLog();
  if ( GlobalLog )
    ((void (__thiscall *)(Scaleform::Log *, Scaleform::GFx::AS3::RefCountBaseGC<328> *, const char *, char *))GlobalLog->LogMessageVarg)(
      GlobalLog,
      id,
      fmt,
      va);
  else
    Scaleform::Render::JPEG::JPEGRwSource::TermSource(id);
}
