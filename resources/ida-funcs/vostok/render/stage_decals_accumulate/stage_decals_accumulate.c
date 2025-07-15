void __usercall vostok::render::stage_decals_accumulate::stage_decals_accumulate(
        vostok::render::stage_decals_accumulate *this@<esi>,
        vostok::render::renderer *in_renderer@<ecx>,
        vostok::render::renderer_context *context@<eax>)
{
  vostok::render::effect_manager *m_conflicted_action_to_bind; // ecx

  this->m_context = context;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  this->m_renderer = in_renderer;
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  this->__vftable = (vostok::render::stage_decals_accumulate_vtbl *)&stru_963F84.m_desc.SampleDesc.Quality;
  this->m_opaque_geometry_mask_effect.m_object = 0;
  this->m_apply_decal_effect.m_object = 0;
  vostok::render::effect_manager::create_effect<vostok::render::effect_decal_mask>(
    m_conflicted_action_to_bind,
    &this->m_opaque_geometry_mask_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_apply_decal>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &this->m_apply_decal_effect);
  this->m_enabled = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                    + 245);
}
