void __usercall vostok::render::ps_data::~ps_data(vostok::render::gs_data *this@<ecx>, int a2@<eax>)
{
  vostok::fixed_vector<vostok::render::texture_slot,128> *v3; // ecx
  vostok::render::shader_constant_table *v4; // ecx

  vostok::fixed_vector<vostok::render::buffer_slot,128>::~fixed_vector<vostok::render::buffer_slot,128>(
    (vostok::fixed_vector<vostok::render::buffer_slot,128> *)this,
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 13056));
  vostok::fixed_vector<vostok::render::texture_slot,128>::~fixed_vector<vostok::render::texture_slot,128>(
    v3,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2292));
  v4 = *(vostok::render::shader_constant_table **)(a2 + 936);
  *(_DWORD *)(a2 + 940) = v4;
  vostok::render::shader_constant_table::~shader_constant_table(v4, a2 + 8);
}
