void __thiscall vostok::render::res_render_output::present(vostok::render::res_render_output *this)
{
  bool v1; // zf
  HRESULT v2; // eax
  vostok::render::device *v3; // ecx
  const char *d3d11_error_string; // eax
  bool do_debug_break; // [esp+Dh] [ebp-1h] BYREF

  do_debug_break = HIBYTE(this);
  v1 = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
       + 241) == 0;
  this->m_present_sync_mode = *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start
                              + 241) != 0;
  v2 = this->m_swap_chain->Present(this->m_swap_chain, !v1, 0);
  if ( v2 == -2005270523 || v2 == -2005270521 || v2 == -2005270496 )
  {
    vostok::render::device::on_device_removed(v3);
  }
  else if ( !LOBYTE(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish)
         && v2 < 0 )
  {
    do_debug_break = 1;
    d3d11_error_string = make_d3d11_error_string(v2);
    vostok::debug::on_error(
      &do_debug_break,
      process_error_true,
      (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_conflicted_action_ids._M_impl._M_finish,
      assert_untyped,
      "assertion_failed",
      d3d11_error_string,
      ".\\res_render_output.cpp",
      "vostok::render::res_render_output::present",
      0x8Du);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
  }
}
