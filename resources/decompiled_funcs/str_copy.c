int __cdecl str_copy(conf_st *conf, char *section, char **pto)
{
  char *from; // ecx
  int v4; // ebx
  char *v5; // esi
  buf_mem_st *v6; // edi
  char v8; // al
  _WORD *meth_data; // ecx
  __int16 v10; // dx
  int v11; // edi
  unsigned __int8 v12; // al
  __int16 i; // dx
  int v14; // edx
  char v15; // al
  unsigned __int8 v16; // al
  char v17; // dl
  char *v18; // eax
  char *v19; // edi
  int v20; // edx
  int v21; // edx
  const char *v22; // ecx
  _WORD *v23; // eax
  int v24; // edx
  int v25; // eax
  const char *string; // ebp
  char j; // al
  buf_mem_st *str; // [esp+Ch] [ebp-1Ch]
  int v29; // [esp+10h] [ebp-18h]
  char *name; // [esp+14h] [ebp-14h]
  char *v31; // [esp+18h] [ebp-10h]
  char v32; // [esp+1Ch] [ebp-Ch]
  char v33; // [esp+20h] [ebp-8h]
  char *v34; // [esp+24h] [ebp-4h]

  v4 = 0;
  v5 = from;
  v32 = 0;
  v6 = BUF_MEM_new();
  str = v6;
  if ( !v6 )
    return 0;
  if ( !BUF_MEM_grow(v6, strlen(v5) + 1) )
  {
err_26:
    BUF_MEM_free(str);
    return 0;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v8 = *v5;
          meth_data = conf->meth_data;
          v10 = meth_data[(unsigned __int8)*v5];
          if ( (v10 & 0x40) == 0 )
            break;
          ++v5;
          v11 = v8;
          v12 = *v5;
          for ( i = meth_data[(unsigned __int8)*v5]; (i & 8) == 0; ++v4 )
          {
            if ( (char)v12 == v11 )
              break;
            if ( (i & 0x20) != 0 )
            {
              v12 = *++v5;
              if ( (meth_data[v12] & 8) != 0 )
                break;
            }
            str->data[v4] = v12;
            v12 = v5[1];
            meth_data = conf->meth_data;
            ++v5;
            i = meth_data[v12];
          }
          if ( *v5 == v11 )
            ++v5;
        }
        if ( (meth_data[(unsigned __int8)*v5] & 0x400) == 0 )
          break;
        ++v5;
        v14 = v8;
        v15 = *v5;
        if ( (meth_data[(unsigned __int8)*v5] & 8) == 0 )
        {
          do
          {
            if ( v15 == v14 )
            {
              if ( v5[1] != v14 )
                break;
              ++v5;
            }
            str->data[v4] = *v5;
            v15 = *++v5;
            ++v4;
          }
          while ( (*((_BYTE *)conf->meth_data + 2 * (unsigned __int8)v15) & 8) == 0 );
        }
        if ( *v5 == v14 )
          ++v5;
      }
      if ( (v10 & 0x20) == 0 )
        break;
      v16 = v5[1];
      v5 += 2;
      if ( (meth_data[v16] & 8) != 0 )
        goto LABEL_57;
      if ( v16 == 114 )
      {
        str->data[v4++] = 13;
      }
      else if ( v16 == 110 )
      {
        str->data[v4++] = 10;
      }
      else if ( v16 == 98 )
      {
        str->data[v4++] = 8;
      }
      else
      {
        if ( v16 == 116 )
          v16 = 9;
        str->data[v4++] = v16;
      }
    }
    if ( (v10 & 8) != 0 )
      break;
    if ( v8 == 36 )
    {
      v17 = v5[1];
      v18 = v5 + 1;
      v31 = 0;
      if ( v17 == 123 )
      {
        v29 = 125;
LABEL_35:
        v18 = v5 + 2;
        goto LABEL_36;
      }
      if ( v17 == 40 )
      {
        v29 = 41;
        goto LABEL_35;
      }
      v29 = 0;
LABEL_36:
      name = v18;
      v19 = v18;
      if ( (meth_data[(unsigned __int8)*v18] & 0x107) != 0 )
      {
        do
          v20 = (unsigned __int8)*++v19;
        while ( (meth_data[v20] & 0x107) != 0 );
      }
      if ( *v19 == 58 && v19[1] == 58 )
      {
        *v19 = 0;
        v21 = (unsigned __int8)v19[2];
        v31 = v19;
        v19 += 2;
        v22 = v18;
        v23 = conf->meth_data;
        v32 = 58;
        name = v19;
        if ( (v23[v21] & 0x107) != 0 )
        {
          do
            v24 = (unsigned __int8)*++v19;
          while ( (v23[v24] & 0x107) != 0 );
        }
      }
      else
      {
        v22 = section;
      }
      v25 = *v19;
      v33 = *v19;
      *v19 = 0;
      v34 = v19;
      if ( v29 )
      {
        if ( v25 != v29 )
        {
          ERR_put_error(0xEu, 101, 102, ".\\crypto\\conf\\conf_def.c", 599);
          goto err_26;
        }
        ++v19;
      }
      string = _CONF_get_string(conf, v22, name);
      if ( v31 )
        *v31 = v32;
      *v34 = v33;
      if ( !string )
      {
        ERR_put_error(0xEu, 101, 104, ".\\crypto\\conf\\conf_def.c", 618);
        goto err_26;
      }
      BUF_MEM_grow_clean(str, (unsigned int)&v5[strlen(string) - (_DWORD)v19 + str->length]);
      for ( j = *string; *string; ++v4 )
      {
        ++string;
        str->data[v4] = j;
        j = *string;
      }
      v5 = v19;
      *v34 = v33;
    }
    else
    {
      str->data[v4++] = v8;
      ++v5;
    }
  }
LABEL_57:
  str->data[v4] = 0;
  if ( *pto )
    CRYPTO_free(*pto);
  *pto = str->data;
  CRYPTO_free(str);
  return 1;
}
