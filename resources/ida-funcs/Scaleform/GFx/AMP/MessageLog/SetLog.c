void __thiscall Scaleform::GFx::AMP::MessageLog::SetLog(
        Scaleform::GFx::AMP::MessageLog *this,
        const Scaleform::String *logText,
        unsigned int logCategory,
        const unsigned __int64 timeStamp)
{
  _BYTE v5[12]; // [esp+10h] [ebp-Ch] BYREF

  Scaleform::String::operator=(&this->LogText, logText);
  this->LogCategory = logCategory;
  Scaleform::SFsprintf(
    v5,
    9u,
    "%02u:%02u:%02u",
    (unsigned int)(timeStamp / 0xE10 % 0x18),
    (unsigned int)(timeStamp / 0x3C % 0x3C),
    (unsigned int)(timeStamp % 0x3C));
  Scaleform::String::operator=(&this->TimeStamp, (const __m128i *)v5);
}
