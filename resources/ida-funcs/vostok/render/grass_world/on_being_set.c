void __usercall vostok::render::grass_world::on_being_set(
        vostok::render::grass_world *this@<ecx>,
        vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *a2@<edi>)
{
  vostok::render::backend *v2; // ecx
  vostok::render::shader_constant_host *v3; // eax
  vostok::shared_string *v4; // ecx
  bool v5; // zf
  vostok::render::backend *v6; // ecx
  vostok::render::shader_constant_host *v7; // eax
  vostok::render::resource_manager *v8; // ecx
  vostok::render::res_declaration *declaration; // eax
  vostok::shared_string name; // [esp+4h] [ebp-4h] BYREF

  vostok::shared_string::shared_string((vostok::shared_string *)this, &name.m_pointer, "patch_parameters");
  v3 = vostok::render::backend::register_constant_host(
         v2,
         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
         &name,
         0);
  v5 = name.m_pointer.m_object == 0;
  a2[113].m_object = (vostok::render::res_declaration *)v3;
  if ( !v5 )
  {
    v4 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v4 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v4, &name.m_pointer, "wind_info_parameters");
  v7 = vostok::render::backend::register_constant_host(
         v6,
         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
         &name,
         0);
  v5 = name.m_pointer.m_object == 0;
  a2[114].m_object = (vostok::render::res_declaration *)v7;
  if ( !v5 )
  {
    v8 = (vostok::render::resource_manager *)_InterlockedExchangeAdd(
                                               &name.m_pointer.m_object->m_reference_count,
                                               0xFFFFFFFF);
    if ( !v8 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  declaration = vostok::render::resource_manager::create_declaration(
                  v8,
                  (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                  grass_instanced_layout,
                  0xAu);
  vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    a2 + 66,
    declaration);
}
