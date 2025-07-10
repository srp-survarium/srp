void __usercall vostok::strings::detail::tuples::tuples(vostok::strings::detail::tuples *this@<ecx>, int a2@<esi>)
{
  `vector constructor iterator'(
    (char *)a2,
    8u,
    6,
    (void *(__thiscall *)(void *))vostok::render::lod_render_info::lod_render_info);
  *(_DWORD *)(a2 + 48) = 3;
  *(_DWORD *)(a2 + 4) = strlen("resources/localization/");
  *(_DWORD *)a2 = "resources/localization/";
  *(_DWORD *)(a2 + 12) = strlen(s_localization_str);
  *(_DWORD *)(a2 + 8) = s_localization_str;
  *(_DWORD *)(a2 + 20) = strlen("/localization");
  *(_DWORD *)(a2 + 16) = "/localization";
}
