int __usercall vostok::render::compare@<eax>(
        const vostok::render::res_declaration *left@<ecx>,
        const vostok::render::res_declaration *right@<eax>)
{
  unsigned int v5; // ecx
  unsigned int *v6; // eax
  D3D11_INPUT_ELEMENT_DESC *M_start; // esi
  D3D11_INPUT_ELEMENT_DESC *v8; // edi
  unsigned int v9; // ecx
  int v10; // eax
  unsigned int v11; // [esp+Ch] [ebp-8h] BYREF
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  if ( left->dcl_code._M_impl._M_finish - left->dcl_code._M_impl._M_start < (unsigned int)(right->dcl_code._M_impl._M_finish
                                                                                         - right->dcl_code._M_impl._M_start) )
    return -1;
  if ( left->dcl_code._M_impl._M_finish - left->dcl_code._M_impl._M_start > (unsigned int)(right->dcl_code._M_impl._M_finish
                                                                                         - right->dcl_code._M_impl._M_start) )
    return 1;
  v5 = right->dcl_code._M_impl._M_finish - right->dcl_code._M_impl._M_start;
  v12 = left->dcl_code._M_impl._M_finish - left->dcl_code._M_impl._M_start;
  v11 = v5;
  v6 = &v11;
  if ( v5 >= v12 )
    v6 = &v12;
  M_start = right->dcl_code._M_impl._M_start;
  v8 = left->dcl_code._M_impl._M_start;
  v9 = 28 * *v6;
  if ( v9 < 4 )
  {
LABEL_10:
    if ( !v9 )
      return 0;
  }
  else
  {
    while ( v8->SemanticName == M_start->SemanticName )
    {
      v9 -= 4;
      M_start = (D3D11_INPUT_ELEMENT_DESC *)((char *)M_start + 4);
      v8 = (D3D11_INPUT_ELEMENT_DESC *)((char *)v8 + 4);
      if ( v9 < 4 )
        goto LABEL_10;
    }
  }
  v10 = LOBYTE(v8->SemanticName) - LOBYTE(M_start->SemanticName);
  if ( v10 )
    return (v10 >> 31) | 1;
  if ( v9 <= 1 )
    return 0;
  v10 = BYTE1(v8->SemanticName) - BYTE1(M_start->SemanticName);
  if ( v10 )
    return (v10 >> 31) | 1;
  if ( v9 <= 2 )
    return 0;
  v10 = BYTE2(v8->SemanticName) - BYTE2(M_start->SemanticName);
  if ( v10 )
    return (v10 >> 31) | 1;
  if ( v9 > 3 )
  {
    v10 = HIBYTE(v8->SemanticName) - HIBYTE(M_start->SemanticName);
    return (v10 >> 31) | 1;
  }
  return 0;
}
