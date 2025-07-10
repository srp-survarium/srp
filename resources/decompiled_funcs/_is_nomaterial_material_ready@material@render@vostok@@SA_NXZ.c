char __cdecl vostok::render::material::is_nomaterial_material_ready()
{
  int v0; // eax

  v0 = 0;
  while ( s_nomaterial_material_effects[v0]->m_effects[0].m_object )
  {
    if ( (unsigned int)++v0 >= 15 )
      return 1;
  }
  return 0;
}
