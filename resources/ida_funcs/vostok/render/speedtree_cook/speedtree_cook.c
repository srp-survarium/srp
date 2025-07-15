void __usercall vostok::render::speedtree_cook::speedtree_cook(
        vostok::render::speedtree_cook *this@<ecx>,
        _DWORD *a2@<esi>)
{
  *a2 = &vostok::resources::cook_base::`vftable';
  a2[1] = 0;
  a2[2] = 16;
  a2[3] = 1;
  a2[4] = -1;
  a2[5] = GetCurrentThreadId();
  a2[6] = 8;
  a2[7] = 0;
  *a2 = &vostok::render::speedtree_cook::`vftable';
}
