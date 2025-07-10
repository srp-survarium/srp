void __userpurge vostok::render::renderer_context_targets::renderer_context_targets(
        vostok::render::renderer_context_targets *this@<ecx>,
        int a2@<esi>,
        vostok::math::uint2 size)
{
  vostok::math::uint2 v3; // [esp-10h] [ebp-10h]

  `vector constructor iterator'(
    (char *)a2,
    0xA0u,
    70,
    (void *(__thiscall *)(void *))vostok::render::render_target_instance::render_target_instance);
  *(_DWORD *)(a2 + 11200) = 0;
  *(_DWORD *)(a2 + 11204) = 0;
  *(_DWORD *)(a2 + 11212) = 0;
  v3.y = size.x;
  v3.x = 1;
  vostok::render::renderer_context_targets::create_targets(
    (vostok::render::renderer_context_targets *)size.x,
    a2,
    v3,
    (vostok::render::renderer_context_targets *)size.y);
}
