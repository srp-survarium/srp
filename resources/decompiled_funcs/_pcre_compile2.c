void *__cdecl pcre_compile2(unsigned __int8 *buf, unsigned int a2, int *a3, _DWORD *a4, _DWORD *a5, char *a6)
{
  int v7; // eax
  __int16 v8; // [esp+0h] [ebp-10F0h]
  __int16 v9; // [esp+4h] [ebp-10ECh]
  int v10; // [esp+8h] [ebp-10E8h]
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *v11)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *); // [esp+Ch] [ebp-10E4h]
  int v12; // [esp+18h] [ebp-10D8h]
  unsigned __int8 v13; // [esp+1Ch] [ebp-10D4h]
  unsigned __int8 *v14; // [esp+20h] [ebp-10D0h]
  unsigned __int8 *i; // [esp+24h] [ebp-10CCh]
  int v16; // [esp+28h] [ebp-10C8h]
  int v17; // [esp+2Ch] [ebp-10C4h]
  int v18; // [esp+30h] [ebp-10C0h]
  unsigned __int8 *bracket; // [esp+34h] [ebp-10BCh]
  int v20; // [esp+38h] [ebp-10B8h]
  int v21; // [esp+3Ch] [ebp-10B4h]
  _BYTE v22[4100]; // [esp+40h] [ebp-10B0h] BYREF
  BOOL v23; // [esp+1044h] [ebp-ACh]
  void *pointer; // [esp+1048h] [ebp-A8h]
  int v25; // [esp+104Ch] [ebp-A4h]
  char v26; // [esp+1050h] [ebp-A0h] BYREF
  int v27; // [esp+10C8h] [ebp-28h] BYREF
  int valid; // [esp+10CCh] [ebp-24h] BYREF
  unsigned int size; // [esp+10D0h] [ebp-20h]
  unsigned __int8 *v30; // [esp+10D4h] [ebp-1Ch] BYREF
  unsigned __int8 *v31; // [esp+10D8h] [ebp-18h] BYREF
  char *v32; // [esp+10DCh] [ebp-14h]
  int v33; // [esp+10E0h] [ebp-10h]
  unsigned __int8 *v34; // [esp+10E4h] [ebp-Ch]
  int v35; // [esp+10E8h] [ebp-8h] BYREF
  int v36; // [esp+10ECh] [ebp-4h] BYREF

  v35 = 1;
  valid = 0;
  v25 = 0;
  v32 = &v26;
  v31 = buf;
  if ( !a4 )
  {
    if ( a3 )
      *a3 = 99;
    return 0;
  }
  *a4 = 0;
  if ( a3 )
    *a3 = 0;
  if ( !a5 )
  {
    valid = 16;
LABEL_110:
    *a4 = sub_5091D0(valid);
    if ( a3 )
      *a3 = valid;
    return 0;
  }
  *a5 = 0;
  if ( !a6 )
    a6 = (char *)&_pcre_default_tables;
  *(_DWORD *)v32 = a6;
  *((_DWORD *)v32 + 1) = a6 + 256;
  *((_DWORD *)v32 + 2) = a6 + 512;
  *((_DWORD *)v32 + 3) = a6 + 832;
  if ( (a2 & 0xD8038580) != 0 )
  {
    valid = 17;
LABEL_109:
    *a5 = v31 - buf;
    goto LABEL_110;
  }
  while ( v31[v25] == 40 && v31[v25 + 1] == 42 )
  {
    v20 = 0;
    v21 = 0;
    if ( !strncmp((const char *)&v31[v25 + 2], "UTF8)", 5u) )
    {
      v25 += 7;
      a2 |= 0x800u;
    }
    else if ( !strncmp((const char *)&v31[v25 + 2], "UCP)", 4u) )
    {
      v25 += 6;
      a2 |= 0x20000000u;
    }
    else if ( !strncmp((const char *)&v31[v25 + 2], "NO_START_OPT)", 0xDu) )
    {
      v25 += 15;
      a2 |= 0x4000000u;
    }
    else
    {
      if ( !strncmp((const char *)&v31[v25 + 2], "CR)", 3u) )
      {
        v25 += 5;
        v20 = 0x100000;
      }
      else if ( !strncmp((const char *)&v31[v25 + 2], "LF)", 3u) )
      {
        v25 += 5;
        v20 = 0x200000;
      }
      else if ( !strncmp((const char *)&v31[v25 + 2], "CRLF)", 5u) )
      {
        v25 += 7;
        v20 = 3145728;
      }
      else if ( !strncmp((const char *)&v31[v25 + 2], "ANY)", 4u) )
      {
        v25 += 6;
        v20 = (int)Scaleform::GFx::AS2::CreateShadow;
      }
      else if ( !strncmp((const char *)&v31[v25 + 2], "ANYCRLF)", 8u) )
      {
        v25 += 10;
        v20 = 5242880;
      }
      else if ( !strncmp((const char *)&v31[v25 + 2], "BSR_ANYCRLF)", 0xCu) )
      {
        v25 += 14;
        v21 = (int)&unk_800000;
      }
      else if ( !strncmp((const char *)&v31[v25 + 2], "BSR_UNICODE)", 0xCu) )
      {
        v25 += 14;
        v21 = 0x1000000;
      }
      if ( v20 )
      {
        a2 = v20 | a2 & 0xFF8FFFFF;
      }
      else
      {
        if ( !v21 )
          break;
        a2 = v21 | a2 & 0xFE7FFFFF;
      }
    }
  }
  v23 = (a2 & 0x800) != 0;
  if ( (a2 & 0x800) != 0 && (a2 & 0x2000) == 0 )
  {
    valid = _pcre_valid_utf8(buf, -1, a5);
    if ( valid )
    {
      valid = 44;
      goto LABEL_110;
    }
  }
  if ( (a2 & 0x20000000) != 0 )
  {
    valid = 67;
    goto LABEL_109;
  }
  if ( (a2 & 0x1800000) == 0x1800000 )
  {
    valid = 56;
    goto LABEL_109;
  }
  v11 = (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))(a2 & 0x700000);
  if ( (a2 & 0x700000) > 0x300000 )
  {
    if ( v11 == Scaleform::GFx::AS2::CreateShadow )
    {
      v33 = -1;
    }
    else
    {
      if ( v11 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_4FFFFF + 1) )
        goto LABEL_62;
      v33 = -2;
    }
  }
  else if ( v11 == (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_2FFFFF + 1) )
  {
    v33 = 3338;
  }
  else if ( v11 )
  {
    if ( v11 == (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_FFFFF + 1) )
    {
      v33 = 13;
    }
    else
    {
      if ( v11 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::ElementNode *, Scaleform::GFx::XML::RootNode *))((char *)&loc_1FFFFE + 2) )
      {
LABEL_62:
        valid = 56;
        goto LABEL_109;
      }
      v33 = 10;
    }
  }
  else
  {
    v33 = -2;
  }
  if ( v33 == -2 )
  {
    *((_DWORD *)v32 + 24) = 2;
  }
  else if ( v33 >= 0 )
  {
    *((_DWORD *)v32 + 24) = 0;
    if ( v33 <= 255 )
    {
      *((_DWORD *)v32 + 25) = 1;
      v32[104] = v33;
    }
    else
    {
      *((_DWORD *)v32 + 25) = 2;
      v32[104] = BYTE1(v33);
      v32[105] = v33;
    }
  }
  else
  {
    *((_DWORD *)v32 + 24) = 1;
  }
  *((_DWORD *)v32 + 16) = 0;
  *((_DWORD *)v32 + 17) = 0;
  *((_DWORD *)v32 + 15) = 0;
  *((_DWORD *)v32 + 14) = 0;
  *((_DWORD *)v32 + 11) = 0;
  *((_DWORD *)v32 + 12) = 0;
  *((_DWORD *)v32 + 10) = 0;
  *((_DWORD *)v32 + 5) = v22;
  *((_DWORD *)v32 + 9) = v22;
  *((_DWORD *)v32 + 4) = v22;
  *((_DWORD *)v32 + 13) = 4096;
  *((_DWORD *)v32 + 6) = buf;
  strlen(buf);
  *((_DWORD *)v32 + 7) = &buf[v7];
  *((_DWORD *)v32 + 21) = 0;
  *((_DWORD *)v32 + 19) = a2;
  *((_DWORD *)v32 + 20) = 0;
  *((_DWORD *)v32 + 8) = 0;
  v31 += v25;
  v30 = v22;
  v22[0] = 125;
  sub_5096F0(*((_DWORD *)v32 + 19), &v30, &v31, &valid, 0, 0, 0, 0, &v36, &v27, 0, v32, &v35);
  if ( valid )
    goto LABEL_109;
  if ( v35 > (int)&_sbh_sizeHeaderList )
  {
    valid = 20;
    goto LABEL_109;
  }
  size = v35 + *((_DWORD *)v32 + 12) * *((_DWORD *)v32 + 11) + 40;
  pointer = pcre_malloc(size);
  if ( !pointer )
  {
    valid = 21;
    goto LABEL_109;
  }
  *(_DWORD *)pointer = 1346589253;
  *((_DWORD *)pointer + 1) = size;
  *((_DWORD *)pointer + 2) = *((_DWORD *)v32 + 19);
  *((_WORD *)pointer + 6) = *((_WORD *)v32 + 40);
  *((_WORD *)pointer + 7) = 0;
  *((_WORD *)pointer + 10) = 0;
  *((_WORD *)pointer + 11) = 0;
  *((_WORD *)pointer + 12) = 40;
  *((_WORD *)pointer + 13) = *((_WORD *)v32 + 24);
  *((_WORD *)pointer + 14) = *((_WORD *)v32 + 22);
  *((_WORD *)pointer + 15) = 0;
  *((_DWORD *)pointer + 8) = &_pcre_default_tables != (_UNKNOWN *)a6 ? a6 : 0;
  *((_DWORD *)pointer + 9) = 0;
  *((_DWORD *)v32 + 15) = *((_DWORD *)v32 + 14);
  *((_DWORD *)v32 + 18) = 0;
  *((_DWORD *)v32 + 14) = 0;
  *((_DWORD *)v32 + 11) = 0;
  *((_DWORD *)v32 + 10) = (char *)pointer + *((unsigned __int16 *)pointer + 12);
  v34 = (unsigned __int8 *)(*((_DWORD *)v32 + 10)
                          + *((unsigned __int16 *)pointer + 14) * *((unsigned __int16 *)pointer + 13));
  *((_DWORD *)v32 + 5) = v34;
  *((_DWORD *)v32 + 9) = *((_DWORD *)v32 + 4);
  *((_DWORD *)v32 + 21) = 0;
  *((_DWORD *)v32 + 22) = 0;
  *((_DWORD *)v32 + 23) = 0;
  *((_DWORD *)v32 + 8) = 0;
  v31 = &buf[v25];
  v30 = v34;
  *v34 = 125;
  sub_5096F0(*((_DWORD *)pointer + 2), &v30, &v31, &valid, 0, 0, 0, 0, &v36, &v27, 0, v32, 0);
  *((_WORD *)pointer + 8) = *((_WORD *)v32 + 28);
  *((_WORD *)pointer + 9) = *((_WORD *)v32 + 32);
  *((_WORD *)pointer + 6) = *((_WORD *)v32 + 40);
  if ( *((_DWORD *)v32 + 22) )
    v27 = -1;
  if ( !valid && *v31 )
    valid = 22;
  *v30++ = 0;
  if ( v30 - v34 > v35 )
    valid = 23;
  if ( *((_DWORD *)v32 + 9) > *((_DWORD *)v32 + 4) )
  {
    v18 = -1;
    bracket = 0;
    while ( !valid && *((_DWORD *)v32 + 9) > *((_DWORD *)v32 + 4) )
    {
      *((_DWORD *)v32 + 9) -= 2;
      v16 = *(unsigned __int8 *)(*((_DWORD *)v32 + 9) + 1) | (**((unsigned __int8 **)v32 + 9) << 8);
      v17 = v34[v16 + 1] | (v34[v16] << 8);
      if ( v17 != v18 )
      {
        bracket = _pcre_find_bracket((unsigned __int8 *)v23, v34, v23, v17);
        v18 = v17;
      }
      if ( bracket )
      {
        v34[v16] = (unsigned __int16)((_WORD)bracket - (_WORD)v34) >> 8;
        v34[v16 + 1] = (_BYTE)bracket - (_BYTE)v34;
      }
      else
      {
        valid = 53;
      }
    }
  }
  if ( *((int *)v32 + 13) > 4096 )
    pcre_free(*((void **)v32 + 4));
  if ( !valid && *((unsigned __int16 *)pointer + 9) > (int)*((unsigned __int16 *)pointer + 8) )
    valid = 15;
  if ( *((_DWORD *)v32 + 23) )
  {
    for ( i = _pcre_find_bracket(v34, v34, v23, -1); i; i = _pcre_find_bracket((unsigned __int8 *)v23, i + 3, v23, -1) )
    {
      if ( !(i[2] | (i[1] << 8)) )
      {
        v14 = &i[(*(i - 1) | (*(i - 2) << 8)) - 3];
        v13 = *v14;
        *v14 = 0;
        v12 = sub_509220(i, (*((_DWORD *)pointer + 2) & 0x800) != 0, 1, v32);
        *v14 = v13;
        if ( v12 < 0 )
        {
          if ( v12 == -2 )
            v10 = 36;
          else
            v10 = v12 != -4 ? 25 : 70;
          valid = v10;
          break;
        }
        i[1] = BYTE1(v12);
        i[2] = v12;
      }
    }
  }
  if ( valid )
  {
    pcre_free(pointer);
    goto LABEL_109;
  }
  if ( (*((_DWORD *)pointer + 2) & 0x10) == 0 )
  {
    if ( sub_5125D0(v34, 0, *((_DWORD *)v32 + 17)) )
    {
      *((_DWORD *)pointer + 2) |= 0x10u;
    }
    else
    {
      if ( v36 < 0 )
        v36 = sub_5129B0(v34, 0);
      if ( v36 < 0 )
      {
        if ( sub_512770(v34, 0, *((_DWORD *)v32 + 17)) )
          *((_WORD *)pointer + 6) |= 8u;
      }
      else
      {
        if ( (v36 & 0x100) != 0
          && *(unsigned __int8 *)(*((_DWORD *)v32 + 1) + (unsigned __int8)v36) == (unsigned __int8)v36 )
        {
          v9 = (unsigned __int8)v36;
        }
        else
        {
          v9 = v36;
        }
        *((_WORD *)pointer + 10) = v9;
        *((_WORD *)pointer + 6) |= 2u;
      }
    }
  }
  if ( v27 >= 0 && ((*((_DWORD *)pointer + 2) & 0x10) == 0 || (v27 & 0x200) != 0) )
  {
    if ( (v27 & 0x100) != 0 && *(unsigned __int8 *)(*((_DWORD *)v32 + 1) + (unsigned __int8)v27) == (unsigned __int8)v27 )
      v8 = v27 & 0xFEFF;
    else
      v8 = v27;
    *((_WORD *)pointer + 11) = v8;
    *((_WORD *)pointer + 6) |= 4u;
  }
  return pointer;
}
