void __usercall vostok::render::decal_shader_constants_and_geometry::decal_shader_constants_and_geometry(
        vostok::render::decal_shader_constants_and_geometry *this@<ecx>,
        vostok::render::shader_constant_host **a2@<edi>)
{
  vostok::render::backend *v2; // ecx
  vostok::shared_string *v3; // ecx
  vostok::render::backend *v4; // ecx
  vostok::shared_string *v5; // ecx
  vostok::render::backend *v6; // ecx
  vostok::shared_string *v7; // ecx
  vostok::render::backend *v8; // ecx
  vostok::render::decal_shader_constants_and_geometry *v9; // ecx
  vostok::shared_string name; // [esp+Ch] [ebp-4h] BYREF

  a2[4] = 0;
  a2[5] = 0;
  LODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.y) = a2;
  a2[6] = 0;
  vostok::shared_string::shared_string((vostok::shared_string *)this, &name.m_pointer, "world_to_decal");
  *a2 = vostok::render::backend::register_constant_host(
          v2,
          SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
          &name,
          0);
  if ( name.m_pointer.m_object )
  {
    v3 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v3 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v3, &name.m_pointer, "s_eye_ray_corner");
  a2[1] = vostok::render::backend::register_constant_host(
            v4,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v5 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v5 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v5, &name.m_pointer, "decal_tangent_to_view_space_matrix");
  a2[2] = vostok::render::backend::register_constant_host(
            v6,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v7 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v7 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v7, &name.m_pointer, "decal_angle_parameters");
  a2[3] = vostok::render::backend::register_constant_host(
            v8,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v9 = (vostok::render::decal_shader_constants_and_geometry *)_InterlockedExchangeAdd(
                                                                  &name.m_pointer.m_object->m_reference_count,
                                                                  0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::render::decal_shader_constants_and_geometry::create_decal_geometry(v9, (int)a2);
}
