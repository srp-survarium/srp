void __thiscall vostok::particle::base_particle::base_particle(vostok::particle::base_particle *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->render_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->render_old_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->spawn_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->old_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->velocity);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->start_velocity);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->size);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->start_size);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->rotation_rate);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->start_rotation_rate);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->prev_offset_position);
}
