void __thiscall survarium::vostok_scaleform_log::LogMessageVarg(
        survarium::vostok_scaleform_log *this,
        Scaleform::LogMessageId messageId,
        char *fmt,
        char *argList)
{
  char *v4; // esi
  char buffer[4096]; // [esp+4h] [ebp-1000h] BYREF

  v4 = (char *)(((unsigned int)&loc_EFFFF + 1) & messageId.Id);
  Scaleform::Log::FormatLog(buffer, 0x1000u, messageId, fmt, argList);
  if ( (((unsigned int)&loc_EFFFF + 1) & messageId.Id) == 0 )
    goto LABEL_6;
  if ( v4 == (char *)&loc_20000 )
  {
    g_log_output_ptr(2u, buffer);
    return;
  }
  if ( v4 == (char *)&loc_2FFFB + 5 )
    g_log_output_ptr(3u, buffer);
  else
LABEL_6:
    g_log_output_ptr(1u, buffer);
}
