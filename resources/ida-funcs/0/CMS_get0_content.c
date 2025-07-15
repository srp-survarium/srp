asn1_string_st **__usercall CMS_get0_content@<eax>(int a1@<ebx>, asn1_string_st *cms)
{
  asn1_string_st *type; // esi
  int v3; // eax
  asn1_string_st **result; // eax

  type = cms;
  v3 = (int)OBJ_obj2nid((const asn1_object_st *)cms->length);
  if ( v3 > 205 )
  {
    if ( v3 == 786 )
    {
      return (asn1_string_st **)(*(_DWORD *)(cms->type + 12) + 4);
    }
    else
    {
LABEL_11:
      type = (asn1_string_st *)cms->type;
      if ( type->length == 4 )
      {
        return (asn1_string_st **)&type->type;
      }
      else
      {
        ERR_put_error(a1, 0x2Eu, 129, 152, ".\\crypto\\cms\\cms_lib.c", 238);
        return 0;
      }
    }
  }
  else if ( v3 == 205 )
  {
    return (asn1_string_st **)(*(_DWORD *)(cms->type + 20) + 4);
  }
  else
  {
    switch ( v3 )
    {
      case 21:
        return (asn1_string_st **)&type->type;
      case 22:
        result = (asn1_string_st **)(*(_DWORD *)(cms->type + 8) + 4);
        break;
      case 23:
        result = (asn1_string_st **)(*(_DWORD *)(cms->type + 12) + 8);
        break;
      case 25:
        result = (asn1_string_st **)(*(_DWORD *)(cms->type + 8) + 4);
        break;
      case 26:
        result = (asn1_string_st **)(*(_DWORD *)(cms->type + 4) + 8);
        break;
      default:
        goto LABEL_11;
    }
  }
  return result;
}
