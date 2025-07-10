char __usercall vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>@<al>(
        vostok::variant<32> *this@<eax>,
        vostok::animation::animation_collection_cook_user_data *out_value@<edi>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+Bh] [ebp-1h] BYREF

  if ( BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3])
    || this->m_type_id == vostok::detail::type_to_int<vostok::animation::animation_collection_cook_user_data>::get() )
  {
    out_value->val = *(const vostok::configs::binary_config_value **)this->m_storage;
    vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
      &out_value->cfg_ptr,
      (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)&this->m_storage[4]);
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::animation::animation_collection_cook_user_data>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !BYTE2(`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3]) )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          (bool *)&`vostok::memory::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>::single_size_buffer_allocator<300,vostok::threading::single_threading_policy>'::`5'::debug_macro_helper_ignore_always.m_options[3]
        + 2,
          assert_untyped,
          "assertion_failed",
          "m_type_id == detail::type_to_int<T>::get()",
          "C:\\survarium\\sources\\vostok/type_variant_inline.h",
          "vostok::variant<32>::try_get",
          0x98u);
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
    return 0;
  }
}
