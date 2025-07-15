int __usercall sub_4801F0@<eax>(int a1@<esi>)
{
  int v1; // edi
  int v2; // ecx
  char v3; // al
  int result; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // [esp+0h] [ebp-10h]
  char v8; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 400);
  jpeg_calc_output_dimensions(v7);
  sub_480160(a1);
  *(_DWORD *)(v1 + 12) = 0;
  *(_BYTE *)(v1 + 16) = sub_47FEC0(v2, a1);
  *(_DWORD *)(v1 + 20) = 0;
  *(_DWORD *)(v1 + 24) = 0;
  v3 = *(_BYTE *)(a1 + 74);
  if ( !v3 || !*(_BYTE *)(a1 + 64) )
  {
    *(_BYTE *)(a1 + 88) = 0;
    *(_BYTE *)(a1 + 89) = 0;
    *(_BYTE *)(a1 + 90) = 0;
  }
  if ( v3 )
  {
    if ( *(_BYTE *)(a1 + 65) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 48;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( *(_DWORD *)(a1 + 100) == 3 )
    {
      if ( *(_DWORD *)(a1 + 116) )
      {
        *(_BYTE *)(a1 + 89) = 1;
        goto LABEL_10;
      }
      if ( *(_BYTE *)(a1 + 80) )
      {
        *(_BYTE *)(a1 + 90) = 1;
        goto LABEL_10;
      }
    }
    else
    {
      *(_BYTE *)(a1 + 89) = 0;
      *(_BYTE *)(a1 + 90) = 0;
      *(_DWORD *)(a1 + 116) = 0;
    }
    *(_BYTE *)(a1 + 88) = 1;
LABEL_10:
    if ( *(_BYTE *)(a1 + 88) )
    {
      jinit_1pass_quantizer(a1);
      *(_DWORD *)(v1 + 20) = *(_DWORD *)(a1 + 440);
    }
    if ( *(_BYTE *)(a1 + 90) || *(_BYTE *)(a1 + 89) )
    {
      jinit_2pass_quantizer(a1);
      *(_DWORD *)(v1 + 24) = *(_DWORD *)(a1 + 440);
    }
  }
  if ( !*(_BYTE *)(a1 + 65) )
  {
    if ( *(_BYTE *)(v1 + 16) )
    {
      jinit_merged_upsampler(a1);
    }
    else
    {
      jinit_color_deconverter(a1);
      jinit_upsampler(a1);
    }
    jinit_d_post_controller(a1, *(_BYTE *)(a1 + 90));
  }
  jinit_inverse_dct(a1);
  if ( *(_BYTE *)(a1 + 202) )
    jinit_arith_decoder(a1);
  else
    jinit_huff_decoder(a1);
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 416) + 16) || (v8 = 0, *(_BYTE *)(a1 + 64)) )
    v8 = 1;
  jinit_d_coef_controller(a1, v8);
  if ( !*(_BYTE *)(a1 + 65) )
    jinit_d_main_controller(a1, 0);
  (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 4) + 24))(a1);
  result = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 416) + 8))(a1);
  v5 = *(_DWORD *)(a1 + 8);
  if ( v5 )
  {
    if ( !*(_BYTE *)(a1 + 64) )
    {
      result = *(_DWORD *)(a1 + 416);
      if ( *(_BYTE *)(result + 16) )
      {
        v6 = *(_DWORD *)(a1 + 36);
        if ( *(_BYTE *)(a1 + 201) )
          v6 = 3 * v6 + 2;
        *(_DWORD *)(v5 + 4) = 0;
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = v6 * *(_DWORD *)(a1 + 288);
        result = *(_DWORD *)(a1 + 8);
        *(_DWORD *)(result + 12) = 0;
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 16) = (*(_BYTE *)(a1 + 90) != 0) + 2;
        ++*(_DWORD *)(v1 + 12);
      }
    }
  }
  return result;
}
