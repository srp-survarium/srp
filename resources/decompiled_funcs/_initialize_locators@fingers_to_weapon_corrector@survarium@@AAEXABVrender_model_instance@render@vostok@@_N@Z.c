void __userpurge survarium::fingers_to_weapon_corrector::initialize_locators(
        survarium::fingers_to_weapon_corrector *this@<eax>,
        bool first_person_view@<cl>,
        vostok::render::render_model_instance *weapon_model)
{
  const char **v3; // ebp
  int i; // ebx
  vostok::math::float4x4 *v5; // edi
  int v6; // ebx
  bool v7; // zf
  vostok::math::float4x4 *v8; // [esp+14h] [ebp-9C4h]
  unsigned __int8 *dst; // [esp+18h] [ebp-9C0h]
  int v10; // [esp+1Ch] [ebp-9BCh]
  vostok::math::float4x4 result; // [esp+20h] [ebp-9B8h] BYREF
  vostok::render::model_locator_item current_item; // [esp+60h] [ebp-978h] BYREF
  const char *v13; // [esp+C8h] [ebp-910h] BYREF
  vostok::math::float4x4 matrices[16]; // [esp+1D8h] [ebp-800h] BYREF
  vostok::math::float4x4 inverted_matrices[16]; // [esp+5D8h] [ebp-400h] BYREF

  this->m_first_person_view = first_person_view;
  dst = (unsigned __int8 *)this;
  v3 = s_arm_fingers_phalanges[0];
  v10 = 2;
  do
  {
    for ( i = 0; i != 16; ++i )
    {
      vostok::fixed_string<256>::createf((int)&v13, (vostok::fixed_string<256> *)&::result, *v3);
      weapon_model->get_locator(weapon_model, v13, &current_item);
      qmemcpy((void *)&matrices[i], &current_item.m_offset, sizeof(vostok::math::float4x4));
      vostok::math::float4x4::try_invert(&inverted_matrices[i], &matrices[i]);
      ++v3;
    }
    v5 = matrices;
    v8 = matrices;
    v6 = 0;
    while ( 1 )
    {
      vostok::math::mul4x3(&result, v5, &inverted_matrices[s_index_of_parent[v6]]);
      ++v8;
      ++v6;
      qmemcpy((void *)v5, &result, sizeof(vostok::math::float4x4));
      if ( v6 == 15 )
        break;
      v5 = v8;
    }
    memmove(dst, (unsigned __int8 *)matrices, 0x3C0u);
    v7 = v10-- == 1;
    dst += 1028;
  }
  while ( !v7 );
}
