void __usercall vostok::console_commands::save_storage::~save_storage(
        vostok::console_commands::save_storage *this@<ecx>,
        int a2@<edi>)
{
  _DWORD *v2; // ebx
  _DWORD *i; // esi

  v2 = *(_DWORD **)(a2 + 4);
  for ( i = *(_DWORD **)a2; i != v2; ++i )
  {
    this = *(vostok::console_commands::save_storage **)(a2 + 16);
    if ( *i )
    {
      (*((void (__thiscall **)(vostok::console_commands::save_storage *, _DWORD, const char *, const char *, int))this->m_lines._M_impl._M_start
       + 6))(
        this,
        *i,
        "vostok::console_commands::save_storage::~save_storage",
        ".\\console_command_processor.cpp",
        178);
      *i = 0;
    }
  }
  stlp_std::priv::_Impl_vector<void const *,vostok::vectora_allocator<void const *>>::~_Impl_vector<void const *,vostok::vectora_allocator<void const *>>(
    &this->m_lines._M_impl,
    a2);
}
