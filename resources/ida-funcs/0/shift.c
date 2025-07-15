void __usercall shift(__m128i *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist )
  {
    strlen((unsigned __int8 *)s);
    memmove((int)s->m128i_i32 + dist, s, v3 + 1);
  }
}
