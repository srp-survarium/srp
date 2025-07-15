int __usercall sub_377F90@<eax>(_DWORD *a1@<edi>)
{
  int v1; // esi
  unsigned __int8 *v2; // eax
  unsigned __int8 v3; // cl

  v1 = a1[6];
  if ( !*(_DWORD *)(v1 + 4) && !(*(unsigned __int8 (__cdecl **)(_DWORD *))(v1 + 12))(a1) )
  {
    *(_DWORD *)(*a1 + 20) = 25;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v2 = *(unsigned __int8 **)v1;
  --*(_DWORD *)(v1 + 4);
  v3 = *v2;
  *(_DWORD *)v1 = v2 + 1;
  return v3;
}
