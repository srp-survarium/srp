const btMatrix3x3 *__cdecl btMatrix3x3::getIdentity()
{
  const float *v1; // [esp+0h] [ebp-28h]
  float v2; // [esp+4h] [ebp-24h] BYREF
  int v3; // [esp+8h] [ebp-20h] BYREF
  int v4; // [esp+Ch] [ebp-1Ch] BYREF
  int v5; // [esp+10h] [ebp-18h] BYREF
  float v6; // [esp+14h] [ebp-14h] BYREF
  int v7; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+1Ch] [ebp-Ch] BYREF
  int v9; // [esp+20h] [ebp-8h] BYREF
  float v10; // [esp+24h] [ebp-4h] BYREF

  if ( (`btMatrix3x3::getIdentity'::`2'::`local static guard' & 1) == 0 )
  {
    `btMatrix3x3::getIdentity'::`2'::`local static guard' |= 1u;
    v10 = s_bm_current_air_resistance;
    v9 = 0;
    v8 = 0;
    v7 = 0;
    v6 = s_bm_current_air_resistance;
    v5 = 0;
    v4 = 0;
    v3 = 0;
    v2 = s_bm_current_air_resistance;
    btMatrix3x3::setValue(
      (btMatrix3x3 *)&v2,
      (int)&`btMatrix3x3::getIdentity'::`2'::identityMatrix,
      (float *)&v3,
      (float *)&v4,
      (float *)&v5,
      &v6,
      (float *)&v7,
      (float *)&v8,
      (float *)&v9,
      &v10,
      v1);
  }
  return &`btMatrix3x3::getIdentity'::`2'::identityMatrix;
}
