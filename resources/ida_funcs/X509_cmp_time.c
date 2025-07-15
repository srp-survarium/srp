int __cdecl X509_cmp_time(const asn1_string_st *ctm, __int64 *cmp_time)
{
  int length; // ecx
  unsigned __int8 *data; // eax
  int type; // edi
  int v5; // edx
  char *v6; // ecx
  char *v7; // eax
  int result; // eax
  int v9; // ecx
  int v10; // edx
  char v11; // dl
  _BYTE *v12; // ecx
  _BYTE *v13; // ecx
  char i; // dl
  _BYTE *v15; // ecx
  char v16; // dl
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  asn1_string_st s; // [esp+Ch] [ebp-44h] BYREF
  int v21; // [esp+1Ch] [ebp-34h] BYREF
  int v22; // [esp+20h] [ebp-30h]
  int v23; // [esp+24h] [ebp-2Ch] BYREF
  char v24; // [esp+28h] [ebp-28h] BYREF
  char v25[24]; // [esp+34h] [ebp-1Ch] BYREF

  length = ctm->length;
  data = ctm->data;
  type = ctm->type;
  if ( type == 23 )
  {
    if ( (unsigned int)(length - 11) > 6 )
      return 0;
    v5 = *((_DWORD *)data + 1);
    v21 = *(_DWORD *)data;
    LOWORD(v23) = *((_WORD *)data + 4);
    v22 = v5;
    v6 = (char *)&v23 + 2;
    v7 = (char *)(data + 10);
  }
  else
  {
    if ( length < 13 )
      return 0;
    v9 = *((_DWORD *)data + 1);
    v21 = *(_DWORD *)data;
    v10 = *((_DWORD *)data + 2);
    v22 = v9;
    v23 = v10;
    v6 = &v24;
    v7 = (char *)(data + 12);
  }
  v11 = *v7;
  if ( *v7 == 90 || v11 == 45 || v11 == 43 )
  {
    *v6 = 48;
    v15 = v6 + 1;
    *v15 = 48;
    v13 = v15 + 1;
  }
  else
  {
    *v6 = v11;
    v12 = v6 + 1;
    *v12 = v7[1];
    v7 += 2;
    v13 = v12 + 1;
    if ( *v7 == 46 )
    {
      for ( i = *++v7; i >= 48; i = *++v7 )
      {
        if ( i > 57 )
          break;
      }
    }
  }
  v16 = *v7;
  *v13 = 90;
  v13[1] = 0;
  if ( v16 == 90 )
  {
    v17 = 0;
  }
  else
  {
    if ( v16 != 43 && v16 != 45 )
      return 0;
    v17 = v7[4] + 10 * (v7[3] + 6 * (v7[2] + 10 * v7[1])) - 32208;
    if ( v16 == 45 )
      v17 = -v17;
  }
  s.type = type;
  s.flags = 0;
  s.length = 24;
  s.data = (unsigned __int8 *)v25;
  if ( !X509_time_adj_ex(&s, 0, 60 * v17, cmp_time) )
    return 0;
  if ( ctm->type != 23 )
    goto LABEL_31;
  v18 = SBYTE1(v21) + 10 * (char)v21 - 528;
  if ( v18 < 50 )
    v18 += 100;
  v19 = v25[1] + 10 * v25[0] - 528;
  if ( v19 < 50 )
    v19 += 100;
  if ( v18 >= v19 )
  {
    if ( v18 > v19 )
      return 1;
LABEL_31:
    result = strcmp((const char *)&v21, v25);
    if ( result )
      return result;
  }
  return -1;
}
