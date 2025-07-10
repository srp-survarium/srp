void __usercall vostok::render::res_render_output::initialize_swap_chain(
        vostok::render::res_render_output *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::res_render_output *v2; // ecx
  IDXGIDevice *pDXGIDevice; // [esp+1Ch] [ebp-Ch] BYREF
  IDXGIAdapter *pDXGIAdapter; // [esp+20h] [ebp-8h] BYREF
  IDXGIFactory *dxgi_factory; // [esp+24h] [ebp-4h] BYREF

  (**(void (__stdcall ***)(int, GUID *, IDXGIDevice **))`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x)(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
    &_GUID_54ec77fa_1377_44e6_8c32_88fd5f44c84c,
    &pDXGIDevice);
  pDXGIDevice->GetParent(pDXGIDevice, &_GUID_2411e7e1_12ac_4ccf_bd14_9798e8534dc0, (void **)&pDXGIAdapter);
  pDXGIAdapter->GetParent(pDXGIAdapter, &_GUID_7b7166ec_21c7_44ae_b21a_c9ae321ae369, (void **)&dxgi_factory);
  dxgi_factory->CreateSwapChain(
    dxgi_factory,
    (IUnknown *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.x,
    (DXGI_SWAP_CHAIN_DESC *)(a2 + 144),
    (IDXGISwapChain **)(a2 + 204));
  vostok::render::res_render_output::update_targets(v2, a2);
}
