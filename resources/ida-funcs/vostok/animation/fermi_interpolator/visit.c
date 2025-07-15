void __thiscall vostok::animation::fermi_interpolator::visit(
        vostok::animation::fermi_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::fermi_interpolator *interpolator)
{
  float m_epsilon; // xmm0_4
  float v6; // xmm1_4
  vostok::animation::comparison_result_enum v7; // eax
  float v8; // [esp+8h] [ebp-4h]
  float v9; // [esp+18h] [ebp+Ch]

  v9 = interpolator->transition_time(interpolator);
  v8 = this->transition_time(this);
  if ( v8 <= (double)v9 )
  {
    if ( v9 <= v8 )
    {
      m_epsilon = interpolator->m_epsilon;
      v6 = this->m_epsilon;
      if ( v6 <= m_epsilon )
      {
        if ( m_epsilon <= v6 )
          v7 = equal;
        else
          v7 = more;
      }
      else
      {
        v7 = less;
      }
      dispatcher->result = v7;
    }
    else
    {
      dispatcher->result = more;
    }
  }
  else
  {
    dispatcher->result = less;
  }
}


void __thiscall vostok::animation::fermi_interpolator::visit(
        vostok::animation::fermi_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::instant_interpolator *interpolator)
{
  dispatcher->result = less;
}
