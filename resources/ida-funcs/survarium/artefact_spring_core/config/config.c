void __usercall survarium::artefact_spring_core::config::config(
        survarium::artefact_spring_core::config *this@<eax>,
        const survarium::artefact_spring_core::config *__that@<edx>)
{
  double value; // st7
  double v3; // st7
  double v4; // st7
  double v5; // st7

  qmemcpy(this, __that, 0x18u);
  this->passive.movement_speed_mod.next = 0;
  value = __that->passive.max_carried_weight_mod.value;
  this->passive.max_carried_weight_mod.next = 0;
  this->passive.max_carried_weight_mod.value = value;
  v3 = __that->active.movement_speed_mod.value;
  this->active.movement_speed_mod.next = 0;
  this->active.movement_speed_mod.value = v3;
  v4 = __that->active.stamina_regen_mod.value;
  this->active.stamina_regen_mod.next = 0;
  this->active.stamina_regen_mod.value = v4;
  v5 = __that->active.stamina_spend_mod.value;
  this->active.stamina_spend_mod.next = 0;
  this->active.stamina_spend_mod.value = v5;
  this->active.duration_ms = __that->active.duration_ms;
}
