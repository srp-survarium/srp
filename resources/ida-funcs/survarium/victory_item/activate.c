void __userpurge survarium::victory_item::activate(
        survarium::victory_item *this@<ecx>,
        __m128i a2@<xmm0>,
        bool real_insert)
{
  vostok::animation::hand_to_weapon_ik_solver *v3; // ecx
  long double v4; // rdi
  vostok::math::float4x4 *v5; // ebx
  vostok::math::float4x4 *v6; // eax
  vostok::math::float4x4 v7; // [esp+14h] [ebp-C0h] BYREF
  vostok::math::float4x4 v8; // [esp+54h] [ebp-80h] BYREF
  vostok::math::float4x4 v9; // [esp+94h] [ebp-40h] BYREF

  HIDWORD(v4) = this;
  survarium::victory_item_core::activate(this, real_insert);
  LODWORD(v4) = *(_DWORD *)(HIDWORD(v4) + 476) + 264;
  if ( !*(_BYTE *)(*(_DWORD *)LODWORD(v4) + 269) )
  {
    v5 = vostok::math::create_translation((const vostok::math::float3 *)(HIDWORD(v4) + 416), &v8);
    v6 = vostok::math::create_rotation_y(v4, a2, &v9, *(float *)(HIDWORD(v4) + 428));
    vostok::math::mul4x3(v5, v6, &v7);
    vostok::render::scene_renderer::add_model(
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)LODWORD(v4),
      *(vostok::render::scene_renderer **)((char *)&dword_200060
                                         + *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(HIDWORD(v4) + 480) + 160) + 172)),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)(HIDWORD(v4) + 480) + 4),
      &v7,
      &v7);
  }
  vostok::animation::hand_to_weapon_ik_solver::initialize_locators(
    v3,
    (vostok::render::model_locator_item *)(*(_DWORD *)(HIDWORD(v4) + 444) + 496),
    *(vostok::render::render_model_instance **)(*(_DWORD *)(HIDWORD(v4) + 476) + 264));
}
