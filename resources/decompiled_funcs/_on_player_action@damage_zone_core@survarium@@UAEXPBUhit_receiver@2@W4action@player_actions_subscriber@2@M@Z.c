void __thiscall survarium::damage_zone_core::on_player_action(
        survarium::damage_zone_core *this,
        const survarium::hit_receiver *receiver,
        survarium::player_actions_subscriber::action action,
        float param)
{
  void (__thiscall ***v4)(_DWORD, const survarium::hit_receiver *, survarium::player_actions_subscriber::action, _DWORD); // [esp+4h] [ebp-Ch]

  v4 = (void (__thiscall ***)(_DWORD, const survarium::hit_receiver *, survarium::player_actions_subscriber::action, _DWORD))(*(_DWORD *)(*(_DWORD *)(HIDWORD(this->m_motion_on_bound_curve.points.max_storage) + 24) + 40) + 4);
  (**v4)(v4, receiver, action, LODWORD(param));
}
