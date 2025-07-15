void __thiscall survarium::grenade::on_contact_callback(
        survarium::grenade *this,
        const vostok::physics::contact_point *cp)
{
  survarium::grenade_set_core *m_owner; // eax
  unsigned __int16 v4; // ax
  unsigned int time_in_ms; // edx
  unsigned int v6; // esi
  unsigned __int16 m_material_id; // ax
  const survarium::game_material_manager *v8; // eax
  survarium::game_material_manager *v9; // ecx
  const survarium::material_pair *pair; // eax
  const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_collision_sound; // eax
  unsigned __int16 v12; // [esp-8h] [ebp-24h]
  unsigned __int16 v13; // [esp-4h] [ebp-20h]
  __int64 v14; // [esp+10h] [ebp-Ch]
  vostok::math::float3 *p_position; // [esp+18h] [ebp-4h]

  p_position = &this->m_last_contact.position;
  this->m_last_contact.position = cp->point_world_on_a;
  LODWORD(v14) = LODWORD(cp->normal_world_on_a.y) ^ _mask__NegFloat_;
  m_owner = this->m_owner;
  HIDWORD(v14) = LODWORD(cp->normal_world_on_a.z) ^ _mask__NegFloat_;
  LODWORD(this->m_last_contact.normal.x) = LODWORD(cp->normal_world_on_a.x) ^ _mask__NegFloat_;
  *(_QWORD *)&this->m_last_contact.normal.elements[1] = v14;
  this->m_last_contact.time_in_ms = survarium::grenade_set_core::current_time_in_ms(
                                      (survarium::grenade_set_core *)this,
                                      (int)m_owner);
  v4 = ((int (__thiscall *)(vostok::physics::base_physics_object *, int, bool))cp->object_b->__vftable[2].get_collision_group)(
         cp->object_b,
         cp->index_b,
         cp->part_id_b == 1);
  time_in_ms = this->m_last_contact.time_in_ms;
  v6 = this->m_collide_sound_last_time + this->m_min_roll_time_ms;
  this->m_last_contact.material_id = v4;
  if ( time_in_ms >= v6 )
  {
    v13 = v4;
    m_material_id = this->m_material_id;
    this->m_collide_sound_last_time = time_in_ms;
    v12 = m_material_id;
    v8 = this->m_game_world->get_game_material_manager(this->m_game_world);
    pair = survarium::game_material_manager::get_pair(v9, (int)v8, v12, v13);
    if ( pair )
    {
      p_m_collision_sound = &pair->m_collision_sound;
      if ( p_m_collision_sound->m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          this->m_game_world->play_sound(this->m_game_world, p_m_collision_sound, p_position);
      }
    }
  }
}
