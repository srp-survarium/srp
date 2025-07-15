void __userpurge vostok::animation::mixing::n_ary_tree_comparer::n_ary_tree_comparer(
        vostok::animation::mixing::n_ary_tree_comparer *this@<esi>,
        const vostok::animation::mixing::n_ary_tree *to@<edi>,
        const boost::function<unsigned char __cdecl(void const *)> *animated_object_resolver@<eax>,
        const vostok::animation::mixing::n_ary_tree *from,
        unsigned int current_time_in_ms)
{
  void *v5; // esp
  unsigned int v6; // eax
  unsigned int v7; // ecx
  _BYTE v8[8]; // [esp+0h] [ebp-8h] BYREF

  this->m_animations_count = 0;
  this->m_animated_objects_count = 0;
  this->m_animated_object_resolver = animated_object_resolver;
  this->m_current_time_in_ms = current_time_in_ms;
  this->m_from = from;
  this->m_to = to;
  this->m_equal = 1;
  this->m_needed_buffer_size = 60;
  vostok::animation::mixing::n_ary_tree_comparer::process_interpolators(from, to, this);
  v5 = alloca(136 * (to->m_animated_objects_count + from->m_animated_objects_count));
  this->m_animated_objects = (vostok::animation::mixing::animated_object_holder *)v8;
  this->m_animated_objects_end = (vostok::animation::mixing::animated_object_holder *)v8;
  vostok::animation::mixing::n_ary_tree_comparer::merge_trees(from, this, to);
  v6 = this->m_animated_objects_end - this->m_animated_objects;
  v7 = 176 * this->m_animations_count;
  this->m_animated_objects_count = v6;
  this->m_needed_buffer_size += 136 * v6 + v7;
}
