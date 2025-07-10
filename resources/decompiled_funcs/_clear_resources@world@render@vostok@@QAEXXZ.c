void __usercall vostok::render::world::clear_resources(vostok::render::world *this@<ecx>, int a2@<eax>)
{
  vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base>::operator=(
    (vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)(*(_DWORD *)(**(_DWORD **)(a2 + 368) + 352) + 12392),
    0);
}
