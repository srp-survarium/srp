void __userpurge vostok::physics::collision_shape_cook::collision_shape_cook(
        vostok::physics::collision_shape_cook *this@<ecx>,
        int a2@<esi>,
        bool static_object)
{
  int v3; // ecx

  *(_DWORD *)a2 = &vostok::resources::cook_base::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 12) = 1;
  *(_DWORD *)(a2 + 16) = -1;
  *(_DWORD *)(a2 + 8) = static_object + 31;
  *(_DWORD *)(a2 + 20) = GetCurrentThreadId();
  *(_DWORD *)(a2 + 24) = 8;
  *(_DWORD *)(a2 + 28) = 0;
  *(_DWORD *)a2 = &vostok::physics::collision_shape_cook::`vftable';
  *(_BYTE *)(a2 + 32) = static_object;
  vostok::resources::resources_manager::register_cook(v3, (vostok::resources::cook_base *)a2);
}
