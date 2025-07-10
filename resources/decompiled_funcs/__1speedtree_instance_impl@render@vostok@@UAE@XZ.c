void __thiscall vostok::render::speedtree_instance_impl::~speedtree_instance_impl(
        vostok::render::speedtree_instance_impl *this)
{
  SpeedTree::CInstance *m_speedtree_instance; // esi
  vostok::render::grass_render_model *m_object; // ebp
  SpeedTree::CInstance *v4; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::speedtree_tree_base *v6; // eax

  this->__vftable = (vostok::render::speedtree_instance_impl_vtbl *)&stru_966A14.m_name.m_string.m_buffer[64];
  m_speedtree_instance = this->m_speedtree_instance;
  m_object = vostok::render::g_allocator.m_object;
  if ( m_speedtree_instance )
  {
    SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)this->m_speedtree_instance);
    v4 = m_speedtree_instance;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, (void *)v4);
    this->m_speedtree_instance = 0;
  }
  v6 = this->m_speedtree_tree_ptr.m_object;
  if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_speedtree_tree_ptr.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_speedtree_tree_ptr.m_object);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
