void __usercall vostok::render::xs_descriptor<vostok::render::gs_data>::reset(
        vostok::render::xs_descriptor<vostok::render::gs_data> *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::gs_data> *xs_hw@<eax>)
{
  vostok::render::shader_constant_table *v4; // ecx

  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_hardware_shader,
    xs_hw);
  if ( this->m_hardware_shader.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::render::gs_data::operator=(&this->m_shader_data, &xs_hw->m_shader_data, v4);
  }
}


void __usercall vostok::render::xs_descriptor<vostok::render::ps_data>::reset(
        vostok::render::xs_descriptor<vostok::render::ps_data> *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::ps_data> *xs_hw@<eax>)
{
  vostok::render::shader_constant_table *v4; // ecx

  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_hardware_shader,
    xs_hw);
  if ( this->m_hardware_shader.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::render::gs_data::operator=(
        (vostok::render::gs_data *)&this->m_shader_data,
        (const vostok::render::gs_data *)&xs_hw->m_shader_data,
        v4);
  }
}


void __usercall vostok::render::xs_descriptor<vostok::render::vs_data>::reset(
        vostok::render::xs_descriptor<vostok::render::vs_data> *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::vs_data> *xs_hw@<eax>)
{
  vostok::render::shader_constant_table *v4; // ecx

  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &this->m_hardware_shader,
    xs_hw);
  if ( this->m_hardware_shader.m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      vostok::render::vs_data::operator=(&this->m_shader_data, &xs_hw->m_shader_data, v4);
  }
}
