void __userpurge vostok::render::temporal_projection_matrix_modifier::temporal_projection_matrix_modifier(
        vostok::render::temporal_projection_matrix_modifier *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *const context,
        unsigned int window_size_x,
        bool window_size_y,
        const bool need_modify)
{
  *(_DWORD *)a2 = this;
  *(_DWORD *)(a2 + 4) = context;
  *(_DWORD *)(a2 + 8) = window_size_x;
  *(_BYTE *)(a2 + 12) = window_size_y;
  *(_BYTE *)(a2 + 13) = 0;
}
