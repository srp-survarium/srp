void __usercall vostok::render::res_pass::destroy_impl(
        vostok::render::res_pass *this@<ecx>,
        const vostok::render::res_pass *a2@<eax>)
{
  vostok::render::effect_manager::delete_pass(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    a2);
}
