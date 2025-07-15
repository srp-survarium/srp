void __usercall vostok::animation::animation_player::~animation_player(
        vostok::animation::animation_player *this@<ecx>,
        vostok::animation::animation_player *a2@<eax>)
{
  vostok::animation::mixing::n_ary_tree *v3; // ecx
  vostok::animation::mixing::n_ary_tree_intrusive_base *m_object; // esi

  vostok::animation::animation_player::reset(this, a2, 1);
  vostok::animation::mixing::n_ary_tree::destroy(v3);
  m_object = a2->m_mixing_tree.m_reference_counter.m_object;
  if ( m_object )
    --m_object->m_reference_count;
}
