void __userpurge vostok::render::resource_manager::copy2D(
        unsigned int size_x@<ecx>,
        vostok::render::resource_manager *this,
        vostok::render::res_texture *dest,
        unsigned int dest_x,
        unsigned int dest_y,
        vostok::render::res_texture *source,
        unsigned int src_x,
        unsigned int src_y,
        unsigned int size_y,
        unsigned int dest_mip,
        unsigned int src_mip)
{
  ID3D11DeviceContext *m_context; // ecx
  ID3D11Resource *v12; // [esp-20h] [ebp-44h]
  ID3D11Resource *m_surface; // [esp-Ch] [ebp-30h]
  _DWORD v14[7]; // [esp+8h] [ebp-1Ch] BYREF

  m_surface = dest->m_surface;
  v14[3] = size_x;
  memset(v14, 0, 12);
  v12 = *(ID3D11Resource **)&this->m_loaded_texture_names.m_buffer[1].m_store[120];
  v14[4] = dest_x;
  m_context = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
  v14[5] = 1;
  m_context->CopySubresourceRegion(m_context, v12, 0, 0, 0, 0, m_surface, 0, (const D3D11_BOX *)v14);
}
