vostok::fixed_string<260> *__cdecl vostok::render::make_effect_name(
        vostok::fixed_string<260> *result,
        const char *descriptor_name,
        const vostok::resources::resource_ptr<vostok::render::material,vostok::resources::unmanaged_intrusive_base> *material,
        unsigned int vtype)
{
  vostok::fixed_string<260> *v4; // ebx
  char *m_buffer; // eax
  vostok::fixed_string<260> *v6; // ecx
  vostok::buffer_string *v7; // ecx

  v4 = result;
  m_buffer = result->m_buffer;
  v6 = result + 1;
  result->m_begin = result->m_buffer;
  v4->m_end = m_buffer;
  v4->m_max_end = (char *)v6;
  *m_buffer = 0;
  *m_buffer = 0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&material->m_object->m_config);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  vostok::fs_new::path_string_impl::assignf(
    v4,
    v7,
    (vostok::buffer_string *)"%s/%s/%llu_%d",
    material->m_object->m_material_name.m_begin,
    descriptor_name,
    (__int64)(int)result,
    vtype);
  return v4;
}
