void __userpurge vostok::render::scene::render_triangles(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        bool covering_effect)
{
  vostok::buffer_vector<vostok::render::vertex_colored> *v3; // edi
  vostok::render::system_renderer *v4; // ecx
  int *v5; // esi

  v3 = (vostok::buffer_vector<vostok::render::vertex_colored> *)((char *)&off_6F34D4 + a2);
  v4 = *(vostok::render::system_renderer **)((char *)&off_6F34D4 + a2);
  if ( v4 != (vostok::render::system_renderer *)*(_UNKNOWN **)((char *)&off_6F34D4 + a2 + 4) )
  {
    v5 = (int *)(a2 + 8336608);
    vostok::render::system_renderer::draw_triangles(
      *(const vostok::render::vertex_colored *const *)&aSpltChunkTooLo[a2],
      v4,
      (unsigned int)vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
      (unsigned int)v4,
      *(unsigned __int8 **)(a2 + 8336608),
      *(char **)(a2 + 8336612),
      covering_effect);
    vostok::buffer_vector<vostok::render::vertex_colored>::resize(v3, 0);
    vostok::buffer_vector<unsigned short>::resize(0, v5);
  }
}
