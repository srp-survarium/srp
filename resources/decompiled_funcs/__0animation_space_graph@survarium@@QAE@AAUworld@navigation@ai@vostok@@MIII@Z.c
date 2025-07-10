void __userpurge survarium::animation_space_graph::animation_space_graph(
        survarium::animation_space_graph *this@<ecx>,
        int a2@<esi>,
        vostok::ai::navigation::world *navigation_world,
        float agent_radius,
        unsigned int animations_count,
        unsigned int mixes_count,
        const unsigned int edges_count)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 264) = navigation_world;
  *(float *)(a2 + 268) = ::agent_radius;
  *(_DWORD *)(a2 + 284) = mixes_count;
  *(_DWORD *)a2 = &survarium::animation_space_graph::`vftable';
  *(_DWORD *)(a2 + 272) = -1082130432;
  *(float *)(a2 + 276) = agent_radius;
  *(_DWORD *)(a2 + 280) = animations_count;
}
