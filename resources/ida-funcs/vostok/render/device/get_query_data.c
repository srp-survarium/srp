char __userpurge vostok::render::device::get_query_data@<al>(
        vostok::render::device *this@<ecx>,
        int a2@<edi>,
        ID3D11Query *in_query,
        void *in_out_data,
        const unsigned int in_data_size,
        bool in_wait)
{
  int v6; // ebx
  vostok::command_line::key *v7; // ecx

  v6 = (*(int (__stdcall **)(_DWORD, ID3D11Query *, void *, int, _DWORD))(**(_DWORD **)(a2 + 308) + 116))(
         *(_DWORD *)(a2 + 308),
         in_query,
         in_out_data,
         4,
         0);
  while ( v6 == 1 )
  {
    v6 = (*(int (__stdcall **)(_DWORD, ID3D11Query *, void *, int, _DWORD))(**(_DWORD **)(a2 + 308) + 116))(
           *(_DWORD *)(a2 + 308),
           in_query,
           in_out_data,
           4,
           0);
    vostok::resources::dispatch_callbacks(v7);
    vostok::threading::yield(1u);
  }
  if ( !v6 )
    return 1;
  if ( v6 == -2005270523 || v6 == -2005270521 || v6 == -2005270496 )
    *(_BYTE *)(a2 + 358) = 1;
  return 0;
}
