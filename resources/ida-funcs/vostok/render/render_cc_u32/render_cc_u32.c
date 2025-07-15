void __userpurge vostok::render::render_cc_u32::render_cc_u32(
        vostok::render::render_cc_u32 *this@<esi>,
        vostok::render::render_cc *define_name@<ecx>,
        const char *name,
        const char *changed_result,
        unsigned int *value,
        unsigned int *prev_value,
        unsigned int min,
        unsigned int max,
        bool serializable,
        const vostok::console_commands::command_type command_type)
{
  vostok::console_commands::cc_u32 *v10; // ecx
  _DWORD *v11; // eax
  vostok::render::enum_options_changes_result savedregs; // [esp+0h] [ebp+0h]
  vostok::console_commands::execution_filter savedregsa; // [esp+0h] [ebp+0h]

  vostok::render::render_cc::render_cc(define_name, this, changed_result, savedregs);
  vostok::console_commands::cc_u32::cc_u32(
    v10,
    (int)&this->vostok::console_commands::cc_u32,
    name,
    value,
    min,
    max,
    serializable,
    command_type,
    savedregsa);
  *v11 = &vostok::render::render_cc_u32::`vftable'{for `vostok::console_commands::cc_u32'};
  this->m_prev_value = prev_value;
  this->vostok::render::render_cc::__vftable = (vostok::render::render_cc_u32_vtbl *)&vostok::render::render_cc_u32::`vftable'{for `vostok::render::render_cc'};
}
