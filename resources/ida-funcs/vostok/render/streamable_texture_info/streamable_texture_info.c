void __thiscall vostok::render::streamable_texture_info::streamable_texture_info(
        vostok::render::streamable_texture_info *this,
        const vostok::render::streamable_texture_info *__that,
        int a3)
{
  vostok::fixed_string<260>::fixed_string<260>(&__that->path, (const vostok::fixed_string<260> *)a3);
  __that->instances = *(vostok::render::streaming_texture_instance **)(a3 + 272);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &__that->texture,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a3 + 276));
  __that->max_tiling = *(float *)(a3 + 280);
  __that->max_uses_width = *(_DWORD *)(a3 + 284);
  __that->max_uses_height = *(_DWORD *)(a3 + 288);
  __that->loaded_num_mips = *(_DWORD *)(a3 + 292);
  __that->max_uses_mips = *(_DWORD *)(a3 + 296);
  __that->base_format = *(_DWORD *)(a3 + 300);
  __that->width = *(_DWORD *)(a3 + 304);
  __that->height = *(_DWORD *)(a3 + 308);
  __that->array_size = *(_DWORD *)(a3 + 312);
  __that->streaming_priority = *(_DWORD *)(a3 + 316);
  __that->num_mips = *(_DWORD *)(a3 + 320);
  __that->always_closer = *(_BYTE *)(a3 + 324);
}
