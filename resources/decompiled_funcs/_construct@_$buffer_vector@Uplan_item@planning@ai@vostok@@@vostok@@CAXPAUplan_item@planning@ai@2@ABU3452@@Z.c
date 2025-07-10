void __cdecl vostok::buffer_vector<vostok::ai::planning::plan_item>::construct(
        vostok::ai::planning::plan_item *p,
        const vostok::ai::planning::plan_item *value)
{
  vostok::ai::planning::plan_item *v2; // [esp+2Ch] [ebp-4h]

  v2 = (vostok::ai::planning::plan_item *)operator new(0x1Cu, p);
  if ( v2 )
    vostok::ai::planning::plan_item::plan_item(v2, value);
}
