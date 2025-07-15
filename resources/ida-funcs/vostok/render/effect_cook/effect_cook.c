void __thiscall vostok::render::effect_cook::effect_cook(vostok::render::effect_cook *this)
{
  DWORD CurrentThreadId; // eax

  effect_cooker.__vftable = (vostok::render::effect_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  effect_cooker.m_cook_users_count.m_count = 0;
  effect_cooker.m_class_id = render_effect_class;
  effect_cooker.m_reuse_type = reuse_true;
  effect_cooker.m_creation_thread_id = GetCurrentThreadId();
  CurrentThreadId = GetCurrentThreadId();
  effect_cooker.m_flags.m_flags = 0;
  effect_cooker.m_next = 0;
  effect_cooker.m_allocate_thread_id = CurrentThreadId;
  effect_cooker.__vftable = (vostok::render::effect_cook_vtbl *)&stru_984D24.m_working_macro_list.m_buffer[0].m_store[368];
}
