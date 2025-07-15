void __usercall vostok::render::res_signature::destroy_impl(
        vostok::render::res_signature *this@<ecx>,
        const vostok::render::res_signature *a2@<eax>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
