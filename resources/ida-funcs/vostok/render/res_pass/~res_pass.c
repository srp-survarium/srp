void __usercall vostok::render::res_pass::~res_pass(vostok::render::res_pass *this@<ecx>, int a2@<eax>)
{
  _DWORD *v3; // esi

  vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 20));
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 16));
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 12));
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a2 + 8));
  v3 = *(_DWORD **)(a2 + 4);
  if ( v3 )
    --*v3;
}
