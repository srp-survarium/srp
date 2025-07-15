vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **__thiscall survarium::empty_hands::selected_animations(
        survarium::empty_hands *this,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **result,
        vostok::mutable_buffer *buffer)
{
  unsigned int m_animations_count; // edx
  vostok::math::random32 *p_m_random; // ecx
  int v6; // eax
  int v7; // edx
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *m_animations; // eax
  vostok::resources::managed_resource *v9; // ecx
  vostok::resources::managed_resource *v10; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v11; // eax
  vostok::animation::mixing::animation_lexeme *v12; // ecx
  const vostok::animation::mixing::animation_lexeme_parameters *v13; // eax
  vostok::animation::mixing::animation_lexeme_parameters *v14; // ecx
  vostok::animation::mixing::expression *v15; // ecx
  vostok::animation::mixing::animation_lexeme *v16; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v18; // [esp-18h] [ebp-110h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v19; // [esp-14h] [ebp-10Ch] BYREF
  vostok::animation::mixing::animation_lexeme *v20; // [esp-10h] [ebp-108h]
  vostok::animation::mixing::animation_lexeme *v21; // [esp-Ch] [ebp-104h]
  vostok::animation::mixing::animation_lexeme *v22; // [esp-8h] [ebp-100h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v23; // [esp+8h] [ebp-F0h] BYREF
  _DWORD v24[2]; // [esp+Ch] [ebp-ECh] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v25; // [esp+14h] [ebp-E4h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v26; // [esp+1Ch] [ebp-DCh] BYREF
  vostok::animation::mixing::animation_lexeme v27; // [esp+70h] [ebp-88h] BYREF

  m_animations_count = this->m_animations_count;
  p_m_random = &this->m_random;
  v6 = 134775813 * p_m_random->m_seed + 1;
  p_m_random->m_seed = v6;
  v7 = (m_animations_count * (unsigned __int64)(unsigned int)v6) >> 32;
  m_animations = this->m_animations;
  v24[0] = &vostok::animation::linear_interpolator::`vftable';
  *(float *)&v24[1] = s_aim_transition_time;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v23,
    &m_animations[v7]);
  v21 = 0;
  v20 = 0;
  v19.m_object = v9;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v19,
    &v23);
  v18.m_object = v10;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v18,
    &v23);
  v11 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
          &v25,
          v18,
          v19);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v26,
    buffer,
    v12,
    &v11->first,
    v20,
    v21,
    v22);
  v13->m_weight_synchronization_group_id = 0;
  v13->m_time_synchronization_group_id = 0;
  v13->m_weight_interpolator = (const vostok::animation::base_interpolator *)v24;
  v13->m_time_scale_interpolator = (const vostok::animation::base_interpolator *)v24;
  v13->m_animated_object = this->m_user;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&v27, v13);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v14, (int)&v26);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v25.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v25.first);
  vostok::animation::mixing::expression::expression(v15, result, &v27);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v16, (int)&v27);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v23);
  return result;
}
