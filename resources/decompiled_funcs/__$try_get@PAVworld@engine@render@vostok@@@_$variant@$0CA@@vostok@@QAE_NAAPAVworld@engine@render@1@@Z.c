char __userpurge vostok::variant<32>::try_get<vostok::render::engine::world *>@<al>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::engine::world **out_value)
{
  unsigned int v3; // eax

  if ( LOBYTE(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[1])
    || *(_DWORD *)(a2 + 44) == vostok::detail::type_to_int<vostok::render::engine::world *>::get() )
  {
    *out_value = *(vostok::render::engine::world **)(a2 + 8);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::render::engine::world *>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::render::engine::world *>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::render::engine::world *>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !LOBYTE(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[1]) )
      {
        LOBYTE(out_value) = 0;
        vostok::debug::on_error(
          (bool *)&out_value,
          process_error_false,
          (bool *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[1],
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || (_BYTE)out_value )
          __debugbreak();
      }
    }
    return 0;
  }
}
