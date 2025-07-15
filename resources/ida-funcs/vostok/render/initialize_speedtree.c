void __cdecl vostok::render::initialize_speedtree()
{
  vostok::render::speedtree_cook *v0; // ecx
  vostok::render::speedtree_instance_cook *v1; // ecx
  int v2; // ecx
  SpeedTree::CAllocatorInterface cOn; // [esp+Bh] [ebp-1h] BYREF

  if ( (_S6_2 & 1) == 0 )
  {
    _S6_2 |= 1u;
    s_speed_tree_allocator.__vftable = (vostok::render::speed_tree_allocator_vtbl *)&vostok::render::speed_tree_allocator::`vftable';
    atexit(vostok::render::initialize_speedtree_::_2_::_dynamic_atexit_destructor_for__s_speed_tree_allocator__);
  }
  SpeedTree::CCore::IsAuthorized();
  SpeedTree::CAllocatorInterface::CAllocatorInterface(&cOn, &s_speed_tree_allocator);
  SpeedTree::CCoordSys::SetCoordSys(COORD_SYS_LEFT_HANDED_Y_UP, 0);
  vostok::render::speedtree_cook::speedtree_cook(v0, &s_speedtree_cook);
  _InterlockedExchange(&s_speedtree_cook.m_initialized, 1);
  vostok::resources::resources_manager::register_cook((int)&s_speedtree_cook.m_initialized, s_speedtree_cook.m_variable);
  vostok::render::speedtree_instance_cook::speedtree_instance_cook(v1, &s_speedtree_instance_cook);
  _InterlockedExchange(&s_speedtree_instance_cook.m_initialized, 1);
  vostok::resources::resources_manager::register_cook(v2, s_speedtree_instance_cook.m_variable);
}
