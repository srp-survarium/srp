void __userpurge vostok::render::renderer_context::push_set_v(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<esi>,
        const vostok::math::float4x4 *m)
{
  vostok::render::renderer_context *v3; // ecx

  vostok::buffer_vector<vostok::math::float4x4>::push_back(
    (vostok::buffer_vector<vostok::math::float4x4> *)this,
    (const vostok::math::float4x4 *)(a2 + 17308),
    (const void *)(a2 + 19508));
  vostok::render::renderer_context::set_v(v3, (const vostok::math::float4x4 *)a2, m);
}
