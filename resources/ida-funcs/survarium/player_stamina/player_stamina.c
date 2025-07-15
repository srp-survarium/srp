void __thiscall survarium::player_stamina::player_stamina(
        survarium::player_stamina *this,
        const survarium::stamina_base_parameters *parameters,
        survarium::player_params_modifiers_container *modifiers,
        float a4)
{
  float max_value; // esi
  vostok::threading::mutex *v5; // ecx

  parameters->max_value = 0.0;
  vostok::threading::mutex_tasks_unaware::mutex_tasks_unaware(
    (vostok::threading::mutex_tasks_unaware *)this,
    (_RTL_CRITICAL_SECTION *)&parameters->regeneration_speed);
  parameters->max_carried_weight_spending_speed_modifier = 0.0;
  parameters[1].max_value = 0.0;
  qmemcpy(&parameters[1].regeneration_speed, modifiers, sizeof(const survarium::stamina_base_parameters));
  parameters[2].regeneration_speed = 0.0;
  parameters[3].max_value = a4;
  *(_QWORD *)&parameters[3].sprint_spending_speed = 0;
  *(_QWORD *)&parameters[3].amount_to_jump = 0;
  max_value = parameters[3].max_value;
  parameters[3].stop_low_stamina_value = parameters[1].regeneration_speed;
  parameters[3].min_carried_weight = NAN;
  parameters[3].max_carried_weight = NAN;
  LOBYTE(parameters[3].max_carried_weight_movement_speed_modifier) = 0;
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(LODWORD(max_value) + 992),
    (survarium::player_params_modifier *)&parameters[3].sprint_spending_speed,
    0);
  vostok::intrusive_list<vostok::resources::fs_task,vostok::resources::fs_task *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
    (vostok::intrusive_list<survarium::player_params_modifier,survarium::player_params_modifier *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)(LODWORD(parameters[3].max_value) + 272),
    (survarium::player_params_modifier *)&parameters[3].amount_to_jump,
    v5);
}
