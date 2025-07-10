void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::gs_data> *gs@<eax>)
{
  vostok::render::resource_manager::release_impl<vostok::render::gs_data>(this, gs);
}
