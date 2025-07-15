void __usercall vostok::render::skeleton_render_model::skeleton_render_model(
        vostok::render::skeleton_render_model *this@<ecx>,
        vostok::shared_string *a2@<edi>)
{
  vostok::render::backend *v2; // ecx
  vostok::strings::shared::profile *v3; // eax
  vostok::shared_string *v4; // ecx
  bool v5; // zf
  vostok::render::backend *v6; // ecx
  vostok::strings::shared::profile *v7; // eax
  vostok::shared_string name; // [esp+4h] [ebp-4h] BYREF

  vostok::render::render_model::render_model(this, (int)a2);
  a2->m_pointer.m_object = (vostok::strings::shared::profile *)&vostok::render::skeleton_render_model::`vftable';
  a2[80].m_pointer.m_object = (vostok::strings::shared::profile *)&a2[83];
  a2[81].m_pointer.m_object = (vostok::strings::shared::profile *)&a2[83];
  a2[82].m_pointer.m_object = (vostok::strings::shared::profile *)&a2[2131];
  vostok::shared_string::shared_string(a2 + 2131, &name.m_pointer, "bones_matrices");
  v3 = (vostok::strings::shared::profile *)vostok::render::backend::register_constant_host(
                                             v2,
                                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                             &name,
                                             0);
  v5 = name.m_pointer.m_object == 0;
  a2[78].m_pointer.m_object = v3;
  if ( !v5 )
  {
    v4 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v4 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  vostok::shared_string::shared_string(v4, &name.m_pointer, "prev_bones_matrices");
  v7 = (vostok::strings::shared::profile *)vostok::render::backend::register_constant_host(
                                             v6,
                                             SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                             &name,
                                             0);
  v5 = name.m_pointer.m_object == 0;
  a2[79].m_pointer.m_object = v7;
  if ( !v5 && !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
}
