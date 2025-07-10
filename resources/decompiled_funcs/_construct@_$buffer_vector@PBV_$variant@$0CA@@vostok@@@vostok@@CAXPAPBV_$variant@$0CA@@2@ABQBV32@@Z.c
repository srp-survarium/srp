void __cdecl vostok::buffer_vector<vostok::variant<32> const *>::construct(
        const vostok::variant<32> **p,
        const vostok::variant<32> *const *value)
{
  if ( p )
    *p = *value;
}
