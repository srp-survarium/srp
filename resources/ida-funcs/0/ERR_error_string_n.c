void __cdecl ERR_error_string_n(unsigned int e, char *buf, unsigned int len)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  char *v5; // edx
  char *v6; // ecx
  char *v7; // eax
  char *v8; // eax
  int v9; // esi
  char *v10; // ebp
  char *v11; // eax
  ERR_string_data_st *v12; // [esp+10h] [ebp-D0h]
  ERR_string_data_st *v13; // [esp+14h] [ebp-CCh]
  ERR_string_data_st *v14; // [esp+18h] [ebp-C8h]
  char v15[64]; // [esp+1Ch] [ebp-C4h] BYREF
  char v16[64]; // [esp+5Ch] [ebp-84h] BYREF
  char bufa[64]; // [esp+9Ch] [ebp-44h] BYREF

  v3 = (e >> 12) & 0xFFF;
  v4 = e & 0xFFF;
  v13 = ERR_lib_error_string(v3, v4, e);
  v12 = ERR_func_error_string(v3, v4, e);
  v14 = ERR_reason_error_string(v3, v4, e);
  if ( !v13 )
    BIO_snprintf(bufa, 0x40u, "lib(%lu)", HIBYTE(e));
  if ( !v12 )
    BIO_snprintf(v15, 0x40u, "func(%lu)", v3);
  v5 = (char *)v14;
  if ( !v14 )
  {
    BIO_snprintf(v16, 0x40u, "reason(%lu)", v4);
    v5 = v16;
  }
  v6 = (char *)v12;
  if ( !v12 )
    v6 = v15;
  v7 = (char *)v13;
  if ( !v13 )
    v7 = bufa;
  BIO_snprintf(buf, len, "error:%08lX:%s:%s:%s", e, v7, v6, v5);
  if ( strlen(buf) == len - 1 && len > 4 )
  {
    v8 = buf;
    v9 = 0;
    v10 = &buf[len];
    do
    {
      strchr(v8, 0x3Au);
      if ( !v11 || v11 > &v10[v9 - 5] )
      {
        v11 = &v10[v9 - 5];
        *v11 = 58;
      }
      ++v9;
      v8 = v11 + 1;
    }
    while ( v9 < 4 );
  }
}
