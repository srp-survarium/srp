void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::decal_instance>(
        vostok::render::decal_instance *const pointer@<eax>,
        vostok::render::decal_instance *a2@<ecx>,
        vostok::memory::detail::call_destructor_predicate *this)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_material; // esi
  vostok::render::material_manager *v5; // ecx

  vostok::render::decal_instance::remove_collision(a2);
  p_material = &pointer->m_properties.material;
  vostok::render::material_manager::remove_material_effects(
    v5,
    (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y);
  if ( p_material->m_object )
  {
    if ( !_InterlockedExchangeAdd(&p_material->m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &p_material->m_object->vostok::resources::unmanaged_intrusive_base,
        p_material->m_object);
  }
}


void __usercall vostok::memory::detail::call_destructor_predicate::operator()<vostok::render::environment_probe>(
        vostok::render::environment_probe *const pointer@<edi>,
        vostok::render::environment_probe *a2@<ecx>,
        vostok::memory::detail::call_destructor_predicate *this)
{
  vostok::render::res_texture *v3; // ecx
  vostok::render::res_texture *m_object; // eax
  bool v5; // zf
  vostok::render::res_texture *v6; // eax

  vostok::render::environment_probe::remove_collision(a2);
  m_object = pointer->m_texture_depth.m_object;
  if ( m_object )
  {
    v5 = m_object->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl(v3);
  }
  v6 = pointer->m_texture.m_object;
  if ( v6 )
  {
    v5 = v6->m_reference_count-- == 1;
    if ( v5 )
      vostok::render::res_texture::destroy_impl(v3);
  }
}


void __thiscall vostok::memory::detail::call_destructor_predicate::operator()<survarium::profile_player_character>(
        vostok::memory::detail::call_destructor_predicate *this)
{
  if ( *(_DWORD *)this && !_InterlockedExchangeAdd((volatile signed __int32 *)(*(_DWORD *)this + 496), 0xFFFFFFFF) )
  {
    if ( *(_DWORD *)this )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)this + 496),
        (vostok::resources::unmanaged_resource *)(*(_DWORD *)this + 288));
    else
      vostok::resources::unmanaged_intrusive_base::destroy((vostok::resources::unmanaged_intrusive_base *)0x1F0, 0);
  }
}


void __thiscall vostok::memory::detail::call_destructor_predicate::operator()<vostok::resources::resource_base>(
        vostok::memory::detail::call_destructor_predicate *this)
{
  (**(void (__thiscall ***)(vostok::memory::detail::call_destructor_predicate *, _DWORD))this)(this, 0);
}
