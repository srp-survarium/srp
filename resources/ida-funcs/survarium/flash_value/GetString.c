const char *__usercall survarium::flash_value::GetString@<eax>(survarium::flash_value *this@<ecx>, int a2@<eax>)
{
  int v2; // ecx
  const char *result; // eax

  v2 = *(_DWORD *)(a2 + 4);
  result = *(const char **)(a2 + 8);
  if ( (v2 & 0x40) != 0 )
    return *(const char **)result;
  return result;
}
