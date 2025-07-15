int __cdecl asn1_cb(const char *elem, int len, tag_exp_arg *bitstr)
{
  const char *v3; // ebx
  unsigned int v4; // esi
  const char *v5; // ebp
  const char *v6; // edi
  int v7; // ecx
  const char *v8; // eax
  int v9; // eax
  tag_exp_arg *v11; // ecx
  int exp_count; // ecx
  tag_exp_type *v13; // eax
  int v14; // edx
  int appended; // eax
  int v16; // [esp-14h] [ebp-24h]
  int v17; // [esp-Ch] [ebp-1Ch]

  v3 = elem;
  v4 = len;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  v8 = elem;
  if ( len > 0 )
  {
    while ( *v8 != 58 )
    {
      ++v7;
      ++v8;
      if ( v7 >= len )
        goto LABEL_6;
    }
    v6 = v8 + 1;
    v5 = (const char *)(len + elem - (v8 + 1));
    v4 = v8 - elem;
  }
LABEL_6:
  v9 = asn1_str2tag(elem, v4);
  if ( v9 == -1 )
  {
    ERR_put_error(0xDu, 177, 194, ".\\crypto\\asn1\\asn1_gen.c", 303);
    ERR_add_error_data(2, "tag=", v3);
    return -1;
  }
  else
  {
    if ( ((unsigned int)&_sbh_sizeHeaderList & v9) != 0 )
    {
      switch ( v9 )
      {
        case 65537:
          if ( bitstr->imp_tag != -1 )
          {
            ERR_put_error(0xDu, 177, 181, ".\\crypto\\asn1\\asn1_gen.c", 329);
            return -1;
          }
          if ( !parse_tagging(v6, (int)v5, &bitstr->imp_class, &bitstr->imp_tag) )
            return -1;
          return 1;
        case 65538:
          if ( !parse_tagging(v6, (int)v5, &len, (int *)&elem) )
            return -1;
          if ( bitstr->imp_tag == -1 )
          {
            exp_count = bitstr->exp_count;
            if ( exp_count != 20 )
            {
              v13 = &bitstr->exp_list[exp_count];
              bitstr->exp_count = exp_count + 1;
              v14 = len;
              v13->exp_tag = (int)elem;
              v13->exp_class = v14;
              v13->exp_constructed = 1;
              v13->exp_pad = 0;
              return 1;
            }
            ERR_put_error(0xDu, 176, 174, ".\\crypto\\asn1\\asn1_gen.c", 524);
          }
          else
          {
            ERR_put_error(0xDu, 176, 179, ".\\crypto\\asn1\\asn1_gen.c", 518);
          }
          return -1;
        case 65540:
          appended = append_exp(bitstr, 3, 0, 0, 1, 1);
          goto LABEL_29;
        case 65541:
          v17 = 0;
          v16 = 4;
          goto LABEL_28;
        case 65542:
          v17 = 1;
          v16 = 16;
LABEL_28:
          appended = append_exp(bitstr, v16, 0, v17, 0, 1);
          goto LABEL_29;
        case 65543:
          appended = append_exp(bitstr, 17, 0, 1, 0, 1);
LABEL_29:
          if ( appended )
            return 1;
          return -1;
        case 65544:
          if ( !strncmp(v6, "ASCII", 5u) )
          {
            bitstr->format = 1;
            return 1;
          }
          if ( !strncmp(v6, "UTF8", 4u) )
          {
            bitstr->format = 2;
            return 1;
          }
          if ( !strncmp(v6, "HEX", 3u) )
          {
            bitstr->format = 3;
            return 1;
          }
          if ( !strncmp(v6, "BITLIST", 3u) )
          {
            bitstr->format = 4;
            return 1;
          }
          ERR_put_error(0xDu, 177, 195, ".\\crypto\\asn1\\asn1_gen.c", 375);
          return -1;
        default:
          return 1;
      }
    }
    v11 = bitstr;
    bitstr->utype = v9;
    v11->str = v6;
    if ( v6 || !v3[v4] )
    {
      return 0;
    }
    else
    {
      ERR_put_error(0xDu, 177, 189, ".\\crypto\\asn1\\asn1_gen.c", 316);
      return -1;
    }
  }
}
