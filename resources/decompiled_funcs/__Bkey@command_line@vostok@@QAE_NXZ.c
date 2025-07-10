BOOL __usercall vostok::command_line::key::operator bool@<eax>(vostok::command_line::key *this@<ecx>, int a2@<esi>)
{
  if ( !*(_DWORD *)(a2 + 548) )
  {
    *(_DWORD *)(a2 + 548) = 1;
    vostok::command_line::iterate_keys<vostok::command_line::key_initializator>(0);
  }
  return *(_DWORD *)(a2 + 548) != 1;
}
