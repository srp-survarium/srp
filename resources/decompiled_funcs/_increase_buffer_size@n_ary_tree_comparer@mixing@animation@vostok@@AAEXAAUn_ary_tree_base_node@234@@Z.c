void __usercall vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_comparer *a2@<eax>)
{
  float z; // edx
  vostok::animation::mixing::n_ary_tree_size_calculator calculator; // [esp+0h] [ebp-14h] BYREF

  z = this->m_animated_objects->transform.i.z;
  calculator.m_comparer = a2;
  calculator.vostok::animation::mixing::n_ary_tree_visitor::__vftable = (vostok::animation::mixing::n_ary_tree_visitor_vtbl *)&vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  calculator.m_size = 0;
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *, vostok::animation::mixing::n_ary_tree_visitor *))LODWORD(z))(
    this,
    &calculator.vostok::animation::mixing::n_ary_tree_visitor);
}
