int __cdecl do_name_ex(
        int (__cdecl *io_ch)(void *, const void *, int),
        X509_name_st *n,
        int indent,
        unsigned int flags)
{
  void *arg; // ecx
  X509_name_st *v5; // ebp
  int v6; // edi
  HINSTANCE__ *v8; // eax
  Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *v9)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *); // ebx
  X509_name_st *v10; // eax
  unsigned int v11; // ecx
  X509_name_entry_st *entry; // eax
  ui_string_st *v13; // esi
  ui_string_st *object; // edi
  unsigned int v15; // eax
  unsigned int v16; // ebp
  int v17; // edi
  const char *v18; // eax
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
  asn1_string_st *str; // [esp+44h] [ebp-60h]
  X509_name_st *v36; // [esp+48h] [ebp-5Ch]
  char buf[80]; // [esp+50h] [ebp-54h] BYREF

  v5 = n;
  v6 = indent;
  v25 = arg;
  input_flags = -1;
  if ( indent < 0 )
  {
    indent = 0;
    v6 = 0;
  }
  v24 = v6;
  if ( !do_indent(arg, v6, io_ch) )
    return -1;
  v8 = (HINSTANCE__ *)(flags & 0xF0000);
  if ( (flags & 0xF0000) > 0x30000 )
  {
    if ( v8 == (HINSTANCE__ *)((char *)&loc_3FFFF + 1) )
    {
      v29 = "\n";
      v26 = 1;
      goto LABEL_14;
    }
    return -1;
  }
  if ( (flags & 0xF0000) == 0x30000 )
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
      v29 = (const char *)&stru_95AF78.m_key_bindings[32];
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
  if ( ((unsigned int)&unk_800000 & flags) != 0 )
  {
    v32 = " = ";
    v33 = 3;
  }
  else
  {
    v32 = "=";
    v33 = 1;
  }
  v9 = (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))((unsigned int)&loc_600000 & flags);
  v10 = X509_NAME_entry_count(n);
  v36 = v10;
  loc = 0;
  if ( (int)v10 > 0 )
  {
    v11 = flags & 0x100000;
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
          v9 = (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))((unsigned int)&loc_600000 & flags);
          v24 += indent + v26;
        }
      }
      input_flags = v13->input_flags;
      object = X509_EXTENSION_get_object(v13);
      str = (asn1_string_st *)UI_get0_output_string(v13);
      v15 = OBJ_obj2nid((const asn1_object_st *)object);
      v16 = v15;
      if ( (char *)v9 == (char *)&loc_600000 )
      {
        v20 = io_ch;
        goto LABEL_49;
      }
      if ( v9 == Scaleform::GFx::AS2::CreateShadow || !v15 )
        break;
      if ( v9 )
      {
        if ( v9 != (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))((char *)&loc_1FFFFE + 2) )
        {
          v18 = (const char *)&::buf;
LABEL_40:
          v17 = 0;
          goto LABEL_41;
        }
        v17 = 25;
        v18 = OBJ_nid2ln(v15);
      }
      else
      {
        v17 = 10;
        v18 = OBJ_nid2sn(v15);
      }
LABEL_41:
      v19 = strlen(v18);
      v20 = io_ch;
      if ( !io_ch(v25, v18, v19) )
        return -1;
      if ( v19 < v17 && ((unsigned int)&vostok::memory::s_CRT_arena[22351416] & flags) != 0 )
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
      if ( v16 || ((unsigned int)&vostok::memory::s_CRT_arena[5574200] & flags) == 0 )
        v22 = 0;
      else
        v22 = 128;
      v23 = do_print_ex(v20, flags | v22, v25, str);
      if ( v23 < 0 )
        return -1;
      v24 += v23;
      --v30;
      if ( ++loc >= (int)v36 )
        return v24;
      v5 = n;
      v11 = flags & 0x100000;
      v9 = (Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *(__cdecl *)(Scaleform::Ptr<Scaleform::GFx::AS2::XmlNodeObject> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::XML::Node *, Scaleform::GFx::XML::RootNode *))((unsigned int)&loc_600000 & flags);
    }
    OBJ_obj2txt(buf, 0x50u, (const asn1_object_st *)object, 1);
    v18 = buf;
    goto LABEL_40;
  }
  return v24;
}
