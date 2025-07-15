vostok::render::effect_compiler *__usercall vostok::render::effect_compiler::begin_technique@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>)
{
  if ( !byte_61F4C[a2] )
  {
    vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
      (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)this,
      (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)((char *)dword_61EB0 + a2));
    *(int *)((char *)&dword_61F48 + a2) = 0;
  }
  return (vostok::render::effect_compiler *)a2;
}
