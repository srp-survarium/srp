void Scaleform::Log::LogWarning(Scaleform::Log *this, const char *fmt, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, fmt);
  ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))this->LogMessageVarg)(this, 135168, fmt, va);
}
