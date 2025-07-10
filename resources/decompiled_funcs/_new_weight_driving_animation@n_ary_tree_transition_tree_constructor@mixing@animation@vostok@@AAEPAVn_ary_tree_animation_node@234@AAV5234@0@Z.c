vostok::animation::mixing::n_ary_tree_animation_node *__userpurge vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_weight_driving_animation@<eax>(
        vostok::animation::mixing::n_ary_tree_transition_tree_constructor *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_animation_node *new_driving_animation_in_previous_target@<eax>,
        vostok::animation::mixing::n_ary_tree_base_node **new_weight_driving_animation)
{
  vostok::animation::mixing::n_ary_tree_animation_node *v3; // ebx
  vostok::animation::mixing::n_ary_tree_animation_node *v6; // ebp
  vostok::mutable_buffer *m_buffer; // eax
  char *v8; // ecx
  unsigned int v9; // ebp
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor *v10; // ecx
  unsigned int operands_offset; // [esp+1Ch] [ebp-14h] BYREF
  float animation_interval_time; // [esp+20h] [ebp-10h] BYREF
  unsigned int animation_interval_id; // [esp+24h] [ebp-Ch] BYREF
  vostok::animation::mixing::n_ary_tree_animation_node *result[2]; // [esp+28h] [ebp-8h] BYREF

  v3 = (vostok::animation::mixing::n_ary_tree_animation_node *)new_weight_driving_animation;
  vostok::animation::mixing::computed_operands_count(
    new_driving_animation_in_previous_target,
    (stlp_std::pair<unsigned int,unsigned int> *)result,
    new_weight_driving_animation);
  v6 = result[0];
  LOBYTE(operands_offset) = v3->m_is_transitting_to_zero;
  new_weight_driving_animation = (vostok::animation::mixing::n_ary_tree_base_node **)result[1];
  result[0] = vostok::animation::mixing::n_ary_tree_transition_tree_constructor::new_animation(
                v3,
                &operands_offset,
                this,
                (const vostok::animation::mixing::animation_state *)new_driving_animation_in_previous_target,
                0,
                (unsigned int)result[0],
                (unsigned int *)&new_weight_driving_animation,
                &animation_interval_id,
                &animation_interval_time,
                operands_offset,
                COERCE_FLOAT(1));
  m_buffer = this->m_buffer;
  v8 = (char *)new_weight_driving_animation + (_DWORD)v6;
  v9 = operands_offset;
  new_weight_driving_animation = (vostok::animation::mixing::n_ary_tree_base_node **)&m_buffer->m_data[4 * operands_offset];
  m_buffer->m_data += 4 * (_DWORD)v8;
  m_buffer->m_size -= 4 * (_DWORD)v8;
  vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_operands(
    (vostok::animation::mixing::n_ary_tree_transition_tree_constructor *)&new_weight_driving_animation[(_DWORD)&v8[-v9]],
    this,
    new_driving_animation_in_previous_target,
    (vostok::animation::mixing::n_ary_tree_base_node **)v3,
    new_weight_driving_animation,
    &new_weight_driving_animation[(_DWORD)&v8[-v9]],
    v9 != 0);
  return vostok::animation::mixing::n_ary_tree_transition_tree_constructor::add_animation_node(
           v10,
           (int)this,
           result[0],
           new_driving_animation_in_previous_target->m_animation_state,
           animation_interval_id,
           animation_interval_time,
           0);
}
