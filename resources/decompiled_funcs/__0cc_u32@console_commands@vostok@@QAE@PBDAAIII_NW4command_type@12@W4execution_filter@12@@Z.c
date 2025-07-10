void __userpurge vostok::console_commands::cc_u32::cc_u32(
        vostok::console_commands::cc_u32 *this@<esi>,
        vostok::console_commands::command_type command_type@<ecx>,
        vostok::console_commands::execution_filter execution_filter@<eax>,
        const char *name,
        unsigned int *value,
        vostok::console_commands::cc_value<unsigned int> *min,
        unsigned int max,
        bool serializable)
{
  vostok::console_commands::cc_value<unsigned int>::cc_value<unsigned int>(
    min,
    (int)this,
    name,
    value,
    (unsigned int)min,
    max,
    serializable,
    command_type,
    execution_filter);
  this->__vftable = (vostok::console_commands::cc_u32_vtbl *)&stru_95AF78.m_key_bindings[50].m_keyboard[1];
}
