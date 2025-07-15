void __userpurge vostok::animation::mixing::n_ary_tree_node_constructor::propagate(
        vostok::animation::mixing::n_ary_tree_node_constructor *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::animation::mixing::binary_tree_binary_operation_node *node)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v5; // eax
  vostok::animation::mixing::binary_tree_base_node *m_object; // ecx
  int v7; // eax
  vostok::animation::mixing::binary_tree_base_node *v8; // ecx
  _DWORD v9[2]; // [esp+8h] [ebp-28h] BYREF
  int v10; // [esp+10h] [ebp-20h]
  int v11; // [esp+14h] [ebp-1Ch]
  int v12; // [esp+18h] [ebp-18h]
  _DWORD v13[2]; // [esp+1Ch] [ebp-14h] BYREF
  int v14; // [esp+24h] [ebp-Ch]
  int v15; // [esp+28h] [ebp-8h]
  int v16; // [esp+2Ch] [ebp-4h]

  v3 = a2[1];
  v4 = *(_DWORD **)v3;
  *(_DWORD *)v3 += 8;
  *(_DWORD *)(v3 + 4) -= 8;
  v5 = a2[1];
  v14 = 0;
  v13[1] = v5;
  v15 = a2[3];
  v16 = a2[4];
  m_object = node->m_left.m_object;
  v13[0] = &vostok::animation::mixing::n_ary_tree_node_constructor::`vftable';
  m_object->accept(m_object, (vostok::animation::mixing::binary_tree_visitor *)v13);
  v7 = a2[1];
  v10 = 0;
  v9[1] = v7;
  v11 = a2[3];
  v12 = a2[4];
  v8 = node->m_right.m_object;
  v9[0] = &vostok::animation::mixing::n_ary_tree_node_constructor::`vftable';
  v8->accept(v8, (vostok::animation::mixing::binary_tree_visitor *)v9);
  *v4 = v14;
  v4[1] = v10;
}
