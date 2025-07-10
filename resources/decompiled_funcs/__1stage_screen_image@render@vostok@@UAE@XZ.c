void __thiscall vostok::render::stage_screen_image::~stage_screen_image(vostok::render::stage_screen_image *this)
{
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::res_declaration *m_object; // eax
  vostok::render::res_effect *v6; // eax

  this->__vftable = (vostok::render::stage_screen_image_vtbl *)&vostok::render::stage_screen_image::`vftable';
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>(
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)this->m_textures.m_container._M_impl._M_finish,
    (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>)this->m_textures.m_container._M_impl._M_start);
  M_start = this->m_textures.m_container._M_impl._M_start;
  if ( M_start )
  {
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
  }
  m_object = this->m_decl_ptr.m_object;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        this->m_decl_ptr.m_object);
  }
  v6 = this->m_present_effect.m_object;
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_present_effect.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_present_effect.m_object);
  this->__vftable = (vostok::render::stage_screen_image_vtbl *)&vostok::render::stage::`vftable';
}
