void __thiscall vostok::animation::skeleton_animation_scene_operator::~skeleton_animation_scene_operator(
        vostok::animation::skeleton_animation_scene_operator *this)
{
  stlp_std::pair<vostok::animation::skeleton_animation_scene_node_base *,vostok::animation::skeleton_animation_scene_operator_link *> *M_start; // eax

  this->__vftable = (vostok::animation::skeleton_animation_scene_operator_vtbl *)&vostok::animation::skeleton_animation_scene_operator::`vftable';
  M_start = this->m_children._M_impl._M_start;
  if ( M_start )
    this->m_children._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_children._M_impl._M_end_of_storage.m_allocator,
      M_start,
      "vostok::detail::std_allocator<struct stlp_std::pair<class vostok::animation::skeleton_animation_scene_node_base *,"
      "class vostok::animation::skeleton_animation_scene_operator_link *> >::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102u);
  this->__vftable = (vostok::animation::skeleton_animation_scene_operator_vtbl *)&vostok::animation::skeleton_animation_scene_node_base::`vftable';
}
