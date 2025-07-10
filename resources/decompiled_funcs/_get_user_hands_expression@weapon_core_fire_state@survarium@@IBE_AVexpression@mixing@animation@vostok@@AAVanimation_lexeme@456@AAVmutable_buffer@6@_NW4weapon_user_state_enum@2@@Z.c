vostok::animation::mixing::expression *__thiscall survarium::weapon_core_fire_state::get_user_hands_expression(
        survarium::weapon_core_fire_state *this,
        vostok::animation::mixing::expression *result,
        vostok::animation::mixing::base_lexeme *weapon_lexeme,
        vostok::mutable_buffer *buffer,
        bool is_third_view,
        survarium::weapon_user_state_enum user_state_id)
{
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> *v7; // ecx
  int v8; // eax
  stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object> > *v9; // ecx
  survarium::base_player *user; // esi
  vostok::animation::mixing::animation_lexeme_parameters *v11; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v12; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v13; // ecx
  vostok::animation::mixing::animation_lexeme *v14; // ecx
  vostok::animation::mixing::animation_lexeme *v15; // ecx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v16[3]; // [esp-4h] [ebp-13Ch] BYREF
  const survarium::weapon_core_fire_state *thisa; // [esp+8h] [ebp-130h]
  vostok::animation::mixing::animation_lexeme_parameters *parameters; // [esp+24h] [ebp-114h]
  survarium::link_resolver *object; // [esp+2Ch] [ebp-10Ch]
  survarium::base_project::resolve_link_object *v20; // [esp+30h] [ebp-108h]
  _BYTE v21[88]; // [esp+38h] [ebp-100h] BYREF
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> v22; // [esp+90h] [ebp-A8h] BYREF
  bool v23; // [esp+9Fh] [ebp-99h]
  unsigned int user_animation_index; // [esp+A0h] [ebp-98h]
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *selected_animation; // [esp+A4h] [ebp-94h]
  vostok::animation::mixing::animation_lexeme hands_lexeme; // [esp+A8h] [ebp-90h] BYREF
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
    v16[0].m_object = (vostok::resources::managed_resource *)user_animation_index;
    vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
      v16,
      selected_animation);
    vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(
      v7,
      v16[0]);
    v20 = stlp_std::priv::_Impl_vector<survarium::base_project::resolve_link_object,survarium::std_allocator<survarium::base_project::resolve_link_object>>::end(
            v9,
            v8);
    object = v20->object;
    v23 = object != (survarium::link_resolver *)1;
    vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>(&v22);
    if ( v23 )
    {
      fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>(
        (vostok::animation::mixing::expression *)v23,
        result);
    }
    else
    {
      user_animation_captions[0] = "stand_shoot";
      user_animation_captions[1] = "crouch_shoot";
      user = survarium::weapon_core::get_user(0, (int)thisa->m_weapon);
      vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
        (vostok::animation::mixing::animation_lexeme_parameters *)selected_animation,
        (int)v21,
        buffer,
        selected_animation,
        weapon_lexeme,
        0,
        (vostok::animation::mixing::animation_lexeme *const)v16[1].m_object);
      v12 = vostok::animation::mixing::animation_lexeme_parameters::animated_object(
              (vostok::animation::mixing::animation_lexeme_parameters *)user,
              v11);
      parameters = vostok::animation::mixing::animation_lexeme_parameters::playback_type(
                     (vostok::animation::mixing::animation_lexeme_parameters *)1,
                     v12);
      parameters->m_additivity_priority = 1;
      vostok::animation::mixing::animation_lexeme::animation_lexeme(&hands_lexeme, parameters);
      vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v13, (int)v21);
      vostok::animation::mixing::expression::expression(
        result,
        (vostok::animation::mixing::base_lexeme *)&hands_lexeme,
        v14);
      vostok::animation::mixing::animation_lexeme::~animation_lexeme(v15, (int)&hands_lexeme);
    }
    return result;
  }
}
