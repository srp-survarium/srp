void __usercall _recalloc_crt(
        survarium::empty_hands *this@<ecx>,
        int a2@<esi>,
        const vostok::collision::object *writer,
        const vostok::math::float3 *client_writer,
        const vostok::math::float3 *time_offset,
        float a5,
        float *a6,
        vostok::collision::ray_triangle_result *a7,
        const fastdelegate::FastDelegate<bool __cdecl(vostok::collision::ray_triangle_result const &)> *a8)
{
  vostok::collision::box_geometry_instance *v9; // ecx

  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)this);
  vostok::collision::box_geometry_instance::ray_query(v9, a2, writer, client_writer, time_offset, a5, a6, a7, a8);
}
