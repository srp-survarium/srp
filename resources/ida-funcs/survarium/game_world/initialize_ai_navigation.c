void __usercall survarium::game_world::initialize_ai_navigation(
        survarium::game_world *this@<ecx>,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *a2@<esi>)
{
  vostok::ai::navigation::engine *v2; // eax

  if ( a2 )
    v2 = (vostok::ai::navigation::engine *)&a2[48];
  else
    v2 = 0;
  a2[147].m_object = (vostok::render::base_scene *)vostok::ai::navigation::create_world(
                                                     v2,
                                                     a2 + 1,
                                                     *(vostok::render::debug::renderer **)(a2[42].m_object->grm_satisfaction_tree_hook.color_
                                                                                         + 8));
}
