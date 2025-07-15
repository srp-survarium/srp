void __userpurge vostok::animation::animation_collection::animation_collection(
        vostok::animation::animation_collection *this@<esi>,
        vostok::resources::resource_ptr<vostok::animation::animation_expression_emitter,vostok::resources::unmanaged_intrusive_base> *buffer@<edi>,
        vostok::resources::unmanaged_resource *a3@<ecx>,
        vostok::animation::collection_playback_types type,
        bool can_repeat_successively,
        bool is_cyclic_repeating,
        unsigned int max_count,
        unsigned int last_time)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(a3, this, fs_iterator_class);
  this->__vftable = (vostok::animation::animation_collection_vtbl *)&vostok::animation::animation_collection::`vftable';
  this->m_animations.m_begin = buffer;
  this->m_animations.m_end = buffer;
  this->m_animations.m_max_end = &buffer[max_count];
  this->m_random_number.m_seed = 0;
  this->m_current_animation_index = -1;
  this->m_type = type;
  this->m_is_cyclic_repeating = is_cyclic_repeating;
  this->m_can_repeat_successively = can_repeat_successively;
  this->m_is_child_last_animation = 1;
  if ( max_count == 1 )
    this->m_can_repeat_successively = 1;
}
