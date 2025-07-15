void __userpurge vostok::console_commands::cc_delegate::cc_delegate(
        vostok::console_commands::cc_delegate *this@<ecx>,
        int a2@<esi>,
        const char *name,
        boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *functor,
        bool need_args,
        const vostok::console_commands::command_type command_type)
{
  vostok::console_commands::console_command::console_command(this, a2, name, 1, command_type, execution_filter_general);
  *(_DWORD *)a2 = &vostok::console_commands::cc_delegate::`vftable';
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    functor,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(a2 + 64));
  *(_BYTE *)(a2 + 28) = need_args;
}
