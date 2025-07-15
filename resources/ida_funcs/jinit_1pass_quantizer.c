int __cdecl jinit_1pass_quantizer(_DWORD *a1)
{
  _DWORD *v1; // eax
  int result; // eax

  v1 = (_DWORD *)(*(int (__cdecl **)(_DWORD *, int, int))a1[1])(a1, 1, 88);
  a1[110] = v1;
  *v1 = sub_37D0C0;
  v1[2] = Scaleform::Render::JPEG::JPEGRwSource::TermSource;
  v1[3] = sub_37D1B0;
  v1[17] = 0;
  v1[13] = 0;
  if ( (int)a1[25] > 4 )
  {
    *(_DWORD *)(*a1 + 20) = 57;
    *(_DWORD *)(*a1 + 24) = 4;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( (int)a1[21] > 256 )
  {
    *(_DWORD *)(*a1 + 20) = 59;
    *(_DWORD *)(*a1 + 24) = 256;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  sub_37C7D0(a1);
  result = sub_37C940(a1);
  if ( a1[19] == 2 )
    return sub_37D080(a1);
  return result;
}
