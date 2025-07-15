void __userpurge vostok::animation::mixing::n_ary_tree_converter::n_ary_tree_converter(
        vostok::animation::mixing::n_ary_tree_converter *this@<ecx>,
        vostok::animation::mixing::n_ary_tree_converter *a2@<esi>,
        const vostok::animation::mixing::expression *expression)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  vostok::animation::mixing::binary_tree_base_node *v4; // eax
  bool v5; // zf
  vostok::animation::mixing::binary_tree_base_node *v6; // ecx
  vostok::animation::mixing::n_ary_tree_converter *v7; // ecx
  vostok::animation::mixing::n_ary_tree_converter *v8; // ecx
  vostok::animation::mixing::n_ary_tree_converter *v9; // ecx
  vostok::animation::mixing::n_ary_tree_converter *v10; // ecx
  void **v11; // [esp+8h] [ebp-38h] BYREF
  vostok::animation::mixing::binary_tree_base_node *v12; // [esp+Ch] [ebp-34h]
  _DWORD v13[2]; // [esp+10h] [ebp-30h] BYREF
  vostok::animation::mixing::binary_tree_base_node *v14; // [esp+18h] [ebp-28h]
  int v15; // [esp+1Ch] [ebp-24h]
  vostok::animation::mixing::n_ary_tree_weaver weaver; // [esp+20h] [ebp-20h] BYREF

  m_object = expression->m_node.m_object;
  v13[1] = expression->m_lexeme->m_buffer;
  v13[0] = &vostok::animation::mixing::binary_tree_expression_simplifier::`vftable';
  v14 = 0;
  v15 = 0;
  m_object->accept(m_object, (vostok::animation::mixing::binary_tree_visitor *)v13);
  v11 = &vostok::animation::mixing::binary_tree_initializer::`vftable';
  v12 = v14;
  v14->accept(v14, (vostok::animation::mixing::binary_tree_visitor *)&v11);
  v4 = v12;
  a2->m_root.m_object = 0;
  if ( v4 )
  {
    a2->m_root.m_object = v4;
    ++v4->m_reference_count;
  }
  if ( v15 )
  {
    v5 = (*(_DWORD *)(v15 + 16))-- == 1;
    if ( v5 )
      (**(void (__thiscall ***)(int, _DWORD))v15)(v15, 0);
  }
  if ( v14 )
  {
    v5 = v14->m_reference_count-- == 1;
    if ( v5 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v14->~vostok::animation::mixing::binary_tree_base_node)(
        v14,
        0);
  }
  a2->m_animations_root = 0;
  a2->m_binary_interpolators = 0;
  a2->m_interpolators = 0;
  a2->m_animation_states = 0;
  a2->m_animation_events = 0;
  a2->m_animated_objects = 0;
  a2->m_reference_counter = 0;
  a2->m_nodes_to_destroy_manually = 0;
  a2->m_animations_count = 0;
  a2->m_animated_objects_count = 0;
  a2->m_interpolators_count = 0;
  a2->m_buffer_size = 0;
  v6 = a2->m_root.m_object;
  weaver.m_buffer = expression->m_lexeme->m_buffer;
  weaver.__vftable = (vostok::animation::mixing::n_ary_tree_weaver_vtbl *)&vostok::animation::mixing::n_ary_tree_weaver::`vftable';
  memset(&weaver.m_animations_root, 0, 20);
  v6->accept(v6, &weaver);
  a2->m_animations_root = weaver.m_animations_root;
  vostok::animation::mixing::n_ary_tree_converter::process_interpolators(
    (vostok::animation::mixing::n_ary_tree_converter *)weaver.m_interpolators_root,
    a2,
    weaver.m_interpolators_root,
    (const vostok::animation::base_interpolator **)weaver.m_interpolators_count,
    expression->m_lexeme->m_buffer);
  vostok::animation::mixing::n_ary_tree_converter::simplify_weights(v7, (int)a2);
  vostok::animation::mixing::n_ary_tree_converter::sort_animations(v8, a2, expression->m_lexeme->m_buffer);
  vostok::animation::mixing::n_ary_tree_converter::fix_weight_driving_animations_with_null_weights(v9, a2, expression);
  vostok::animation::mixing::n_ary_tree_converter::compute_buffer_size(v10, a2);
  a2->m_buffer_size += 4;
}
