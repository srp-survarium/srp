vostok::math::float4_pod *__cdecl vostok::particle::cubic_interpolation<vostok::math::float4_pod,float>(
        vostok::math::float4_pod *result,
        vostok::math::float4_pod P0,
        vostok::math::float4_pod M0,
        vostok::math::float4_pod P1,
        vostok::math::float4_pod M1,
        float t)
{
  vostok::math::float4 *v6; // eax
  vostok::math::float4 *v7; // eax
  vostok::math::float4 *v8; // eax
  vostok::math::float4 *v10; // [esp-Ch] [ebp-A4h]
  vostok::math::float4 *v11; // [esp-8h] [ebp-A0h]
  vostok::math::float4 *v12; // [esp-4h] [ebp-9Ch]
  vostok::math::float4 v13; // [esp+0h] [ebp-98h] BYREF
  vostok::math::float4 v14; // [esp+10h] [ebp-88h] BYREF
  vostok::math::float4 v15; // [esp+20h] [ebp-78h] BYREF
  vostok::math::float4 v16; // [esp+30h] [ebp-68h] BYREF
  float v17; // [esp+40h] [ebp-58h] BYREF
  vostok::math::float4 v18; // [esp+44h] [ebp-54h] BYREF
  float v19; // [esp+54h] [ebp-44h] BYREF
  vostok::math::float4 v20; // [esp+58h] [ebp-40h] BYREF
  float v21; // [esp+68h] [ebp-30h] BYREF
  vostok::math::float4 v22; // [esp+6Ch] [ebp-2Ch] BYREF
  float value; // [esp+7Ch] [ebp-1Ch] BYREF
  vostok::math::float4 v24; // [esp+80h] [ebp-18h]
  float t_pow_2; // [esp+90h] [ebp-8h]
  float t_pow_3; // [esp+94h] [ebp-4h]

  t_pow_2 = t * t;
  t_pow_3 = (float)(t * t) * t;
  value = t_pow_3 - (float)(t * t);
  v21 = (float)(-2.0 * t_pow_3) + (float)(3.0 * (float)(t * t));
  v19 = (float)(t_pow_3 - (float)(2.0 * (float)(t * t))) + t;
  v17 = (float)((float)(2.0 * t_pow_3) - (float)(3.0 * (float)(t * t))) + *(float *)&clear_value;
  v12 = vostok::math::operator*(&M1, &v22, &value);
  v11 = vostok::math::operator*(&P1, &v20, &v21);
  v10 = vostok::math::operator*(&M0, &v18, &v19);
  v6 = vostok::math::operator*(&P0, &v16, &v17);
  v7 = vostok::math::operator+(&v15, v6, v10);
  v8 = vostok::math::operator+(&v14, v7, v11);
  v24 = *vostok::math::operator+(&v13, v8, v12);
  *result = v24.vostok::math::float4_pod;
  return result;
}
