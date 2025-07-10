void __userpurge vostok::render::render_cc_u32::render_cc_u32(
        vostok::render::render_cc_u32 *this@<esi>,
        vostok::render::enum_options_changes_result changed_result@<ecx>,
        const char *define_name@<eax>,
        const char *name,
        unsigned int *value,
        unsigned int *prev_value,
        vostok::console_commands::cc_value<unsigned int> *min,
        unsigned int max,
        bool serializable,
        vostok::console_commands::command_type command_type)
{
  vostok::render::render_cc **M_start; // eax

  this->m_define_name = define_name;
  M_start = (vostok::render::render_cc **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_ids._M_impl._M_start;
  this->m_changes_result = changed_result;
  this->vostok::render::render_cc::__vftable = (vostok::render::render_cc_u32_vtbl *)&vostok::render::render_cc::`vftable';
  this->render_next = *M_start;
  *M_start = this;
  vostok::console_commands::cc_value<unsigned int>::cc_value<unsigned int>(
    min,
    (int)&this->vostok::console_commands::cc_u32,
    name,
    value,
    (unsigned int)min,
    max,
    1,
    command_type_user_specific,
    execution_filter_general);
  this->vostok::console_commands::cc_u32::vostok::console_commands::cc_value<unsigned int>::vostok::console_commands::console_command::__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
  this->vostok::console_commands::cc_u32::vostok::console_commands::cc_value<unsigned int>::vostok::console_commands::console_command::__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::render::render_cc_u32::`vftable'{for `vostok::console_commands::cc_u32'};
  this->vostok::render::render_cc::__vftable = (vostok::render::render_cc_u32_vtbl *)&vostok::render::render_cc_u32::`vftable'{for `vostok::render::render_cc'};
  this->m_prev_value = prev_value;
}
