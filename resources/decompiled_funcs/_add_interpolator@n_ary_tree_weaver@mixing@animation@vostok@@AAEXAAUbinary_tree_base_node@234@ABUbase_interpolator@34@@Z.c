void __usercall vostok::animation::mixing::n_ary_tree_weaver::add_interpolator(
        vostok::animation::mixing::n_ary_tree_weaver *this@<ecx>,
        int a2@<eax>)
{
  vostok::animation::mixing::binary_tree_animation_node *v2; // edx

  v2 = *(vostok::animation::mixing::binary_tree_animation_node **)(a2 + 20);
  ++*(_DWORD *)(a2 + 28);
  this->m_animations_root = v2;
  *(_DWORD *)(a2 + 20) = this;
}
