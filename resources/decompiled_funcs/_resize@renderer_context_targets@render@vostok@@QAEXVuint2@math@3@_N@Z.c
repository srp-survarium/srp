void __thiscall vostok::render::renderer_context_targets::resize(
        vostok::render::renderer_context_targets *this,
        vostok::math::uint2 size,
        vostok::math::uint2 force_resize)
{
  vostok::render::renderer_context_targets::create_targets(
    (vostok::render::renderer_context_targets *)force_resize.x,
    size.x,
    (vostok::math::uint2)__PAIR64__(force_resize.x, size.y),
    (vostok::render::renderer_context_targets *)force_resize.y);
}
