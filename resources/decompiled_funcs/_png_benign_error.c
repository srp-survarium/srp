int __cdecl png_benign_error(int a1, _BYTE *a2)
{
  if ( ((unsigned int)&unk_800000 & *(_DWORD *)(a1 + 112)) == 0 )
    png_error(a1, (int)a2);
  return png_warning(a1, a2);
}
