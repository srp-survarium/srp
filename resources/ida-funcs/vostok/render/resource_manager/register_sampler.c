void __thiscall vostok::render::resource_manager::register_sampler(
        vostok::render::resource_manager *this,
        const char *name,
        ID3D11SamplerState *sampler,
        ID3D11SamplerState *a4)
{
  const vostok::fixed_string<64> *v4; // eax
  vostok::buffer_vector<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> > *v5; // ecx
  vostok::buffer_string v6[6]; // [esp+Ch] [ebp-A0h] BYREF
  stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *> value; // [esp+58h] [ebp-54h] BYREF

  vostok::fixed_string<64>::fixed_string<64>((vostok::fixed_string<64> *)this, v6, (char *)sampler);
  vostok::fixed_string<64>::fixed_string<64>(&value.first, v4);
  value.second = a4;
  vostok::buffer_vector<stlp_std::pair<vostok::fixed_string<64>,ID3D11SamplerState *>>::push_back(
    v5,
    (int)&dword_93A84 + (_DWORD)name,
    &value);
}
