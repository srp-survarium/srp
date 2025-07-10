void __userpurge vostok::resources::resource_quality::satisfaction_with(
        vostok::resources::resource_quality *this@<ecx>,
        int a2@<eax>,
        unsigned int quality_level,
        const vostok::math::float4x4 *user_matrix,
        unsigned int users_count)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  cook->satisfaction_with(cook, quality_level, user_matrix, users_count);
}
