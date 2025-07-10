void __cdecl vostok::buffer_vector<vostok::resources::creation_request>::construct(
        vostok::resources::creation_request *p,
        const vostok::resources::creation_request *value)
{
  vostok::resources::creation_request *v2; // [esp+4h] [ebp-4h]

  v2 = (vostok::resources::creation_request *)operator new(0x10u, (void *)p);
  if ( v2 )
    *v2 = *value;
}
