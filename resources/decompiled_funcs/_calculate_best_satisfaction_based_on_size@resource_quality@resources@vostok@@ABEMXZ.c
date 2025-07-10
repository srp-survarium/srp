double __usercall vostok::resources::resource_quality::calculate_best_satisfaction_based_on_size@<st0>(
        vostok::resources::resource_quality *this@<ecx>,
        _DWORD *a2@<esi>)
{
  if ( vostok::resources::resource_base::has_user_references((vostok::resources::resource_base *)this, a2) )
    return 0.0;
  else
    return (1.0 - (double)(unsigned int)a2[23] * 0.000000059604645 + 1.0) * 1024.0;
}
