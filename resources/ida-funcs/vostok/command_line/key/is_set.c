BOOL __usercall vostok::command_line::key::is_set@<eax>(vostok::command_line::key *this@<ecx>, int a2@<eax>)
{
  _DWORD *v2; // esi

  v2 = (_DWORD *)(a2 + 548);
  if ( !*(_DWORD *)(a2 + 548) )
    vostok::command_line::key::initialize(this, a2);
  return *v2 != 1;
}
