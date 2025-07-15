void __thiscall vostok::animation::linear_interpolator::visit(
        vostok::animation::linear_interpolator *this,
        vostok::animation::interpolator_comparer *dispatcher,
        const vostok::animation::linear_interpolator *interpolator)
{
  vostok::animation::comparison_result_enum v4; // eax
  float v5; // [esp+4h] [ebp-4h]
  float v6; // [esp+14h] [ebp+Ch]

  v6 = interpolator->transition_time(interpolator);
  v5 = this->transition_time(this);
  if ( v5 <= (double)v6 )
  {
    if ( v6 <= v5 )
      v4 = equal;
    else
      v4 = more;
  }
  else
  {
    v4 = less;
  }
  dispatcher->result = v4;
}
