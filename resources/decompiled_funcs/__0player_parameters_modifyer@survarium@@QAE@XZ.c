void __thiscall survarium::player_parameters_modifyer::player_parameters_modifyer(
        survarium::player_parameters_modifyer *this)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->body_part_parameters_modifyers);
  this->__vftable = (survarium::player_parameters_modifyer_vtbl *)&survarium::player_parameters_modifyer::`vftable';
  stlp_std::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>::map<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>,stlp_std::less<vostok::ai::npc *>,vostok::ai::std_allocator<stlp_std::pair<vostok::ai::npc *,vostok::intrusive_list<vostok::ai::sensors::sound_subscriber,vostok::ai::sensors::sound_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>>>>((stlp_std::map<char const *,unsigned int,stlp_std::less<char const *>,vostok::ai::std_allocator<stlp_std::pair<char const *,unsigned int> > > *)&this->body_part_parameters_modifyers);
  this->speed_modifyer = *(float *)&FLOAT_0_0;
  this->total_items_weight = *(float *)&FLOAT_0_0;
  this->dispersion_correction_perc = *(float *)&FLOAT_0_0;
  this->aiming_speed_correction_perc = *(float *)&FLOAT_0_0;
  this->movement_speed_correction_perc = *(float *)&FLOAT_0_0;
  this->additional_max_weight = *(float *)&FLOAT_0_0;
  this->stamina_regen_correction_perc = *(float *)&FLOAT_0_0;
  this->health_regen_correction_perc = *(float *)&FLOAT_0_0;
  this->pain_healt_correction_perc = *(float *)&FLOAT_0_0;
  this->artcontainer_time_corr_perc = *(float *)&FLOAT_0_0;
  this->anomaly_damage_corr_perc = *(float *)&FLOAT_0_0;
  this->engineer_use_time_corr_perc = *(float *)&FLOAT_0_0;
  this->engineer_succ_chance_corr_perc = *(float *)&FLOAT_0_0;
  this->additional_artefact_slots = 0;
  this->additional_devices_slots = 0;
}
