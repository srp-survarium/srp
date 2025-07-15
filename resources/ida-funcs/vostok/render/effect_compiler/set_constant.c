vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_constant<float>@<eax>(
        vostok::render::effect_constant_storage *ecx0@<ecx>,
        float *a2@<eax>,
        vostok::render::effect_compiler *this,
        char *hlsl_name)
{
  vostok::shared_string *v4; // ecx
  vostok::command_line::key *v5; // ecx
  vostok::render::effect_compiler *v6; // esi
  vostok::render::shader_constant_binding binding; // [esp+10h] [ebp-14h] BYREF

  binding.m_source.m_pointer = vostok::render::effect_constant_storage::store_constant<float>(
                                 ecx0,
                                 vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.x,
                                 COERCE_UNSIGNED_INT(*a2));
  binding.m_source.m_size = 4;
  vostok::shared_string::shared_string(v4, &binding.m_name.m_pointer, hlsl_name);
  binding.m_type = rc_float;
  binding.m_class_id = rc_1x1;
  v6 = vostok::render::effect_compiler::bind_constant(
         (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&binding,
         v5,
         this);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  return v6;
}


vostok::render::effect_compiler *__thiscall vostok::render::effect_compiler::set_constant<vostok::math::float2>(
        vostok::render::effect_constant_storage *source,
        vostok::render::effect_compiler *this,
        char *hlsl_name)
{
  vostok::shared_string *v3; // ecx
  vostok::command_line::key *v4; // ecx
  vostok::render::effect_compiler *v5; // esi
  vostok::math::float2 v7; // [esp-Ch] [ebp-2Ch]
  vostok::render::shader_constant_binding binding; // [esp+Ch] [ebp-14h] BYREF

  v7.x = vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.x;
  v7.y = *(float *)&source->m_indexers.m_begin;
  binding.m_source.m_pointer = vostok::render::effect_constant_storage::store_constant<vostok::math::float2>(
                                 source,
                                 v7,
                                 COERCE_UNSIGNED_INT(*(float *)&source->m_indexers.m_end));
  binding.m_source.m_size = 8;
  vostok::shared_string::shared_string(v3, &binding.m_name.m_pointer, hlsl_name);
  binding.m_type = rc_float;
  binding.m_class_id = rc_1x2;
  v5 = vostok::render::effect_compiler::bind_constant(
         (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&binding,
         v4,
         this);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&binding.m_name.m_pointer);
  return v5;
}


vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_constant<vostok::math::float3>@<eax>(
        const vostok::math::float3 *source@<eax>,
        vostok::render::effect_constant_storage *a2@<ecx>,
        vostok::render::effect_compiler *this,
        char *hlsl_name)
{
  vostok::math::float3 *v4; // eax
  vostok::shared_string *v5; // ecx
  const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // esi
  vostok::math::float3 v10; // [esp-10h] [ebp-30h]
  vostok::render::shader_constant_binding v11; // [esp+Ch] [ebp-14h] BYREF

  v10.x = vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.x;
  *(_QWORD *)&v10.elements[1] = *(_QWORD *)&source->x;
  v4 = vostok::render::effect_constant_storage::store_constant<vostok::math::float3>(a2, v10, LODWORD(source->z));
  vostok::render::shader_constant_binding::shader_constant_binding(&v11, v4, v5, hlsl_name);
  v8 = vostok::render::effect_compiler::bind_constant(v6, v7, this);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v11.m_name.m_pointer);
  return v8;
}


vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_constant<vostok::math::float4>@<eax>(
        const vostok::math::float4 *source@<eax>,
        vostok::render::effect_constant_storage *a2@<ecx>,
        vostok::render::effect_compiler *this,
        char *hlsl_name)
{
  vostok::math::float4 *v4; // eax
  vostok::shared_string *v5; // ecx
  const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *v6; // eax
  vostok::command_line::key *v7; // ecx
  vostok::render::effect_compiler *v8; // esi
  vostok::math::float4 v10; // [esp-14h] [ebp-34h]
  vostok::render::shader_constant_binding v11; // [esp+Ch] [ebp-14h] BYREF

  v10.x = vostok::quasi_singleton<vostok::render::effect_constant_storage>::pinst.x;
  v10.y = source->x;
  *(_QWORD *)&v10.elements[2] = *(_QWORD *)&source->elements[1];
  v4 = vostok::render::effect_constant_storage::store_constant<vostok::math::float4>(a2, v10, LODWORD(source->w));
  vostok::render::shader_constant_binding::shader_constant_binding(&v11, v4, v5, hlsl_name);
  v8 = vostok::render::effect_compiler::bind_constant(v6, v7, this);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v11.m_name.m_pointer);
  return v8;
}
