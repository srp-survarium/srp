void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<ecx>,
        int a2@<edi>,
        vostok::animation::mixing::n_ary_tree_comparer *from,
        vostok::animation::mixing::n_ary_tree_subtraction_node *to)
{
  int v4; // eax
  vostok::animation::mixing::n_ary_tree_comparer *v5; // ecx
  int v6; // eax
  double v7; // st6
  vostok::animation::mixing::n_ary_tree_base_node *v8; // [esp+0h] [ebp-18h]
  _DWORD v9[3]; // [esp+8h] [ebp-10h] BYREF
  char v10; // [esp+14h] [ebp-4h]

  v4 = *(_DWORD *)(a2 + 16);
  v9[2] = 0;
  v9[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v9[1] = v4;
  v10 = 0;
  if ( vostok::animation::mixing::n_ary_tree_node_comparer::compare(
         (vostok::animation::mixing::n_ary_tree_node_comparer *)from,
         (int)v9,
         to,
         v8) == equal )
  {
    v5 = from;
    v6 = a2;
LABEL_3:
    vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(v5, v6);
    return;
  }
  *(_BYTE *)(a2 + 36) = 0;
  v7 = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)to->m_operands_count + 16))(to->m_operands_count);
  v6 = a2;
  if ( v7 == 0.0 )
  {
    v5 = (vostok::animation::mixing::n_ary_tree_comparer *)to;
    goto LABEL_3;
  }
  vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(from, a2);
  vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(
    (vostok::animation::mixing::n_ary_tree_comparer *)to,
    a2);
  *(_DWORD *)(a2 + 28) += 20;
}


void __usercall vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_comparer *from@<edi>)
{
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // eax
  void **v3; // [esp+0h] [ebp-8h] BYREF
  int v4; // [esp+4h] [ebp-4h]

  m_animated_objects = from->m_animated_objects;
  v4 = 0;
  v3 = &vostok::animation::mixing::n_ary_tree_interpolator_selector::`vftable';
  ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *, void ***))LODWORD(m_animated_objects->transform.i.z))(
    from,
    &v3);
  if ( ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v4 + 16))(v4) == 0.0 )
  {
    this->m_needed_buffer_size += 20;
  }
  else
  {
    this->m_equal = 0;
    vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(from, (int)this);
    this->m_needed_buffer_size += 40;
  }
}


void __usercall vostok::animation::mixing::n_ary_tree_comparer::new_time_scale_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_comparer *to@<edi>,
        int a3@<ecx>)
{
  this->m_equal = 0;
  if ( ((double (__thiscall *)(vostok::animation::mixing::animated_object_holder *, int))*(_DWORD *)(LODWORD(to->m_animated_objects_end->transform.i.x) + 16))(
         to->m_animated_objects_end,
         a3) == 0.0 )
  {
    vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(to, (int)this);
  }
  else
  {
    this->m_needed_buffer_size += 20;
    vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(to, (int)this);
    this->m_needed_buffer_size += 20;
  }
}
