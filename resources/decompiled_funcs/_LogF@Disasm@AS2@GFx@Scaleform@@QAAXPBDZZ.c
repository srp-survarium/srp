void Scaleform::GFx::AS2::Disasm::LogF(Scaleform::GFx::AS2::Disasm *this, const char *pfmt, ...)
{
  va_list va; // [esp+Ch] [ebp+Ch] BYREF

  va_start(va, pfmt);
  if ( this->pLog )
    ((void (__thiscall *)(Scaleform::Log *, int, const char *, char *))this->pLog->LogMessageVarg)(
      this->pLog,
      this->MsgId.Id,
      pfmt,
      va);
}
