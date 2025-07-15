void vostok::render::material::initialize_nomaterial_material()
{
  unsigned int v0; // edi
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v2; // eax
  vostok::memory::doug_lea_allocator *v3; // ecx
  char *v4; // eax
  vostok::render::material_effects *v5; // ecx
  int v6; // eax
  char *v7; // ebx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *m_object; // eax
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v9; // esi
  vostok::render::effect_descriptor *v10; // eax
  vostok::render::effect_manager *v11; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v12; // esi
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v13; // ebx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v14; // esi
  vostok::render::effect_descriptor *v15; // eax
  vostok::render::effect_manager *v16; // [esp-4h] [ebp-44h]
  const char *v17; // [esp+0h] [ebp-40h]
  const char *v18; // [esp+4h] [ebp-3Ch]
  unsigned int v19; // [esp+8h] [ebp-38h]
  vostok::render::surface_effect_parameters v20; // [esp+10h] [ebp-30h] BYREF
  vostok::render::surface_effect_parameters v21; // [esp+20h] [ebp-20h] BYREF
  vostok::render::effect_descriptor v22; // [esp+30h] [ebp-10h] BYREF
  vostok::render::effect_descriptor descriptor; // [esp+34h] [ebp-Ch] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v24; // [esp+38h] [ebp-8h] BYREF
  unsigned int v25; // [esp+3Ch] [ebp-4h]

  v0 = 0;
  v25 = 0;
  do
  {
    v1 = vostok::render::g_allocator;
    v2 = type_info::raw_name(&vostok::render::material_effects `RTTI Type Descriptor');
    v4 = vostok::memory::doug_lea_allocator::malloc_impl(v3, (int)v1, 0x98u, v2, v17, v18, v19);
    if ( v4 )
      vostok::render::material_effects::material_effects(v5, (int)v4);
    else
      v6 = 0;
    v7 = &s_system_renderer_buffer.m_family[2].orig_name.m_buffer[4 * v0 + 4];
    *(_DWORD *)v7 = v6;
    v21.draw_to_gbuffer = -1;
    v21.blend_mode = -1;
    *(_DWORD *)(v6 + 36) = 1 << v0;
    m_object = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
    v9 = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)v7 + 44);
    v21.vertex_input_type = v0;
    v21.cull_mode = 1;
    v24.m_object = (vostok::particle::particle_system_instance_impl *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
    if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_nomaterial_materials>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_nomaterial_materials>'::`2'::`local static guard' |= 1u;
      `vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_nomaterial_materials>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_gbuffer_nomaterial_materials::`vftable';
      atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_nomaterial_materials>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
      m_object = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)v24.m_object;
    }
    v24.m_object = 0;
    if ( LOBYTE(m_object->m_object) )
    {
      v10 = vostok::render::effect_manager::create_new_effect(
              (vostok::render::effect_manager *)&descriptor,
              m_object,
              &descriptor,
              (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_nomaterial_materials>'::`2'::descriptor_object,
              &v24,
              &v21);
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v10,
        v9);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&descriptor);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v24);
      v0 = v25;
    }
    else
    {
      vostok::render::effect_manager::create_new_effect(
        (vostok::render::effect_manager *)&v24,
        __SPAIR64__((unsigned int)v9, (unsigned int)m_object),
        (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_gbuffer_nomaterial_materials>'::`2'::descriptor_object,
        &v24,
        &v21);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v24);
    }
    v12 = *(vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> **)v7;
    v20.draw_to_gbuffer = -1;
    v20.blend_mode = -1;
    v13 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
    v14 = v12 + 37;
    v20.vertex_input_type = v0;
    v20.cull_mode = 1;
    if ( (`vostok::render::effect_manager::create_effect<vostok::render::depth_accumulate_material_effect>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `vostok::render::effect_manager::create_effect<vostok::render::depth_accumulate_material_effect>'::`2'::`local static guard' |= 1u;
      `vostok::render::effect_manager::create_effect<vostok::render::depth_accumulate_material_effect>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::depth_accumulate_material_effect::`vftable';
      atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::depth_accumulate_material_effect>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
      v11 = v16;
    }
    v24.m_object = 0;
    if ( LOBYTE(v13->m_object) )
    {
      v15 = vostok::render::effect_manager::create_new_effect(
              v11,
              v13,
              &v22,
              (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::depth_accumulate_material_effect>'::`2'::descriptor_object,
              &v24,
              &v20);
      vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
        (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v15,
        v14);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v22);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v24);
      v0 = v25;
    }
    else
    {
      vostok::render::effect_manager::create_new_effect(
        v11,
        __SPAIR64__((unsigned int)v14, (unsigned int)v13),
        (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::depth_accumulate_material_effect>'::`2'::descriptor_object,
        &v24,
        &v20);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v24);
    }
    v25 = ++v0;
  }
  while ( v0 < 0xF );
}
