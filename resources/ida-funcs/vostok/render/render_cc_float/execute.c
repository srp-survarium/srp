void __thiscall vostok::render::render_cc_float::execute(vostok::render::render_cc_float *this, const char *args)
{
  *this->m_value = *(float *)this->m_on_change_event.functor.vostok_pointer_size_alignment[2];
  vostok::console_commands::cc_float::execute((vostok::console_commands::cc_float *)this, args);
}
