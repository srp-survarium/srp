int __cdecl vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::get()
{
  if ( !vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id )
  {
    while ( vostok::threading::interlocked_exchange_pointer(
              &vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_lock,
              1) )
      ;
    if ( !vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id )
      vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id = vostok::threading::interlocked_increment(&vostok::detail::global_type_id_holder<int>::s_next_type_id)
                                                                                             - 1;
    vostok::threading::interlocked_exchange_pointer(
      &vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_lock,
      0);
  }
  return vostok::detail::type_to_int<survarium::animation_analysis_result_cook_user_data>::s_id;
}
