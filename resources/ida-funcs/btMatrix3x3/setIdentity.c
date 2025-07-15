void __thiscall btMatrix3x3::setIdentity(btMatrix3x3 *this, int a2)
{
  int v2; // [esp+0h] [ebp-24h] BYREF
  int v3; // [esp+4h] [ebp-20h] BYREF
  int v4; // [esp+8h] [ebp-1Ch] BYREF
  int v5; // [esp+Ch] [ebp-18h] BYREF
  float v6; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+14h] [ebp-10h] BYREF
  int v8; // [esp+18h] [ebp-Ch] BYREF
  int v9; // [esp+1Ch] [ebp-8h] BYREF
  float v10; // [esp+20h] [ebp-4h] BYREF

  v10 = s_bm_current_air_resistance;
  v9 = 0;
  v8 = 0;
  v7 = 0;
  v6 = s_bm_current_air_resistance;
  v5 = 0;
  v4 = 0;
  v3 = 0;
  btMatrix3x3::setValue(
    (btMatrix3x3 *)&v2,
    a2,
    (float *)&v3,
    (float *)&v4,
    (float *)&v5,
    &v6,
    (float *)&v7,
    (float *)&v8,
    (float *)&v9,
    &v10,
    (const float *)LODWORD(s_bm_current_air_resistance));
}
