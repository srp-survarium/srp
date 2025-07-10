void __cdecl vostok::buffer_vector<vostok::ai::statistics_item<46,16>>::construct(
        vostok::ai::statistics_item<46,16> *p,
        const vostok::ai::statistics_item<46,16> *value)
{
  vostok::ai::statistics_item<46,16> *v2; // [esp+58h] [ebp-4h]

  v2 = (vostok::ai::statistics_item<46,16> *)operator new(0x3F4u, p);
  if ( v2 )
    vostok::ai::statistics_item<46,16>::statistics_item<46,16>(v2, value);
}
