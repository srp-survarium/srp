_DWORD *__cdecl DES_encrypt2(_DWORD *a1, _DWORD *a2, int a3)
{
  int v3; // esi
  int v4; // edi
  _DWORD *result; // eax

  v3 = __ROL4__(*a1, 3);
  v4 = __ROL4__(a1[1], 3);
  if ( a3 )
    _x86_DES_encrypt(a2, (int)&DES_SPtrans, v4, v3);
  else
    _x86_DES_decrypt(a2, (int)&DES_SPtrans, v4, v3);
  result = a1;
  *a1 = __ROR4__(v4, 3);
  a1[1] = __ROR4__(v3, 3);
  return result;
}
