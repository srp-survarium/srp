void __usercall vostok::render::samplers_handler<0>::assign(
        vostok::render::samplers_handler<0> *this@<esi>,
        const vostok::render::res_sampler_list *list@<edi>)
{
  const vostok::render::res_sampler_list *m_object; // eax
  unsigned int v3; // eax
  const vostok::render::res_sampler_list *v4; // ecx
  const vostok::render::res_sampler_list *v5; // eax

  m_object = this->m_current.m_object;
  if ( m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
    && list )
  {
    vostok::render::utils::calc_lists_diff_range<vostok::render::res_sampler_list>(
      m_object,
      list,
      &this->m_diff_range_start,
      &this->m_diff_range_end);
  }
  else
  {
    this->m_diff_range_start = 0;
    if ( list )
      v3 = list->m_samplers._M_impl._M_finish - list->m_samplers._M_impl._M_start;
    else
      v3 = 0;
    this->m_diff_range_end = v3;
  }
  v4 = 0;
  if ( list )
  {
    ++list->m_reference_count;
    v4 = list;
  }
  v5 = this->m_current.m_object;
  this->m_current.m_object = v4;
  if ( v5 )
  {
    if ( v5->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v5);
  }
}
