void __cdecl ERR_error_string_n(unsigned int e, char *buf, unsigned int len)
{
  unsigned int v3; // edi
  char *v4; // edx
  char *v5; // ecx
  char *v6; // eax
  char *v7; // eax
  int v8; // esi
  char *v9; // ebp
  char *v10; // eax
  ERR_string_data_st *v11; // [esp+10h] [ebp-D0h]
  ERR_string_data_st *v12; // [esp+14h] [ebp-CCh]
  ERR_string_data_st *v13; // [esp+18h] [ebp-C8h]
  char v14[64]; // [esp+1Ch] [ebp-C4h] BYREF
  char v15[64]; // [esp+5Ch] [ebp-84h] BYREF
  char bufa[64]; // [esp+9Ch] [ebp-44h] BYREF

  v3 = (e >> 12) & 0xFFF;
  v12 = ERR_lib_error_string(v3, e);
  v11 = ERR_func_error_string(v3, e);
  v13 = ERR_reason_error_string(v3, e);
  if ( !v12 )
    BIO_snprintf(bufa, 0x40u, "lib(%lu)", HIBYTE(e));
  if ( !v11 )
    BIO_snprintf(v14, 0x40u, "func(%lu)", v3);
  v4 = (char *)v13;
  if ( !v13 )
  {
    BIO_snprintf(v15, 0x40u, "reason(%lu)", e & 0xFFF);
    v4 = v15;
  }
  v5 = (char *)v11;
  if ( !v11 )
    v5 = v14;
  v6 = (char *)v12;
  if ( !v12 )
    v6 = bufa;
  BIO_snprintf(buf, len, "error:%08lX:%s:%s:%s", e, v6, v5, v4);
  if ( strlen(buf) == len - 1 && len > 4 )
  {
    v7 = buf;
    v8 = 0;
    v9 = &buf[len];
    do
    {
      strchr(v7, 0x3Au);
      if ( !v10 || v10 > &v9[v8 - 5] )
      {
        v10 = &v9[v8 - 5];
        *v10 = 58;
      }
      ++v8;
      v7 = v10 + 1;
    }
    while ( v8 < 4 );
  }
}
