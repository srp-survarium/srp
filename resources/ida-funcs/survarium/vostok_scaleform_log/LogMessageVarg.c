void __thiscall survarium::vostok_scaleform_log::LogMessageVarg(
        survarium::vostok_scaleform_log *this,
        Scaleform::LogMessageId messageId,
        char *fmt,
        char *argList)
{
  void *v4; // esi
  char buffer[4096]; // [esp+4h] [ebp-1000h] BYREF

  v4 = (void *)((unsigned int)&locret_F0000 & messageId.Id);
  Scaleform::Log::FormatLog(buffer, 0x1000u, messageId, fmt, argList);
  if ( ((unsigned int)&locret_F0000 & messageId.Id) == 0 )
    goto LABEL_6;
  if ( v4 == &loc_20000 )
  {
    g_log_output_ptr(2u, buffer);
    return;
  }
  if ( v4 == &loc_30000 )
    g_log_output_ptr(3u, buffer);
  else
LABEL_6:
    g_log_output_ptr(1u, buffer);
}
