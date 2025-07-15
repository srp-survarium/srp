vostok::animation::mixing::expression *__thiscall survarium::hit_animations_selector::selected_animations(
        survarium::hit_animations_selector *this,
        survarium::hit_animations_selector::hit_body_part_type *result,
        vostok::animation::mixing::expression *current_time_in_ms,
        const survarium::hit_animations_selector::hit_body_part *animated_object,
        vostok::mutable_buffer *buffer,
        vostok::mutable_buffer *a6)
{
  survarium::hit_animations_selector::hit_body_part *v7; // edi
  survarium::hit_animations_selector::hit_body_part_type current_hit_amount; // eax
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *stand_hit_animation; // eax
  vostok::animation::mixing::animation_lexeme *v10; // ecx
  double v11; // st7
  const vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v13; // ecx
  vostok::animation::mixing::expression *v14; // ecx
  vostok::animation::mixing::animation_lexeme *v15; // ecx
  vostok::animation::mixing::expression *v16; // eax
  int v17; // [esp-Ch] [ebp-128h]
  survarium::hit_animations_selector::selected_animations::__l2::hit_body_part_greater v18; // [esp-4h] [ebp-120h]
  vostok::animation::mixing::animation_lexeme *v19; // [esp+0h] [ebp-11Ch]
  vostok::animation::mixing::animation_lexeme v20; // [esp+10h] [ebp-10Ch] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v21; // [esp+98h] [ebp-84h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v22; // [esp+ECh] [ebp-30h] BYREF
  survarium::hit_animations_selector::hit_body_part_type __first[2]; // [esp+F4h] [ebp-28h] BYREF
  survarium::hit_animations_selector::hit_body_part_type __middle[6]; // [esp+FCh] [ebp-20h] BYREF
  survarium::hit_animations_selector::hit_body_part_type __last[2]; // [esp+114h] [ebp-8h] BYREF
  survarium::hit_animations_selector::hit_body_part_type *__formal; // [esp+124h] [ebp+8h]

  v18.m_body_parts = animated_object;
  __first[0] = head;
  __first[1] = back;
  __middle[0] = left_arm;
  __middle[1] = right_arm;
  __middle[2] = left_chest;
  __middle[3] = right_chest;
  __middle[4] = left_leg;
  __middle[5] = right_leg;
  _____partial_sort_PAW4hit_body_part_type_hit_animations_selector_survarium__W4123_Uhit_body_part_greater__1__selected_animations_23_QBE_AVexpression_mixing_animation_vostok__IPBXAAVmutable_buffer_9__Z__priv_stlp_std__YAXPAW4hit_body_part_type_hit_animations_selector_survarium__000Uhit_body_part_greater__1__selected_animations_34_QBE_AVexpression_mixing_animation_vostok__IPBXAAVmutable_buffer_vostok___Z__Z(
    __first,
    __middle,
    __last,
    result,
    v18);
  current_time_in_ms->m_node.m_object = 0;
  current_time_in_ms->m_lexeme = 0;
  __formal = __first;
  do
  {
    v7 = (survarium::hit_animations_selector::hit_body_part *)&result[6 * *__formal];
    if ( !survarium::hit_animations_selector::hit_body_part::has_hit(v7, (const unsigned int)animated_object) )
      break;
    current_hit_amount = survarium::hit_animations_selector::hit_body_part::get_current_hit_amount(
                           v7,
                           (const unsigned int)animated_object);
    v17 = *__formal;
    __last[0] = current_hit_amount;
    stand_hit_animation = survarium::weapon_user_animations_container::get_stand_hit_animation(
                            (survarium::weapon_user_animations_container *)&v22,
                            *((stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > **)result
                            + 48),
                            &v22,
                            v17);
    vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
      &v21,
      a6,
      v10,
      &stand_hit_animation->first,
      0,
      0,
      v19);
    v11 = (double)(unsigned int)__last[0] * 0.001;
    v12->m_animated_object = buffer;
    v12->m_start_animation_interval_time = v11;
    v12->m_time_calculator.m_Closure.m_pFunction = (void (__thiscall *)(fastdelegate::detail::GenericClass *))survarium::hit_animations_selector::hit_body_part::hit_time_factor_calculator;
    v12->m_time_calculator.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)v7;
    v12->m_additivity_priority = 6;
    vostok::animation::mixing::animation_lexeme::animation_lexeme(&v20, v12);
    vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v13, (int)&v21);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v22.second);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v22.first);
    vostok::animation::mixing::expression::operator+=<vostok::animation::mixing::animation_lexeme>(
      v14,
      current_time_in_ms,
      &v20);
    vostok::animation::mixing::animation_lexeme::~animation_lexeme(v15, (int)&v20);
    ++__formal;
  }
  while ( __formal != __middle );
  v16 = current_time_in_ms;
  *((_BYTE *)result + 244) = 0;
  return v16;
}
