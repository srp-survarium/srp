void __usercall vostok::render::untyped_buffer::destroy_impl(
        vostok::render::untyped_buffer *this@<ecx>,
        const vostok::render::untyped_buffer *a2@<edi>)
{
  vostok::render::resource_manager::release(
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
    a2);
}
