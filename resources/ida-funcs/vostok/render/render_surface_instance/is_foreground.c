BOOL __usercall vostok::render::render_surface_instance::is_foreground@<eax>(
        vostok::render::render_surface_instance *this@<ecx>,
        int a2@<eax>)
{
  return *(_BYTE *)(*(_DWORD *)(a2 + 20) + 276) || *(_BYTE *)(a2 + 54);
}
