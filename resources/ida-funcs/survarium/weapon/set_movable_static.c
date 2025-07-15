void __thiscall survarium::weapon::set_movable_static(survarium::weapon *this)
{
  survarium::rifle_scope *m_object; // eax
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_idle_scope; // eax
  survarium::rifle_scope *v3; // eax
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_aimed_scope; // eax

  m_object = this->m_rifle_scope.m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      p_m_idle_scope = &m_object->m_idle_scope;
      if ( p_m_idle_scope->m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          p_m_idle_scope->m_object->m_render_model.m_object->m_is_movable_static = 1;
      }
    }
  }
  v3 = this->m_rifle_scope.m_object;
  if ( v3 )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      p_m_aimed_scope = &v3->m_aimed_scope;
      if ( p_m_aimed_scope->m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          p_m_aimed_scope->m_object->m_render_model.m_object->m_is_movable_static = 1;
      }
    }
  }
  this->m_model.m_object->m_render_model.m_object->m_is_movable_static = 1;
}
