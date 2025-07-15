void __thiscall vostok::render::stage_light_propagation_volumes::post_lpv_batch_render(
        vostok::render::stage_light_propagation_volumes *this,
        const vostok::render::geometry_batch *batch)
{
  ++vostok::quasi_singleton<vostok::render::statistics>::pinst->debug_stat_group.num_dips_in_lpv.value;
}
