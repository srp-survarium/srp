bool __usercall vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>::operator()@<al>(
        const vostok::render::res_signature *const left@<eax>,
        const vostok::render::res_signature *const right@<ecx>,
        vostok::render::resource_manager::compare_predicate<vostok::render::res_signature> *this)
{
  return right->m_signature > left->m_signature;
}
