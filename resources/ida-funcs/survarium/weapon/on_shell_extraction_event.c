vostok::animation::callback_return_type_enum __thiscall survarium::weapon::on_shell_extraction_event(
        survarium::weapon *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon *v3; // ecx
  survarium::fx_history_item item; // [esp+8h] [ebp-8h] BYREF

  item.time_in_ms = params->callback_time_in_ms;
  item.uid = this;
  if ( !survarium::weapon::is_fx_already_beeing_played(this, (int)this, &item) )
    survarium::weapon::play_weapon_shell_pfx(
      v3,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
  return 0;
}
