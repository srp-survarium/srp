void __thiscall vostok::particle::particle_system_instance_impl::apply_lod(
        vostok::particle::particle_system_instance_impl *this,
        unsigned int lod_index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_old_lod = this->m_current_lod;
  this->m_current_lod = lod_index;
  this->m_lods_lerp_alpha = *(float *)&clear_value - this->m_lods_lerp_alpha;
  this->m_lerped = 0;
}
