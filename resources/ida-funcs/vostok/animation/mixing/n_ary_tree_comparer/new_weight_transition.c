void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        const vostok::animation::base_interpolator *from_animation_interpolator@<edi>,
        vostok::animation::mixing::n_ary_tree_comparer *from,
        float to)
{
  const boost::function<unsigned char __cdecl(void const *)> *m_animated_object_resolver; // eax
  vostok::animation::mixing::animated_object_holder *m_animated_objects; // eax
  _DWORD v6[2]; // [esp+4h] [ebp-20h] BYREF
  int v7; // [esp+Ch] [ebp-18h]
  char v8; // [esp+10h] [ebp-14h]
  _DWORD v9[4]; // [esp+14h] [ebp-10h] BYREF

  if ( ((double (__thiscall *)(const vostok::animation::base_interpolator *))from_animation_interpolator->transition_time)(from_animation_interpolator) == 0.0 )
  {
    this->m_needed_buffer_size += 12;
  }
  else
  {
    vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(from, (int)this);
    m_animated_object_resolver = this->m_animated_object_resolver;
    v7 = 0;
    v6[1] = m_animated_object_resolver;
    m_animated_objects = from->m_animated_objects;
    v9[0] = &vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
    v9[1] = from_animation_interpolator;
    *(float *)&v9[2] = s_bm_current_air_resistance;
    v6[0] = &vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
    v8 = 0;
    ((void (__thiscall *)(vostok::animation::mixing::n_ary_tree_comparer *, _DWORD *, _DWORD *))LODWORD(m_animated_objects->transform.i.y))(
      from,
      v6,
      v9);
    if ( !v7 )
      return;
    this->m_needed_buffer_size += 32;
  }
  this->m_equal = 0;
}


void __userpurge vostok::animation::mixing::n_ary_tree_comparer::new_weight_transition(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        vostok::animation::mixing::n_ary_tree_comparer *to@<edi>,
        const vostok::animation::base_interpolator *to_animation_interpolator,
        float from)
{
  vostok::animation::mixing::n_ary_tree_double_dispatcher dispatcher; // [esp+4h] [ebp-20h] BYREF
  const boost::function<unsigned char __cdecl(void const *)> *m_animated_object_resolver; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-18h]
  char v7; // [esp+10h] [ebp-14h]
  vostok::animation::mixing::n_ary_tree_weight_node v8; // [esp+14h] [ebp-10h] BYREF

  vostok::animation::mixing::n_ary_tree_comparer::increase_buffer_size(to, (int)this);
  v6 = 0;
  v8.m_interpolator = to_animation_interpolator;
  m_animated_object_resolver = this->m_animated_object_resolver;
  v8.__vftable = (vostok::animation::mixing::n_ary_tree_weight_node_vtbl *)&vostok::animation::mixing::n_ary_tree_weight_node::`vftable';
  v8.m_weight = s_bm_current_air_resistance;
  dispatcher.__vftable = (vostok::animation::mixing::n_ary_tree_double_dispatcher_vtbl *)&vostok::animation::mixing::n_ary_tree_node_comparer::`vftable';
  v7 = 0;
  vostok::animation::mixing::n_ary_tree_weight_node::accept(
    &v8,
    &dispatcher,
    (vostok::animation::mixing::n_ary_tree_base_node *)to);
  if ( v6 )
  {
    this->m_equal = 0;
    if ( ((double (__thiscall *)(vostok::animation::mixing::animated_object_holder *))*(_DWORD *)(LODWORD(to->m_animated_objects_end->transform.i.x)
                                                                                                + 16))(to->m_animated_objects_end) != 0.0 )
      this->m_needed_buffer_size += 32;
  }
}
