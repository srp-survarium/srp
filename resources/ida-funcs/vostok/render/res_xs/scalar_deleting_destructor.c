int __usercall vostok::render::res_xs<vostok::render::gs_data>::`scalar deleting destructor'@<eax>(
        vostok::render::res_xs<vostok::render::gs_data> *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax

  v2 = *(_DWORD **)(a2 + 20);
  if ( v2 )
    --*v2;
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_sampler_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 16));
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 12));
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 8));
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 4));
  return a2;
}


int __usercall vostok::render::res_xs<vostok::render::ps_data>::`scalar deleting destructor'@<eax>(
        vostok::render::res_xs<vostok::render::ps_data> *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax

  v2 = *(_DWORD **)(a2 + 20);
  if ( v2 )
    --*v2;
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_sampler_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 16));
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 12));
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 8));
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 4));
  return a2;
}


int __usercall vostok::render::res_xs<vostok::render::vs_data>::`scalar deleting destructor'@<eax>(
        vostok::render::res_xs<vostok::render::vs_data> *this@<ecx>,
        int a2@<esi>)
{
  _DWORD *v2; // eax

  v2 = *(_DWORD **)(a2 + 20);
  if ( v2 )
    --*v2;
  vostok::intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_sampler_list const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_sampler_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 16));
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_texture_list const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 12));
  vostok::intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::shader_constant_table const,vostok::render::resource_intrusive_base const,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::shader_constant_table const ,vostok::render::resource_intrusive_base const ,vostok::threading::single_threading_policy> *)(a2 + 8));
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 4));
  return a2;
}
