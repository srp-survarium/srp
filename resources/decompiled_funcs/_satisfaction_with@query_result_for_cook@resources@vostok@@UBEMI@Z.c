void __thiscall vostok::resources::query_result_for_cook::satisfaction_with(
        vostok::resources::query_result_for_cook *this,
        unsigned int quality_level)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(this->m_class_id);
  cook->satisfaction_with(cook, quality_level, this->m_transform, 1u);
}
