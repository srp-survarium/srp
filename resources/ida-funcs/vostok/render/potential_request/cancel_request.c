void __usercall vostok::render::potential_request::cancel_request(
        vostok::render::potential_request *this@<ecx>,
        int a2@<eax>)
{
  unsigned int v2; // esi
  unsigned int v3; // edi
  char v4; // cl
  unsigned int v5; // edx
  unsigned int v6; // edx
  unsigned int v7; // edx
  unsigned int v8; // edx

  v2 = *(_DWORD *)(a2 + 8);
  v3 = *(_DWORD *)(a2 + 12);
  if ( v3 <= v2 )
    v4 = v2 - v3;
  else
    v4 = v3 - v2;
  v5 = *(_DWORD *)(a2 + 36);
  if ( v3 <= v2 )
    v6 = v5 << v4;
  else
    v6 = v5 >> v4;
  *(_DWORD *)(a2 + 36) = v6;
  v7 = *(_DWORD *)(a2 + 40);
  if ( v3 <= v2 )
    v8 = v7 << v4;
  else
    v8 = v7 >> v4;
  *(_DWORD *)(a2 + 12) = v2;
  *(_DWORD *)(a2 + 40) = v8;
  *(_DWORD *)(a2 + 64) = 0;
  *(_BYTE *)(a2 + 104) = 0;
}
