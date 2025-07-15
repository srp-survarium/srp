void __usercall vostok::render::effect_material_base::compile_end(
        vostok::render::effect_compiler *compiler@<eax>,
        vostok::render::effect_compiler *a2@<ecx>,
        vostok::render::effect_material_base *this)
{
  vostok::render::effect_compiler *v4; // ecx

  vostok::render::effect_compiler::end_pass(
    a2,
    (vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
  vostok::render::effect_compiler::end_technique(v4, (int)compiler);
}
