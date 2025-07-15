void __userpurge vostok::render::material_effects::get_used_textures(
        vostok::render::material_effects *this@<ecx>,
        int a2@<eax>,
        vostok::fixed_vector<vostok::render::texture_named_instance,1024> *out_array)
{
  int v3; // eax
  const vostok::render::texture_named_instance *v4; // esi
  vostok::render::texture_named_instance *m_end; // ebx
  const vostok::render::texture_named_instance *i; // [esp+10h] [ebp-Ch]
  int v7; // [esp+14h] [ebp-8h]
  int *v8; // [esp+18h] [ebp-4h]

  v8 = (int *)(a2 + 40);
  v7 = 28;
  do
  {
    v3 = *v8;
    if ( *v8 )
    {
      v4 = *(const vostok::render::texture_named_instance **)(v3 + 264);
      for ( i = *(const vostok::render::texture_named_instance **)(v3 + 268); v4 != i; ++v4 )
      {
        m_end = out_array->m_end;
        if ( stlp_std::find<vostok::render::texture_named_instance *,vostok::render::texture_named_instance>(
               out_array->m_begin,
               v4,
               m_end) == m_end )
          vostok::buffer_vector<vostok::render::texture_named_instance>::push_back(out_array, v4);
      }
    }
    ++v8;
    --v7;
  }
  while ( v7 );
}
