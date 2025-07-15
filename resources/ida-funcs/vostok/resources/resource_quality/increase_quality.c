void __thiscall vostok::resources::resource_quality::increase_quality(
        vostok::resources::resource_quality *this,
        unsigned int target_quality,
        float target_satisfaction,
        vostok::resources::query_result_for_cook *parent_query)
{
  void (__thiscall *increase_quality_to_target)(vostok::resources::resource_quality *, vostok::resources::query_result_for_cook *); // edx

  increase_quality_to_target = this->increase_quality_to_target;
  this->m_target_quality_level = target_quality;
  this->m_target_satisfaction = target_satisfaction;
  ((void (__stdcall *)(vostok::resources::query_result_for_cook *))increase_quality_to_target)(parent_query);
}
