char *__usercall win32_joiner@<eax>(const file_st *file_split@<esi>, int a2@<ebx>)
{
  int devicelen; // eax
  int v3; // edi
  char *result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ebp
  unsigned __int8 *device; // eax
  const char *predir; // ecx
  int predirlen; // edx
  unsigned __int8 *v13; // eax
  unsigned int v14; // ecx
  unsigned __int8 *v15; // ebx
  int v16; // ebx
  int v17; // edi
  const char *dir; // ecx
  int dirlen; // edx
  unsigned __int8 *v20; // eax
  unsigned int v21; // ecx
  unsigned __int8 *v22; // ebx
  int v23; // ebx
  int v24; // edi
  int v25; // [esp+4h] [ebp-8h]
  unsigned __int8 *v26; // [esp+4h] [ebp-8h]
  int v27; // [esp+4h] [ebp-8h]
  unsigned __int8 *v28; // [esp+4h] [ebp-8h]
  const char *v29; // [esp+8h] [ebp-4h]
  const char *v30; // [esp+8h] [ebp-4h]

  devicelen = 0;
  v3 = 0;
  if ( !file_split )
  {
    ERR_put_error(a2, 0x25u, 135, 67, ".\\crypto\\dso\\dso_win32.c", 443);
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
  v5 = file_split->predirlen + devicelen;
  if ( file_split->predir && (file_split->dir || file_split->file) )
    ++v5;
  v6 = file_split->dirlen + v5;
  if ( file_split->dir && file_split->file )
    ++v6;
  v7 = file_split->filelen + v6;
  if ( !v7 )
  {
    ERR_put_error(a2, 0x25u, 135, 113, ".\\crypto\\dso\\dso_win32.c", 470);
    return 0;
  }
  v8 = (unsigned __int8 *)CRYPTO_malloc(v7 + 1, ".\\crypto\\dso\\dso_win32.c", 474);
  v9 = v8;
  if ( !v8 )
  {
    ERR_put_error(a2, 0x25u, 135, 65, ".\\crypto\\dso\\dso_win32.c", 478);
    return 0;
  }
  if ( file_split->node )
  {
    strcpy((char *)v8, "\\\\");
    strncpy(v8 + 2, (unsigned __int8 *)file_split->node, file_split->nodelen);
    v3 = file_split->nodelen + 2;
    if ( !file_split->predir && !file_split->dir && !file_split->file )
      goto LABEL_31;
    v9[v3] = 92;
    goto LABEL_30;
  }
  device = (unsigned __int8 *)file_split->device;
  if ( device )
  {
    strncpy(v9, device, file_split->devicelen);
    v3 = file_split->devicelen;
    v9[v3] = 58;
LABEL_30:
    ++v3;
  }
LABEL_31:
  predir = file_split->predir;
  predirlen = file_split->predirlen;
  v13 = (unsigned __int8 *)predir;
  if ( predirlen > 0 )
  {
    do
    {
      v29 = &predir[predirlen];
      v14 = &predir[predirlen] - (const char *)v13;
      v25 = 0;
      v15 = v13;
      if ( v14 )
      {
        while ( *v15 )
        {
          if ( *v15 == 47 )
          {
            v26 = v15;
            goto LABEL_37;
          }
          ++v15;
          if ( ++v25 >= v14 )
            break;
        }
      }
      v26 = (unsigned __int8 *)v29;
LABEL_37:
      v16 = v26 - v13;
      strncpy(&v9[v3], v13, v26 - v13);
      v17 = v16 + v3;
      v9[v17] = 92;
      predir = file_split->predir;
      predirlen = file_split->predirlen;
      v13 = v26 + 1;
      v3 = v17 + 1;
    }
    while ( predirlen > v26 + 1 - (unsigned __int8 *)predir );
  }
  dir = file_split->dir;
  dirlen = file_split->dirlen;
  v20 = (unsigned __int8 *)dir;
  if ( dirlen > 0 )
  {
    do
    {
      v30 = &dir[dirlen];
      v21 = &dir[dirlen] - (const char *)v20;
      v27 = 0;
      v22 = v20;
      if ( v21 )
      {
        while ( *v22 )
        {
          if ( *v22 == 47 )
          {
            v28 = v22;
            goto LABEL_44;
          }
          ++v22;
          if ( ++v27 >= v21 )
            break;
        }
      }
      v28 = (unsigned __int8 *)v30;
LABEL_44:
      v23 = v28 - v20;
      strncpy(&v9[v3], v20, v28 - v20);
      v24 = v23 + v3;
      v9[v24] = 92;
      dir = file_split->dir;
      dirlen = file_split->dirlen;
      v20 = v28 + 1;
      v3 = v24 + 1;
    }
    while ( dirlen > v28 + 1 - (unsigned __int8 *)dir );
  }
  strncpy(&v9[v3], (unsigned __int8 *)file_split->file, file_split->filelen);
  result = (char *)v9;
  v9[file_split->filelen + v3] = 0;
  return result;
}
