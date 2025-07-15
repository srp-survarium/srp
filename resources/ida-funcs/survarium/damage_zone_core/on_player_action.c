void __thiscall survarium::damage_zone_core::on_player_action(
        survarium::damage_zone_core *this,
        const survarium::hit_receiver *receiver,
        survarium::player_actions_subscriber::action action,
        float param)
{
  (**(void (__stdcall ***)(const survarium::hit_receiver *, survarium::player_actions_subscriber::action, _DWORD))(*(_DWORD *)(*(_DWORD *)(LODWORD(this->m_target_satisfaction) + 32) + 40) + 4))(
    receiver,
    action,
    LODWORD(param));
}
