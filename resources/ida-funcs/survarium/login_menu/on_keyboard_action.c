char __thiscall survarium::login_menu::on_keyboard_action(
        survarium::login_menu *this,
        survarium::swf_input_translator *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  survarium::swf_input_translator::process_keyboard(
    input_world,
    (survarium::swf_input_translator *)(&this[-1].m_scheduler.m_active_objects._M_impl._M_start[248].m_callback.functor.data
                                      + 12),
    key,
    action,
    *(survarium::flash_movie **)(LODWORD(this->m_inverted_view_matrix.i.x) + 264),
    (unsigned int)this[-1].m_scheduler.m_active_objects._M_impl._M_start[249].m_callback.functor.vostok_pointer_size_alignment[2]);
  return 1;
}
