char __userpurge vostok::animation::animation_player::set_target_and_tick@<al>(
        vostok::animation::animation_player *this@<esi>,
        vostok::animation::subscribed_channel **current_time_in_ms@<edi>,
        vostok::animation::animation_player *a3@<ecx>,
        const vostok::animation::mixing::expression *expression,
        boost::function<vostok::math::float4x4 __cdecl(void const *)> *get_transform_functor)
{
  char v5; // bl
  vostok::animation::animation_player *v6; // ecx

  if ( this->m_mixing_tree.m_animations_count )
    vostok::animation::animation_player::tick(a3, (int)this, current_time_in_ms);
  v5 = vostok::animation::animation_player::set_target(
         expression,
         (vostok::animation::mixing::n_ary_tree_converter *)a3,
         this,
         (char *)current_time_in_ms,
         get_transform_functor);
  vostok::animation::animation_player::tick(v6, (int)this, current_time_in_ms);
  return v5;
}
