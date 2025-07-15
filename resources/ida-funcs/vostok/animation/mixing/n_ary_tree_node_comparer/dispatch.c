void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  vostok::animation::mixing::n_ary_tree_node_comparer::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
    left,
    right,
    this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_addition_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  vostok::animation::mixing::animation_comparer_predicate v3; // [esp+6h] [ebp-2h] BYREF

  v3.m_use_synchronized_animations = 1;
  v3.m_use_overriding_animations = 1;
  this->result = vostok::animation::mixing::animation_comparer_predicate::operator()(&v3, left, right);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_animation_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  vostok::animation::mixing::n_ary_tree_node_comparer::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
    (vostok::animation::mixing::n_ary_tree_addition_node *)left,
    (vostok::animation::mixing::n_ary_tree_addition_node *)right,
    this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_multiplication_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  vostok::animation::mixing::n_ary_tree_node_comparer::propagate<vostok::animation::mixing::n_ary_tree_addition_node>(
    (vostok::animation::mixing::n_ary_tree_addition_node *)left,
    (vostok::animation::mixing::n_ary_tree_addition_node *)right,
    this);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_subtraction_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  vostok::animation::mixing::n_ary_tree_time_scale_node *v3; // esi
  float m_time_scale; // xmm0_4
  vostok::animation::mixing::n_ary_tree_time_scale_node *v5; // edi
  float v6; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  v3 = left;
  m_time_scale = left->m_time_scale;
  v5 = right;
  v6 = right->m_time_scale;
  if ( v6 > m_time_scale
    || m_time_scale <= v6
    && (left->m_interpolator->accept(
          left->m_interpolator,
          (vostok::animation::interpolator_comparer *)&left,
          right->m_interpolator),
        left == (vostok::animation::mixing::n_ary_tree_time_scale_node *)1) )
  {
    this->result = less;
  }
  else
  {
    v8 = v5->m_time_scale;
    v9 = v3->m_time_scale;
    if ( v9 <= v8 )
    {
      if ( v8 <= v9 )
      {
        v5->m_interpolator->accept(
          v5->m_interpolator,
          (vostok::animation::interpolator_comparer *)&left,
          v3->m_interpolator);
        this->result = left == (vostok::animation::mixing::n_ary_tree_time_scale_node *)1 ? more : equal;
      }
      else
      {
        this->result = equal;
      }
    }
    else
    {
      this->result = more;
    }
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  vostok::animation::comparison_result_enum result; // eax

  right->m_to->accept(right->m_to, this, left);
  result = this->result;
  if ( result == more )
  {
    this->result = less;
  }
  else
  {
    if ( result == less )
      result = more;
    this->result = result;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  left->m_from->accept(left->m_from, this, right->m_from);
  if ( this->result == equal )
    left->m_to->accept(left->m_to, this, right->m_to);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  left->m_to->accept(left->m_to, this, right);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  vostok::animation::mixing::n_ary_tree_weight_node *v3; // esi
  vostok::animation::mixing::n_ary_tree_weight_node *v4; // edi

  v3 = left;
  v4 = right;
  left->m_interpolator->accept(
    left->m_interpolator,
    (vostok::animation::interpolator_comparer *)&left,
    right->m_interpolator);
  if ( !left )
  {
    if ( v4->m_weight <= v3->m_weight )
      goto LABEL_3;
LABEL_7:
    this->result = less;
    return;
  }
  if ( left == (vostok::animation::mixing::n_ary_tree_weight_node *)1 )
    goto LABEL_7;
LABEL_3:
  v4->m_interpolator->accept(v4->m_interpolator, (vostok::animation::interpolator_comparer *)&left, v3->m_interpolator);
  if ( left )
  {
    if ( left == (vostok::animation::mixing::n_ary_tree_weight_node *)1 )
    {
LABEL_5:
      this->result = more;
      return;
    }
  }
  else if ( v3->m_weight > v4->m_weight )
  {
    goto LABEL_5;
  }
  this->result = equal;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  vostok::animation::comparison_result_enum result; // eax

  right->m_to->accept(right->m_to, this, left);
  result = this->result;
  if ( result == more )
  {
    this->result = less;
  }
  else
  {
    if ( result == less )
      result = more;
    this->result = result;
  }
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *right)
{
  left->m_from->accept(left->m_from, this, right->m_from);
  if ( this->result == equal )
    left->m_to->accept(left->m_to, this, right->m_to);
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_addition_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_animation_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_multiplication_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_subtraction_node *right)
{
  this->result = less;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_time_scale_transition_node *right)
{
  this->result = more;
}


void __thiscall vostok::animation::mixing::n_ary_tree_node_comparer::dispatch(
        vostok::animation::mixing::n_ary_tree_node_comparer *this,
        vostok::animation::mixing::n_ary_tree_weight_transition_node *left,
        vostok::animation::mixing::n_ary_tree_weight_node *right)
{
  left->m_to->accept(left->m_to, this, right);
}
