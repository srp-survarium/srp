void __usercall vostok::command_line::key::initialize(vostok::command_line::key *this@<ecx>, int a2@<eax>)
{
  *(_DWORD *)(a2 + 548) = 1;
  vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
}
