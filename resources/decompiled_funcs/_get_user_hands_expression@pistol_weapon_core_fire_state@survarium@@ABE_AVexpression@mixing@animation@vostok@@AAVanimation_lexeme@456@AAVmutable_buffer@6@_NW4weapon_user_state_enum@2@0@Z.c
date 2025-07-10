vostok::animation::mixing::expression *__thiscall survarium::pistol_weapon_core_fire_state::get_user_hands_expression(
        survarium::pistol_weapon_core_fire_state *this,
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::animation_lexeme *weapon_lexeme,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id,
        vostok::animation::mixing::base_lexeme *weight_driving_animation)
{
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *v8; // ecx
  int v9; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v10; // ecx
  survarium::base_player *user; // esi
  vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v13; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v14; // ecx
  vostok::animation::mixing::animation_lexeme *v15; // ecx
  vostok::animation::mixing::animation_lexeme *v16; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v17[3]; // [esp-4h] [ebp-13Ch] BYREF
  const survarium::pistol_weapon_core_fire_state *thisa; // [esp+8h] [ebp-130h]
  vostok::animation::mixing::animation_lexeme_parameters *parameters; // [esp+24h] [ebp-114h]
  survarium::link_resolver *object; // [esp+2Ch] [ebp-10Ch]
  survarium::base_project::resolve_link_object *v21; // [esp+30h] [ebp-108h]
  _BYTE v22[88]; // [esp+38h] [ebp-100h] BYREF
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> v23; // [esp+90h] [ebp-A8h] BYREF
  bool v24; // [esp+9Fh] [ebp-99h]
  vostok::animation::mixing::animation_lexeme override_lexeme; // [esp+A0h] [ebp-98h] BYREF
  unsigned int user_animation_index; // [esp+128h] [ebp-10h]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+12Ch] [ebp-Ch]
  const char *user_animation_captions[2]; // [esp+130h] [ebp-8h]

  thisa = this;
  if ( user_state_id == type_sprint )
  {
    fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
      (vostok::animation::mixing::expression *)this,
      result);
    return result;
  }
  else
  {
    user_animation_index = user_state_id == type_crouch;
    selected_animation = &thisa->m_user_animations[is_third_view][user_animation_index];
    v17[0].m_object = (vostok::resources::managed_resource *)user_animation_index;
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      v17,
      selected_animation);
    vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
      v8,
      v17[0]);
    v21 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
            v10,
            v9);
    object = v21->object;
    v24 = object != (survarium::link_resolver *)1;
    vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(&v23);
    if ( v24 )
    {
      fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
        (vostok::animation::mixing::expression *)v24,
        result);
    }
    else
    {
      user_animation_captions[0] = "stand_shot_pistol";
      user_animation_captions[1] = "crouch_shot_pistol";
      user = survarium::weapon_core::get_user(0, (int)thisa->m_weapon);
      vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
        (vostok::animation::mixing::animation_lexeme_parameters *)weapon_lexeme,
        (int)v22,
        buffer,
        selected_animation,
        (vostok::animation::mixing::base_lexeme *)weapon_lexeme,
        weight_driving_animation,
        (vostok::animation::mixing::animation_lexeme *const)v17[1].m_object);
      v13 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
              (vostok::animation::mixing::animation_lexeme_parameters *)user,
              v12);
      parameters = vostok::animation::mixing::animation_lexeme_parameters::playback_type(
                     (vostok::animation::mixing::animation_lexeme_parameters *)1,
                     v13);
      parameters->m_additivity_priority = 1;
      vostok::animation::mixing::animation_lexeme::animation_lexeme(&override_lexeme, parameters);
      vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v14, (int)v22);
      vostok::animation::mixing::expression::expression(
        result,
        (vostok::animation::mixing::base_lexeme *)&override_lexeme,
        v15);
      vostok::animation::mixing::animation_lexeme::~animation_lexeme(v16, (int)&override_lexeme);
    }
    return result;
  }
}
