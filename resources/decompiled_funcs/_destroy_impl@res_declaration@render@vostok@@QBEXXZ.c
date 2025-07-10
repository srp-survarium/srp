void __usercall vostok::render::res_declaration::destroy_impl(
        vostok::render::res_declaration *this@<ecx>,
        vostok::render::res_declaration *a2@<eax>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
