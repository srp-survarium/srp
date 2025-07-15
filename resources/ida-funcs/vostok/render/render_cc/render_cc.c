void __userpurge vostok::render::render_cc::render_cc(
        vostok::render::render_cc *this@<ecx>,
        vostok::render::render_cc *a2@<eax>,
        const char *define_name,
        vostok::render::enum_options_changes_result changed_result)
{
  vostok::render::options *v4; // ecx

  a2->m_define_name = (const char *)this;
  a2->m_changes_result = (vostok::render::enum_options_changes_result)define_name;
  v4 = vostok::quasi_singleton<vostok::render::options>::pinst;
  a2->__vftable = (vostok::render::render_cc_vtbl *)&vostok::render::render_cc::`vftable';
  a2->render_next = v4->first_render_command;
  v4->first_render_command = a2;
}
