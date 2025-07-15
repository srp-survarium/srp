void __usercall vostok::render::speedtree_instance_cook::speedtree_instance_cook(
        vostok::render::speedtree_instance_cook *this@<ecx>,
        _DWORD *a2@<esi>)
{
  *a2 = &vostok::resources::cook_base::`vftable';
  a2[1] = 0;
  a2[2] = 17;
  a2[3] = 0;
  a2[4] = -1;
  a2[5] = GetCurrentThreadId();
  a2[6] = 8;
  a2[7] = 0;
  *a2 = &vostok::render::speedtree_instance_cook::`vftable';
}
