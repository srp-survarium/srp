ID3D11Resource *__userpurge vostok::render::texture_pool::add_texture@<eax>(
        const vostok::render::texture_pool_key *desc@<eax>,
        vostok::render::texture_pool *this,
        bool occupied,
        unsigned int calculate_memory_only)
{
  unsigned int array_size; // eax
  unsigned int mips; // ecx
  HRESULT v7; // eax
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v8; // ecx
  bool *d3d11_error_string; // eax
  unsigned int v10; // edi
  DXGI_FORMAT format; // ecx
  unsigned int height; // edx
  unsigned int v13; // eax
  int v14; // eax
  vostok::buffer_vector<vostok::render::texture_pool_slot> *v15; // ecx
  unsigned __int8 dst[44]; // [esp+10h] [ebp-3Ch] BYREF
  _DWORD v18[2]; // [esp+3Ch] [ebp-10h] BYREF
  bool v19; // [esp+44h] [ebp-8h]
  char v20; // [esp+45h] [ebp-7h]
  char v21; // [esp+46h] [ebp-6h]
  int v22; // [esp+48h] [ebp-4h] BYREF

  v22 = 0;
  memset((int)dst, 0, sizeof(dst));
  array_size = desc->array_size;
  *(_DWORD *)&dst[16] = desc->format;
  *(_DWORD *)dst = desc->width;
  *(_DWORD *)&dst[4] = desc->height;
  mips = desc->mips;
  *(_DWORD *)&dst[12] = array_size;
  *(_DWORD *)&dst[32] = 8;
  *(_DWORD *)&dst[8] = mips;
  *(_DWORD *)&dst[40] = 4;
  if ( array_size != 6 )
    *(_DWORD *)&dst[40] = 0;
  *(_DWORD *)&dst[20] = 1;
  *(_DWORD *)&dst[24] = 0;
  *(_DWORD *)&dst[36] = 0;
  *(_DWORD *)&dst[28] = 0;
  if ( !(_BYTE)calculate_memory_only )
  {
    v7 = vostok::quasi_singleton<vostok::render::device>::pinst->m_device->CreateTexture2D(
           vostok::quasi_singleton<vostok::render::device>::pinst->m_device,
           (const D3D11_TEXTURE2D_DESC *)dst,
           0,
           (ID3D11Texture2D **)&v22);
    if ( !ignore_always_35 && v7 < 0 )
    {
      HIBYTE(calculate_memory_only) = 1;
      d3d11_error_string = (bool *)make_d3d11_error_string(v7, v8);
      vostok::debug::on_error(
        (bool *)&calculate_memory_only + 3,
        process_error_true,
        d3d11_error_string,
        ".\\texture_pool.cpp",
        "vostok::render::texture_pool::add_texture",
        (const char *)0x30);
      if ( vostok::debug::is_debugger_present() || HIBYTE(calculate_memory_only) )
        __debugbreak();
    }
    (*(void (__stdcall **)(int))(*(_DWORD *)v22 + 4))(v22);
  }
  v10 = desc->array_size;
  format = desc->format;
  height = desc->height;
  v19 = occupied;
  v13 = desc->mips;
  calculate_memory_only = desc->width;
  v20 = 0;
  v21 = 0;
  if ( (unsigned int)(format - 70) > 0xE )
    v14 = vostok::render::utils::calc_texture_size_uncompressed(v13, calculate_memory_only, height, format, v10);
  else
    v14 = v10 * vostok::render::utils::calc_texture_size_compressed(calculate_memory_only, height, format, v13, 0, 0);
  v18[1] = v14;
  v18[0] = v22;
  vostok::buffer_vector<vostok::render::texture_pool_slot>::push_back(
    v15,
    (const vostok::render::texture_pool_slot *)&this->m_slots,
    v18);
  return (ID3D11Resource *)v18[0];
}
