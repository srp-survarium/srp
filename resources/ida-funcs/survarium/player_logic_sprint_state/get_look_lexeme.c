vostok::animation::mixing::animation_lexeme *__userpurge survarium::player_logic_sprint_state::get_look_lexeme@<eax>(
        survarium::player_logic_sprint_state *this@<ecx>,
        int a2@<edi>,
        float a3@<xmm0>,
        vostok::animation::mixing::animation_lexeme *result,
        vostok::mutable_buffer *buffer,
        int animation_index,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation)
{
  vostok::animation::mixing::animation_lexeme *v7; // ecx
  float v8; // xmm0_4
  fastdelegate::detail::GenericClass *v9; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v10; // ecx
  vostok::animation::mixing::animation_lexeme *v12; // [esp+0h] [ebp-68h]
  vostok::animation::mixing::animation_lexeme_parameters parameters; // [esp+8h] [ebp-60h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v14; // [esp+60h] [ebp-8h] BYREF

  survarium::weapon_user_animations_container::get_sprint_animation(
    (survarium::weapon_user_animations_container *)this,
    *(stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > **)(*(_DWORD *)(a2 + 24) + 56),
    &v14,
    animation_index);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &parameters,
    buffer,
    v7,
    &v14.first,
    0,
    weight_driving_animation,
    v12);
  survarium::weapon_user_animations_selector::look_time_factor(*(survarium::weapon_user_animations_selector **)(*(_DWORD *)(a2 + 24) + 60));
  v8 = a3 * parameters.m_animation_intervals->m_length;
  parameters.m_animated_object = *(const void **)(a2 + 28);
  parameters.m_time_calculator.m_Closure.m_pthis = v9;
  parameters.m_start_animation_interval_time = v8;
  parameters.m_additivity_priority = 5;
  parameters.m_time_calculator.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::base_player::look_time_factor_calculator;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(result, &parameters);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v10, (int)&parameters);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v14.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v14.first);
  return result;
}
