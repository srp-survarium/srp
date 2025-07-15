void __userpurge vostok::render::scene::render_lines(
        vostok::render::scene *this@<ecx>,
        int a2@<eax>,
        bool covering_effect)
{
  vostok::buffer_vector<vostok::render::vertex_colored> *v3; // edi
  vostok::render::system_renderer *v4; // ecx
  int *v5; // esi

  v3 = (vostok::buffer_vector<vostok::render::vertex_colored> *)((char *)&loc_5534BC + a2);
  v4 = *(vostok::render::system_renderer **)((char *)&loc_5534BC + a2);
  if ( v4 != *(vostok::render::system_renderer **)((char *)&loc_5534BC + a2 + 4) )
  {
    v5 = (int *)((char *)&loc_6534C8 + a2);
    vostok::render::system_renderer::draw_lines(
      *(const vostok::render::vertex_colored *const *)((char *)&loc_5534BE + a2 + 2),
      v4,
      vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
      (unsigned int)v4,
      *(unsigned __int8 **)((char *)&loc_6534C8 + a2),
      *(char **)((char *)&loc_6534C8 + a2 + 4),
      covering_effect);
    vostok::buffer_vector<vostok::render::vertex_colored>::resize(v3, 0);
    vostok::buffer_vector<unsigned short>::resize(0, v5);
  }
}
