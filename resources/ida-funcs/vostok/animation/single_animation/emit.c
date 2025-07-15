vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **__thiscall vostok::animation::single_animation::emit(
        vostok::animation::single_animation *this,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **result,
        vostok::mutable_buffer *buffer,
        vostok::animation::mixing::animation_lexeme *time_driving_animation,
        bool *is_last_animation)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_animation; // edi
  vostok::resources::managed_resource *v6; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v7; // eax
  vostok::animation::mixing::animation_lexeme *v8; // ecx
  vostok::animation::mixing::expression *v9; // ecx
  vostok::animation::mixing::animation_lexeme *v10; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v11; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v13; // [esp-10h] [ebp-100h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v14; // [esp-Ch] [ebp-FCh] BYREF
  vostok::animation::mixing::animation_lexeme *v15; // [esp-8h] [ebp-F8h]
  vostok::animation::mixing::animation_lexeme *v16; // [esp-4h] [ebp-F4h]
  vostok::animation::mixing::animation_lexeme *v17; // [esp+0h] [ebp-F0h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v18; // [esp+8h] [ebp-E8h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v19; // [esp+10h] [ebp-E0h] BYREF
  vostok::animation::mixing::animation_lexeme v20; // [esp+68h] [ebp-88h] BYREF

  v16 = 0;
  v15 = time_driving_animation;
  p_m_animation = &this->m_animation;
  v14.m_object = (vostok::resources::managed_resource *)this;
  *is_last_animation = 1;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v14,
    &this->m_animation);
  v13.m_object = v6;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v13,
    p_m_animation);
  v7 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
         &v18,
         v13,
         v14);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v19,
    buffer,
    v8,
    &v7->first,
    v15,
    v16,
    v17);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v18.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v18.first);
  v19.m_weight_interpolator = (const vostok::animation::base_interpolator *)&v18;
  v18.first.m_object = (vostok::resources::managed_resource *)&vostok::animation::linear_interpolator::`vftable';
  *(float *)&v18.second.m_object = FLOAT_0_25;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&v20, &v19);
  vostok::animation::mixing::expression::expression(v9, result, &v20);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v10, (int)&v20);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v11, (int)&v19);
  return result;
}


vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **__thiscall vostok::animation::single_animation::emit(
        vostok::animation::single_animation *this,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **result,
        vostok::mutable_buffer *buffer,
        bool *is_last_animation)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_m_animation; // edi
  vostok::resources::managed_resource *v5; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v6; // eax
  vostok::animation::mixing::animation_lexeme *v7; // ecx
  vostok::animation::mixing::expression *v8; // ecx
  vostok::animation::mixing::animation_lexeme *v9; // ecx
  vostok::animation::mixing::animation_lexeme_parameters *v10; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp-10h] [ebp-100h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v13; // [esp-Ch] [ebp-FCh] BYREF
  vostok::animation::mixing::animation_lexeme *v14; // [esp-8h] [ebp-F8h]
  vostok::animation::mixing::animation_lexeme *v15; // [esp-4h] [ebp-F4h]
  vostok::animation::mixing::animation_lexeme *v16; // [esp+0h] [ebp-F0h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v17; // [esp+8h] [ebp-E8h] BYREF
  vostok::animation::mixing::animation_lexeme_parameters v18; // [esp+10h] [ebp-E0h] BYREF
  vostok::animation::mixing::animation_lexeme v19; // [esp+68h] [ebp-88h] BYREF

  v15 = 0;
  v14 = 0;
  v13.m_object = (vostok::resources::managed_resource *)this;
  p_m_animation = &this->m_animation;
  *is_last_animation = 1;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v13,
    &this->m_animation);
  v12.m_object = v5;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    p_m_animation);
  v6 = stlp_std::make_pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
         &v17,
         v12,
         v13);
  vostok::animation::mixing::animation_lexeme_parameters::animation_lexeme_parameters(
    &v18,
    buffer,
    v7,
    &v6->first,
    v14,
    v15,
    v16);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v17.first);
  v18.m_weight_interpolator = (const vostok::animation::base_interpolator *)&v17;
  v17.first.m_object = (vostok::resources::managed_resource *)&vostok::animation::linear_interpolator::`vftable';
  *(float *)&v17.second.m_object = FLOAT_0_25;
  vostok::animation::mixing::animation_lexeme::animation_lexeme(&v19, &v18);
  vostok::animation::mixing::expression::expression(v8, result, &v19);
  vostok::animation::mixing::animation_lexeme::~animation_lexeme(v9, (int)&v19);
  vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(v10, (int)&v18);
  return result;
}
