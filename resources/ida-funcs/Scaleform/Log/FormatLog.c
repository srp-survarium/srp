void __usercall Scaleform::Log::FormatLog(
        int a1@<edi>,
        char *buffer,
        unsigned int bufferSize,
        Scaleform::LogMessageId messageId,
        char *fmt,
        char *argList)
{
  char *v6; // eax
  unsigned int v7; // eax
  char *v8; // edi
  unsigned int v9; // esi

  v6 = (char *)((unsigned int)&locret_F0000 & messageId.Id);
  if ( (int)((unsigned int)&locret_F0000 & messageId.Id) > (int)&loc_30000 )
  {
    if ( v6 == (_BYTE *)&loc_3FFFF + 1 )
    {
      strcpy_s(a1, buffer, bufferSize, "Assert: ");
      goto LABEL_11;
    }
    if ( v6 != (_BYTE *)&loc_4FFFF + 1 )
      goto LABEL_11;
LABEL_9:
    *buffer = 0;
    goto LABEL_11;
  }
  if ( (_UNKNOWN *)((unsigned int)&locret_F0000 & messageId.Id) == &loc_30000 )
  {
    strcpy_s(a1, buffer, bufferSize, "Error: ");
    goto LABEL_11;
  }
  if ( !v6 )
    goto LABEL_9;
  if ( v6 == (char *)&loc_20000 )
    strcpy_s(a1, buffer, bufferSize, "Warning: ");
LABEL_11:
  v7 = strlen(buffer);
  v8 = &buffer[v7];
  v9 = bufferSize - v7;
  *v8 = 0;
  if ( vsnprintf_s((int)v8, v9, v8, v9, 0xFFFFFFFF, fmt, argList) == -1 )
    v8[v9 - 1] = 0;
  if ( ((unsigned int)&locret_F0000 & messageId.Id) != 0 )
    strcat_s(a1, buffer, bufferSize, "\n");
}
