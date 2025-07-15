vostok::math::float4x4 *__userpurge survarium::game_camera::get_projection_matrix@<eax>(
        survarium::game_camera *this@<ecx>,
        long double a2@<esi:edi>,
        vostok::math::float4x4 *result,
        const vostok::math::float2 *window_size)
{
  vostok::math::create_perspective_projection(
    a2,
    (float)((float)(survarium::default_vertical_fov * 0.0055555557) * 3.1415927) * this->m_fov_factor,
    (vostok::math *)result,
    COERCE_STRUCT_VOSTOK_MATH_FLOAT4X4_(window_size->x / window_size->y),
    this->m_near_plane,
    this->m_far_plane);
  return result;
}
