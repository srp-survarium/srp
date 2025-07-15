void __usercall vostok::animation::mixing::n_ary_tree_animation_node::set_time_driving_animation(
        vostok::animation::mixing::n_ary_tree_animation_node *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)(a2 + 20) = this;
}
