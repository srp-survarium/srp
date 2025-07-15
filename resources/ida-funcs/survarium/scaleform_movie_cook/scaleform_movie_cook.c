void __thiscall survarium::scaleform_movie_cook::scaleform_movie_cook(
        survarium::scaleform_movie_cook *this,
        survarium::flash_factory *factory)
{
  s_scaleform_movie_cook.__vftable = (survarium::scaleform_movie_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  s_scaleform_movie_cook.m_cook_users_count.m_count = 0;
  s_scaleform_movie_cook.m_class_id = flash_movie_class;
  s_scaleform_movie_cook.m_reuse_type = reuse_false;
  s_scaleform_movie_cook.m_creation_thread_id = -1;
  s_scaleform_movie_cook.m_allocate_thread_id = GetCurrentThreadId();
  s_scaleform_movie_cook.m_flags.m_flags = 8;
  s_scaleform_movie_cook.m_next = 0;
  s_scaleform_movie_cook.__vftable = (survarium::scaleform_movie_cook_vtbl *)&survarium::scaleform_movie_cook::`vftable';
  s_scaleform_movie_cook.m_factory = factory;
  vostok::resources::resources_manager::register_cook(&s_scaleform_movie_cook);
}
