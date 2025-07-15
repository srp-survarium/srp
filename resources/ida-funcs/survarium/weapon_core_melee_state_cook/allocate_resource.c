vostok::mutable_buffer *__thiscall survarium::weapon_core_melee_state_cook::allocate_resource(
        survarium::weapon_core_melee_state_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  const char *v9; // [esp+0h] [ebp-8h]
  const char *v10; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  v5 = survarium::g_allocator;
  v6 = type_info::raw_name(&survarium::weapon_core_melee_state `RTTI Type Descriptor');
  result->m_data = vostok::memory::doug_lea_allocator::malloc_impl(v7, (int)v5, 0x140u, v6, v9, v10, savedregs);
  result->m_size = 320;
  return result;
}
