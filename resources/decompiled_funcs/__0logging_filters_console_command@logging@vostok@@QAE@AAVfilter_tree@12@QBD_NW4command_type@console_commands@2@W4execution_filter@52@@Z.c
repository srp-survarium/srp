void __thiscall vostok::logging::logging_filters_console_command::logging_filters_console_command(
        vostok::logging::logging_filters_console_command *this,
        vostok::logging::filter_tree *filter_tree,
        const char *name,
        bool serializable,
        vostok::console_commands::console_command *command_type,
        vostok::console_commands::execution_filter execution_filter)
{
  vostok::console_commands::console_command::console_command(
    command_type,
    (int)this,
    name,
    serializable,
    (vostok::console_commands::command_type)command_type,
    execution_filter);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)(&this->gap40 + 1));
  this->__vftable = (vostok::logging::logging_filters_console_command_vtbl *)&vostok::logging::logging_filters_console_command::`vftable';
  this->m_filter_tree = filter_tree;
  this->m_need_args = 1;
}
