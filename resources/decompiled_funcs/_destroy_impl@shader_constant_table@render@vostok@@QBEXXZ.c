void __usercall vostok::render::shader_constant_table::destroy_impl(
        vostok::render::shader_constant_table *this@<ecx>,
        vostok::render::shader_constant_table *a2@<eax>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
