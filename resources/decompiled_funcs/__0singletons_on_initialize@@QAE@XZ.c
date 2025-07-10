singletons_on_initialize *__usercall singletons_on_initialize::singletons_on_initialize@<eax>(
        singletons_on_initialize *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::decal_shader_constants_and_geometry *v2; // ecx
  unsigned __int8 v4; // [esp+Bh] [ebp-1h]

  vostok::render::renderer_context::renderer_context(&this->renderer_context);
  *(_DWORD *)(a2 + 17028) = 0;
  *(_DWORD *)(a2 + 17032) = 0;
  *(_DWORD *)(a2 + 17036) = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.y = a2 + 17028;
  *(_QWORD *)(a2 + 17040) = 0;
  *(_QWORD *)(a2 + 17048) = 0;
  *(_BYTE *)(a2 + 17040) = 0;
  *(_DWORD *)(a2 + 17044) = 0;
  *(_DWORD *)(a2 + 17056) = 0;
  *(_DWORD *)(a2 + 17048) = a2 + 17040;
  *(_DWORD *)(a2 + 17052) = a2 + 17040;
  *(_BYTE *)(a2 + 17060) = v4;
  vostok::render::particle_shader_constants::particle_shader_constants((vostok::render::particle_shader_constants *)v4);
  vostok::render::decal_shader_constants_and_geometry::decal_shader_constants_and_geometry(v2);
  return (singletons_on_initialize *)a2;
}
