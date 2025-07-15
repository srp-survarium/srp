char __thiscall survarium::login_menu::on_keyboard_action(
        survarium::login_menu *this,
        vostok::input::world *input_world,
        vostok::input::enum_keyboard key,
        vostok::input::enum_keyboard_action action)
{
  survarium::swf_input_translator::process_keyboard(
    (survarium::swf_input_translator *)&this[-1].vostok::input::handler::__vftable[30],
    input_world,
    key,
    action,
    (survarium::flash_movie *)this->survarium::base_game_scene::survarium::engine::__vftable[66].get_bullet_manager,
    (unsigned int)this[-1].vostok::input::handler::__vftable[31].on_after_processing);
  return 1;
}
