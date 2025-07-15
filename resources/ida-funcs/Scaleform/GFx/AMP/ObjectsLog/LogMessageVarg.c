void __userpurge Scaleform::GFx::AMP::ObjectsLog::LogMessageVarg(
        Scaleform::GFx::AMP::ObjectsLog *this@<ecx>,
        int a2@<edi>,
        Scaleform::LogMessageId messageType,
        char *pfmt,
        char *argList)
{
  __m128i v6[256]; // [esp+4h] [ebp-1000h] BYREF

  Scaleform::Log::FormatLog(a2, v6[0].m128i_i8, 0x1000u, messageType, pfmt, argList);
  Scaleform::StringBuffer::AppendString(&this->Report, v6, 0xFFFFFFFF);
}
