void __usercall vostok::render::scene_shader_constants::scene_shader_constants(
        vostok::render::scene_shader_constants *this@<ecx>,
        vostok::render::shader_constant_host **a2@<edi>)
{
  vostok::render::backend *v2; // ecx
  vostok::shared_string *v3; // ecx
  vostok::render::backend *v4; // ecx
  vostok::shared_string *v5; // ecx
  vostok::render::backend *v6; // ecx
  vostok::shared_string *v7; // ecx
  vostok::render::backend *v8; // ecx
  vostok::shared_string *v9; // ecx
  vostok::render::backend *v10; // ecx
  vostok::shared_string *v11; // ecx
  vostok::render::backend *v12; // ecx
  vostok::shared_string *v13; // ecx
  vostok::render::backend *v14; // ecx
  vostok::shared_string *v15; // ecx
  vostok::render::backend *v16; // ecx
  vostok::shared_string *v17; // ecx
  vostok::render::backend *v18; // ecx
  vostok::shared_string *v19; // ecx
  vostok::render::backend *v20; // ecx
  vostok::shared_string *v21; // ecx
  vostok::render::backend *v22; // ecx
  vostok::shared_string name; // [esp+Ch] [ebp-4h] BYREF

  vostok::shared_string::shared_string(
    (vostok::shared_string *)this,
    &name.m_pointer,
    "frame_height_lights_and_desaturation");
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
  vostok::shared_string::shared_string(v3, &name.m_pointer, "frame_mid_tones");
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
  vostok::shared_string::shared_string(v5, &name.m_pointer, "frame_shadows");
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
  vostok::shared_string::shared_string(v7, &name.m_pointer, "gamma_correction_factor");
  a2[3] = vostok::render::backend::register_constant_host(
            v8,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v9 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v9 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v9, &name.m_pointer, "frame_fade");
  a2[4] = vostok::render::backend::register_constant_host(
            v10,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v11 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v11 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v11, &name.m_pointer, "filmic_tonemap_packed_parameters_0");
  a2[5] = vostok::render::backend::register_constant_host(
            v12,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v13 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v13 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v13, &name.m_pointer, "filmic_tonemap_packed_parameters_1");
  a2[6] = vostok::render::backend::register_constant_host(
            v14,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v15 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v15 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v15, &name.m_pointer, "s_eye_ray_corner");
  a2[9] = vostok::render::backend::register_constant_host(
            v16,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v17 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v17 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v17, &name.m_pointer, "image_grain_parameters");
  a2[10] = vostok::render::backend::register_constant_host(
             v18,
             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
             &name,
             0);
  if ( name.m_pointer.m_object )
  {
    v19 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v19 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v19, &name.m_pointer, "bloom_parameters");
  a2[7] = vostok::render::backend::register_constant_host(
            v20,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    v21 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v21 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v21, &name.m_pointer, "blueshift");
  a2[8] = vostok::render::backend::register_constant_host(
            v22,
            SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
            &name,
            0);
  if ( name.m_pointer.m_object )
  {
    if ( !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
}
