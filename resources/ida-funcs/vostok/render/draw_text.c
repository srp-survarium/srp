void __usercall vostok::render::draw_text(
        const char *str@<edi>,
        const vostok::ui::font *in_font,
        unsigned int pos_x,
        unsigned int pos_y,
        vostok::math::color clr)
{
  unsigned int v5; // esi
  vostok::math::float2 in_position; // [esp+4h] [ebp-38h] BYREF
  vostok::vectora<vostok::render::ui::vertex> out_vertices; // [esp+Ch] [ebp-30h] BYREF
  vostok::render::ui::vertex __x; // [esp+1Ch] [ebp-20h] BYREF

  v5 = strlen(str);
  out_vertices._M_impl._M_end_of_storage.m_allocator = (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object;
  out_vertices._M_impl._M_start = 0;
  out_vertices._M_impl._M_finish = 0;
  out_vertices._M_impl._M_end_of_storage._M_data = 0;
  __x.m_uv.x = SNaN;
  __x.m_uv.y = SNaN;
  stlp_std::priv::_Impl_vector<vostok::render::ui::vertex,vostok::vectora_allocator<vostok::render::ui::vertex>>::resize(
    4 * v5,
    &out_vertices._M_impl,
    &__x);
  in_position.x = (float)pos_x;
  in_position.y = (float)pos_y;
  vostok::render::make_ui_vertices(&in_position, &out_vertices, str, in_font, &clr, &clr, v5);
  clr = (vostok::math::color)(out_vertices._M_impl._M_finish - out_vertices._M_impl._M_start);
  vostok::render::system_renderer::draw_ui_vertices(
    (vostok::render::system_renderer *)&clr,
    (vostok::render::system_renderer *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x,
    (unsigned __int8 *)out_vertices._M_impl._M_start,
    (unsigned int)&clr,
    0,
    0);
  if ( out_vertices._M_impl._M_start )
    out_vertices._M_impl._M_end_of_storage.m_allocator->call_free(
      out_vertices._M_impl._M_end_of_storage.m_allocator,
      out_vertices._M_impl._M_start);
}
