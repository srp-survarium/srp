vostok::math::float4x4 *__userpurge vostok::animation::mixing::n_ary_tree::get_object_transform@<eax>(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        int a2@<eax>,
        float a3@<xmm4>,
        vostok::math::float4x4 *result,
        void *animated_object)
{
  char v6; // bl
  vostok::animation::mixing::animated_object_holder *v7; // eax
  const vostok::animation::mixing::animation_state *v8; // ecx
  const vostok::math::float4x4 *p_transform; // edi
  vostok::math::float4x4 *v10; // eax
  vostok::math::float4x4 *object_transform; // eax
  vostok::math::float4x4 *v12; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v13; // ecx
  vostok::animation::bone_matrices_computer *v15; // [esp-8h] [ebp-D0h]
  boost::function<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> __cdecl(unsigned short)> animation_resolver; // [esp+10h] [ebp-B8h] BYREF
  vostok::animation::bone_matrices_computer v17; // [esp+30h] [ebp-98h] BYREF
  vostok::math::float4x4 v18; // [esp+48h] [ebp-80h] BYREF
  vostok::math::float4x4 v19; // [esp+88h] [ebp-40h] BYREF

  v6 = 0;
  v7 = stlp_std::priv::__find<vostok::animation::mixing::animated_object_holder *,void const *>(
         *(vostok::animation::mixing::animated_object_holder **)(a2 + 24),
         (const void **)&animated_object,
         (vostok::animation::mixing::animated_object_holder *)(*(_DWORD *)(a2 + 24) + 136 * *(_DWORD *)(a2 + 36)));
  v8 = *(const vostok::animation::mixing::animation_state **)(a2 + 16);
  p_transform = &v7->transform;
  if ( v8 )
  {
    animation_resolver.vtable = 0;
    v6 = 3;
    v15 = (vostok::animation::bone_matrices_computer *)v8;
    vostok::animation::bone_matrices_computer::bone_matrices_computer(
      v8,
      *(_DWORD *)(a2 + 32),
      &v17,
      animated_object,
      0,
      &animation_resolver);
    object_transform = vostok::animation::bone_matrices_computer::get_object_transform(v15, a3, v10, &v19);
    vostok::math::mul4x3(p_transform, object_transform, &v18);
    v12 = &v18;
  }
  else
  {
    v12 = &v7->transform;
  }
  qmemcpy(result, v12, sizeof(vostok::math::float4x4));
  v13 = 0;
  if ( (v6 & 2) != 0 )
  {
    v6 &= ~2u;
    vostok::animation::bone_matrices_computer::~bone_matrices_computer(0, (int)&v17);
  }
  if ( (v6 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v13,
      (int *)&animation_resolver);
  return result;
}
