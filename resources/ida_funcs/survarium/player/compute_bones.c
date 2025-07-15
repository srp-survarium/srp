void __userpurge survarium::player::compute_bones(
        survarium::player *this@<ecx>,
        int a2@<esi>,
        vostok::render::game::renderer *current_time_in_ms)
{
  unsigned int v3; // edi
  void *v4; // esp
  vostok::collision::animated_object *v5; // ecx
  vostok::math::float4x4 *v6[2]; // [esp+0h] [ebp-Ch] BYREF
  int v7; // [esp+8h] [ebp-4h]

  v7 = *(_DWORD *)(a2 + 34800) + 268;
  v3 = *(_DWORD *)(*(_DWORD *)v7 + 264) - (*(_DWORD *)(*(_DWORD *)v7 + 280) - (*(_DWORD *)v7 + 272)) / 20;
  v4 = alloca(v3 << 6);
  (*(void (__thiscall **)(_DWORD, int, vostok::math::float4x4 **, unsigned int, vostok::render::game::renderer *, int, char *, int))(**(_DWORD **)(a2 + 64) + 60))(
    *(_DWORD *)(a2 + 64),
    v7,
    v6,
    v3,
    current_time_in_ms,
    a2 + 72,
    &byte_10DD0[a2],
    a2 + 552);
  vostok::collision::animated_object::update(
    v5,
    *(const vostok::math::float4x4 *const *)((char *)&dword_10EF0 + a2),
    (const vostok::math::float4x4 *const)v6);
  if ( byte_10F33[a2] )
    vostok::render::scene_renderer::update_skeleton(
      (vostok::render::scene_renderer *)(*(_DWORD *)(a2 + 34800) + 264),
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(a2 + 34800) + 264),
      (const vostok::math::float4x4 *)v6,
      v3);
  if ( byte_10F32[a2] )
  {
    vostok::animation::mixing::n_ary_tree::compute_bones_matrices(
      (vostok::animation::mixing::n_ary_tree *)((char *)&unk_10CFC + a2),
      (const void *)a2,
      *(const vostok::animation::skeleton **)(*(int *)((char *)&dword_10DC4 + a2) + 268),
      (vostok::math::float4x4 *const)v6,
      v6[0],
      0);
    vostok::render::scene_renderer::update_skeleton(
      (vostok::render::scene_renderer *)(*(int *)((char *)&dword_10DC4 + a2) + 264),
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)(*(int *)((char *)&dword_10DC4 + a2) + 264),
      (const vostok::math::float4x4 *)v6,
      v3);
  }
}
