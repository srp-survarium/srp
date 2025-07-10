int __userpurge vostok::animation::mixing::n_ary_tree_time_scale_calculator::n_ary_tree_time_scale_calculator@<eax>(
        vostok::animation::mixing::n_ary_tree_time_scale_calculator *this@<ecx>,
        int result@<eax>,
        int a3@<xmm0>,
        unsigned int current_time_in_ms,
        float previous_time_in_ms,
        unsigned int a6,
        struct vostok::animation::mixing::n_ary_tree_animation_node *a7)
{
  *(_DWORD *)(result + 4) = this;
  *(_DWORD *)(result + 16) = current_time_in_ms;
  *(_DWORD *)(result + 20) = a3;
  *(_DWORD *)result = &vostok::animation::mixing::n_ary_tree_time_scale_calculator::`vftable';
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = 0;
  *(float *)(result + 24) = previous_time_in_ms;
  *(_DWORD *)(result + 28) = 0;
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 36) = 0;
  return result;
}
