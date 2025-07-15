vostok::mutable_buffer *__thiscall survarium::weapon_preview_state_cook::allocate_resource(
        survarium::weapon_preview_state_cook *this,
        vostok::mutable_buffer *result,
        vostok::resources::query_result_for_cook *in_query,
        vostok::const_buffer raw_file_data,
        bool file_exist)
{
  const char *v6; // [esp+0h] [ebp-8h]
  const char *v7; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  result->m_data = vostok::memory::doug_lea_allocator::malloc_impl(
                     (vostok::memory::doug_lea_allocator *)this,
                     (int)survarium::g_allocator,
                     0x138u,
                     "buffer for weapon_preview_state",
                     v6,
                     v7,
                     savedregs);
  result->m_size = 312;
  return result;
}
