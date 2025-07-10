vostok::math::float3_pod *__cdecl vostok::particle::cubic_interpolation<vostok::math::float3_pod,float>(
        vostok::math::float3_pod *result,
        vostok::math::float3_pod P0,
        vostok::math::float3_pod M0,
        vostok::math::float3_pod P1,
        vostok::math::float3_pod M1,
        float t)
{
  vostok::math::float3 *v6; // esi
  vostok::math::float3 *v7; // edi
  vostok::math::float3 *v8; // ebx
  vostok::math::float3 *v9; // eax
  vostok::math::float3 *v10; // eax
  vostok::math::float3 *v11; // eax
  vostok::math::float3 v13; // [esp+Ch] [ebp-78h] BYREF
  vostok::math::float3 v14; // [esp+18h] [ebp-6Ch] BYREF
  vostok::math::float3 v15; // [esp+24h] [ebp-60h] BYREF
  vostok::math::float3 v16; // [esp+30h] [ebp-54h] BYREF
  float v17; // [esp+3Ch] [ebp-48h] BYREF
  vostok::math::float3 v18; // [esp+40h] [ebp-44h] BYREF
  float v19; // [esp+4Ch] [ebp-38h] BYREF
  vostok::math::float3 v20; // [esp+50h] [ebp-34h] BYREF
  float v21; // [esp+5Ch] [ebp-28h] BYREF
  vostok::math::float3 v22; // [esp+60h] [ebp-24h] BYREF
  float value; // [esp+6Ch] [ebp-18h] BYREF
  vostok::math::float3_pod v24; // [esp+70h] [ebp-14h]
  float t_pow_2; // [esp+7Ch] [ebp-8h]
  float t_pow_3; // [esp+80h] [ebp-4h]

  t_pow_2 = t * t;
  t_pow_3 = (float)(t * t) * t;
  value = t_pow_3 - (float)(t * t);
  v21 = (float)(-2.0 * t_pow_3) + (float)(3.0 * (float)(t * t));
  v19 = (float)(t_pow_3 - (float)(2.0 * (float)(t * t))) + t;
  v17 = (float)((float)(2.0 * t_pow_3) - (float)(3.0 * (float)(t * t))) + *(float *)&clear_value;
  v6 = vostok::math::operator*(&M1, &v22, &value);
  v7 = vostok::math::operator*(&P1, &v20, &v21);
  v8 = vostok::math::operator*(&M0, &v18, &v19);
  v9 = vostok::math::operator*(&P0, &v16, &v17);
  v10 = vostok::math::operator+(v8, v9, &v15);
  v11 = vostok::math::operator+(v7, v10, &v14);
  v24 = vostok::math::operator+(v6, v11, &v13)->vostok::math::float3_pod;
  *result = v24;
  return result;
}
