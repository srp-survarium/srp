void __userpurge vostok::physics::bullet_physics_world::object_query_::_2_::object_query_callback::object_query_callback(
        vostok::physics::bullet_physics_world::object_query::__l2::object_query_callback *this@<ecx>,
        int a2@<eax>,
        vostok::vectora<vostok::physics::closest_ray_result> *results,
        unsigned __int16 group,
        const unsigned __int16 mask)
{
  const vostok::math::float4x4 *v5; // xmm1_4

  v5 = clear_value;
  *(_DWORD *)(a2 + 12) = this;
  *(_DWORD *)(a2 + 4) = v5;
  *(_DWORD *)a2 = &`vostok::physics::bullet_physics_world::object_query'::`2'::object_query_callback::`vftable';
  *(_WORD *)(a2 + 8) = (_WORD)results;
  *(_WORD *)(a2 + 10) = group;
  *(_DWORD *)(a2 + 16) = v5;
  *(_DWORD *)(a2 + 20) = 0;
  *(_DWORD *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = v5;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  *(_DWORD *)(a2 + 56) = v5;
  *(_DWORD *)(a2 + 60) = 0;
  *(_DWORD *)(a2 + 64) = 0;
  *(_DWORD *)(a2 + 68) = 0;
  *(_DWORD *)(a2 + 72) = 0;
  *(_DWORD *)(a2 + 76) = 0;
}
