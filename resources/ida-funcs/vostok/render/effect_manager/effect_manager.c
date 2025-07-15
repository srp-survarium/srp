void __thiscall vostok::render::effect_manager::effect_manager(vostok::render::effect_manager *this, int a2)
{
  _DWORD *v2; // eax
  char *v3; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v4; // ecx
  bool v5; // zf
  vostok::buffer_vector<vostok::resources::cook_base *> *v6; // [esp-4h] [ebp-28h]
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v7; // [esp+0h] [ebp-24h]

  *(_BYTE *)a2 = 0;
  *(_DWORD *)(a2 + 4) = a2 + 16;
  *(_DWORD *)(a2 + 8) = a2 + 16;
  *(_DWORD *)(a2 + 12) = a2 + 18192;
  *(_BYTE *)(a2 + 18192) = 0;
  *(_DWORD *)(a2 + 18196) = 0;
  *(_DWORD *)(a2 + 18200) = 0;
  *(_DWORD *)(a2 + 18204) = 0;
  *(_DWORD *)(a2 + 18208) = 0;
  *(_BYTE *)(a2 + 18196) = 0;
  *(_DWORD *)(a2 + 18204) = a2 + 18196;
  *(_DWORD *)(a2 + 18208) = a2 + 18196;
  *(_DWORD *)(a2 + 18200) = 0;
  *(_DWORD *)(a2 + 18212) = 0;
  *(_DWORD *)(a2 + 18220) = 0;
  *(_DWORD *)(a2 + 18224) = 0;
  *(_DWORD *)(a2 + 18228) = 0;
  *(_DWORD *)(a2 + 18232) = 0;
  *(_BYTE *)(a2 + 18220) = 0;
  *(_DWORD *)(a2 + 18224) = 0;
  *(_DWORD *)(a2 + 18228) = a2 + 18220;
  *(_DWORD *)(a2 + 18232) = a2 + 18220;
  *(_DWORD *)(a2 + 18236) = 0;
  *(_DWORD *)(a2 + 18244) = 0;
  *(_DWORD *)(a2 + 18248) = 0;
  *(_DWORD *)(a2 + 18252) = 0;
  *(_DWORD *)(a2 + 18256) = 0;
  *(_BYTE *)(a2 + 18244) = 0;
  *(_DWORD *)(a2 + 18248) = 0;
  *(_DWORD *)(a2 + 18252) = a2 + 18244;
  *(_DWORD *)(a2 + 18256) = a2 + 18244;
  *(_DWORD *)(a2 + 18260) = 0;
  *(_DWORD *)(a2 + 18268) = a2 + 18280;
  *(_DWORD *)(a2 + 18272) = a2 + 18280;
  *(_DWORD *)(a2 + 18276) = (char *)&loc_3FFFF + a2 + 18281;
  vostok::quasi_singleton<vostok::render::effect_manager>::pinst = (vostok::render::effect_manager *)a2;
  vostok::render::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128>>>::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128>>>((vostok::render::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128> > > *)((char *)&loc_44768 + a2));
  vostok::render::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128>>>::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128>>>((vostok::render::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128> > > *)(a2 + 280448));
  v2 = (_DWORD *)((char *)&loc_4479C + a2);
  *((_BYTE *)&loc_44798 + a2) = 0;
  v3 = (char *)&loc_4479C + a2 + 12;
  *v2 = v3;
  v2[1] = v3;
  v4 = (vostok::buffer_vector<vostok::resources::cook_base *> *)((char *)&loc_4479C + a2 + 4108);
  v5 = (_S5_15 & 1) == 0;
  v2[2] = v4;
  if ( v5 )
  {
    _S5_15 |= 1u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0xD,
      &effect_cooker,
      reuse_true,
      0xFFFFFFFD,
      0,
      v7);
    effect_cooker.__vftable = (vostok::render::effect_cook_vtbl *)&vostok::render::effect_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::effect_manager::effect_manager_::_2_::_dynamic_atexit_destructor_for__effect_cooker__);
    v4 = v6;
  }
  vostok::resources::resources_manager::register_cook(&effect_cooker, v4);
  *(_BYTE *)(a2 + 1) = 0;
}
