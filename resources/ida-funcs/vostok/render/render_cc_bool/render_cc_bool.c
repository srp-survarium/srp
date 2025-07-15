void __userpurge vostok::render::render_cc_bool::render_cc_bool(
        vostok::render::render_cc_bool *this@<ecx>,
        vostok::render::render_cc *a2@<esi>,
        const char *name,
        const char *changed_result,
        bool *define_name,
        bool *value,
        bool *prev_value,
        vostok::console_commands::command_type serializable,
        const vostok::console_commands::command_type command_type)
{
  vostok::console_commands::cc_bool *v9; // ecx
  _DWORD *v10; // eax
  vostok::render::enum_options_changes_result savedregs; // [esp+0h] [ebp+0h]
  vostok::console_commands::execution_filter savedregsa; // [esp+0h] [ebp+0h]

  vostok::render::render_cc::render_cc(0, a2, changed_result, savedregs);
  vostok::console_commands::cc_bool::cc_bool(
    v9,
    (int)&a2[1],
    name,
    define_name,
    (bool)prev_value,
    serializable,
    savedregsa);
  *v10 = &vostok::render::render_cc_bool::`vftable'{for `vostok::console_commands::cc_bool'};
  a2[5].m_define_name = (const char *)value;
  a2->__vftable = (vostok::render::render_cc_vtbl *)&vostok::render::render_cc_bool::`vftable'{for `vostok::render::render_cc'};
}
