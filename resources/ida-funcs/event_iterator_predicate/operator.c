bool __userpurge event_iterator_predicate::operator()@<al>(
        event_iterator_predicate *this@<eax>,
        const vostok::animation::mixing::animation_state *const right@<ecx>,
        const vostok::animation::mixing::animation_state *const left)
{
  return vostok::animation::mixing::n_ary_tree_event_iterator::is_less(
           &left->event_iterator,
           &right->event_iterator,
           this->m_animated_object_resolver);
}
