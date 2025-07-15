vostok::render::streamable_texture_info *__userpurge vostok::render::streamable_texture_info::operator=@<eax>(
        vostok::render::streamable_texture_info *this@<ecx>,
        int a2@<esi>,
        const vostok::render::streamable_texture_info *__that)
{
  vostok::fixed_string<260>::operator=(&__that->path, (const vostok::fixed_string<260> *)a2);
  *(_DWORD *)(a2 + 272) = __that->instances;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &__that->texture,
    (vostok::render::res_texture *)(a2 + 276));
  *(float *)(a2 + 280) = __that->max_tiling;
  *(_DWORD *)(a2 + 284) = __that->max_uses_width;
  *(_DWORD *)(a2 + 288) = __that->max_uses_height;
  *(_DWORD *)(a2 + 292) = __that->loaded_num_mips;
  *(_DWORD *)(a2 + 296) = __that->max_uses_mips;
  *(_DWORD *)(a2 + 300) = __that->base_format;
  *(_DWORD *)(a2 + 304) = __that->width;
  *(_DWORD *)(a2 + 308) = __that->height;
  *(_DWORD *)(a2 + 312) = __that->array_size;
  *(_DWORD *)(a2 + 316) = __that->streaming_priority;
  *(_DWORD *)(a2 + 320) = __that->num_mips;
  *(_BYTE *)(a2 + 324) = __that->always_closer;
  return (vostok::render::streamable_texture_info *)a2;
}
