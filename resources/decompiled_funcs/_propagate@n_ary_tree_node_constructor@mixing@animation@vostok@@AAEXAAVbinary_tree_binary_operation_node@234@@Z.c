void __userpurge vostok::animation::mixing::n_ary_tree_node_constructor::propagate(
        vostok::animation::mixing::n_ary_tree_node_constructor *this@<ecx>,
        int a2@<esi>,
        vostok::animation::mixing::binary_tree_binary_operation_node *node)
{
  int v3; // eax
  vostok::animation::mixing::n_ary_tree_base_node **v4; // edi
  vostok::mutable_buffer *v5; // eax
  const vostok::animation::base_interpolator *const *v6; // edx
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  const vostok::animation::base_interpolator *const *v8; // edx
  const vostok::animation::base_interpolator *const *v9; // eax
  vostok::animation::mixing::binary_tree_base_node *v10; // ecx
  vostok::animation::mixing::n_ary_tree_node_constructor left; // [esp+8h] [ebp-28h] BYREF
  vostok::animation::mixing::n_ary_tree_node_constructor right; // [esp+1Ch] [ebp-14h] BYREF

  v3 = *(_DWORD *)(a2 + 4);
  v4 = *(vostok::animation::mixing::n_ary_tree_base_node ***)v3;
  *(_DWORD *)v3 += 8;
  *(_DWORD *)(v3 + 4) -= 8;
  v5 = *(vostok::mutable_buffer **)(a2 + 4);
  v6 = *(const vostok::animation::base_interpolator *const **)(a2 + 16);
  left.m_interpolators_begin = *(const vostok::animation::base_interpolator *const *const *)(a2 + 12);
  m_object = node->m_left.m_object;
  left.m_buffer = v5;
  left.m_interpolators_end = v6;
  left.__vftable = (vostok::animation::mixing::n_ary_tree_node_constructor_vtbl *)&vostok::animation::mixing::n_ary_tree_node_constructor::`vftable';
  left.m_result = 0;
  m_object->accept(m_object, &left);
  v8 = *(const vostok::animation::base_interpolator *const **)(a2 + 12);
  v9 = *(const vostok::animation::base_interpolator *const **)(a2 + 16);
  right.m_buffer = *(vostok::mutable_buffer **)(a2 + 4);
  v10 = node->m_right.m_object;
  right.m_interpolators_begin = v8;
  right.m_interpolators_end = v9;
  right.__vftable = (vostok::animation::mixing::n_ary_tree_node_constructor_vtbl *)&vostok::animation::mixing::n_ary_tree_node_constructor::`vftable';
  right.m_result = 0;
  v10->accept(v10, &right);
  *v4 = left.m_result;
  v4[1] = right.m_result;
}
