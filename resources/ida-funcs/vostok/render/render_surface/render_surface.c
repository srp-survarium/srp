void __usercall vostok::render::render_surface::render_surface(
        vostok::render::render_surface *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)a2 = &vostok::render::render_surface::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)(a2 + 28) = a2 + 40;
  *(_DWORD *)(a2 + 32) = a2 + 40;
  *(_BYTE *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 36) = a2 + 104;
  *(_DWORD *)(a2 + 104) = 0;
  vostok::math::create_zero_aabb((vostok::math::aabb *)(a2 + 108));
  *(float *)(a2 + 152) = FLOAT_10000_0;
}
