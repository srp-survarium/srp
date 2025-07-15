void __usercall vostok::render::res_state::destroy_impl(
        vostok::render::res_state *this@<ecx>,
        const vostok::render::res_state *a2@<edi>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
