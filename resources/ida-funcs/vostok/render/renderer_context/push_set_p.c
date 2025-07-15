void __userpurge vostok::render::renderer_context::push_set_p(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<esi>,
        const vostok::math::float4x4 *m)
{
  vostok::buffer_vector<vostok::math::float4x4>::push_back(
    (vostok::buffer_vector<vostok::math::float4x4> *)this,
    (const vostok::math::float4x4 *)(a2 + 18344),
    (const void *)(a2 + 19828));
  vostok::render::renderer_context::set_p(m, (vostok::render::renderer_context *)a2);
}
