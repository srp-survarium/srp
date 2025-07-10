void Scaleform::LogDebugMessage(Scaleform::LogMessageId id, const char *fmt, ...)
{
  Scaleform::Log *GlobalLog; // eax
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, fmt);
  GlobalLog = Scaleform::Log::GetGlobalLog();
  if ( GlobalLog )
    ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))GlobalLog->LogMessageVarg)(
      GlobalLog,
      id.Id,
      fmt,
      va);
  else
    Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)id.Id);
}
