vostok::math::aabb *__userpurge vostok::render::render_surface_instance::get_aabb@<eax>(
        vostok::render::render_surface_instance *this@<ecx>,
        int a2@<eax>,
        vostok::math::aabb *result)
{
  qmemcpy(result, (const void *)(*(_DWORD *)(a2 + 16) + 108), sizeof(vostok::math::aabb));
  return vostok::math::aabb::modify(*(vostok::math::aabb **)(a2 + 36), result);
}
