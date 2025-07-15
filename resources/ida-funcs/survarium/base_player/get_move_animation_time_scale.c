float __userpurge survarium::base_player::get_move_animation_time_scale@<xmm0>(
        survarium::base_player *this@<esi>,
        survarium::weapon_user_state_enum user_state@<edx>,
        unsigned int animation_index@<ecx>,
        bool aimed)
{
  float value; // xmm0_4

  value = COERCE_FLOAT(
            survarium::player_speed_parameters::get_speed_multiplier(
              animation_index,
              user_state,
              &this->m_speed_parameters,
              aimed));
  return survarium::player_params_modifiers_container::apply_modifier(
           (survarium::player_params_modifiers_container *)&(*(survarium::base_player_vtbl **)((char *)&this->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
                                                                                             + (_DWORD)&loc_11066
                                                                                             + 2))[7],
           movement_speed_modifier,
           value,
           value,
           1.0);
}
