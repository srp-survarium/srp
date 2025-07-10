void __cdecl vostok::buffer_vector<vostok::resources::request>::construct(
        vostok::resources::request *p,
        const vostok::resources::request *value)
{
  if ( p )
    *p = *value;
}
