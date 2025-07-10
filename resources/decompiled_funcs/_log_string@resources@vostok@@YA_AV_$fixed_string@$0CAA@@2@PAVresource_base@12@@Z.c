vostok::fixed_string<512> *__usercall vostok::resources::log_string@<eax>(
        vostok::resources::query_result *resource@<ecx>,
        vostok::fixed_string<512> *a2@<eax>)
{
  if ( (resource->vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::query_result_for_cook::vostok::resources::query_result_for_user::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
      & 2) != 0
    && resource )
  {
    vostok::resources::logging_name_for_query(resource, (int)a2);
    return a2;
  }
  else
  {
    resource->log_string(resource, a2);
    return a2;
  }
}
