vostok::animation::mixing::animation_lexeme *__userpurge survarium::player_logic_stand_state::look_lexeme@<eax>(
        survarium::player_logic_stand_state *this@<edi>,
        const unsigned int movement_animation_index@<eax>,
        survarium::weapon_user_animations_container *a3@<ecx>,
        float a4@<xmm0>,
        vostok::animation::mixing::animation_lexeme *buffer,
        vostok::mutable_buffer *is_aimed,
        vostok::animation::mixing::animation_lexeme *weight_driving_animation,
        vostok::animation::mixing::animation_lexeme *a8)
{
  survarium::weapon_user_animations_selector *m_owner; // eax
  vostok::animation::mixing::animation_lexeme *v9; // ecx
  float v10; // xmm0_4
  fastdelegate::detail::GenericClass *v11; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v12; // ecx
  int v14; // [esp-4h] [ebp-74h]
  vostok::animation::mixing::animation_lexeme *v15; // [esp+0h] [ebp-70h]
  vostok::animation::mixing::animation_lexeme_parameters parameters; // [esp+8h] [ebp-68h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v17; // [esp+64h] [ebp-Ch] BYREF
  void **v18; // [esp+6Ch] [ebp-4h] BYREF

  v14 = movement_animation_index + 2;
  m_owner = this->m_owner;
  v18 = &vostok::animation::instant_interpolator::`vftable';
  survarium::weapon_user_animations_container::get_stand_animation(
    a3,
    (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)m_owner->m_animations.m_object,
    &v17,
    (char)weight_driving_animation,
    v14);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &parameters,
    is_aimed,
    v9,
    &v17.first,
    0,
    a8,
    v15);
  survarium::weapon_user_animations_selector::look_time_factor((survarium::weapon_user_animations_selector *)this->m_owner->m_user);
  v10 = a4 * parameters.m_animation_intervals->m_length;
  parameters.m_animated_object = this->m_user;
  parameters.m_time_scale_interpolator = (const vostok::animation::base_interpolator *)&v18;
  parameters.m_time_calculator.m_Closure.m_pthis = v11;
  parameters.m_start_animation_interval_time = v10;
  parameters.m_additivity_priority = 5;
  parameters.m_time_calculator.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::base_player::look_time_factor_calculator;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(buffer, &parameters);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v12, (int)&parameters);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.first);
  return buffer;
}
