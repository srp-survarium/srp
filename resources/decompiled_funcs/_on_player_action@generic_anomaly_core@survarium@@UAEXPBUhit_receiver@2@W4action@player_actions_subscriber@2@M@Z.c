void __thiscall survarium::generic_anomaly_core::on_player_action(
        survarium::generic_anomaly_core *this,
        const survarium::hit_receiver *receiver,
        survarium::player_actions_subscriber::action action,
        float param)
{
  float amount; // [esp+0h] [ebp-3Ch]
  float amounta; // [esp+0h] [ebp-3Ch]
  float amountb; // [esp+0h] [ebp-3Ch]
  float amountc; // [esp+0h] [ebp-3Ch]
  float amountd; // [esp+0h] [ebp-3Ch]
  float amounte; // [esp+0h] [ebp-3Ch]

  switch ( action )
  {
    case none:
      amount = (double)this->energy_on_walk * param;
      survarium::generic_anomaly_core::inc_energy((survarium::generic_anomaly_core *)((char *)this - 4), amount);
      break;
    case move_forward:
      amounta = (double)this->energy_on_run * param;
      survarium::generic_anomaly_core::inc_energy((survarium::generic_anomaly_core *)((char *)this - 4), amounta);
      break;
    case move_backward:
      amountb = (float)this->energy_on_sprint;
      survarium::generic_anomaly_core::inc_energy((survarium::generic_anomaly_core *)((char *)this - 4), amountb);
      break;
    case move_backward|move_forward:
      amountc = (float)this->energy_on_jump;
      survarium::generic_anomaly_core::inc_energy((survarium::generic_anomaly_core *)((char *)this - 4), amountc);
      BYTE1(this->m_current_state) = 1;
      break;
    case strafe_left:
      amountd = (float)this->energy_on_shoot;
      survarium::generic_anomaly_core::inc_energy((survarium::generic_anomaly_core *)((char *)this - 4), amountd);
      break;
    case strafe_left|move_forward:
      amounte = (float)this->energy_on_character_hit;
      survarium::generic_anomaly_core::inc_energy((survarium::generic_anomaly_core *)((char *)this - 4), amounte);
      break;
  }
}
