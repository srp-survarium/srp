const btMatrix3x3 *__usercall btSoftBody::Body::invWorldInertia@<eax>(btSoftBody::Body *this@<ecx>, _DWORD *a2@<esi>)
{
  int v2; // eax
  const float *v4; // [esp+0h] [ebp-28h]
  int v5; // [esp+4h] [ebp-24h] BYREF
  int v6; // [esp+8h] [ebp-20h] BYREF
  int v7; // [esp+Ch] [ebp-1Ch] BYREF
  int v8; // [esp+10h] [ebp-18h] BYREF
  int v9; // [esp+14h] [ebp-14h] BYREF
  int v10; // [esp+18h] [ebp-10h] BYREF
  int v11; // [esp+1Ch] [ebp-Ch] BYREF
  int v12; // [esp+20h] [ebp-8h] BYREF
  int v13; // [esp+24h] [ebp-4h] BYREF

  if ( (`btSoftBody::Body::invWorldInertia'::`2'::`local static guard' & 1) == 0 )
  {
    `btSoftBody::Body::invWorldInertia'::`2'::`local static guard' |= 1u;
    v13 = 0;
    v12 = 0;
    v11 = 0;
    v10 = 0;
    v9 = 0;
    v8 = 0;
    v7 = 0;
    v6 = 0;
    v5 = 0;
    btMatrix3x3::setValue(
      (btMatrix3x3 *)&v5,
      (int)&`btSoftBody::Body::invWorldInertia'::`2'::iwi,
      (float *)&v6,
      (float *)&v7,
      (float *)&v8,
      (float *)&v9,
      (float *)&v10,
      (float *)&v11,
      (float *)&v12,
      (const float *)&v13,
      v4);
  }
  v2 = a2[1];
  if ( v2 )
    return (const btMatrix3x3 *)(v2 + 272);
  if ( *a2 )
    return (const btMatrix3x3 *)(*a2 + 192);
  return &`btSoftBody::Body::invWorldInertia'::`2'::iwi;
}
