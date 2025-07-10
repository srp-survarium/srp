char __usercall vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>@<al>(
        vostok::variant<32> *this@<esi>,
        vostok::ai::brain_unit_cook_params *out_value@<edi>,
        int a3@<ecx>)
{
  unsigned int v3; // eax
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a3);
  if ( `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`5'::debug_macro_helper_ignore_always
    || this->m_type_id == vostok::detail::type_to_int<vostok::ai::brain_unit_cook_params>::get() )
  {
    out_value->sound_world_user = *(vostok::sound::world_user **)this->m_storage;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
      &out_value->sound_scene,
      (const vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_storage[4]);
    out_value->npc = *(vostok::ai::npc **)&this->m_storage[8];
    return 1;
  }
  else
  {
    v3 = `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`8'::occurances_left;
    if ( `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`8'::occurances_left == -1 )
      v3 = 10;
    `vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`8'::occurances_left = v3 - 1;
    if ( v3 )
    {
      if ( !`vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`5'::debug_macro_helper_ignore_always )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          &do_debug_break,
          process_error_false,
          &`vostok::variant<32>::try_get<vostok::ai::brain_unit_cook_params>'::`5'::debug_macro_helper_ignore_always,
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
