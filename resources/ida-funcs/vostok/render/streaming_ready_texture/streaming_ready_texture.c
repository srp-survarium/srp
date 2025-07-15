void __thiscall vostok::render::streaming_ready_texture::streaming_ready_texture(
        vostok::render::streaming_ready_texture *this,
        const vostok::render::streaming_ready_texture *__that,
        int a3)
{
  vostok::fixed_string<260>::fixed_string<260>(&__that->name, (const vostok::fixed_string<260> *)a3);
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>(
    &__that->texture,
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)(a3 + 272));
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &__that->data,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a3 + 276));
  __that->num_mips = *(_DWORD *)(a3 + 280);
  __that->distance = *(float *)(a3 + 284);
}
