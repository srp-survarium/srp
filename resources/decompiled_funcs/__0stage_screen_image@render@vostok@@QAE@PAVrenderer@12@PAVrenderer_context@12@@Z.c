void __usercall vostok::render::stage_screen_image::stage_screen_image(
        vostok::render::stage_screen_image *this@<edi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::render::resource_manager *v3; // eax
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v5; // ecx
  vostok::render::res_declaration *m_object; // eax
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> __x; // [esp+Ch] [ebp-40h] BYREF
  D3D11_INPUT_ELEMENT_DESC dcl[2]; // [esp+10h] [ebp-3Ch] BYREF

  this->m_context = context;
  this->m_renderer = in_renderer;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->__vftable = (vostok::render::stage_screen_image_vtbl *)&vostok::render::stage_screen_image::`vftable';
  this->m_present_effect.m_object = 0;
  this->m_decl_ptr.m_object = 0;
  dcl[0].Format = DXGI_FORMAT_R32G32_FLOAT;
  dcl[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  v3 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  this->m_textures.m_reference_count = 0;
  this->m_textures.m_container._M_impl._M_start = 0;
  this->m_textures.m_container._M_impl._M_finish = 0;
  this->m_textures.m_container._M_impl._M_end_of_storage._M_data = 0;
  this->m_textures.m_is_registered = 0;
  dcl[0].SemanticName = "POSITIONT";
  dcl[0].SemanticIndex = 0;
  dcl[0].InputSlot = 0;
  dcl[0].AlignedByteOffset = 0;
  dcl[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  dcl[0].InstanceDataStepRate = 0;
  dcl[1].SemanticName = "TEXCOORD";
  dcl[1].SemanticIndex = 0;
  dcl[1].InputSlot = 0;
  dcl[1].AlignedByteOffset = 8;
  dcl[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  dcl[1].InstanceDataStepRate = 0;
  declaration = vostok::render::resource_manager::create_declaration(2u, v3, (stlp_std::forward_iterator_tag *)dcl);
  v5 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v5 = declaration;
  }
  m_object = this->m_decl_ptr.m_object;
  this->m_decl_ptr.m_object = v5;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  vostok::render::effect_manager::create_effect<vostok::render::scr_quad_effect>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_present_effect);
  __x.m_object = 0;
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::resize(
    &this->m_textures.m_container._M_impl,
    1u,
    &__x);
}
