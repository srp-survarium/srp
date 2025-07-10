survarium::collision_geometry *__thiscall survarium::collision_sensor::get_collision_geometry(
        survarium::collision_sensor *this,
        unsigned int index)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  return this->m_collision_geometries[index];
}
