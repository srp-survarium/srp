void __usercall vostok::render::res_pass::apply(vostok::render::res_pass *this@<ecx>, int a2@<esi>)
{
  vostok::render::res_xs<vostok::render::ps_data> *v2; // ecx

  vostok::render::res_xs<vostok::render::vs_data>::apply((vostok::render::res_xs<vostok::render::vs_data> *)this);
  vostok::render::res_xs<vostok::render::gs_data>::apply(*(vostok::render::res_xs<vostok::render::gs_data> **)(a2 + 12));
  vostok::render::res_xs<vostok::render::ps_data>::apply(v2);
  vostok::render::res_state::apply(*(vostok::render::res_state **)(a2 + 4));
}
