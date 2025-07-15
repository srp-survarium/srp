vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **__usercall vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme>@<eax>(
        vostok::animation::mixing::expression *left@<edi>,
        vostok::animation::mixing::animation_lexeme *a2@<ecx>,
        vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **right,
        vostok::animation::mixing::animation_lexeme *a4)
{
  vostok::animation::mixing::animation_lexeme *v4; // eax
  vostok::animation::mixing::base_lexeme *m_lexeme; // eax
  vostok::animation::mixing::expression *v6; // eax
  vostok::animation::mixing::addition_lexeme v8; // [esp+4h] [ebp-24h] BYREF

  if ( left->m_node.m_object && left->m_lexeme )
  {
    v4 = vostok::animation::mixing::animation_lexeme::cloned_in_buffer(a2, a4);
    vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(
      &v8,
      left->m_node.m_object,
      v4);
    m_lexeme = left->m_lexeme;
    v8.__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_addition_node::`vftable';
    v8.m_buffer = m_lexeme->m_buffer;
    v8.m_cloned = 0;
    v8.__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
    v6 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(&v8);
    vostok::animation::mixing::expression::expression(v6, right);
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v8.m_right);
    vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v8.m_left);
  }
  else
  {
    vostok::animation::mixing::expression::expression((vostok::animation::mixing::expression *)a2, right, a4);
  }
  return right;
}


vostok::animation::mixing::addition_lexeme *__usercall vostok::animation::mixing::operator+<vostok::animation::mixing::animation_lexeme,vostok::animation::mixing::animation_lexeme>@<eax>(
        vostok::animation::mixing::animation_lexeme *left@<edi>,
        vostok::animation::mixing::animation_lexeme *a2@<ecx>,
        vostok::animation::mixing::animation_lexeme *right)
{
  vostok::animation::mixing::animation_lexeme *v3; // esi
  vostok::animation::mixing::animation_lexeme *v4; // ecx
  vostok::animation::mixing::animation_lexeme *v5; // eax
  vostok::animation::mixing::addition_lexeme *v6; // esi
  vostok::animation::mixing::addition_lexeme v8; // [esp+4h] [ebp-24h] BYREF

  v3 = vostok::animation::mixing::animation_lexeme::cloned_in_buffer(a2, right);
  v5 = vostok::animation::mixing::animation_lexeme::cloned_in_buffer(v4, left);
  vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(&v8, v5, v3);
  v8.m_buffer = left->vostok::animation::mixing::base_lexeme::m_buffer;
  v8.m_cloned = 0;
  v8.__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
  v6 = vostok::animation::mixing::addition_lexeme::cloned_in_buffer(&v8);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v8.m_right);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v8.m_left);
  return v6;
}


vostok::animation::mixing::addition_lexeme *__usercall vostok::animation::mixing::operator+<vostok::animation::mixing::multiplication_lexeme,vostok::animation::mixing::multiplication_lexeme>@<eax>(
        vostok::animation::mixing::multiplication_lexeme *left@<edi>,
        vostok::animation::mixing::multiplication_lexeme *right@<ecx>)
{
  vostok::animation::mixing::multiplication_lexeme *v2; // esi
  vostok::animation::mixing::multiplication_lexeme *v3; // eax
  vostok::animation::mixing::addition_lexeme *v4; // esi
  vostok::animation::mixing::addition_lexeme v6; // [esp+4h] [ebp-24h] BYREF

  v2 = vostok::animation::mixing::multiplication_lexeme::cloned_in_buffer(right);
  v3 = vostok::animation::mixing::multiplication_lexeme::cloned_in_buffer(left);
  vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(&v6, v3, v2);
  v6.m_buffer = left->m_buffer;
  v6.m_cloned = 0;
  v6.__vftable = (vostok::animation::mixing::addition_lexeme_vtbl *)&vostok::animation::mixing::addition_lexeme::`vftable';
  v4 = vostok::animation::mixing::addition_lexeme::cloned_in_buffer(&v6);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v6.m_right);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v6.m_left);
  return v4;
}


vostok::animation::mixing::expression *__usercall vostok::animation::mixing::operator*@<eax>(
        vostok::animation::mixing::expression *left@<eax>,
        vostok::animation::mixing::expression *right@<edx>,
        int a3)
{
  vostok::animation::mixing::base_lexeme *m_lexeme; // eax
  vostok::animation::mixing::multiplication_lexeme *v5; // eax
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v6; // edi
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *v7; // eax
  vostok::animation::mixing::multiplication_lexeme v9; // [esp+8h] [ebp-24h] BYREF

  if ( left->m_node.m_object && left->m_lexeme )
  {
    if ( right->m_node.m_object && right->m_lexeme )
    {
      vostok::animation::mixing::binary_tree_binary_operation_node::binary_tree_binary_operation_node(
        &v9,
        left->m_node.m_object,
        right->m_node.m_object);
      m_lexeme = left->m_lexeme;
      v9.__vftable = (vostok::animation::mixing::multiplication_lexeme_vtbl *)&vostok::animation::mixing::binary_tree_multiplication_node::`vftable';
      v9.m_buffer = m_lexeme->m_buffer;
      v9.m_cloned = 0;
      v9.__vftable = (vostok::animation::mixing::multiplication_lexeme_vtbl *)&vostok::animation::mixing::multiplication_lexeme::`vftable';
      v5 = vostok::animation::mixing::multiplication_lexeme::cloned_in_buffer(&v9);
      *(_DWORD *)a3 = 0;
      v6 = (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)vostok::animation::mixing::multiplication_lexeme::cloned_in_buffer(v5);
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::operator=(
        v6,
        (vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> **)a3);
      if ( v6 )
        v7 = v6 + 7;
      else
        v7 = 0;
      *(_DWORD *)(a3 + 4) = v7;
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v9.m_right);
      vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v9.m_left);
    }
    else
    {
      vostok::animation::mixing::expression::expression((vostok::animation::mixing::expression *)a3, right);
    }
  }
  else
  {
    vostok::animation::mixing::expression::expression((vostok::animation::mixing::expression *)a3, left);
  }
  return (vostok::animation::mixing::expression *)a3;
}


