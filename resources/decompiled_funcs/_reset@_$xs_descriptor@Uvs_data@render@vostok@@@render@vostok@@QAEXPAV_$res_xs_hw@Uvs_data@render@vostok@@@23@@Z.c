void __usercall vostok::render::xs_descriptor<vostok::render::vs_data>::reset(
        vostok::render::xs_descriptor<vostok::render::vs_data> *this@<eax>,
        vostok::render::res_xs_hw<vostok::render::vs_data> *xs_hw@<edi>)
{
  vostok::render::res_xs_hw<vostok::render::vs_data> *v3; // eax
  vostok::render::res_xs_hw<vostok::render::vs_data> *v4; // ecx
  vostok::render::res_xs_hw<vostok::render::vs_data> *m_object; // eax

  v3 = 0;
  if ( xs_hw )
  {
    ++xs_hw->m_reference_count;
    v3 = xs_hw;
  }
  v4 = v3;
  m_object = this->m_hardware_shader.m_object;
  this->m_hardware_shader.m_object = v4;
  if ( m_object )
  {
    if ( m_object->m_reference_count-- == 1 )
      vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
        (vostok::render::resource_manager *)v4,
        (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  if ( this->m_hardware_shader.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::render::vs_data::operator=(&this->m_shader_data, &xs_hw->m_shader_data);
  }
}
