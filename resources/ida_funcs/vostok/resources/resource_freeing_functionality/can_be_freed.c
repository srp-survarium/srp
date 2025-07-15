char __thiscall vostok::resources::resource_freeing_functionality::can_be_freed(
        vostok::resources::resource_freeing_functionality *this,
        vostok::resources::resource_base *resource,
        bool *can_try_free,
        bool *can_try_decrease_quality)
{
  char v4; // bl

  v4 = 1;
  if ( resource->m_quality_levels_count == 1 || !resource->is_increasing_quality(resource) )
    v4 = 0;
  if ( !vostok::resources::resource_base::has_user_references((vostok::resources::resource_base *)this, resource) && !v4 )
    return vostok::resources::resource_freeing_functionality::parents_can_be_freed(
             resource,
             (vostok::threading::simple_lock *)can_try_free,
             this,
             can_try_free,
             can_try_decrease_quality);
  *can_try_decrease_quality = 0;
  *can_try_free = 0;
  return 0;
}
