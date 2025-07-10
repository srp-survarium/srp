void __usercall vostok::render::resource_manager::release(
        vostok::render::resource_manager *this@<ecx>,
        vostok::render::res_xs_hw<vostok::render::ps_data> *ps@<eax>)
{
  vostok::render::resource_manager::release_impl<vostok::render::ps_data>(this, ps);
}
