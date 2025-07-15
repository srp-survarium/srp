void __usercall vostok::render::shader_macros::fill_global_macros(
        vostok::fixed_vector<vostok::render::shader_macro,128> *defines@<eax>,
        vostok::render::options *a2@<ecx>,
        vostok::render::shader_macros *this)
{
  vostok::render::options::fill_global_macros(
    a2,
    (int *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start,
    defines);
}
