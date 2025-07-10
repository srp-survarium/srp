void __fastcall stlp_std::fill<survarium::inventory_item_instance *,survarium::inventory_item_instance>(
        vostok::render::vertex_colored *__last,
        const vostok::render::vertex_colored *__val,
        vostok::render::vertex_colored *__first)
{
  vostok::render::vertex_colored *v3; // eax
  int i; // ecx

  v3 = __first;
  for ( i = __last - __first; i > 0; ++v3 )
  {
    *v3 = *__val;
    --i;
  }
}
