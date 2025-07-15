void __usercall vostok::render::res_sampler_list::destroy_impl(
        vostok::render::res_sampler_list *this@<ecx>,
        const vostok::render::res_sampler_list *a2@<eax>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
