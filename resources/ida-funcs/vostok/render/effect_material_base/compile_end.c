void __thiscall vostok::render::effect_material_base::compile_end(
        vostok::render::effect_material_base *this,
        vostok::render::effect_compiler *compiler)
{
  vostok::render::effect_compiler *v2; // ecx

  vostok::render::effect_compiler::end_pass((vostok::render::effect_compiler *)this, (int)compiler);
  vostok::render::effect_compiler::end_technique(
    v2,
    (vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>)compiler);
}
