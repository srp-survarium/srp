void __cdecl vostok::render::on_single_material_loaded()
{
  _InterlockedExchangeAdd(&s_pending_materials_count, 0xFFFFFFFF);
}
