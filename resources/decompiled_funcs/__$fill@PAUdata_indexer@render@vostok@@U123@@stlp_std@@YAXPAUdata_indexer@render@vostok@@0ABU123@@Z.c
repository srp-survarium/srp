void __fastcall stlp_std::fill<vostok::render::data_indexer *,vostok::render::data_indexer>(
        vostok::resources::request *__last,
        const vostok::resources::request *__val,
        vostok::resources::request *__first)
{
  vostok::resources::request *v3; // eax
  int i; // ecx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__val;
    --i;
  }
}
