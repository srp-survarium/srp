vostok::mutable_buffer *__thiscall survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state>::allocate_resource(
        survarium::weapon_core_state_cook_template<survarium::weapon_core_idle_state> *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  unsigned __int8 *v5; // eax

  v5 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                            (vostok::memory::doug_lea_allocator *)survarium::g_allocator.f_.f_,
                            0x148u);
  boost::_bi::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>::storage2<boost::_bi::value<enum vostok::connection_error_types_enum>,boost::_bi::value<enum vostok::handshaking_error_types_enum>>(
    result,
    v5,
    0x148u);
  return result;
}
