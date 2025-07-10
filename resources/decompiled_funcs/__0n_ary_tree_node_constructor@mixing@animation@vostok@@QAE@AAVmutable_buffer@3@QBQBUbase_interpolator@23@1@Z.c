void __userpurge vostok::animation::mixing::n_ary_tree_node_constructor::n_ary_tree_node_constructor(
        vostok::animation::mixing::n_ary_tree_node_constructor *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::animation::base_interpolator *const *buffer,
        const vostok::animation::base_interpolator *const *interpolators_begin,
        const vostok::animation::base_interpolator *const *const interpolators_end)
{
  a2[1] = this;
  *a2 = &vostok::animation::mixing::n_ary_tree_node_constructor::`vftable';
  a2[2] = 0;
  a2[3] = buffer;
  a2[4] = interpolators_begin;
}
