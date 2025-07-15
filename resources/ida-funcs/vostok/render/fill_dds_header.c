void __usercall vostok::render::fill_dds_header(
        dds_header *header@<eax>,
        unsigned int width,
        unsigned int height,
        int depth,
        unsigned int size,
        char format,
        DXGI_FORMAT is_normal_map,
        bool is_cubemap,
        unsigned int is_volume_texture)
{
  _DDSURFACEDESC2 *p_header; // esi
  int v10; // eax

  p_header = &header->header;
  header->signature = 542327876;
  memset((int)&header->header, 0, sizeof(header->header));
  p_header->dwSize = 124;
  p_header->dwFlags = (unsigned int)&loc_A100F;
  if ( is_cubemap )
    p_header->dwFlags = 9048079;
  p_header->dwWidth = width;
  p_header->dwHeight = height;
  p_header->dwMipMapCount = is_volume_texture;
  if ( is_cubemap )
    p_header->dwBackBufferCount = 1;
  p_header->ddpfPixelFormat.$A1F399CE406BB07A8079F5E82F964E8F::dwSize = 32;
  p_header->ddsCaps.dwCaps = (unsigned int)&loc_401007 + 1;
  if ( (_BYTE)is_normal_map )
    p_header->ddsCaps.dwCaps2 |= 0xFE00u;
  if ( is_cubemap )
    p_header->ddsCaps.dwCaps2 |= (unsigned int)&loc_200000;
  if ( format )
  {
    p_header->ddpfPixelFormat.dwRGBBitCount = 893661761;
    p_header->ddpfPixelFormat.dwFourCC = 894720068;
LABEL_15:
    p_header->ddpfPixelFormat.dwFlags = 4;
    p_header->lPitch = depth;
    return;
  }
  if ( size == 71 )
    v10 = 827611204;
  else
    v10 = size == 74 ? 861165636 : (int)&s_ui_commands_allocator + 879978268;
  p_header->ddpfPixelFormat.dwFourCC = v10;
  if ( v10 )
    goto LABEL_15;
}
