void __usercall vostok::console_commands::load(
        vostok::memory::reader *F@<esi>,
        vostok::console_commands::execution_filter filter,
        unsigned int command_types_to_execute)
{
  char v3[4096]; // [esp+0h] [ebp-1000h] BYREF

  while ( F->m_pointer - F->m_data < F->m_size )
  {
    vostok::console_commands::r_string(F, (char (*)[4096])v3);
    vostok::console_commands::execute(v3, filter, command_types_to_execute);
  }
}
