void __userpurge survarium::grenade_core::explode(
        survarium::grenade_core *this@<ecx>,
        float a2@<xmm0>,
        const unsigned int time_delta_ms,
        const unsigned int current_time_ms)
{
  survarium::grenade_set_core *m_owner; // esi
  int v6; // eax
  const survarium::hit_initiator *v7; // eax
  survarium::grenade_set_core *m_game_world_core; // ecx
  survarium::bullet_manager *m_flags; // ebp
  survarium::grenade_set_core *v10; // ecx
  vostok::physics::bt_animated_rigid_body **v11; // esi
  unsigned int v12; // [esp-8h] [ebp-50h]
  const survarium::hit_initiator *v13; // [esp-4h] [ebp-4Ch]
  survarium::explosive result; // [esp+10h] [ebp-38h] BYREF

  m_owner = this->m_owner;
  v6 = (int)m_owner->m_inventory->m_holder->cast_to_base_player(m_owner->m_inventory->m_holder);
  if ( v6 )
    v7 = (const survarium::hit_initiator *)(v6 + 300);
  else
    v7 = 0;
  m_game_world_core = (survarium::grenade_set_core *)m_owner->m_game_world_core;
  m_flags = (survarium::bullet_manager *)m_game_world_core[139].survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.survarium::inventory_item::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v13 = v7;
  v12 = survarium::grenade_set_core::current_time_in_ms(m_game_world_core, (int)m_owner);
  v11 = (vostok::physics::bt_animated_rigid_body **)survarium::grenade_set_core::explosive(
                                                      v10,
                                                      (int)m_owner,
                                                      a2,
                                                      &result);
  survarium::bullet_manager::explode((const vostok::math::float3 *)&this->m_transform.lines[3], v11, m_flags, v12, v13);
  this->remove_physics(this);
  this->reset_pin(this);
  this->m_exploded = 1;
}
