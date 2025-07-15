UINT __usercall ProcessCodePage@<eax>(char *lpCodePageStr@<ecx>, setloc_struct *_psetloc_data@<edi>, int a3@<ebx>)
{
  char *v3; // esi
  int v4; // eax
  int v5; // eax
  int v7; // eax
  char LCData[8]; // [esp+4h] [ebp-Ch] BYREF

  v3 = lpCodePageStr;
  if ( lpCodePageStr )
  {
    if ( *lpCodePageStr )
    {
      strcmp((unsigned __int8 *)lpCodePageStr, "ACP");
      if ( v4 )
      {
        strcmp((unsigned __int8 *)v3, "OCP");
        if ( v5 )
          return atol(a3, v3);
        if ( GetLocaleInfoA(_psetloc_data->lcidCountry, 0xBu, LCData, 8) )
        {
LABEL_6:
          v3 = LCData;
          return atol(a3, v3);
        }
        return 0;
      }
    }
  }
  if ( !GetLocaleInfoA(_psetloc_data->lcidCountry, 0x1004u, LCData, 8) )
    return 0;
  strcmp((unsigned __int8 *)LCData, "0");
  if ( v7 )
    goto LABEL_6;
  return GetACP();
}
