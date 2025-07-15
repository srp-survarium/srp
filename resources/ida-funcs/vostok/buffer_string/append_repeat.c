vostok::buffer_string *__userpurge vostok::buffer_string::append_repeat@<eax>(
        unsigned int count@<eax>,
        vostok::buffer_string *this,
        char *string_to_repeat)
{
  unsigned int v5; // eax
  const char *v6; // edi
  unsigned int v8; // [esp+14h] [ebp+Ch]

  v5 = strlen(string_to_repeat);
  if ( count )
  {
    v6 = &string_to_repeat[v5];
    v8 = count;
    do
    {
      vostok::buffer_string::append(this, v6, string_to_repeat);
      --v8;
    }
    while ( v8 );
  }
  return this;
}
