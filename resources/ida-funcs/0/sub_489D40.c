int __usercall sub_489D40@<eax>(_DWORD *a1@<esi>)
{
  int result; // eax
  int v2; // edi
  int v3; // ebp
  int *v4; // ebx

  result = a1[110];
  v2 = 0;
  v3 = 2 * a1[23] + 4;
  if ( (int)a1[25] > 0 )
  {
    v4 = (int *)(result + 68);
    do
    {
      result = (*(int (__cdecl **)(_DWORD *, int, int))(a1[1] + 4))(a1, 1, v3);
      *v4 = result;
      ++v2;
      ++v4;
    }
    while ( v2 < a1[25] );
  }
  return result;
}
