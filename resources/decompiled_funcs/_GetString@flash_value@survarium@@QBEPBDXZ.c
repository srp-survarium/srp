const char *__usercall survarium::flash_value::GetString@<eax>(survarium::flash_value *this@<ecx>, int a2@<eax>)
{
  if ( (*(_DWORD *)(a2 + 4) & 0x40) != 0 )
    return **(const char ***)(a2 + 8);
  else
    return *(const char **)(a2 + 8);
}
