vostok::animation::callback_return_type_enum __thiscall survarium::weapon::on_shell_extraction_event(
        survarium::weapon *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon::play_weapon_shell_pfx(this, (int)this);
  return 0;
}
