void __userpurge vostok::render::stage_accumulate_distortion::stage_accumulate_distortion(
        vostok::render::stage_accumulate_distortion *this@<eax>,
        vostok::render::renderer_context *context@<ecx>,
        vostok::render::renderer *in_renderer)
{
  survarium::game_action_id *M_start; // ecx

  this->m_context = context;
  this->m_enabled = 1;
  this->m_prev_enabled = 1;
  M_start = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  this->m_renderer = in_renderer;
  this->__vftable = (vostok::render::stage_accumulate_distortion_vtbl *)&stru_963F84.m_name.m_string.m_end;
  this->m_enabled = *((_BYTE *)M_start + 246);
}
