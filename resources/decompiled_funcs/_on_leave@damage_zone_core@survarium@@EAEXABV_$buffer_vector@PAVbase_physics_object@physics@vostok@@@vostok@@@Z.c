void __thiscall survarium::damage_zone_core::on_leave(
        survarium::damage_zone_core *this,
        const vostok::buffer_vector<vostok::physics::base_physics_object *> *objects)
{
  vostok::physics::base_physics_object **m_begin; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  survarium::game_camera *v5; // ecx
  survarium::hit_receiver_info *__pos; // [esp+8h] [ebp-48h]
  stlp_std::__false_type __formal; // [esp+27h] [ebp-29h] BYREF
  survarium::hit_receiver_info *__first; // [esp+28h] [ebp-28h]
  survarium::hit_receiver_info *__last; // [esp+2Ch] [ebp-24h]
  survarium::generic_anomaly_core *owner; // [esp+30h] [ebp-20h]
  char v12; // [esp+34h] [ebp-1Ch]
  char v13; // [esp+35h] [ebp-1Bh]
  char v14; // [esp+36h] [ebp-1Ah]
  char v15; // [esp+37h] [ebp-19h]
  survarium::hit_receiver *receiver; // [esp+38h] [ebp-18h]
  survarium::hit_receiver_info info; // [esp+3Ch] [ebp-14h] BYREF
  vostok::physics::base_physics_object *const *end; // [esp+48h] [ebp-8h]
  vostok::physics::base_physics_object *const *it; // [esp+4Ch] [ebp-4h]

  m_begin = objects->m_begin;
  it = objects->m_begin;
  end = objects->m_end;
  while ( it != end )
  {
    v15 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)m_begin);
    receiver = (*it)->user_data->cast_to_hit_receiver((*it)->user_data);
    v14 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    v13 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    if ( this->m_owner )
    {
      if ( this )
        receiver->unsubscribe_from_actions(receiver, &this->survarium::player_actions_subscriber);
      else
        receiver->unsubscribe_from_actions(receiver, 0);
      owner = this->m_owner->owner->owner;
      survarium::generic_anomaly_core::on_hit_receiver_leave(owner, receiver, this);
    }
    survarium::hit_receiver_info::hit_receiver_info(&info, receiver, 0);
    v12 = 0;
    survarium::weapon_user_dead_state::finalize(v5);
    __last = this->m_receivers._M_impl._M_finish;
    __first = this->m_receivers._M_impl._M_start;
    __pos = stlp_std::find<survarium::hit_receiver_info *,survarium::hit_receiver_info>(__first, __last, &info);
    __formal = 0;
    stlp_std::priv::_Impl_vector<survarium::hit_receiver_info,survarium::std_allocator<survarium::hit_receiver_info>>::_M_erase(
      &this->m_receivers._M_impl,
      __pos,
      &__formal);
    m_begin = (vostok::physics::base_physics_object **)++it;
  }
}
