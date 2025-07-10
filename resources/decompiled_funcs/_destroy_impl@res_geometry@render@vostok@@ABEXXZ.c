void __usercall vostok::render::res_geometry::destroy_impl(
        vostok::render::res_geometry *this@<ecx>,
        vostok::render::res_geometry *a2@<eax>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
