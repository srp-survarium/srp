malloc_segment *__usercall segment_holding@<eax>(malloc_state *m@<eax>, char *addr@<edx>)
{
  malloc_segment *result; // eax

  result = &m->seg;
  do
  {
    if ( addr >= result->base && addr < &result->base[result->size] )
      break;
    result = result->next;
  }
  while ( result );
  return result;
}
