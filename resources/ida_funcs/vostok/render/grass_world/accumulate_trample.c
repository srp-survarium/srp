void __thiscall vostok::render::grass_world::accumulate_trample(
        vostok::render::grass_world *this,
        vostok::render::grass_world *in_renderer,
        vostok::render::res_effect *in_context)
{
  vostok::render::grass_patch **M_start; // eax
  vostok::fixed_vector<vostok::render::stage *,29>::allign_helper M_finish; // ecx
  vostok::render::grass_patch *v6; // ebp
  vostok::render::trample_desc *v7; // esi
  vostok::fixed_vector<vostok::render::stage *,29>::allign_helper v8; // edi
  vostok::fixed_vector<vostok::render::stage *,29>::allign_helper v9; // eax
  vostok::render::renderer_context *v10; // [esp+0h] [ebp-14h]
  vostok::render::grass_patch *const *end_patch; // [esp+10h] [ebp-4h]
  vostok::render::grass_patch *const *it_patch; // [esp+18h] [ebp+4h]

  M_start = (vostok::render::grass_patch **)in_renderer->m_visible_patches._M_impl._M_start;
  M_finish = (vostok::fixed_vector<vostok::render::stage *,29>::allign_helper)in_renderer->m_visible_patches._M_impl._M_finish;
  it_patch = M_start;
  for ( end_patch = (vostok::render::grass_patch *const *)M_finish;
        M_start != *(vostok::render::grass_patch ***)&M_finish;
        it_patch = M_start )
  {
    v6 = *M_start;
    if ( !*((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
          + 288)
      || !v6->m_occluded )
    {
      v7 = in_renderer->m_trample_array._M_impl._M_start;
      v8 = (vostok::fixed_vector<vostok::render::stage *,29>::allign_helper)in_renderer->m_trample_array._M_impl._M_finish;
      if ( v7 != *(vostok::render::trample_desc **)&v8 )
      {
        do
          vostok::render::grass_patch::try_accumulate_trample(v7++, in_context, v6, in_renderer, v10);
        while ( v7 != *(vostok::render::trample_desc **)&v8 );
        M_start = (vostok::render::grass_patch **)it_patch;
        M_finish = (vostok::fixed_vector<vostok::render::stage *,29>::allign_helper)end_patch;
      }
    }
    ++M_start;
  }
  v9 = (vostok::fixed_vector<vostok::render::stage *,29>::allign_helper)in_renderer->m_trample_array._M_impl._M_start;
  if ( (vostok::render::trample_desc *)v9 != in_renderer->m_trample_array._M_impl._M_finish )
    in_renderer->m_trample_array._M_impl._M_finish = (vostok::render::trample_desc *)v9;
}
