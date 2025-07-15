char *__usercall win32_joiner@<eax>(const file_st *file_split@<esi>)
{
  int devicelen; // eax
  int v2; // edi
  char *result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // ebp
  unsigned __int8 *device; // eax
  const char *predir; // ecx
  int predirlen; // edx
  unsigned __int8 *v12; // eax
  unsigned int v13; // ecx
  unsigned __int8 *v14; // ebx
  int v15; // ebx
  int v16; // edi
  const char *dir; // ecx
  int dirlen; // edx
  unsigned __int8 *v19; // eax
  unsigned int v20; // ecx
  unsigned __int8 *v21; // ebx
  int v22; // ebx
  int v23; // edi
  int v24; // [esp+4h] [ebp-8h]
  unsigned __int8 *v25; // [esp+4h] [ebp-8h]
  int v26; // [esp+4h] [ebp-8h]
  unsigned __int8 *v27; // [esp+4h] [ebp-8h]
  const char *v28; // [esp+8h] [ebp-4h]
  const char *v29; // [esp+8h] [ebp-4h]

  devicelen = 0;
  v2 = 0;
  if ( !file_split )
  {
    ERR_put_error(0x25u, 135, 67, ".\\crypto\\dso\\dso_win32.c", 443);
    return 0;
  }
  if ( file_split->node )
  {
    devicelen = file_split->nodelen + 2;
    if ( file_split->predir || file_split->dir || file_split->file )
      goto LABEL_11;
  }
  else if ( file_split->device )
  {
    devicelen = file_split->devicelen;
LABEL_11:
    ++devicelen;
  }
  v4 = file_split->predirlen + devicelen;
  if ( file_split->predir && (file_split->dir || file_split->file) )
    ++v4;
  v5 = file_split->dirlen + v4;
  if ( file_split->dir && file_split->file )
    ++v5;
  v6 = file_split->filelen + v5;
  if ( !v6 )
  {
    ERR_put_error(0x25u, 135, 113, ".\\crypto\\dso\\dso_win32.c", 470);
    return 0;
  }
  v7 = (unsigned __int8 *)CRYPTO_malloc(v6 + 1, ".\\crypto\\dso\\dso_win32.c", 474);
  v8 = v7;
  if ( !v7 )
  {
    ERR_put_error(0x25u, 135, 65, ".\\crypto\\dso\\dso_win32.c", 478);
    return 0;
  }
  if ( file_split->node )
  {
    strcpy((char *)v7, "\\\\");
    strncpy(v7 + 2, (unsigned __int8 *)file_split->node, file_split->nodelen);
    v2 = file_split->nodelen + 2;
    if ( !file_split->predir && !file_split->dir && !file_split->file )
      goto LABEL_31;
    v8[v2] = 92;
    goto LABEL_30;
  }
  device = (unsigned __int8 *)file_split->device;
  if ( device )
  {
    strncpy(v8, device, file_split->devicelen);
    v2 = file_split->devicelen;
    v8[v2] = 58;
LABEL_30:
    ++v2;
  }
LABEL_31:
  predir = file_split->predir;
  predirlen = file_split->predirlen;
  v12 = (unsigned __int8 *)predir;
  if ( predirlen > 0 )
  {
    do
    {
      v28 = &predir[predirlen];
      v13 = &predir[predirlen] - (const char *)v12;
      v24 = 0;
      v14 = v12;
      if ( v13 )
      {
        while ( *v14 )
        {
          if ( *v14 == 47 )
          {
            v25 = v14;
            goto LABEL_37;
          }
          ++v14;
          if ( ++v24 >= v13 )
            break;
        }
      }
      v25 = (unsigned __int8 *)v28;
LABEL_37:
      v15 = v25 - v12;
      strncpy(&v8[v2], v12, v25 - v12);
      v16 = v15 + v2;
      v8[v16] = 92;
      predir = file_split->predir;
      predirlen = file_split->predirlen;
      v12 = v25 + 1;
      v2 = v16 + 1;
    }
    while ( predirlen > v25 + 1 - (unsigned __int8 *)predir );
  }
  dir = file_split->dir;
  dirlen = file_split->dirlen;
  v19 = (unsigned __int8 *)dir;
  if ( dirlen > 0 )
  {
    do
    {
      v29 = &dir[dirlen];
      v20 = &dir[dirlen] - (const char *)v19;
      v26 = 0;
      v21 = v19;
      if ( v20 )
      {
        while ( *v21 )
        {
          if ( *v21 == 47 )
          {
            v27 = v21;
            goto LABEL_44;
          }
          ++v21;
          if ( ++v26 >= v20 )
            break;
        }
      }
      v27 = (unsigned __int8 *)v29;
LABEL_44:
      v22 = v27 - v19;
      strncpy(&v8[v2], v19, v27 - v19);
      v23 = v22 + v2;
      v8[v23] = 92;
      dir = file_split->dir;
      dirlen = file_split->dirlen;
      v19 = v27 + 1;
      v2 = v23 + 1;
    }
    while ( dirlen > v27 + 1 - (unsigned __int8 *)dir );
  }
  strncpy(&v8[v2], (unsigned __int8 *)file_split->file, file_split->filelen);
  result = (char *)v8;
  v8[file_split->filelen + v2] = 0;
  return result;
}
