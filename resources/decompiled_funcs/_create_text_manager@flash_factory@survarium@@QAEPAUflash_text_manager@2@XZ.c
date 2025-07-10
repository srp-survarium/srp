void __thiscall survarium::flash_factory::create_text_manager(
        survarium::flash_factory *this,
        survarium::flash_factory *thisa)
{
  survarium::flash_text_manager *v2; // esi

  v2 = (survarium::flash_text_manager *)operator new(0x10u);
  if ( v2 )
    survarium::flash_text_manager::flash_text_manager(v2, thisa->m_gfx_loader);
}
