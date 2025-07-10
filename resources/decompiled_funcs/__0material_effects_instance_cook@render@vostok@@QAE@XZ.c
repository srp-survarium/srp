void __thiscall vostok::render::material_effects_instance_cook::material_effects_instance_cook(
        vostok::render::material_effects_instance_cook *this)
{
  material_effects_instance_cooker.__vftable = (vostok::render::material_effects_instance_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  material_effects_instance_cooker.m_cook_users_count.m_count = 0;
  material_effects_instance_cooker.m_class_id = material_effects_instance_class;
  material_effects_instance_cooker.m_reuse_type = reuse_false;
  material_effects_instance_cooker.m_creation_thread_id = -1;
  material_effects_instance_cooker.m_allocate_thread_id = GetCurrentThreadId();
  material_effects_instance_cooker.m_next = 0;
  material_effects_instance_cooker.m_flags.m_flags = 8;
  material_effects_instance_cooker.__vftable = (vostok::render::material_effects_instance_cook_vtbl *)&stru_960AE0.m_effect_descriptors._M_t._M_node_count;
}
