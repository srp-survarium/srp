void __cdecl survarium::scaleform_engine::initialize()
{
  if ( (_S4_3 & 1) == 0 )
  {
    _S4_3 |= 1u;
    scaleform_alloc.__vftable = (survarium::scaleform_engine::xrSysAllocMalloc_vtbl *)&survarium::scaleform_engine::xrSysAllocMalloc::`vftable';
    scaleform_alloc.m_mem_alloc_ptr = vostok::engine::scaleform_engine_alloc;
    scaleform_alloc.m_mem_free_ptr = vostok::engine::scaleform_engine_free;
    atexit(survarium::scaleform_engine::initialize_::_2_::_dynamic_atexit_destructor_for__scaleform_alloc__);
  }
  Scaleform::GFx::System::Init(&scaleform_alloc);
  g_log_output_ptr = vostok::engine::scaleform_log_output;
}
