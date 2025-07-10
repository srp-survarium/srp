void __usercall vostok::animation::cubic_spline_skeleton_animation::new_animation(
        vostok::animation::cubic_spline_skeleton_animation *buffer_for_animation@<ecx>,
        const vostok::animation::bi_spline_skeleton_animation_baked *animation@<eax>)
{
  if ( buffer_for_animation )
    vostok::animation::cubic_spline_skeleton_animation::cubic_spline_skeleton_animation(
      buffer_for_animation,
      (int)buffer_for_animation,
      animation);
}
