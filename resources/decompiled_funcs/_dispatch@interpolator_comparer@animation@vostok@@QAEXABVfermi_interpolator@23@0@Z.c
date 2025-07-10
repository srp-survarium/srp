void __userpurge vostok::animation::interpolator_comparer::dispatch(
        const vostok::animation::fermi_interpolator *left@<edi>,
        const vostok::animation::fermi_interpolator *right@<esi>,
        vostok::animation::interpolator_comparer *this)
{
  double v4; // st7
  float m_epsilon; // xmm0_4
  float v6; // xmm1_4
  float right_transition_time; // [esp+4h] [ebp-4h]
  float left_transition_time; // [esp+Ch] [ebp+4h]

  left_transition_time = left->transition_time(left);
  v4 = ((double (__thiscall *)(const vostok::animation::fermi_interpolator *))right->transition_time)(right);
  if ( v4 <= left_transition_time )
  {
    right_transition_time = v4;
    if ( left_transition_time <= right_transition_time )
    {
      m_epsilon = left->m_epsilon;
      v6 = right->m_epsilon;
      if ( v6 <= m_epsilon )
      {
        if ( m_epsilon <= v6 )
          this->result = equal;
        else
          this->result = more;
      }
      else
      {
        this->result = less;
      }
    }
    else
    {
      this->result = more;
    }
  }
  else
  {
    this->result = less;
  }
}
