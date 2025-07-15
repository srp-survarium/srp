void __thiscall vostok::animation::skeleton_animation_scene_node::~skeleton_animation_scene_node(
        vostok::animation::skeleton_animation_scene_node *this)
{
  vostok::vectora<vostok::animation::skeleton_animation_scene_node_interval *> *p_m_intervals; // ebx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **v3; // edi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // esi
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v5; // ecx
  unsigned int v6; // [esp+10h] [ebp-4h]

  v6 = 0;
  p_m_intervals = &this->m_intervals;
  this->__vftable = (vostok::animation::skeleton_animation_scene_node_vtbl *)&vostok::animation::skeleton_animation_scene_node::`vftable';
  if ( this->m_intervals._M_impl._M_finish - this->m_intervals._M_impl._M_start )
  {
    do
    {
      v3 = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)&p_m_intervals->_M_impl._M_start[v6];
      v4 = *v3;
      if ( *v3 )
      {
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v4 + 1);
        vostok::memory::g_resources_unmanaged_allocator.call_free(
          &vostok::memory::g_resources_unmanaged_allocator,
          v4,
          "vostok::animation::skeleton_animation_scene_node::~skeleton_animation_scene_node",
          ".\\skeleton_animation_scene.cpp",
          53u);
        *v3 = 0;
      }
      ++v6;
    }
    while ( v6 < p_m_intervals->_M_impl._M_finish - p_m_intervals->_M_impl._M_start );
  }
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::animation::base_interpolator>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &this->m_time_interpolator,
    "vostok::animation::skeleton_animation_scene_node::~skeleton_animation_scene_node",
    ".\\skeleton_animation_scene.cpp",
    0x37u);
  vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::animation::base_interpolator>(
    &vostok::memory::g_resources_unmanaged_allocator,
    &this->m_weight_interpolator,
    "vostok::animation::skeleton_animation_scene_node::~skeleton_animation_scene_node",
    ".\\skeleton_animation_scene.cpp",
    0x38u);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v5,
    (int)p_m_intervals);
  this->__vftable = (vostok::animation::skeleton_animation_scene_node_vtbl *)&vostok::animation::skeleton_animation_scene_node_base::`vftable';
}
