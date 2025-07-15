void __thiscall survarium::animated_model_instance_cook::animated_model_instance_cook(
        survarium::animated_model_instance_cook *this)
{
  s_animated_model_instance_cook.m_cook_users_count.m_count = 0;
  s_animated_model_instance_cook.m_reuse_type = reuse_false;
  s_animated_model_instance_cook.m_next = 0;
  s_animated_model_instance_cook.m_class_id = game_animated_model_instance_class;
  s_animated_model_instance_cook.m_creation_thread_id = -1;
  s_animated_model_instance_cook.m_allocate_thread_id = -4;
  s_animated_model_instance_cook.m_flags.m_flags = 8;
  s_animated_model_instance_cook.__vftable = (survarium::animated_model_instance_cook_vtbl *)&survarium::animated_model_instance_cook::`vftable';
}
