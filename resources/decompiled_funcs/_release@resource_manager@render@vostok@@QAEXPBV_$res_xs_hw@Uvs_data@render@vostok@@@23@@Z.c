void __userpurge vostok::render::resource_manager::release(
        const vostok::render::res_xs_hw<vostok::render::vs_data> *vs@<eax>,
        vostok::render::resource_manager *a2@<ecx>,
        vostok::render::resource_manager *this)
{
  vostok::render::resource_manager::release_impl<vostok::render::vs_data>(a2, (int)this, vs);
}
