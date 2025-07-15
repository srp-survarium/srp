void __usercall vostok::render::vs_data::~vs_data(vostok::render::vs_data *this@<ecx>, int a2@<eax>)
{
  vostok::fixed_vector<vostok::render::buffer_slot,128> *v3; // ecx
  vostok::fixed_vector<vostok::render::texture_slot,128> *v4; // ecx
  vostok::render::shader_constant_table *v5; // ecx

  vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)(a2 + 23820));
  vostok::fixed_vector<vostok::render::buffer_slot,128>::~fixed_vector<vostok::render::buffer_slot,128>(
    v3,
    (vostok::intrusive_ptr<vostok::render::shader_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 13056));
  vostok::fixed_vector<vostok::render::texture_slot,128>::~fixed_vector<vostok::render::texture_slot,128>(
    v4,
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 2292));
  v5 = *(vostok::render::shader_constant_table **)(a2 + 936);
  *(_DWORD *)(a2 + 940) = v5;
  vostok::render::shader_constant_table::~shader_constant_table(v5, a2 + 8);
}
