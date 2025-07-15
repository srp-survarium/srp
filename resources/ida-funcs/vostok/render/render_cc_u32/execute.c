void __thiscall vostok::render::render_cc_u32::execute(vostok::render::render_cc_u32 *this, char *args)
{
  *this->m_value = *(_DWORD *)this->m_on_change_event.functor.vostok_pointer_size_alignment[2];
  vostok::console_commands::cc_u32::execute((vostok::console_commands::cc_u32 *)this, args);
}
