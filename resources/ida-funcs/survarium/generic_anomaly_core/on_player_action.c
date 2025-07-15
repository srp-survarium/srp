void __thiscall survarium::generic_anomaly_core::on_player_action(
        survarium::generic_anomaly_core *this,
        const survarium::hit_receiver *receiver,
        survarium::player_actions_subscriber::action action,
        float param)
{
  float v4; // xmm0_4
  int v5; // ecx
  float energy_on_shoot; // [esp+10h] [ebp+10h]
  float energy_on_jump; // [esp+10h] [ebp+10h]
  float energy_on_sprint; // [esp+10h] [ebp+10h]
  float v9; // [esp+10h] [ebp+10h]
  float v10; // [esp+10h] [ebp+10h]

  if ( action )
  {
    if ( action == sprint )
    {
      v9 = (double)this->energy_on_run * param;
      v4 = v9;
    }
    else if ( action == jump )
    {
      energy_on_sprint = (float)this->energy_on_sprint;
      v4 = energy_on_sprint;
    }
    else
    {
      if ( action == shoot )
      {
        energy_on_jump = (float)this->energy_on_jump;
        survarium::generic_anomaly_core::inc_energy(this, (int)(&this[-1].m_random + 1), energy_on_jump);
        *(_BYTE *)(v5 + 389) = 1;
        return;
      }
      if ( action == hit )
        energy_on_shoot = (float)this->energy_on_shoot;
      else
        energy_on_shoot = (float)this->energy_on_character_hit;
      v4 = energy_on_shoot;
    }
  }
  else
  {
    v10 = (double)this->energy_on_walk * param;
    v4 = v10;
  }
  survarium::generic_anomaly_core::inc_energy(this, (int)(&this[-1].m_random + 1), v4);
}
