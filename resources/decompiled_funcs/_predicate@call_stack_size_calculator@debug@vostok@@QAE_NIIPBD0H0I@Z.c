char __thiscall vostok::debug::call_stack_size_calculator::predicate(
        vostok::debug::call_stack_size_calculator *this,
        survarium::game_camera *call_stack_id,
        unsigned int num_call_stack_lines,
        const char *module_name,
        const char *file_name,
        int line_number,
        const char *function,
        unsigned int address)
{
  _BYTE *v8; // eax
  char buffer; // [esp+18h] [ebp-2000h] BYREF
  _BYTE v12[3]; // [esp+19h] [ebp-1FFFh] BYREF

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v8 )
    survarium::weapon_user_dead_state::finalize(call_stack_id);
  if ( line_number <= 0 )
    vostok::sprintf(
      &buffer,
      0x2000u,
      `vostok::debug::call_stack_size_calculator::predicate'::`6'::s_call_stack_line_format_local,
      module_name,
      function,
      address);
  else
    vostok::sprintf(
      &buffer,
      0x2000u,
      `vostok::debug::call_stack_size_calculator::predicate'::`6'::s_full_call_stack_line_format_local,
      file_name,
      line_number,
      function,
      module_name,
      address);
  this->m_size += &v12[strlen(&buffer)] - v12 + 2;
  return 1;
}
