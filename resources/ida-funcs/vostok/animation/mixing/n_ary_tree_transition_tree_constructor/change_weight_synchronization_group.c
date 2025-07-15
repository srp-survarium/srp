void __userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::change_weight_synchronization_group(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<edi>,
        vostok::animation::mixing::n_ary_tree_subtraction_node *to_begin@<esi>,
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *a3@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *from_begin,
        vostok::animation::mixing::n_ary_tree_animation_node *from_end,
        vostok::animation::mixing::n_ary_tree_animation_node *to_end)
{
  vostok::animation::mixing::n_ary_tree_animation_node *animation; // eax
  vostok::animation::mixing::n_ary_tree_animation_node *v7; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v8; // eax
  int v9; // ecx
  fastdelegate::FastDelegate<float __cdecl(float,float,unsigned int,unsigned int,unsigned int,float)> v10; // [esp-4h] [ebp-Ch]
  vostok::animation::mixing::n_ary_tree_animation_node *v11; // [esp+4h] [ebp-4h]

  if ( from_begin->m_weight_synchronization_group_id == -1 )
  {
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_asynchronous_groups(
      from_begin,
      a3,
      (const vostok::animation::base_interpolator *)this,
      to_begin,
      (vostok::animation::mixing::n_ary_tree_animation_node *const)v10.m_Closure.m_pFunction,
      v11);
  }
  else
  {
    animation = vostok::animation::mixing::find_animation(
                  this->m_animated_object_resolver,
                  from_begin,
                  from_end,
                  (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin);
    v7 = animation;
    if ( animation )
    {
      v10.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)to_begin;
      v8 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation(
             this,
             animation,
             v10);
    }
    else
    {
      v10.m_Closure.m_pthis = (fastdelegate::detail::GenericClass *)this;
      v8 = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation(
             (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin,
             v10);
    }
    if ( !v7 || v7->m_is_transitting_to_zero )
      v9 = 1;
    else
      LOBYTE(v9) = 0;
    vostok::animation::mixing::n_ary_tree_transition_tree_constructor::merge_weight_synchronization_groups(
      (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)v9,
      (const vostok::animation::base_interpolator *)this,
      from_begin,
      from_end,
      (vostok::animation::mixing::n_ary_tree_animation_node *)to_begin[5].__vftable,
      to_end,
      __SPAIR64__(v9, (unsigned int)v8));
  }
}
