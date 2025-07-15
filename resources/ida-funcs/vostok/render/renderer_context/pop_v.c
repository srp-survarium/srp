void __usercall vostok::render::renderer_context::pop_v(vostok::render::renderer_context *this@<ecx>, int a2@<esi>)
{
  vostok::render::renderer_context::set_v(
    this,
    (const vostok::math::float4x4 *)a2,
    (const vostok::math::float4x4 *)(*(_DWORD *)(a2 + 17312) - 64));
  *(_DWORD *)(a2 + 17312) -= 64;
}
