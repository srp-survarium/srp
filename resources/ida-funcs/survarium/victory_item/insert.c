void __userpurge survarium::victory_item::insert(
        survarium::victory_item *this@<ecx>,
        __m128i a2@<xmm0>,
        const vostok::math::float3 *position,
        float rotation_y)
{
  long double v4; // rdi
  vostok::math::float4x4 *v5; // eax
  vostok::math::float4x4 v6; // [esp+Ch] [ebp-C0h] BYREF
  vostok::math::float4x4 v7; // [esp+4Ch] [ebp-80h] BYREF
  vostok::math::float4x4 v8; // [esp+8Ch] [ebp-40h] BYREF

  HIDWORD(v4) = this;
  survarium::victory_item_core::insert(this, position, rotation_y);
  LODWORD(v4) = vostok::math::create_translation(position, &v7);
  v5 = vostok::math::create_rotation_y(v4, a2, &v8, rotation_y);
  vostok::math::mul4x3((const vostok::math::float4x4 *)LODWORD(v4), v5, &v6);
  vostok::render::scene_renderer::add_model(
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(HIDWORD(v4) + 472) + 264),
    *(vostok::render::scene_renderer **)((char *)&dword_200060
                                       + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(HIDWORD(v4) + 480) + 160) + 172)),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(HIDWORD(v4) + 480) + 4),
    &v6,
    &v6);
}
