void __usercall vostok::render::effect_compiler::~effect_compiler(
        vostok::render::effect_compiler *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::render::shader_constant_bindings *v2; // ecx
  vostok::render::gs_data *v3; // ecx
  vostok::render::gs_data *v4; // ecx
  vostok::render::vs_data *v5; // ecx

  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)this,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)((char *)dword_61EB0 + (_DWORD)a2));
  vostok::render::shader_constant_bindings::~shader_constant_bindings(
    v2,
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_61C1C + (_DWORD)a2));
  vostok::render::ps_data::~ps_data(v3, (int)&loc_5BF08 + (_DWORD)a2 + 4);
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_5BF08 + (_DWORD)a2));
  vostok::render::ps_data::~ps_data(v4, (int)a2 + (_DWORD)&loc_561F6 + 2 + 4);
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)a2 + (_DWORD)&loc_561F6 + 2));
  vostok::render::vs_data::~vs_data(v5, (int)a2 + (_DWORD)&loc_504E3 + 1 + 4);
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)a2 + (_DWORD)&loc_504E3 + 1));
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)&loc_50338 + (_DWORD)a2));
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)a2 + (_DWORD)&loc_50332 + 2));
  vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_xs_hw<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)((char *)a2 + (_DWORD)&loc_5032F + 1));
  *(_DWORD *)((char *)a2 + (_DWORD)&loc_4BE23 + 1 + 4) = *(_DWORD *)((char *)a2 + (_DWORD)&loc_4BE23 + 1);
  a2[7047] = a2[7046];
  a2[4] = a2[3];
}
