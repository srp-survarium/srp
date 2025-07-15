void __usercall vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        int a2@<eax>)
{
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // eax
  _DWORD v3[3]; // [esp+4h] [ebp-Ch] BYREF

  v3[2] = 0;
  v3[1] = a2;
  m_animated_objects = this->m_animated_objects;
  v3[0] = &vostok::animation::mixing::n_ary_tree_size_calculator::`vftable'{for `vostok::animation::mixing::n_ary_tree_visitor'};
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *, _DWORD *))LODWORD(m_animated_objects->transform.i.z))(
    this,
    v3);
}
