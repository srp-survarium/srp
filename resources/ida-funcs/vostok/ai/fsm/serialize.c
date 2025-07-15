void __userpurge vostok::ai::fsm::serialize(
        vostok::ai::fsm *this@<ecx>,
        int a2@<esi>,
        vostok::network_core::buffer_writer *writer,
        const vostok::network_core::buffer_writer *client_writer)
{
  int v4; // eax
  unsigned __int8 v5; // [esp+3h] [ebp-1h] BYREF

  v4 = *(_DWORD *)(a2 + 8);
  v5 = 0;
  if ( v4 )
  {
    this = *(vostok::ai::fsm **)(a2 + 16);
    do
    {
      if ( (vostok::ai::fsm *)v4 == this )
        break;
      v4 = *(_DWORD *)(v4 + 4);
      ++v5;
    }
    while ( v4 );
  }
  vostok::network_core::buffer_writer::w<unsigned char>(
    &v5,
    (vostok::network_core::buffer_writer *)this,
    writer,
    ".\\fsm.cpp",
    (const char *)0x87,
    "vostok::ai::fsm::serialize",
    "state_id");
  (*(void (__thiscall **)(_DWORD, vostok::network_core::buffer_writer *, const vostok::network_core::buffer_writer *))(**(_DWORD **)(a2 + 16) + 16))(
    *(_DWORD *)(a2 + 16),
    writer,
    client_writer);
}
