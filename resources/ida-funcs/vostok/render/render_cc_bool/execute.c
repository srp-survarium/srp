void __thiscall vostok::render::render_cc_bool::execute(vostok::render::render_cc_bool *this, const char *args)
{
  *(_BYTE *)this->m_on_change_event.functor.bound_memfunc_ptr.obj_ptr = *(_BYTE *)this->m_on_change_event.functor.vostok_pointer_size_alignment[2];
  vostok::console_commands::cc_bool::execute((vostok::console_commands::cc_bool *)this, args);
}
