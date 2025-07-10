int __cdecl engine_unlocked_init(engine_st *e)
{
  int result; // eax
  int (__cdecl *init)(engine_st *); // ecx

  result = 1;
  if ( e->funct_ref || (init = e->init) == 0 || (result = init(e)) != 0 )
  {
    ++e->struct_ref;
    ++e->funct_ref;
  }
  return result;
}