vostok::animation::mixing::expression *__usercall vostok::animation::mixing::operator+@<eax>(
        vostok::animation::mixing::expression *left@<edx>,
        const vostok::animation::mixing::expression *right@<eax>,
        vostok::animation::mixing::expression *a3)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // esi
  vostok::animation::mixing::addition_lexeme *v4; // eax
  vostok::animation::mixing::expression *v5; // eax
  vostok::animation::mixing::addition_lexeme v8; // [esp+Ch] [ebp-30h] BYREF
  vostok::animation::mixing::expression v9; // [esp+30h] [ebp-Ch] BYREF

  if ( !left->m_node.m_object || !left->m_lexeme )
  {
    left = (vostok::animation::mixing::expression *)right;
LABEL_4:
    vostok::animation::mixing::expression::expression(a3, left);
    return a3;
  }
  m_object = right->m_node.m_object;
  if ( !right->m_node.m_object || !right->m_lexeme )
    goto LABEL_4;
  ++m_object->m_reference_count;
  v9.m_lexeme = right->m_lexeme;
  v9.m_node.m_object = m_object;
  vostok::animation::mixing::addition_lexeme::addition_lexeme(&v8, &v9, left);
  v5 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v4);
  vostok::animation::mixing::expression::expression(v5, a3);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v8.m_right);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v8.m_left);
  if ( m_object->m_reference_count-- == 1 )
    ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
      m_object,
      0);
  return a3;
}


vostok::animation::mixing::expression *__usercall vostok::animation::mixing::operator+@<eax>(
        const vostok::animation::mixing::expression *left@<edx>,
        const vostok::animation::mixing::expression *right@<eax>,
        vostok::animation::mixing::expression *a3)
{
  vostok::animation::mixing::binary_tree_base_node *m_object; // esi
  vostok::animation::mixing::binary_tree_base_node *v4; // ebx
  vostok::animation::mixing::binary_tree_base_node *v5; // ecx
  vostok::animation::mixing::addition_lexeme *v6; // eax
  vostok::animation::mixing::expression *v7; // eax
  bool v8; // zf
  vostok::animation::mixing::addition_lexeme v10; // [esp+Ch] [ebp-38h] BYREF
  vostok::animation::mixing::expression v11; // [esp+30h] [ebp-14h] BYREF
  vostok::animation::mixing::expression v12; // [esp+38h] [ebp-Ch] BYREF

  m_object = left->m_node.m_object;
  v4 = 0;
  if ( !left->m_node.m_object || !left->m_lexeme )
  {
    left = right;
LABEL_4:
    vostok::animation::mixing::expression::expression(a3, left);
    return a3;
  }
  if ( !right->m_node.m_object || !right->m_lexeme )
    goto LABEL_4;
  ++m_object->m_reference_count;
  v11.m_lexeme = left->m_lexeme;
  v5 = right->m_node.m_object;
  v11.m_node.m_object = m_object;
  v12.m_node.m_object = 0;
  if ( v5 )
  {
    v4 = v5;
    ++v5->m_reference_count;
    v12.m_node.m_object = v5;
  }
  v12.m_lexeme = right->m_lexeme;
  vostok::animation::mixing::addition_lexeme::addition_lexeme(&v10, &v12, &v11);
  v7 = (vostok::animation::mixing::expression *)vostok::animation::mixing::addition_lexeme::cloned_in_buffer(v6);
  vostok::animation::mixing::expression::expression(v7, a3);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v10.m_right);
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)&v10.m_left);
  if ( v4 )
  {
    v8 = v4->m_reference_count-- == 1;
    if ( v8 )
      ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))v4->~vostok::animation::mixing::binary_tree_base_node)(
        v4,
        0);
  }
  v8 = m_object->m_reference_count-- == 1;
  if ( v8 )
    ((void (__thiscall *)(vostok::animation::mixing::binary_tree_base_node *, _DWORD))m_object->~vostok::animation::mixing::binary_tree_base_node)(
      m_object,
      0);
  return a3;
}


bool __usercall vostok::animation::mixing::operator<@<al>(
        const vostok::animation::mixing::n_ary_tree_weight_node *left@<edi>,
        const vostok::animation::mixing::n_ary_tree_weight_node *right@<esi>,
        int a3@<ecx>)
{
  int v4; // [esp+0h] [ebp-4h] BYREF

  v4 = a3;
  ((void (__stdcall *)(int *, const vostok::animation::base_interpolator *))left->m_interpolator->accept)(
    &v4,
    right->m_interpolator);
  if ( v4 )
    return v4 == 1;
  else
    return right->m_weight > left->m_weight;
}
