unsigned int __thiscall vostok::animation::cubic_spline_skeleton_animation_cook::calculate_resource_size(
        vostok::animation::cubic_spline_skeleton_animation_cook *this,
        vostok::const_buffer in_raw_file_data,
        bool file_exist)
{
  const vostok::animation::bi_spline_skeleton_animation_baked *v3; // eax

  v3 = (const vostok::animation::bi_spline_skeleton_animation_baked *)vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr((vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&in_raw_file_data);
  return vostok::animation::cubic_spline_skeleton_animation::count_memory_size(v3);
}
