void __cdecl png_set_sCAL_s(int a1, int a2, int a3, char *lpString, char *a5)
{
  int count; // [esp+0h] [ebp-8h]
  unsigned int counta; // [esp+0h] [ebp-8h]
  int size; // [esp+4h] [ebp-4h]
  unsigned int sizea; // [esp+4h] [ebp-4h]

  if ( a1 && a2 )
  {
    if ( a3 != 1 && a3 != 2 )
      png_error(a1, (int)"Invalid sCAL unit");
    if ( !lpString || (count = lstrlenA(lpString)) == 0 || *lpString == 45 || !png_check_fp_string((int)lpString, count) )
      png_error(a1, (int)"Invalid sCAL width");
    if ( !a5 || (size = lstrlenA(a5)) == 0 || *a5 == 45 || !png_check_fp_string((int)a5, size) )
      png_error(a1, (int)"Invalid sCAL height");
    *(_BYTE *)(a2 + 220) = a3;
    counta = count + 1;
    *(_DWORD *)(a2 + 224) = png_malloc_warn(a1, counta);
    if ( *(_DWORD *)(a2 + 224) )
    {
      memcpy(*(unsigned __int8 **)(a2 + 224), (unsigned __int8 *)lpString, counta);
      sizea = size + 1;
      *(_DWORD *)(a2 + 228) = png_malloc_warn(a1, sizea);
      if ( *(_DWORD *)(a2 + 228) )
      {
        memcpy(*(unsigned __int8 **)(a2 + 228), (unsigned __int8 *)a5, sizea);
        *(_DWORD *)(a2 + 8) |= 0x4000u;
        *(_DWORD *)(a2 + 184) |= 0x100u;
      }
      else
      {
        png_free(a1, *(void **)(a2 + 224));
        *(_DWORD *)(a2 + 224) = 0;
        png_warning(a1, "Memory allocation failed while processing sCAL");
      }
    }
    else
    {
      png_warning(a1, "Memory allocation failed while processing sCAL");
    }
  }
}
