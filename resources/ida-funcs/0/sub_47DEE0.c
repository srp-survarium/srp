int __usercall sub_47DEE0@<eax>(int a1@<esi>)
{
  int result; // eax
  int v2; // ecx
  int v3; // eax

  *(_BYTE *)(a1 + 64) = 1;
  jpeg_core_output_dimensions();
  if ( *(_BYTE *)(a1 + 202) )
    jinit_arith_decoder(a1);
  else
    jinit_huff_decoder(a1);
  jinit_d_coef_controller(a1, 1);
  (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 4) + 24))(a1);
  result = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 416) + 8))(a1);
  v2 = *(_DWORD *)(a1 + 8);
  if ( v2 )
  {
    if ( *(_BYTE *)(a1 + 201) )
    {
      v3 = 3 * *(_DWORD *)(a1 + 36) + 2;
    }
    else if ( *(_BYTE *)(*(_DWORD *)(a1 + 416) + 16) )
    {
      v3 = *(_DWORD *)(a1 + 36);
    }
    else
    {
      v3 = 1;
    }
    *(_DWORD *)(v2 + 4) = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = v3 * *(_DWORD *)(a1 + 288);
    result = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(result + 12) = 0;
    *(_DWORD *)(*(_DWORD *)(a1 + 8) + 16) = 1;
  }
  return result;
}
