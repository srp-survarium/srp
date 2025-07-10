vostok::math::float3 *__thiscall survarium::human_npc::get_random_surface_point(
        survarium::human_npc *this,
        vostok::math::float3 *result,
        unsigned int current_time)
{
  vostok::collision::animated_object::get_random_surface_point(
    (vostok::collision::animated_object *)this->m_renderer,
    (vostok::math::float3 *)this->m_renderer[13].m_scene,
    (const unsigned int)result);
  return result;
}
