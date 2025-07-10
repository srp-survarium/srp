void __cdecl vostok::buffer_vector<void const *>::construct(const void **p, const void **value)
{
  const void **v2; // [esp+4h] [ebp-4h]

  v2 = (const void **)operator new(4u, p);
  if ( v2 )
    *v2 = *value;
}
