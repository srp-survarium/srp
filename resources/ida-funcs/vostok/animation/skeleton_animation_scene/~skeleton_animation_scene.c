void __thiscall vostok::animation::skeleton_animation_scene::~skeleton_animation_scene(
        vostok::animation::skeleton_animation_scene *this)
{
  vostok::vectora<vostok::animation::skeleton_animation_scene_node_base *> *p_m_nodes; // esi
  unsigned int v3; // ebp
  void ***v4; // edi
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *v5; // ecx
  _BYTE *v6; // [esp+10h] [ebp-4h]

  p_m_nodes = &this->m_nodes;
  this->__vftable = (vostok::animation::skeleton_animation_scene_vtbl *)&vostok::animation::skeleton_animation_scene::`vftable';
  v3 = 0;
  if ( this->m_nodes._M_impl._M_finish - this->m_nodes._M_impl._M_start )
  {
    do
    {
      v4 = (void ***)&p_m_nodes->_M_impl._M_start[v3];
      if ( *v4 )
      {
        v6 = __RTCastToVoid(*v4);
        (*(void (__thiscall **)(void **, _DWORD))**v4)(*v4, 0);
        vostok::memory::g_resources_unmanaged_allocator.call_free(
          &vostok::memory::g_resources_unmanaged_allocator,
          v6,
          "vostok::animation::skeleton_animation_scene::~skeleton_animation_scene",
          ".\\skeleton_animation_scene.cpp",
          194u);
        *v4 = 0;
      }
      ++v3;
    }
    while ( v3 < p_m_nodes->_M_impl._M_finish - p_m_nodes->_M_impl._M_start );
  }
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    (stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *)this,
    (int)&this->m_targets);
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    v5,
    (int)p_m_nodes);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
