void __thiscall survarium::weapon::on_after_fire(survarium::weapon *this, unsigned int time_in_ms)
{
  survarium::weapon *v3; // ecx
  survarium::fx_history_item item; // [esp+4h] [ebp-8h] BYREF

  item.uid = (char *)&this->survarium::weapon_core::survarium::interactive_object::__vftable + 1;
  item.time_in_ms = time_in_ms;
  if ( !survarium::weapon::is_fx_already_beeing_played(this, (int)this, &item) )
    survarium::weapon::play_weapon_fire_pfx(
      v3,
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
}
