void __usercall vostok::render::render_model::render_model(vostok::render::render_model *this@<ecx>, int a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)a2 = &vostok::render::render_model::`vftable';
  vostok::math::create_identity_aabb((vostok::math::aabb *)(a2 + 264));
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_WORD *)(a2 + 292) = 0;
}
