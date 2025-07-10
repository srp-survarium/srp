vostok::collision::ray_triangle_result *__usercall stlp_std::remove_if<vostok::collision::ray_triangle_result *,negative_distance_detector>@<eax>(
        vostok::collision::ray_triangle_result *__first@<ecx>,
        vostok::collision::ray_triangle_result *__last@<eax>,
        negative_distance_detector __pred)
{
  vostok::collision::ray_triangle_result *result; // eax
  vostok::collision::ray_triangle_result *i; // ecx
  const stlp_std::random_access_iterator_tag *v6; // [esp+0h] [ebp-4h]

  result = stlp_std::priv::__find_if<vostok::collision::ray_triangle_result *,negative_distance_detector>(
             __first,
             __last,
             __pred,
             v6);
  if ( result != __last )
  {
    for ( i = result + 1; i != __last; ++i )
    {
      if ( i->distance >= 0.0 )
      {
        *(_QWORD *)&result->object = *(_QWORD *)&i->object;
        result->distance = i->distance;
        ++result;
      }
    }
  }
  return result;
}
