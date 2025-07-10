void Scaleform::GFx::LogState::LogMessageByType(
        Scaleform::GFx::LogState *this,
        Scaleform::LogMessageId messageType,
        const char *pfmt,
        ...)
{
  va_list va; // [esp+10h] [ebp+10h] BYREF

  va_start(va, pfmt);
  ((void (__thiscall *)(Scaleform::GFx::LogState *, int, const char *, char *))this->LogMessageVarg)(
    this,
    messageType.Id,
    pfmt,
    va);
}
