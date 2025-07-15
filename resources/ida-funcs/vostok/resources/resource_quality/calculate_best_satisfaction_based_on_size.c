double __thiscall vostok::resources::resource_quality::calculate_best_satisfaction_based_on_size(
        vostok::resources::resource_quality *this)
{
  int v1; // ecx

  if ( vostok::resources::resource_base::has_user_references((vostok::resources::resource_base *)this) )
    return 0.0;
  else
    return (1.0 - (double)*(unsigned int *)(v1 + 92) * 0.000000059604645 + 1.0) * 1024.0;
}
