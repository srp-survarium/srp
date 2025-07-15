void __userpurge vostok::render::res_render_output::res_render_output(
        vostok::render::res_render_output *this@<eax>,
        HWND__ *window@<edi>,
        bool windowed)
{
  char *m_buffer; // eax
  vostok::render::res_render_output *v5; // ecx
  HWND__ *m_window; // eax

  m_buffer = this->m_depth_rexture_name.m_buffer;
  this->m_reference_count = 0;
  this->m_depth_rexture_name.m_begin = m_buffer;
  this->m_depth_rexture_name.m_end = m_buffer;
  *m_buffer = 0;
  this->m_depth_rexture_name.m_max_end = m_buffer + 128;
  this->m_swap_chain = 0;
  this->m_base_rt = 0;
  this->m_base_zb = 0;
  this->m_texture_zb.m_object = 0;
  this->m_present_sync_mode = 0;
  this->m_valid_previous_present = 1;
  this->m_is_registered = 0;
  memset((int)&this->m_swap_chain_desc, 0, sizeof(this->m_swap_chain_desc));
  this->m_window = window;
  this->m_windowed = windowed;
  this->m_swap_chain_desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
  this->m_swap_chain_desc.BufferCount = 1;
  this->m_swap_chain_desc.BufferUsage = 32;
  if ( window )
    vostok::render::res_render_output::select_resolution(
      window,
      &this->m_swap_chain_desc.BufferDesc.Width,
      &this->m_swap_chain_desc.BufferDesc.Height,
      windowed);
  else
    GetLastError();
  LOBYTE(v5) = this->m_windowed;
  this->m_swap_chain_desc.BufferDesc.RefreshRate.Numerator = 0;
  this->m_swap_chain_desc.BufferDesc.RefreshRate.Denominator = 1;
  m_window = this->m_window;
  this->m_swap_chain_desc.SampleDesc.Count = 1;
  this->m_swap_chain_desc.SampleDesc.Quality = 0;
  this->m_swap_chain_desc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
  this->m_swap_chain_desc.OutputWindow = m_window;
  this->m_swap_chain_desc.Windowed = (unsigned __int8)v5;
  if ( !(_BYTE)v5 )
    this->m_swap_chain_desc.Flags = 0;
  vostok::render::res_render_output::initialize_swap_chain(v5, (int)this);
}
