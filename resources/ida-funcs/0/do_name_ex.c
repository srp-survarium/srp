int __cdecl do_name_ex(
        int (__cdecl *io_ch)(void *, const void *, int),
        X509_name_st *n,
        int indent,
        unsigned int flags)
{
  void *v4; // ecx
  X509_name_st *v5; // ebp
  int v6; // edi
  HINSTANCE__ *v8; // eax
  void *v9; // ebx
  X509_name_st *v10; // eax
  unsigned int v11; // ecx
  X509_name_entry_st *entry; // eax
  ui_string_st *v13; // esi
  ui_string_st *object; // edi
  void *v15; // eax
  void *v16; // ebp
  int v17; // edi
  char *v18; // eax
  int v19; // esi
  int (__cdecl *v20)(void *, const void *, int); // ebx
  int v21; // edi
  __int16 v22; // cx
  int v23; // eax
  int v24; // [esp+Ch] [ebp-98h]
  void *v25; // [esp+10h] [ebp-94h]
  int v26; // [esp+18h] [ebp-8Ch]
  int v27; // [esp+1Ch] [ebp-88h]
  const char *v28; // [esp+20h] [ebp-84h]
  const char *v29; // [esp+24h] [ebp-80h]
  int v30; // [esp+28h] [ebp-7Ch]
  int loc; // [esp+2Ch] [ebp-78h]
  const char *v32; // [esp+30h] [ebp-74h]
  int v33; // [esp+34h] [ebp-70h]
  int input_flags; // [esp+38h] [ebp-6Ch]
  asn1_string_st *v35; // [esp+44h] [ebp-60h]
  X509_name_st *v36; // [esp+48h] [ebp-5Ch]
  char v37[80]; // [esp+50h] [ebp-54h] BYREF

  v5 = n;
  v6 = indent;
  v25 = v4;
  input_flags = -1;
  if ( indent < 0 )
  {
    indent = 0;
    v6 = 0;
  }
  v24 = v6;
  if ( !do_indent(v4, v6, io_ch) )
    return -1;
  v8 = (HINSTANCE__ *)((unsigned int)&locret_F0000 & flags);
  if ( ((unsigned int)&locret_F0000 & flags) > (unsigned int)&loc_30000 )
  {
    if ( v8 == (HINSTANCE__ *)((char *)&loc_3FFFF + 1) )
    {
      v29 = "\n";
      v26 = 1;
      goto LABEL_14;
    }
    return -1;
  }
  if ( (_UNKNOWN *)((unsigned int)&locret_F0000 & flags) == &loc_30000 )
  {
    v29 = "; ";
    v26 = 2;
    indent = 0;
    goto LABEL_14;
  }
  if ( v8 != &_sbh_sizeHeaderList )
  {
    if ( v8 == (HINSTANCE__ *)&loc_20000 )
    {
      v29 = ", ";
      v26 = 2;
      indent = 0;
LABEL_14:
      v28 = " + ";
      v27 = 3;
      goto LABEL_15;
    }
    return -1;
  }
  v29 = ",";
  v26 = 1;
  v28 = "+";
  v27 = 1;
  indent = 0;
LABEL_15:
  if ( (flags & 0x800000) != 0 )
  {
    v32 = " = ";
    v33 = 3;
  }
  else
  {
    v32 = "=";
    v33 = 1;
  }
  v9 = (void *)((unsigned int)&loc_600000 & flags);
  v10 = X509_NAME_entry_count(n);
  v36 = v10;
  loc = 0;
  if ( (int)v10 > 0 )
  {
    v11 = (unsigned int)&loc_100000 & flags;
    v30 = (int)&v10[-1].canon_enclen + 3;
    while ( 1 )
    {
      if ( v11 )
        entry = X509_NAME_get_entry(v5, v30);
      else
        entry = X509_NAME_get_entry(v5, loc);
      v13 = (ui_string_st *)entry;
      if ( input_flags != -1 )
      {
        if ( input_flags == entry->set )
        {
          if ( !io_ch(v25, v28, v27) )
            return -1;
          v24 += v27;
        }
        else
        {
          if ( !io_ch(v25, v29, v26) || !do_indent(v25, indent, io_ch) )
            return -1;
          v9 = (void *)((unsigned int)&loc_600000 & flags);
          v24 += indent + v26;
        }
      }
      input_flags = v13->input_flags;
      object = X509_EXTENSION_get_object(v13);
      v35 = (asn1_string_st *)UI_get0_output_string(v13);
      v15 = OBJ_obj2nid((const asn1_object_st *)object);
      v16 = v15;
      if ( v9 == &loc_600000 )
      {
        v20 = io_ch;
        goto LABEL_49;
      }
      if ( v9 == &loc_400000 || !v15 )
        break;
      if ( v9 )
      {
        if ( v9 != &loc_200000 )
        {
          v18 = (char *)uri;
LABEL_40:
          v17 = 0;
          goto LABEL_41;
        }
        v17 = 25;
        v18 = (char *)OBJ_nid2ln((int)v9, (unsigned int)v15);
      }
      else
      {
        v17 = 10;
        v18 = (char *)OBJ_nid2sn(0, (unsigned int)v15);
      }
LABEL_41:
      v19 = strlen(v18);
      v20 = io_ch;
      if ( !io_ch(v25, v18, v19) )
        return -1;
      if ( v19 < v17 && (flags & 0x2000000) != 0 )
      {
        v21 = v17 - v19;
        if ( !do_indent(v25, v21, io_ch) )
          return -1;
        v24 += v21;
        v20 = io_ch;
      }
      if ( !v20(v25, v32, v33) )
        return -1;
      v24 += v33 + v19;
LABEL_49:
      if ( v16 || (flags & 0x1000000) == 0 )
        v22 = 0;
      else
        v22 = 128;
      v23 = do_print_ex(v20, flags | v22, v25, v35);
      if ( v23 < 0 )
        return -1;
      v24 += v23;
      --v30;
      if ( ++loc >= (int)v36 )
        return v24;
      v5 = n;
      v11 = (unsigned int)&loc_100000 & flags;
      v9 = (void *)((unsigned int)&loc_600000 & flags);
    }
    OBJ_obj2txt(v37, 0x50u, (const asn1_object_st *)object, 1);
    v18 = v37;
    goto LABEL_40;
  }
  return v24;
}
