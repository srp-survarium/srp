void __cdecl Scaleform::Log::FormatLog(
        char *buffer,
        unsigned int bufferSize,
        Scaleform::LogMessageId messageId,
        const char *fmt,
        char *argList)
{
  char *v5; // eax
  unsigned int v6; // eax
  char *v7; // edi
  int v8; // esi

  v5 = (char *)(messageId.Id & 0xF0000);
  if ( ((unsigned int)messageId.Id & 0xF0000) > 0x30000 )
  {
    if ( v5 == (_BYTE *)&loc_3FFFF + 1 )
    {
      strcpy_s(buffer, bufferSize, "Assert: ");
      goto LABEL_11;
    }
    if ( v5 != (char *)&loc_50000 )
      goto LABEL_11;
LABEL_9:
    *buffer = 0;
    goto LABEL_11;
  }
  if ( (messageId.Id & 0xF0000) == 0x30000 )
  {
    strcpy_s(buffer, bufferSize, "Error: ");
    goto LABEL_11;
  }
  if ( !v5 )
    goto LABEL_9;
  if ( v5 == (char *)&loc_20000 )
    strcpy_s(buffer, bufferSize, "Warning: ");
LABEL_11:
  v6 = strlen(buffer);
  v7 = &buffer[v6];
  v8 = bufferSize - v6;
  buffer[v6] = 0;
  if ( vsnprintf_s(&buffer[v6], bufferSize - v6, 0xFFFFFFFF, fmt, argList) == -1 )
    v7[v8 - 1] = 0;
  if ( (messageId.Id & 0xF0000) != 0 )
    strcat_s(buffer, bufferSize, "\n");
}
