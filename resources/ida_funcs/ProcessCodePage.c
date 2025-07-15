UINT __usercall ProcessCodePage@<eax>(char *lpCodePageStr@<ecx>, setloc_struct *_psetloc_data@<edi>)
{
  char *v2; // esi
  int v3; // eax
  int v4; // eax
  int v6; // eax
  char chCodePage[8]; // [esp+4h] [ebp-Ch] BYREF

  v2 = lpCodePageStr;
  if ( lpCodePageStr )
  {
    if ( *lpCodePageStr )
    {
      strcmp((unsigned __int8 *)lpCodePageStr, "ACP");
      if ( v3 )
      {
        strcmp((unsigned __int8 *)v2, "OCP");
        if ( v4 )
          return atol(v2);
        if ( GetLocaleInfoA(_psetloc_data->lcidCountry, 0xBu, chCodePage, 8) )
        {
LABEL_6:
          v2 = chCodePage;
          return atol(v2);
        }
        return 0;
      }
    }
  }
  if ( !GetLocaleInfoA(_psetloc_data->lcidCountry, 0x1004u, chCodePage, 8) )
    return 0;
  strcmp((unsigned __int8 *)chCodePage, (unsigned __int8 *)&stru_95AF78.m_key_bindings[6].m_keyboard[1]);
  if ( v6 )
    goto LABEL_6;
  return GetACP();
}
