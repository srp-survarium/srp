void __userpurge vostok::render::speedtree_forest::tick(
        vostok::render::speedtree_forest *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *context)
{
  vostok::render::base_scene_view *m_object; // eax
  SpeedTree::CForest *v5; // ecx
  float v6; // [esp+10h] [ebp-Ch] BYREF
  vostok::resources::memory_usage_type m_memory_usage_self; // [esp+14h] [ebp-8h]

  m_object = context->m_scene_view.m_object;
  v6 = *((float *)&m_object[2].m_parent_resources + 6);
  m_memory_usage_self = m_object[2].m_memory_usage_self;
  SpeedTree::CWind::SetDirection((SpeedTree::CWind *)(a2 + 4376), &v6);
  SpeedTree::CWind::SetStrength(
    (SpeedTree::CWind *)(a2 + 4376),
    *(float *)&context->m_scene_view.m_object[2].m_current_satisfaction_update_tick);
  *(float *)(*(_DWORD *)(a2 + 4348) + 120) = context->m_current_time;
  SpeedTree::CForest::SetWindLeader((const SpeedTree::CWind *)(a2 + 4376), *(SpeedTree::CForest **)(a2 + 4348));
  SpeedTree::CForest::AdvanceGlobalWind(v5, *(_DWORD *)(a2 + 4348));
}
