void __usercall vostok::animation::interpolator_comparer::dispatch(
        vostok::animation::interpolator_comparer *this@<edi>,
        const vostok::animation::linear_interpolator *left@<ecx>,
        const vostok::animation::linear_interpolator *right@<esi>)
{
  double v3; // st7
  float left_transition_time; // [esp+0h] [ebp-8h]
  float right_transition_time; // [esp+4h] [ebp-4h]

  left_transition_time = left->transition_time(left);
  v3 = ((double (__thiscall *)(const vostok::animation::linear_interpolator *))right->transition_time)(right);
  if ( v3 <= left_transition_time )
  {
    right_transition_time = v3;
    if ( left_transition_time <= right_transition_time )
      this->result = equal;
    else
      this->result = more;
  }
  else
  {
    this->result = less;
  }
}
