void __usercall vostok::render::res_render_output::destroy_impl(
        vostok::render::res_render_output *this@<ecx>,
        const vostok::render::res_render_output *a2@<edi>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
