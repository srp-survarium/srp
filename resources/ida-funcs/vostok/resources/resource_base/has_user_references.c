BOOL __usercall vostok::resources::resource_base::has_user_references@<eax>(
        vostok::resources::resource_base *this@<ecx>,
        _DWORD *a2@<eax>)
{
  _DWORD *v2; // ecx
  int v3; // ecx
  int v4; // edx

  if ( (a2[2] & 1) != 0 && a2 )
  {
    v2 = a2 + 55;
  }
  else
  {
    if ( (a2[2] & 4) == 0 || !a2 )
    {
LABEL_15:
      v4 = 0;
      goto LABEL_16;
    }
    v2 = a2 + 52;
  }
  if ( !v2 )
    goto LABEL_15;
  if ( (a2[2] & 1) != 0 )
    v3 = (int)(a2 + 55);
  else
    v3 = (a2[2] & 4) != 0 ? (int)(a2 + 52) : 0;
  if ( (*(_DWORD *)(v3 + 4) & 1) == 0 )
    goto LABEL_15;
  v4 = 1;
LABEL_16:
  if ( (a2[2] & 1) != 0 && a2 )
    return a2[15] < (unsigned int)(a2[55] - v4);
  if ( (a2[2] & 4) != 0 && a2 )
    return a2[15] < (unsigned int)(a2[52] - v4);
  return a2[15] < (unsigned int)(MEMORY[0] - v4);
}
