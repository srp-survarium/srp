void __userpurge vostok::sound::sound_scene::update_receivers_position(
        vostok::sound::sound_scene *this@<ecx>,
        float a2@<xmm0>,
        int a3)
{
  int v3; // ebx
  unsigned __int16 *v4; // esi
  vostok::math::half_pod *v5; // ecx
  vostok::math::half_pod *v6; // ecx
  float *v7; // ebx
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  vostok::math::float4x4 *v11; // eax
  vostok::math::float4x4 v12; // [esp+Ch] [ebp-F0h] BYREF
  vostok::math::float4x4 v13; // [esp+4Ch] [ebp-B0h] BYREF
  vostok::math::float4x4 v14; // [esp+8Ch] [ebp-70h] BYREF
  vostok::math::float3 v15; // [esp+CCh] [ebp-30h] BYREF
  vostok::math::float3 v16; // [esp+D8h] [ebp-24h]
  vostok::math::float3 v17; // [esp+E4h] [ebp-18h] BYREF
  vostok::math::float4x4 *right; // [esp+F0h] [ebp-Ch]
  int v19; // [esp+F4h] [ebp-8h]

  v3 = *(_DWORD *)(a3 + 652);
  v19 = v3;
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = *(unsigned __int16 **)v3;
      vostok::math::half_pod::operator float((vostok::math::half_pod *)this, *(unsigned __int16 **)v3);
      v16.x = a2;
      vostok::math::half_pod::operator float(v5, v4 + 1);
      v16.y = a2;
      vostok::math::half_pod::operator float(v6, v4 + 2);
      v7 = *(float **)(v3 + 8);
      v8 = v7[5] - v7[2];
      v9 = v7[6] - v7[3];
      v16.z = a2;
      v10 = v7[4] - v7[1];
      v15 = v16;
      a2 = v10 * 0.5;
      v17.x = a2;
      v17.y = v8 * 0.5;
      v17.z = v9 * 0.5;
      right = vostok::math::create_translation(&v15, &v13);
      v11 = vostok::math::create_scale(&v17, &v12);
      vostok::math::mul4x3(right, v11, &v14);
      (*(void (__thiscall **)(_DWORD, float *, vostok::math::float4x4 *))(**(_DWORD **)(a3 + 608) + 8))(
        *(_DWORD *)(a3 + 608),
        v7,
        &v14);
      v19 = *(_DWORD *)(v19 + 12);
      if ( !v19 )
        break;
      v3 = v19;
    }
  }
}
