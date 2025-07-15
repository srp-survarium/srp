int __cdecl png_chunk_benign_error(int a1, _BYTE *a2)
{
  if ( (*(_DWORD *)(a1 + 112) & 0x800000) == 0 )
    png_chunk_error(a1, (int)a2);
  return png_chunk_warning(a1, a2);
}
