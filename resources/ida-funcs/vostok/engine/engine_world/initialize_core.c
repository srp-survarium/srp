void __usercall vostok::engine::engine_world::initialize_core(
        vostok::engine::engine_world *this@<ecx>,
        _DWORD *a2@<edi>)
{
  void *v2; // ecx
  char *p_initiator_tree; // ebx
  char *v4; // eax
  vostok::strings::detail::tuples *v5; // ecx
  vostok::strings::detail::tuples *v6; // ecx
  void *v7; // esp
  vostok::strings::detail::tuples *v8; // ecx
  BOOL v9; // [esp-4h] [ebp-44h]
  int v10; // [esp+0h] [ebp-40h] BYREF
  vostok::strings::detail::tuples v11; // [esp+Ch] [ebp-34h] BYREF

  if ( vostok::command_line::key::is_set(
         (vostok::command_line::key *)this,
         (int)&vostok::threading::g_debug_single_thread) )
  {
    p_initiator_tree = "main";
  }
  else if ( vostok::threading::core_count(v2) == 1 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(a2[1] + 12))(a2 + 1) )
      p_initiator_tree = "editor + logic + render";
    else
      p_initiator_tree = "logic + render";
  }
  else
  {
    p_initiator_tree = (char *)&initiator_raw.initiator_tree;
  }
  v4 = (char *)(*(int (__thiscall **)(_DWORD *))(*a2 + 72))(a2);
  vostok::strings::detail::tuples::tuples(v5, &v11, v4, "/sources");
  v7 = alloca(vostok::strings::detail::tuples::size(v6, (unsigned int *)&v11));
  vostok::strings::detail::tuples::concat(v8, (int)&v11, (char *)&v10);
  v9 = (*(unsigned __int8 (__thiscall **)(_DWORD *))(a2[1] + 12))(a2 + 1) == 0;
  vostok::core::initialize(p_initiator_tree, (const char *)v9);
  if ( (_S4_3 & 1) == 0 )
  {
    _S4_3 |= 1u;
    psysAlloc.__vftable = (Scaleform::SysAllocBase_vtbl *)&survarium::scaleform_engine::xrSysAllocMalloc::`vftable';
    dword_47EA440 = (int)vostok::engine::scaleform_engine_alloc;
    dword_47EA444 = (int)vostok::engine::scaleform_engine_free;
    atexit((int (__cdecl *)())survarium::scaleform_engine::initialize_::_2_::_dynamic_atexit_destructor_for__scaleform_alloc__);
  }
  Scaleform::GFx::System::Init(&psysAlloc);
  g_log_output_ptr = (void (__cdecl *)(unsigned __int8, const char *))vostok::engine::scaleform_log_output;
}
