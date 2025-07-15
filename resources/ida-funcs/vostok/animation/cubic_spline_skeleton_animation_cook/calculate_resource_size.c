int __thiscall vostok::animation::cubic_spline_skeleton_animation_cook::calculate_resource_size(
        vostok::animation::cubic_spline_skeleton_animation_cook *this,
        vostok::const_buffer in_raw_file_data,
        bool file_exist)
{
  return vostok::animation::cubic_spline_skeleton_animation::count_memory_size((const vostok::animation::bi_spline_skeleton_animation_baked *)in_raw_file_data.m_data);
}
